/*************************************************************************
	> File Name: binarySearchTree.cpp
	> Author: lidongmeng
	> Mail: lidongmeng@ict.ac.cn
	> Created Time: Thu 23 Jun 2016 09:12:51 PM EDT
 ************************************************************************/

#include "binarySearchTree.h"
/**
 * contains build delete and search
 *
 */
// inorder tranversal
// get a increasing sequence
void inorderTranversal(TreeNode * root) {
	stack<TreeNode*> stk;
	TreeNode * current = root;
	while (!stk.empty() || current) {
		if (current) {
			stk.push(current);
			current = current->left;
		} else {
			current = stk.top();
			stk.pop();
			cout << current->val << " ";
			current = current->right;
		}
	}
	cout << endl;
}

/**
 * insert a node using recurive and iteration way
 * time complexity: O(h)---worst:O(n)
 */
// recurive way
TreeNode * insertRe(TreeNode * root, int val) {
	if (!root) return new TreeNode(val);
	if (root->val < val) {
		root->right = insertRe(root->right, val);
	} else {
		root->left = insertRe(root->left, val);
	}
}

// iteration way
// record the parent
TreeNode * insert(TreeNode * root, int val) {
	TreeNode * parent = NULL;
	TreeNode * current = root;
	while (current) {
		if (current->val == val) {
			cout << "duplicate val, do nothing" << endl;
			return root;
		} else if (current->val < val) {
			parent = current;
			current = current->right;
		} else {
			parent = current;
			current = current->left;
		}
	}
	if (parent == NULL) { // no node insert the root
		return new TreeNode(val);
	} else {
		TreeNode * temp = new TreeNode(val);
		if (parent->val > val) {
			parent->left = temp;
		} else {
			parent->right = temp;
		}
		return root;
	}
}

/**
 * search a node with value val
 * using two way: recurive and iteration
 * if not exits return null
 * time complexity:O(h)  worst:O(n)
 */
TreeNode * searchRe(TreeNode * root, int val) {
	if (!root) return NULL;
	if (root->val == val) {
		return root;
	} else if (root->val > val) {
		return searchRe(root->left, val);
	} else {
		return searchRe(root->right, val);
	}
}

TreeNode * search(TreeNode * root, int val) {
	TreeNode * current = root;
	while (current) {
		if (current->val == val) {
			return current;
		} else if (current->val > val) {
			current = current->left;
		} else {
			current = current->right;
		}
	}
	return NULL;
}

/**
 * delete a node with val
 * if it is the null just delete
 * if it has one child use it to replace it
 * if it has two children use precessor or successor to replace it
 */
TreeNode * findSuccessor(TreeNode * root) {
	TreeNode * current = root->right;
	while (current->left) current = current->left;
	return current;
}

TreeNode * findPrecessor(TreeNode * root) {
	TreeNode * current = root->left;
	while (current->right) current = current->right;
	return current;
}

TreeNode * deleteNode(TreeNode * root, int val) {
	if (!root) return root;
	if (root->val < val) {
		root->right = deleteNode(root->right, val);
	} else if (root->val > val) {
		root->left = deleteNode(root->left, val);
	} else {
		if (root->left == NULL) {
			TreeNode * temp = root->right;
			free(root);
			return temp;
		} else if (root->right == NULL) {
			TreeNode * temp = root->left;
			free(root);
			return temp;
		} else {
		    // use successor as the root val
			// TreeNode * temp = findSuccessor(root);
			// root->val = temp->val;
			// root->right = deleteNode(root->right, temp->val);
			// use precessor as the root val
			TreeNode * temp = findPrecessor(root);
			root->val = temp->val;
			root->left = deleteNode(root->left, temp->val);
		}
	}
	return root;
}

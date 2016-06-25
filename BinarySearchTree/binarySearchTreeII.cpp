/*************************************************************************
	> File Name: binarySearchTreeII.cpp
	> Author: lidongmeng
	> Mail: lidongmeng@ict.ac.cn
	> Created Time: Fri 24 Jun 2016 02:01:08 AM EDT
 ************************************************************************/

#include "binarySearchTree.h"

// judge weather a tree is a valid bst
// first we can use vector to store the inorder tranversal result and judge if it is a increasing sequence
// second we use a prev pointer to record the last visited node and compare it with the current node value
// third we can set a range [min, max], judge if every node in the range
void inorderTranversalRe(TreeNode * root, vector<int> & result) {
	if (root) {
		inorderTranversalRe(root->left, result);
		result.push_back(root->val);
		inorderTranversalRe(root->right, result);
	}
}

bool isValidBSTI(TreeNode * root) {
	vector<int> result;
	inorderTranversalRe(root, result);
	for (int i = 0; i < result.size() - 2; ++i) {
		if (result[i] >= result[i+1]) return false;
	}
	return true;
}

bool isValidBSTII(TreeNode * root) {
	TreeNode * current = root;
	TreeNode * prev = NULL;
	stack<TreeNode *> stk;
	while (!stk.empty() || current) {
		if (current) {
			stk.push(current);
			current = current->left;
		} else {
			current = stk.top();
			stk.pop();
			if (prev != NULL && prev->val >= current->val) return false;
			prev = current;
			current = current->right;
		}
	}
	return true;
}

bool isValidBSTIII(TreeNode * root, int l, int r) {
	if (!root) return true;
	if (root->val >= r || root->val <= l) return false;
	return isValidBSTIII(root->left, l, root->val) && isValidBSTIII(root->right, root->val, r);
}

bool isVlaidBST(TreeNode * root) {
	return isValidBSTII(root);
}

// give a preorder of a bst reconstruct the tree
// first we can find the root and the left part , the right part and then do the same
TreeNode * reconstructBSTI(vector<int> preorder, int start, int end) {
	if (start > end) return NULL;
	TreeNode * root = new TreeNode(preorder[start]);
	int pos = start + 1;
	while (pos <= end && preorder[pos] < preorder[start]) ++pos;
	root->left = reconstructBSTI(preorder, start+1, pos-1);
	root->right = reconstructBSTI(preorder,pos, end);
	return root;
}

// second we can use the [min, max] range method like isvalidbst
TreeNode * reconstructBSTII(vector<int> preorder, int & index, int l, int r) {
	if (index >= preorder.size()) return NULL;
	TreeNode * root = NULL;
	int value = preorder[index];
	if (value > l && value < r) {
		root = new TreeNode(value);
		index++;
		if (index < preorder.size()) {
			root->left = reconstructBSTII(preorder, index, l, value);
			root->right = reconstructBSTII(preorder, index, value, r);
		}
	}
	return root;
}

TreeNode * reconstructBSTFromPreorder(vector<int> preorder) {
	//	int index = 0;
	//	return reconstructBSTII(preorder, index, INT_MIN, INT_MAX);
	return reconstructBSTI(preorder, 0, preorder.size()-1);
}

// tranversal a tree and insert every node to the next tree: mlgn--mlg(m+n-1)
// inorder tranversal and stor, the merge and then construct tree using sorted array
TreeNode * mergeTwoBSTAsOne(TreeNode * root1, TreeNode * root2) {
	// later to do
}

// inorder tranversal
// morries tranversal
TreeNode * findKthSmallestNode(TreeNode * root) {
	// later to do
}

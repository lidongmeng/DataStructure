/*************************************************************************
	> File Name: main.cpp
	> Author: lidongmeng
	> Mail: lidongmeng@ict.ac.cn
	> Created Time: Fri 24 Jun 2016 01:49:44 AM EDT
 ************************************************************************/

#include "binarySearchTree.h"
#include<iostream>
using namespace std;

int main(int argc, char ** argv) {
	vector<int> nums{5,2,4,1,6,9,3};
	TreeNode * root = NULL;
	/**
	// inset test
	for (int i = 0; i < nums.size(); ++i) {
		// root = insertRe(root, nums[i]);
		root = insert(root, nums[i]);
	}
	inorderTranversal(root);
	
	// search test
    // cout << searchRe(root, 9)->val << endl;
	// cout << (searchRe(root, 100) == NULL) << endl;
	cout << search(root, 9)->val << endl;
	cout << (search(root, 100) == NULL) << endl;
	
	// delete test
	deleteNode(root, 2);
	inorderTranversal(root);
*/
	
	// reconstruct test
	vector<int> preorder{10, 5, 1, 7, 40, 50};
	TreeNode * rroot = reconstructBSTFromPreorder(preorder);
	inorderTranversal(rroot);
	return 0;
}

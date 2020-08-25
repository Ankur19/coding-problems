#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

int maxSum(TreeNode* root, int& maxVal){
	if(!root)
		return 0;
	int l = max(0, maxSum(root->left, maxVal));
	int r = max(0, maxSum(root->right, maxVal));

	maxVal = max(root->val+l+r, maxVal);

	return root->val + max(l, r);
}

int maxPathSum(TreeNode* root){
	int maxVal = INT_MIN;
	int sum = maxSum(root, maxVal);
	return maxVal;
}


int main(){
	//-10, -5, 30, 45, -20, -21, 5, 1, 3, -3, 100, 2, 100, 1, 100
	TreeNode* root = new TreeNode(-10);
	TreeNode* left = new TreeNode(-5);
	TreeNode* right = new TreeNode(30);
	root->left = left;
	root->right = right;
	left->left = new TreeNode(45);
	left->right = new TreeNode(-20);
	right->left = new TreeNode(-21);
	right->right = new TreeNode(5);
	left->left->left = new TreeNode(1);
	left->left->right = new TreeNode(3);
	left->right->left = new TreeNode(-3);
	left->right->right = new TreeNode(100);
	right->left->left = new TreeNode(2);
	right->left->right = new TreeNode(100);
	right->right->left = new TreeNode(1);
	right->right->right = new TreeNode(100);

	cout << "Expected: 214, Actual: " << maxPathSum(root) << endl;
	return 0;
}

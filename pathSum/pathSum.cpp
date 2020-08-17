#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool hasPathSum(TreeNode* root, int sum){
	if(!root && !sum)
		return false;
	else if(!root && sum)
		return false;
	else if(!(sum - root->val) && !root->left && !root->right)
		return true;
	return hasPathSum(root->left, sum-root->val) || hasPathSum(root->right, sum-root->val);
}

int main(){
	TreeNode* root = new TreeNode(5);
	root->left = new TreeNode(4);
	root->right = new TreeNode(8);
	root->left->left = new TreeNode(11);
	root->left->left->left = new TreeNode(7);
	root->left->left->right = new TreeNode(2);
	root->right->left = new TreeNode(13);
	root->right->right = new TreeNode(4);
	root->right->right->right = new TreeNode(1);

	cout << "Expected: true, Answer: " << hasPathSum(root, 22) << endl;
	return 0;
}

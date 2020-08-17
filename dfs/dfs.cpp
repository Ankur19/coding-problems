#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void dfsRecursive(TreeNode* root, vector<int>& data){
	if(!root)
		return;
	dfsRecursive(root->left, data);
	dfsRecursive(root->right, data);
	data.push_back(root->val);
}

vector<int> dfs(TreeNode* root){
	vector<int> ans;
	dfsRecursive(root, ans);
	return ans;
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

	vector<int> ans = dfs(root);
	cout << "The DFS movement: ";
	for(int i: ans){
		cout << i << ", ";
	}
	cout << endl;
	return 0;
}



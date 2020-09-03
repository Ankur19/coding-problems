#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void flatten(TreeNode* root) {
	if(!root)
            return;
        
	TreeNode* r = root->right;
        flatten(r);
        
	TreeNode* l = root->left;
        flatten(l);
        
	TreeNode* parent = root;
        
	root->left = nullptr;
        root->right = l;

        while(l){
		parent = l;
		l = l->right;
        }
        
	parent->right = r;
	
	return;
}

int main(){
	cout << "Check Leetcode problem: 114. Flatten Binary Tree to Linked List" << endl;
	return 0;
}

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode* prev;
	TreeNode(int v) : val(v), left(nullptr), right(nullptr), prev(nullptr) {}
};

vector<int> inOrder(TreeNode* root){
	TreeNode* prev = nullptr;
	TreeNode* cur = root;
	TreeNode* temp;
	vector<int> iot;
	while(cur != nullptr){
		if(!prev || prev == cur->prev){
			if(cur->left != nullptr){
				temp = cur;
				cur = cur->left;
			}
			else{
				iot.push_back(cur->val);
				temp = cur;
				cur = cur->right != nullptr ? cur->right : cur->prev;
			}
			prev = temp;
		}
		else if(cur->left==prev){
			iot.push_back(cur->val);
			temp = cur;
			cur = cur->right != nullptr ? cur->right : cur->prev;
			prev = temp;
		}
		else{
			temp = cur;
			cur = cur->prev;
			prev = temp;
		}
		int a = cur ? cur->val : -1;
		int b = prev ? prev->val : -1;
		//cout << a << ", " << b << endl;
	}
	return iot;
}

int main(){
	TreeNode* root = new TreeNode(1);
	root->prev = nullptr;
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->prev = root;
	root->right->prev = root;
	root->left->left = new TreeNode(4);
	root->left->left->prev = root->left;
	root->left->left->right = new TreeNode(9);
	root->left->left->right->prev = root->left->left;
	root->right->left = new TreeNode(6);
	root->right->right = new TreeNode(7);
	root->right->left->prev = root->right;
	root->right->right->prev = root->right;

	vector<int> iot = inOrder(root);
	cout << "Ans: [";
	for(int i: iot)
		cout << i << ", ";
	cout << "]" << endl;
	return 0;
}

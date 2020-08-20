#include <iostream>
#include <vector>

using namespace std;

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BST{
	public:
		TreeNode* root;
		BST(){
			this->root = nullptr;
		}
		BST* insert(int val){
			TreeNode* cur = new TreeNode(val);
			if(!this->root)
				this->root = cur;
			else{		
				TreeNode* current = this->root;
				TreeNode* parent = nullptr;
				while(current){
					parent = current;
					if(current->val > val)
						current = current->left;
					else if(current->val <= val)
						current = current->right;
				}
				if(parent->val > val){
					parent->left = cur;
				}
				else{
					parent->right = cur;
				}
			}
			return this;
		}
		BST* remove(TreeNode* root, int val){
			TreeNode* current = root;
			TreeNode* parent = nullptr;
			while(current->val != val){
				parent = current;
				if(current->val > val)
					current = current->left;
				else if(current->val < val)
					current = current->right;
			}
			if(current->left && current->right){
				TreeNode* lowestParent = getRightLowestParent(current);
				TreeNode* toSwitch = lowestParent->left;
				lowestParent->left = toSwitch->right;
				toSwitch->left = current->left;
				toSwitch->right = current->right;
				if(parent->left==current)
					parent->left = toSwitch;
				else
					parent->right = toSwitch;
			}
			else if(current->left){
				if(parent->left==current)
					parent->left = current->left;
				else
					parent->right = current->left;
			}
			else{
				if(parent->left==current)
					parent->left = current->right;
				else
					parent->right = current->right;
			}
			return this;
		}
	private:
		TreeNode* getRightLowestParent(TreeNode* current){
			TreeNode* parent = current;
			TreeNode* cur = parent->right;
			while(cur->left){
				parent = cur;
				cur = cur->left;
			}
			return parent;
		}
};

void inOrderTraversal(TreeNode* root, vector<int>& data){
	if(root){
		inOrderTraversal(root->left, data);
		data.push_back(root->val);
		inOrderTraversal(root->right, data);
	}
	return;
}

int main(){
	BST* bst = new BST();
	bst->insert(10)
		->insert(5)
		->insert(15)
		->insert(22)
		->insert(17)
		->insert(34)
		->insert(7)
		->insert(2)
		->insert(5)
		->insert(1)
		->insert(35)
		->insert(27)
		->insert(16)
		->insert(30)
		->remove(bst->root, 22)
		->remove(bst->root, 17);
	vector<int> traversalData;
	inOrderTraversal(bst->root, traversalData);

	cout << "Expected traversal data: [1, 2, 5, 5, 7, 10, 15, 16, 27, 30, 34, 35]" << endl;
	cout << "Actual data: [";
	for(int i: traversalData)
		cout << i << ", ";
	cout << "] " << endl;
	return 0;
}

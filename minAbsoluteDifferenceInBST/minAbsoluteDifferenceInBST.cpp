#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int getMinimumDifference(TreeNode* root){
	int minimum = INT_MAX;
	int currentMinimum = -1;
	TreeNode *currentNode;

	if(root->left){
		currentMinimum = abs(root->val - root->left->val);
		currentNode = root->left;
		while(currentNode){
			currentNode=currentNode->right;
			if(currentNode && abs(root->val - currentNode->val) < currentMinimum){
				currentMinimum = abs(root->val - currentNode->val);
			}
		}

		currentMinimum = min(getMinimumDifference(root->left), currentMinimum);
		minimum = min(minimum, currentMinimum);
	}
	if(root->right){
		currentMinimum = abs(root->val - root->right->val);
		currentNode = root->right;
		while(currentNode){
			currentNode=currentNode->left;
                        if(currentNode && abs(root->val - currentNode->val) < currentMinimum){
                                currentMinimum = abs(root->val - currentNode->val);
			}
                }

                currentMinimum = min(getMinimumDifference(root->right), currentMinimum);
   		minimum = min(minimum, currentMinimum);
	}
	return minimum;
}

int main(){
	TreeNode* root = new TreeNode(1);
	root->right = new TreeNode(3);
	root->right->left = new TreeNode(2);

	cout << "Expected difference: 1, Answer: " << getMinimumDifference(root) << endl;
	return 0;
}


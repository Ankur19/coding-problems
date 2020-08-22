#include <iostream>
#include <vector>

using namespace std;

struct Node{
	int val;
	Node* next;
	Node() : val(0), next(nullptr) {}
	Node(int value) : val(value), next(nullptr) {}
};

class LinkedList{
	public:
		Node* root;
		LinkedList(vector<int> data){
			root = new Node(data[0]);
			Node* current = root;
			for(int i=1;i<data.size();i++){
				current->next = new Node(data[i]);
				current = current->next;
			}
		}

		void removeKthFromEnd(int k){
			//considering we don't track the size in the class object and k is always valid
			vector<Node*> kNodes(k+1, nullptr);
			Node* current = root;
			int i = 0;
			while(current){
				kNodes[i%(k+1)] = current;
				current = current->next;
				i++;
			}
			kNodes[i%(k+1)]->next = kNodes[(i+2)%(k+1)];
			delete kNodes[(i+1)%(k+1)];
			return;
		}

		vector<int> getElements(){
			vector<int> data;
			Node* current = root;
			while(current){
				data.push_back(current->val);
				current = current->next;
			}
			return data;
		}
};



int main(){
	vector<int> test{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
	
	LinkedList* ll = new LinkedList(test);

	vector<int> data = ll->getElements();

	cout << "LL elements: [";
	for(int i: data)
		cout << i << ", ";
	cout << "]" << endl;

	cout << "Removing 8th element from end." << endl;
	ll->removeKthFromEnd(8);
	data = ll->getElements();
	cout << "LL elements: [";
	for(int i: data)
		cout << i << ", ";
        cout << "]" << endl;
	return 0;
}

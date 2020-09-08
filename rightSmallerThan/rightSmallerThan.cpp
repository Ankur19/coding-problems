#include <iostream>
#include <vector>

using namespace std;

class Bst{
	public:
		int value;
		int numLeftChildren;
		Bst* left;
		Bst* right;
		
		Bst(int val){
			value = val;
			numLeftChildren = 0;
			left = nullptr;
			right = nullptr;
		}

		int insert(int val){
			if(value > val){
				numLeftChildren++;
				if(left){
					return left->insert(val);
				}
				else{
					left = new Bst(val);
					return 0;
				}
			}
			else{
				if(right){
					return (value < val) + numLeftChildren + right->insert(val);
				}
				else{
					right = new Bst(val);
					return (value < val) + numLeftChildren;
				}
			}
		}
};

vector<int> smallAfterSelf(vector<int>& data){
	if(data.empty())
		return {};
	int n = data.size();
	vector<int> ret(n, 0);
	Bst* root = new Bst(data[n-1]);
	for(int i = n-2;i>=0;i--){
		ret[i] = root->insert(data[i]);
	}
	return ret;
}

int main(){
	vector<int> t{5,2,6,1};

	vector<int> ret = smallAfterSelf(t);

	for(int i: ret)
		cout << i << ",";
	cout << endl;
	return 0;
}

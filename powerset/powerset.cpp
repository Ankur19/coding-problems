#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> powersetRec(vector<int>& data, int start);

vector<vector<int>> powerset(vector<int>& data){
	return powersetRec(data, 0);
}

vector<vector<int>> powersetRec(vector<int>& data, int start){
	if(start>=data.size())
		return vector<vector<int>>(1, vector<int>{});

	vector<vector<int>> temp = powersetRec(data, start+1);
	vector<vector<int>> ans;
	for(vector<int>& elem : temp){
		ans.push_back(elem);
		elem.push_back(data[start]);
		ans.push_back(elem);
	}
	return ans;
}

void printArray(vector<int>& data){
	cout << "[";
	for(int i: data)
		cout << i << ", ";
	cout << "]" << endl;
	return;
}

int main(){
	vector<int> test{1, 2, 3};

	vector<vector<int>> res = powerset(test);

	for(vector<int> elem: res)
		printArray(elem);
	return 0;
}

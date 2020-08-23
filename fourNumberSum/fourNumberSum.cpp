#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<vector<int>> fourNumberSum(vector<int>& data, int target){
	int remaining;
	unordered_map<int, int> index;
	vector<vector<int>> ret;
	for(int i=0;i<data.size();i++){
		index[data[i]] = i;
	}
	for(int i=0;i<data.size();i++){
		for(int j=i+1;j<data.size();j++){
			for(int k=j+1;k<data.size();k++){
				remaining = target-data[i]-data[j]-data[k];
				if(index.find(remaining)!=index.end() && index[remaining]>k){
					ret.push_back(vector<int>{data[i], data[j], data[k], remaining});
				}
			}
		}
	}
	return ret;
}


void printArray(vector<int>& data){
	cout << "[";
	for(int i : data){
		cout << i << ", ";
	}
	cout << "]" << endl;
	return;
}


int main(){
	vector<int> test{-2, -1, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	vector<vector<int>> ret = fourNumberSum(test, 4);

	for(vector<int> d: ret)
		printArray(d);

	return 0;
}

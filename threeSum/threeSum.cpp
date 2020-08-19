#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <string>

using namespace std;

vector<vector<int>> threeSum(vector<int> data, int target){
	unordered_map<int, int> index;
	vector<vector<int>> ret{};
	unordered_set<string> found;
	for(int i=0;i<data.size();i++){
		index[data[i]] = i;
	}

	for(int i=0;i<data.size();i++){
		for(int j=0;j<data.size();j++){
			if(i==j) { continue; }
			int remaining = target - data[i] - data[j];
			if(index.find(remaining) != index.end() && index[remaining] != i && index[remaining] != j){
				vector<int> cur{data[i], data[j], remaining};
				sort(cur.begin(), cur.end());
				string key = to_string(cur[0]) + to_string(cur[1]) + to_string(cur[2]);
				if(found.find(key) == found.end()){
					ret.push_back(cur);
					found.insert(key);
				}
			}
		}
	}
	return ret;
}

int main(){
	vector<int> data{12, 3, 1, 2, -6, 5, 0, -8, -1, 6};

	vector<vector<int>> ans = threeSum(data, 0);

	for(vector<int> x: ans){
		for(int i: x){
			cout << i << ", ";
		}
		cout << endl;
	}
	cout << endl;
	return 0;
}

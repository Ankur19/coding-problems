#include <iostream>
#include <vector>

using namespace std;

bool isValid(vector<int>& a, vector<int>& b){
	return a[0]>b[0] && a[1]>b[1] && a[2] > b[2];
}

pair<int, int> diskDp(vector<vector<int>>& disk, int idx, vector<pair<int, int>>& memo){
	if(idx>=disk.size())
		return {-1, -1};
	if(memo[idx].first != -1)
		return memo[idx];
	int height = disk[idx][2];
	int next = -1;
	pair<int, int> temp;
	for(int i=0;i<disk.size();i++){
		if(i != idx && isValid(disk[idx], disk[i])){
			temp = diskDp(disk, i, memo);
			if(temp.first+disk[idx][2]>height){
				height = temp.first+disk[idx][2];
				next = i;
			}
		}
	}
	memo[idx] = {height, next};
	return memo[idx];
}

pair<int, vector<vector<int>>> diskStack(vector<vector<int>> disk){
	pair<int, int> dp{-1, -1};
	pair<int, int> temp{-1, -1};
	int start = -1;
	vector<pair<int, int>> memo(disk.size(), {-1, -1});

	for(int i=0;i<disk.size();i++){
		temp = diskDp(disk, i, memo);
		if(temp.first > dp.first){
			dp = temp;
			start = i;
		}
	}
	int idx = dp.second;
	vector<vector<int>> data{disk[start]};
	while(idx != -1){
		data.push_back(disk[idx]);
		idx = memo[idx].second;
	}
	return {dp.first, data};
}

int main(){
	vector<vector<int>> t1{{2, 1, 2}, {3, 2, 3}, {2, 2, 8}, {2, 3, 4}, {2, 2, 1}, {4, 4, 5}};

	pair<int, vector<vector<int>>> res = diskStack(t1);

	cout << "Height: " << res.first << endl;

	for(vector<int>& x : res.second){
		cout << "[";
		for(int i : x)
			cout << i << ", ";
		cout << "], ";
	}
	cout << endl;
	return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

pair<int, vector<int>> knapsack(vector<vector<int>>& data, int size){
	for(int i=0;i<data.size();i++)
		data[i].push_back(i);
	sort(data.begin(), data.end(), [](vector<int>& a, vector<int>& b){ return (a[0]/a[1])>(b[0]/b[1]); });
	int i = 0;
	int value = 0;
	vector<int> index;
	while(i < data.size()){
		if(data[i][1] < size){
			size-=data[i][1];
			value+=data[i][0];
			index.push_back(data[i][2]);
		}
		i++;
	}
	return {value, index};
}

int main(){
	vector<vector<int>> t1{{465, 100},
		{400, 85},
		{255, 55},
		{350, 45},
		{650, 130},
		{1000, 190},
		{455, 100},
		{100, 25},
		{1200, 190},
		{320, 65},
		{750, 100},
		{50, 45},
		{550, 65},
		{100, 50},
		{600, 70},
		{240, 40}};

	pair<int, vector<int>> result = knapsack(t1, 200);

	cout << "[" << result.first << ", [";
	for(int i: result.second)
		cout << i << ", ";
	cout << "]]" << endl;
	return 0;
}

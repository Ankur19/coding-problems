#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int minJumps(vector<int>& data, int idx, vector<int>& memo){
	if(idx >=data.size())
		return -1;
	else if(idx==data.size()-1)
		return 0;
	if(memo[idx]>-2)
		return memo[idx];
	int steps = data[idx];
	int current = INT_MAX;
	int temp = 0;
	bool found = false;
	for(int i=1;i<=steps;i++){
		temp = minJumps(data, idx+i, memo);
		if(temp != -1 && temp+1 < current){
			current = temp+1;
			found = true;
		}
	}
	if(!found)
		current = -1;
	memo[idx] = current;
	return current;
}

int minNumberOfJumps(vector<int>& data){
	vector<int> memo(data.size(), -2);
	return minJumps(data, 0, memo);
}

int main(){
	vector<int> t1{1};
	vector<int> t2{3, 4, 2, 1, 2, 3, 7, 1, 1, 1, 3};
	vector<int> t3{3, 12, 2, 1, 2, 3, 15, 1, 1, 1, 3, 2, 3, 2, 1, 1, 1, 1};

	cout << "Expected: 0, Actual: " << minNumberOfJumps(t1) << endl;
	cout << "Expected: 4, Actual: " << minNumberOfJumps(t2) << endl;
	cout << "Expected: 3, Actual: " << minNumberOfJumps(t3) << endl;
	return 0;
}

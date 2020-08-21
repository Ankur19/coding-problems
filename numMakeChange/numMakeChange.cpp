#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int numWaysToMakeChange(vector<int>& coins, int target){
	sort(coins.begin(), coins.end());
	vector<int> results(target+1, 0);
	results[0] = 1;
	for(int i: coins){
		for(int j=1;j<=target;j++){
			if(j>=i)
				results[j]+=results[j-i];
		}
	}
	return results[target];
}

int main(){
	vector<int> test{1, 5, 10, 25};

	cout << "Expected for target of 5 : 2, Actual: " << numWaysToMakeChange(test, 5) << endl;
	cout << "Expected for target of 10 : 4, Actual: " << numWaysToMakeChange(test, 10) << endl;
	cout << "Expected for target of 25 : 13, Actual: " << numWaysToMakeChange(test, 25) << endl;

	return 0;
}

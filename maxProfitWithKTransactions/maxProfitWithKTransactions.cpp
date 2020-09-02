#include <iostream>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;

int maxProfitWithKTransactions(vector<int>& data, int start, int k, vector<vector<int>>& memo){
	if(start>=data.size() || k==0)
		return 0;
	if(memo[k][start] > INT_MIN)
		return memo[k][start];
	int current = data[start];
	int maxVal = INT_MIN;

	for(int i = start+1; i< data.size();i++){
		if(data[i] > current){
			int cur = data[i]-current + maxProfitWithKTransactions(data, i+1, k-1, memo);
			if(cur > maxVal)
				maxVal = cur;
		}
	}
	memo[k][start] = maxVal;
	return maxVal;
}

int maxProfitWithKTransactions(vector<int>& data, int k){
	vector<vector<int>> memo(k+1, vector<int>(data.size(), INT_MIN));
	int ret = maxProfitWithKTransactions(data, 0, k, memo);
	for(int i=1;i<data.size();i++){
		ret = max(ret, maxProfitWithKTransactions(data, i, k, memo));
	}
	return ret==INT_MIN ? 0 : ret;
}

int main(){
	vector<int> t1{50, 25, 12, 4, 3, 10, 1, 100};
	cout << "Expected value: 106 for k==2, Actual value: " << maxProfitWithKTransactions(t1, 2) << endl;

	vector<int> t2{100, 99, 98, 97, 1};
	cout << "Expected value: 0 for k==5, Actual value: " << maxProfitWithKTransactions(t2, 5) << endl;
	return 0;
}

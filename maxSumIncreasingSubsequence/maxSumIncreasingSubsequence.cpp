#include <iostream>
#include <vector>
#include <climits>

using namespace std;

pair<int, int> maxSumIncreasingSubsequence(vector<int>& data){
	int maxSum = INT_MIN;
	int curSum;
	int lastIndex;
	int ii;
	vector<pair<int, int>> prev(data.size(), {INT_MIN, INT_MIN});

	for(int i=0;i<data.size();i++){
		curSum = data[i];
		ii = i-1;
		while(ii>=0){
			if(prev[ii].first < data[i] && curSum < curSum + prev[ii].second){
				curSum+=prev[ii].second;
				break;
			}
			ii--;
		}
		if(curSum>maxSum){
			maxSum = curSum;
			lastIndex = i;
		}
		prev[i] = {data[i], curSum};
	}
	int nums = 1;
	int lastData = data[lastIndex];
	int sum = maxSum-data[lastIndex];
	lastIndex--;
	while(sum>0){
		if(data[lastIndex] < lastData){
			sum-=data[lastIndex];
			lastData = data[lastIndex];
			nums++;
		}
		lastIndex--;
	}
	return {maxSum, nums};
}


int main(){
	vector<int> t1{1, 2, 3, 4, 5};
	vector<int> t2{-5, -4, -3, -2, -1};
	vector<int> t3{10, 70, 20, 30, 50, 11, 30};

	cout << "Expected: [15, 5], Actual: " << maxSumIncreasingSubsequence(t1).first << ", " << maxSumIncreasingSubsequence(t1).second << endl;
	cout << "Expected: [-1, 1], Actual: " << maxSumIncreasingSubsequence(t2).first << ", " << maxSumIncreasingSubsequence(t2).second << endl;
	cout << "Expected: [110, 4], Actual: " << maxSumIncreasingSubsequence(t3).first << ", " << maxSumIncreasingSubsequence(t3).second << endl;
	return 0;
}

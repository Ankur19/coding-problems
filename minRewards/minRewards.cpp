#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>

using namespace std;

int minRewards(vector<int>& data){
	vector<int> rewards(data.size(), 1);
	if(data.size()==1)
		return 1;

	for(int i=1;i<data.size();i++){
		if(data[i] > data[i-1]){
			rewards[i] = rewards[i-1]+1;
		}
	}
	for(int i = data.size()-2;i>=0;i--){
		if(data[i]>data[i+1]){
			rewards[i] = max(rewards[i], rewards[i+1]+1);
		}
	}
	return accumulate(rewards.begin(), rewards.end(), 0);
}


int main(){
	vector<int> t1{1};
	vector<int> t2{5, 10};
	vector<int> t3{10, 5};
	vector<int> t4{4, 2, 1, 3};
	vector<int> t5{0, 4, 2, 1, 3};
	vector<int> t6{8, 4, 2, 1, 3, 6, 7, 9, 5};
	vector<int> t7{2, 20, 13, 12, 11, 8, 4, 3, 1, 5, 6, 7, 9, 0};
	vector<int> t8{2, 1, 4, 3, 6, 5, 8, 7, 10, 9};
	vector<int> t9{800,
	                    400,
	                    20,
	                    10,
	                    30,
	                    61,
	                    70,
	                    90,
	                    17,
	                    21,
	                    22,
	                    13,
	                    12,
	                    11,
	                    8,
	                    4,
	                    2,
	                    1,
	                    3,
	                    6,
	                    7,
	                    9,
	                    0,
	                    68,
	                    55,
	                    67,
	                    57,
	                    60,
	                    51,
	                    661,
	                    50,
	                    65,
	                    53};
	vector<int> expected{1, 3, 3, 8, 9, 25, 52, 15, 93};

	cout << "Expected: " << expected[0] << ", Actual: " << minRewards(t1) << endl;
	cout << "Expected: " << expected[1] << ", Actual: " << minRewards(t2) << endl;
	cout << "Expected: " << expected[2] << ", Actual: " << minRewards(t3) << endl;
	cout << "Expected: " << expected[3] << ", Actual: " << minRewards(t4) << endl;
	cout << "Expected: " << expected[4] << ", Actual: " << minRewards(t5) << endl;
	cout << "Expected: " << expected[5] << ", Actual: " << minRewards(t6) << endl;
	cout << "Expected: " << expected[6] << ", Actual: " << minRewards(t7) << endl;
	cout << "Expected: " << expected[7] << ", Actual: " << minRewards(t8) << endl;
	cout << "Expected: " << expected[8] << ", Actual: " << minRewards(t9) << endl;

	return 0;
}

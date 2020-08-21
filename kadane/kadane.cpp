#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

int maxSubArray(vector<int>& nums){
	if(nums.size()==0)
		return 0;
	int maximum = INT_MIN;
	int currentMax = 0;
	for(int i=0; i<nums.size();i++){
		currentMax+=nums[i];
		currentMax = max(0, currentMax);
		if(currentMax > maximum)
			maximum = currentMax;
	}
	return maximum;
}

int main(){
	vector<int> test{-2,1,-3,4,-1,2,1,-5,4};

	cout << "Expected: 6, Actual: " << maxSubArray(test) << endl;

	return 0;
}

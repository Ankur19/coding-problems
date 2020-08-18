#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int thirdMax(vector<int>& nums){
	long first = LONG_MIN; 
	long second = LONG_MIN;
	long third = LONG_MIN;

	for(int i=0;i<nums.size();i++){
		if(nums[i]>=first){
			if(nums[i]==first){ continue; }
			third = second;
			second = first;
			first = nums[i];
		}
		else if(nums[i]>=second){
			if(nums[i]==second){ continue; }
			third = second;
			second = nums[i];
		}
		else if(nums[i]>=third){
			third = nums[i];
		}
	}
	return third==LONG_MIN? first : third;
}


int main(){
	vector<int> data{1, 2, INT_MIN};
	cout << "Expected: " << INT_MIN << ", Actual: " << thirdMax(data) << endl;
	return 0;
}

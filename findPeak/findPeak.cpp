#include <iostream>
#include <vector>

using namespace std;

int findPeakBinary(vector<int>& nums, int start, int end){
	if(end-start<2)
		return -1;
	if(end-start==3 || end-start==2){
		for(int i=start+1;i<end;i++){
			if(nums[i]>nums[i-1] && nums[i]>nums[i+1])
				return i;
		}
		return -1;
	}
	int mid = (start+end)/2;
	if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1])
		return mid;
	int val = findPeakBinary(nums, start, mid);
	if(val !=-1)
		return val;
	return findPeakBinary(nums, mid, end);
}

int findPeakElement(vector<int>& nums){
	if(nums.size()<=1)
		return 0;
	int ret = findPeakBinary(nums, 0, nums.size()-1);
	if(ret==-1)
		return nums[0]>nums[1]? 0 : nums.size()-1;
	return ret;
}

int main(){
	vector<int> test1{1,2,3,1};
	cout << "Expected: 2, Actual: " << findPeakElement(test1) << endl;

	vector<int> test2{1,2,1,3,5,6,4};
	cout << "Expected: 1 or 5, Actual: " << findPeakElement(test2) << endl;
	return 0;
}


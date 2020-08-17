#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int>& nums, int target, int i, int j);

int search(vector<int>& nums, int target){
	return binarySearch(nums, target, 0, nums.size()-1);
}

int binarySearch(vector<int>& nums, int target, int i, int j){
	if((i==j && nums[i]!=target)|| i>j)
		return -1;

	int mid = (i+j)/2;

	if(nums[mid]==target)
		return mid;

	else if(nums[mid]<target)
		return binarySearch(nums, target, mid+1, j);

	return binarySearch(nums, target, i, mid-1);
}


int main(){
	vector<int> nums{-1, 0, 3, 5, 9, 12};

	cout << "Searching for 9. Expected: 4, Actual: " << search(nums, 9) << endl;

	cout << "Searching for 2. Expected: -1, Actual: " << search(nums, 2) << endl;

	return 0;
}

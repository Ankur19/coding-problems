#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target){
	unordered_map<int, int> indices;
	for(int i=0;i<nums.size();i++){
		indices[nums[i]] = i;
	}
	for(int i=0;i<nums.size();i++){
		if(indices.find(target-nums[i]) != indices.end() && indices[target-nums[i]] != i){
			return {i, indices[target-nums[i]]};
		}
	}
	return {-1, -1};
}

int main(){
	vector<int> v {2, 7, 11, 15};

	vector<int> ans = twoSum(v, 9);

	cout << ans[0] << ", " << ans[1] << endl;
	return 0;
}

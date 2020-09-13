#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cPR(vector<int>& nums, vector<vector<int>>& memo, int start, int a, int& total){
        if(a==total-a)
            return true;
        if(start>=nums.size())
            return false;
        else if(memo[start][a] != -1)
            return (bool)memo[start][a];
        bool ans = cPR(nums, memo, start+1, a, total) || cPR(nums, memo, start+1, a+nums[start], total);
        memo[start][a] = (int)ans;
        return ans;
}

bool canPartition(vector<int>& nums) {
	int total = 0;
        for(int i: nums)
                total+=i;
        vector<vector<int>> memo(nums.size(), vector<int>(total+1, -1));
        return cPR(nums, memo, 0, 0, total);
}

int main(){
	vector<int> test{100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100};

	cout << "Expected: true, Actual: " << canPartition(test) << endl;
	return 0;
}

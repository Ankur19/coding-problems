#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> permuteRec(vector<int>& nums, int end);
void swap(int i, int j, vector<int>& nums);
void printVector(vector<int>& data);

vector<vector<int>> permute(vector<int>& nums){
	return permuteRec(nums, nums.size()-1);
}

vector<vector<int>> permuteRec(vector<int>& nums, int end){
	if(end==0){
		vector<vector<int>> ret(1, vector<int>{nums[0]});
		return ret;
	}
	vector<vector<int>> temp;
	vector<vector<int>> allData;
	for(int i=end;i>=0;i--){
		swap(i, end, nums);
		temp = permuteRec(nums, end-1);
		for(vector<int>& i : temp){
			i.push_back(nums[end]);
			allData.push_back(i);
		}
		swap(i, end, nums);
	}
	return allData;
}

void swap(int i, int j, vector<int>& nums){
	int temp = nums[i];
	nums[i] = nums[j];
	nums[j] = temp;
	return;
}

void printVector(vector<int>& data){
        cout << "[";
        for(int i: data)
                cout << i << ", ";
        cout << "]" << endl;
        return;
}

int main(){
	vector<int> test{1,2,3};
	vector<vector<int>> ans = permute(test);

	for(vector<int> data: ans)
		printVector(data);

	return 0;
}

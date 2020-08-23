#include <iostream>
#include <vector>
#include <climits>
#include <unordered_map>

using namespace std;

pair<int, int> largestRange(vector<int>& data){
	if(data.size()==0)
		return {-1, -1};
	unordered_map<int, bool> nums;
	for(int i: data)
		nums[i] = true;

	int minn = data[0];
	int maxx = data[0];
	int tmin;
	int tmax;
	int range;
	int maxRange = 1;
	int current;
	for(int i : data){
		tmin = i;
		tmax = i;
		if(nums[i]){
			range = 1;
			nums[i] = false;
			current = i-1;
			while(nums.find(current)!=nums.end()){
				tmin = current;
				range++;
				nums[current] = false;
				current--;
			}
			current = i+1;
			while(nums.find(current)!=nums.end()){
				tmax=current;
				range++;
				nums[current] = false;
				current++;
			}
			if(range>maxRange){
				maxRange = range;
				minn = tmin;
				maxx = tmax;
			}
		}
	}
	return {minn, maxx};
}

int main(){
	vector<int> test{1, 11, 3, 0, 15, 5, 2, 4, 10, 7, 12, 6};

	pair<int, int> ret = largestRange(test);

	cout << "Expected: [0, 7], Actual: " << ret.first << ", " << ret.second << endl;

	return 0;
}

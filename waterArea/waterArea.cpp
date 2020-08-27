#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <numeric>

using namespace std;

int waterArea(vector<int>& data){
	int leftMax = 0;
	int rightMax = 0;
	vector<int> left(data.size(), 0);
	vector<int> right(data.size(), 0);
	for(int i = 0; i<data.size();i++){
		left[i] = leftMax;
		if(data[i]>leftMax)
			leftMax = data[i];
	}
	for(int i = data.size()-1;i>=0;i--){
		right[i] = min(left[i], rightMax);
		if(data[i]> rightMax)
			rightMax = data[i];
		if(right[i] > data[i])
			right[i]-=data[i];
		else
			right[i] = 0;
	}
	return accumulate(right.begin(), right.end(), 0);
}

int main(){
	vector<int> t1{0, 8, 0, 0, 5, 0, 0, 10, 0, 0, 1, 1, 0, 3};

	cout << waterArea(t1) << endl;
	return 0;
}

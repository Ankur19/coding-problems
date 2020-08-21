#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int maxSubsetSum(vector<int>& data){
	if(data.size()==0)
		return 0;
	else if(data.size()<=2)
		return *max_element(data.begin(), data.end());
	int first = max(data[0], data[1]);
	int second = data[0];
	int current;
	for(int i=2;i<data.size();i++){
		current = max(first, second+data[i]);
		second = first;
		first = current;
	}
	return first;
}

int main(){
	vector<int> test{7, 10, 12, 7, 9, 14, 15, 16, 25, 20, 4};

	cout << "Expected: 72, Actual: " << maxSubsetSum(test) << endl;
	return 0;
}

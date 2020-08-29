#include <iostream>
#include <vector>

using namespace std;

void swap(int i, int j, vector<int>& data){
	int temp = data[i];
	data[i] = data[j];
	data[j] = temp;
}

int findKth(vector<int>& data, int k, int i, int j){
	int target = data[j];
	int x = i;
	int y = j-1;
	while(x <= y){
		if(data[x]>target && data[y] <target)
			swap(x, y, data);
		if(data[x] <= target){
			x++;
		}
		if(data[y]>=target)
			y--;
	}
	swap(x, j, data);
	if(x==target)
		return data[x];
	else if(x < target)
		return findKth(data, k, x+1, j);
	return findKth(data, k, i, x-1);
}

int quickSelect(vector<int>& data, int k){
	if(k>data.size())
		return -1;
	return findKth(data, k, 0, data.size()-1);
}

int main(){
	vector<int> data{8, 3, 2, 5, 1, 7, 4, 6};
	int val = quickSelect(data, 8);
	cout << "expected: 8, Actual: " << val << endl;
	return 0;
}

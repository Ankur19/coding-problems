#include <iostream>
#include <vector>

using namespace std;

int searchForElem(vector<int>& data, int target, int start, int end){
	if(start==end){
		if(data[start]==target)
			return start;
		return -1;
	}
	int mid = (start+end)/2;

	if(data[mid]==target)
		return mid;

	if(data[mid] < target)
		return searchForElem(data, target, mid+1, end);
	return searchForElem(data, target, start, mid-1);
}

vector<int> searchForRange(vector<int>& data, int target){
	int idx = searchForElem(data, target, 0, data.size()-1);
	if(idx==-1)
		return {-1, -1};
	int right = idx;
	while(idx>=0 && data[idx]==target){
		idx--;
	}
	while(right < data.size() && data[right]==target)
		right++;

	return {idx+1, right-1};
}

int main(){
	vector<int> t1{5, 7, 7, 8, 8, 10};

	vector<int> test1 = searchForRange(t1, 8);
	vector<int> test2 = searchForRange(t1, 9);

	cout << "Expected: 3, 4, Actual: " << test1[0] << ", " << test1[1] << endl;
	cout << "Expected: -1, -1, Actual: " << test2[0] << ", " << test2[1] << endl;
	return 0;
}

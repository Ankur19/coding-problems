#include <iostream>
#include <vector>

using namespace std;

int shiftedBinaryRec(vector<int>& data, int& target, int start, int end){
	if(start==end){
		if(data[start]==target)
			return start;
		return -1;
	}
	int mid = (start+end)/2;
	if(data[mid]==target)
		return mid;
	else if(data[start]==target)
		return start;
	else if(data[end]==target)
		return end;
	else{
		if(data[start] < data[mid]){
			if(data[start] < target && data[mid] > target)
				return shiftedBinaryRec(data, target, start, mid-1);
			else
				return shiftedBinaryRec(data, target, mid+1, end);
		}
		else{
			if(data[mid] < target && data[end] > target)
				return shiftedBinaryRec(data, target, mid+1, end);
			else
				return shiftedBinaryRec(data, target, start, mid-1);
		}
	}
	return -1;
}

int shiftedBinarySearch(vector<int>& data, int target){
	return shiftedBinaryRec(data, target, 0, data.size()-1);
}

int main(){
	vector<int> t1{23, 111, 1, 5};
	vector<int> t2{45, 61, 71, 72, 73, 0, 1, 21, 33, 45};

	cout << "Expected: -1, Actual: " << shiftedBinarySearch(t1, 35) << endl;
	cout << "Expected: 8, Actual: " << shiftedBinarySearch(t2, 33) << endl;
	return 0;
}

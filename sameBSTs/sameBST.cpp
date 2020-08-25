#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int getLeftIdx(vector<int>& data, int minVal, int curIdx){
	for(int i=curIdx+1; i<data.size();i++){
		if(data[i]<=data[curIdx] && data[i]>minVal){
			return i;
		}
	}
	return -1;
}
int getRightIdx(vector<int>& data, int maxVal, int curIdx){
	for(int i = curIdx+1; i<data.size();i++){
		if(data[i]>data[curIdx] && data[i]<=maxVal)
			return i;
	}
	return -1;
}

bool areSame(vector<int>& a, vector<int>& b, int idxa, int idxb, int minVal, int maxVal){
	if(idxa==-1 || idxb==-1)
		return idxa==idxb;
	if(a[idxa] != b[idxb])
		return false;
	int lefta = getLeftIdx(a, minVal, idxa);
	int leftb = getLeftIdx(b, minVal, idxb);
	int righta = getRightIdx(a, maxVal, idxa);
	int rightb = getRightIdx(b, maxVal, idxb);

	bool rightSame = areSame(a, b, righta, rightb, a[idxa], maxVal);
	bool leftSame = areSame(a, b, lefta, leftb, minVal, a[idxa]);

	return rightSame && leftSame;
}

bool sameBST(vector<int>& a, vector<int>& b){
	if(a[0]!=b[0] || a.size() != b.size())
		return false;
	return areSame(a, b, 0, 0, INT_MIN, INT_MAX);
}

int main(){
	vector<int> t1{10, 15, 8, 12, 94, 81, 5, 2};
	vector<int> t2{10, 8, 5, 15, 2, 12, 94, 81};

	cout << "Expected: true, Actual: " << sameBST(t1, t2) << endl;

	vector<int> t3{5, 2, -1, 100, 45, 12, 8, -1, 8, 10, 15, 8, 12, 94, 81, 2, -34};
	vector<int> t4{5, 8, 10, 15, 2, 8, 12, 45, 100, 2, 12, 94, 81, -1, -1, -34, 8};

	cout << "Expected: false, Actual: " << sameBST(t3, t4) << endl;

	return 0;
}

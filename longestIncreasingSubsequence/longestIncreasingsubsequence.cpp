#include <iostream>
#include <vector>

using namespace std;

//Trying to do in in O(n lg n)

int binarySearch(vector<int>& seq, vector<int>& lengths, int start, int end, int x, int y, int val){

	if(y < start)
		return y;
	else if(x > y)
		return x;
	int mid = (x+y)/2;

	if(seq[lengths[mid]] < val)
		return binarySearch(seq, lengths, start, end, mid+1, y, val);
	return binarySearch(seq, lengths, start, end, x, mid-1, val);
}

vector<int> lis(vector<int>& seq){
	int maxLen = 1;
	vector<int> lengths(seq.size()+1, -1);
	vector<int> prev(seq.size()+1, -1);
	lengths[1] = 0;
	int temp = -1;
	for(int i = 1; i <seq.size();i++){
		temp = binarySearch(seq, lengths, 1, maxLen, 1, maxLen, seq[i]);
		
		if(temp==0)
			temp=1;
		if(temp > maxLen){
			maxLen = temp;
			lengths[maxLen] = i;
			prev[i] = lengths[maxLen-1];
		}
		else if(seq[lengths[temp]] > seq[i]){
			lengths[temp] = i;
			prev[i] = lengths[temp-1];
		}
	}
	vector<int> increasingSubseq;
	temp = lengths[maxLen];
	while(temp != -1){
		increasingSubseq.push_back(seq[temp]);
		temp = prev[temp];
	}

	return increasingSubseq;
}

int main(){
	vector<int> t{1, 5, -1, 0, 6, 2, 4};
	vector<int> t1{5, 7, -24, 12, 10, 2, 3, 12, 5, 6, 35};
	vector<int> incSub = lis(t);
	for(int i: incSub)
		cout << i << ", ";
	cout << endl;
	
	incSub =lis(t1);
	for(int i: incSub)
		cout << i << ", ";
	cout << endl;

	return 0;
}

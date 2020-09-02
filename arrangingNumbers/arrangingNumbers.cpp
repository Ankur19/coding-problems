#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

void swap(int i, int j, vector<int>& data){
	int temp = data[i];
	data[i] = data[j];
	data[j] = temp;
}

void arrangingNumbers(vector<int>& data, int start, int& add){
	if(start >=data.size())
		add++;
	for(int i = start;i<data.size();i++){
		if(!((start+1)%data[i]) || !(data[i]%(start+1))){
			swap(start, i, data);
			arrangingNumbers(data, start+1, add);
			swap(start, i, data);
		}
	}
	return ;
}

int arrangingNumbers(int n){
	vector<int> data;
	for(int i = 1;i<=n;i++)
		data.push_back(i);

	int sum = 0;//accumulate(data.begin(), data.end(), 0);

	//vector<vector<int>> memo(n+1, vector<int>(sum+1, -2));

	arrangingNumbers(data, 0, sum);

	return sum;
}

int main(){
	cout << "Expected: 10, Actual: " << arrangingNumbers(5) << endl;
	return 0;
}

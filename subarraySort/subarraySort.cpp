#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

pair<int, int> subarraySort(vector<int>& data){
	vector<int> needSort(data.size(), 0);
	vector<pair<int, int>> minMax(data.size(), {0, 0});
	int cmin = data[0];
	int cmax = data[0];
	int temp;
	for(int i=0;i<data.size()-1;i++){
		if(cmax>data[i+1]){
			needSort[i] = 1;
			temp = i-1;
			while(temp >=0){
				if(minMax[temp].first>data[i+1]){
					needSort[temp] = 1;
				}
				else
					break;
				temp--;
			}
			cmin = data[i+1];
			cmax = data[i];
		}
		else{
			cmin = data[i];
			cmax = data[i+1];
		}
		minMax[i] = {cmin, cmax};
	}
	cmin = -1;
	cmax = -1;
	for(int i=0;i<data.size()-1;i++){
		if(cmin==-1 && needSort[i])
			cmin = i;
		else if(needSort[i])
			cmax = i;
	}
	return {cmin, cmax+1};
}


int main(){
	vector<int> t1{1, 2, 4, 7, 10, 11, 7, 12, 6, 7, 16, 18, 19};
	vector<int> t2{1, 2, 4, 7, 10, 11, 7, 12, 7, 7, 16, 18, 19};
	vector<int> t3{1, 2, 4, 7, 10, 11, 7, 12, 13, 14, 16, 18, 19};
	vector<int> t4{-41, 8, 7, 12, 11, 9, -1, 3, 9, 16, -15, 51, 7};

	cout << "Expected: [3, 9], Actual: " << subarraySort(t1).first << ", " << subarraySort(t1).second << endl;
	cout << "Expected: [4, 9], Actual: " << subarraySort(t2).first << ", " << subarraySort(t2).second << endl;
	cout << "Expected: [4, 6], Actual: " << subarraySort(t3).first << ", " << subarraySort(t3).second << endl;
	cout << "Expected: [1, 12], Actual: " << subarraySort(t4).first << ", " << subarraySort(t4).second << endl;
	return 0;
}

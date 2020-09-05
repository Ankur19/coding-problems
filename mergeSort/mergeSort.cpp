#include <iostream>
#include <vector>

using namespace std;

void mergeSort(vector<int>& data, int start, int end){
	if(start>=end)
		return;
	int mid = (start+end)/2;
	mergeSort(data, start, mid);
	mergeSort(data, mid+1, end);
	vector<int> nData;
	int i = start;
	int j = mid+1;
	while(i <= mid && j <= end){
		if(data[i] <= data[j]){
			nData.push_back(data[i]);
			i++;
		}
		else{
			nData.push_back(data[j]);
			j++;
		}
	}
	if(i <= mid){
		while(i <=mid){
			nData.push_back(data[i]);
			i++;
		}
	}
	for(int x = start;x<j;x++){
		data[x] = nData[x-start];
	}
	return;
}

void mergeSort(vector<int>& data){
	mergeSort(data, 0, data.size()-1);
}

int main(){
	vector<int> test{-7, 2, 3, 8, -10, 4, -6, -10, -2, -7, 10, 5, 2, 9, -9, -5, 3, 8};
	mergeSort(test);

	for(int i: test)
		cout << i << ", ";
	cout << endl;
	
	test = vector<int>{-823, 164, 48, -987, 323, 399, -293, 183, -908, -376, 14, 980, 965, 842, 422, 829, 59, 724, -415, -733, 356, -855, -155, 52, 328, -544, -371, -160, -942, -51, 700, -363, -353, -359, 238, 892, -730, -575, 892, 490, 490, 995, 572, 888, -935, 919, -191, 646, -120, 125, -817, 341, -575, 372, -874, 243, 610, -36, -685, -337, -13, 295, 800, -950, -949, -257, 631, -542, 201, -796, 157, 950, 540, -846, -265, 746, 355, -578, -441, -254, -941, -738, -469, -167, -420, -126, -410, 59};

	mergeSort(test);

	for(int i: test)
		cout << i << ", ";
	cout << endl;
	return 0;
}

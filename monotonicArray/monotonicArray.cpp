#include <iostream>
#include<vector>

using namespace std;

bool isMonotonic(vector<int>& array){
	if(array.size()<2)
		return true;
	int direction = 0;

	for(int i=0;i<array.size()-1;i++){
		if(array[i]<array[i+1]){
			if(direction==-1)
				return false;
			direction=1;
		}
		else if(array[i]>array[i+1]){
			if(direction==1)
				return false;
			direction = -1;
		}
	}
	return true;
}

int main(){
	vector<int> increasing{1,2,2,3};

	cout << "Expected: true, Actual: " << isMonotonic(increasing) << endl;

	return 0;
}

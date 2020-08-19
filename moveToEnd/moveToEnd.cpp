#include <iostream>
#include <vector>

using namespace std;

void moveToEnd(vector<int>& array, int target){
	int end = array.size()-1;
	for(int i=0;i<end+1;i++){
		if(array[i]==target){
			while(array[end]==target && end>i)
				end--;
			if(end==i)
				break;
			array[i] = array[end];
			array[end] = target;
			end--;
		}
	}
}

void printVector(vector<int>& toPrint){
	cout << " [";
	for(int i: toPrint){
		cout << i << ", ";
	}
	cout << "] ";
	return;
}

void testResult(vector<int>& test, int target){
	cout << "Given array: ";
        printVector(test);
	cout << ", To Move: "<< target << endl;
        cout << "Actual result: ";
        moveToEnd(test, target);
        printVector(test);
	cout << endl;
	return;
}

int main(){
	vector<int> test{2, 1, 2, 2, 2, 3, 4, 2};
	vector<int> test1{5, 1, 2, 5, 5, 3, 4, 6, 7, 5, 8, 9, 10, 11, 5, 5, 12};
	vector<int> test2{};
	testResult(test, 2);
	testResult(test1, 5);
	testResult(test2, 3);
	return 0;
}

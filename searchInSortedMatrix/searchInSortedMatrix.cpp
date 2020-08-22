#include <iostream>
#include <vector>

using namespace std;

vector<int> searchInSortedMatrix(vector<vector<int>>& matrix, int target){
	int row = 0;
	int col = matrix[0].size() -1;
	while(row < matrix.size() && col>=0){
		if(matrix[row][col] < target)
			row++;
		else if(matrix[row][col]>target)
			col--;
		else
			return {row, col};
	}
	return {-1, -1};
}

int main(){
	vector<int> a{1, 4, 7, 12, 15, 1000};
	vector<int> b{2, 5, 19, 31, 32, 1001};
	vector<int> c{3, 8, 24, 33, 35, 1002};
	vector<int> d{40, 41, 42, 44, 45, 1003};
	vector<int> e{99, 100, 103, 106, 128, 1004};

	vector<vector<int>> test{a, b, c, d, e};

	vector<int> ret = searchInSortedMatrix(test, 100);

	cout << "Expected: 4, 1 .... Actual: " << ret[0] << ", " << ret[1] << endl;

	return 0;
}

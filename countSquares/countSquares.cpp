#include <iostream>
#include <vector>

using namespace std;

int countSquareSubmatrices(vector<vector<int>>& matrix){
	if(matrix.empty())
		return 0;
	int numSquares = 0;
	vector<vector<int>> memo(matrix.size(), vector<int>(matrix[0].size(), 0));
	
	for(int i = 0; i< matrix.size();i++){
		for(int j = 0; j < matrix[0].size();j++){
			if(matrix[i][j]){
				if(i==0 || j==0)
					memo[i][j] = 1;
				else{
					memo[i][j] = min(memo[i][j], min(memo[i-1][j], memo[i][j-1]) + 1);
				}
				numSquares+=memo[i][j];
			}
		}
	}
	return numSquares;
}

int main(){
	cout << "check problem 1277 on leetcode" << endl;
	return 0;
}

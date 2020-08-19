#include <iostream>
#include <vector>

using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix){
	int sx = 0;
	int ex = matrix.size()-1;
	int sy = 0;
	int ey = matrix[0].size()-1;

	vector<int> ans;
	while(sx<=ex && sy<=ey){
		for(int i=sy;i<=ey;i++){
			ans.push_back(matrix[sx][i]);
		}
		sx++;
		for(int i=sx;i<=ex;i++){
			ans.push_back(matrix[i][ey]);
		}
		ey--;
		for(int i=ey;i>=sy;i--){
			ans.push_back(matrix[ex][i]);
		}
		ex--;
		for(int i=ex;i>=sx;i--){
			ans.push_back(matrix[i][sy]);
		}
		sy++;
	}
	ans = vector<int>(ans.begin(), ans.begin()+matrix.size()*matrix[0].size());
	return ans;
}

int main(){
	vector<int> a{1, 2, 3, 4};
	vector<int> b{5, 6, 7, 8};
	vector<int> c{9,10,11,12};

	vector<vector<int>> test{a, b, c};

	vector<int> ans = spiralOrder(test);

	cout << "Expected: [1,2,3,4,8,12,11,10,9,5,6,7]" << endl;
	cout << "Actual: [";
	for(int i: ans){
		cout << i << ", ";
	}
	cout << "] " << endl;
	return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Can be optimized to O(n^2). loop over the elements twice and find one which is on the bottom-right. if also has elements on the same row and same col then is Rectangle

int rectangleMania(vector<vector<int>>& data){
	vector<vector<int>> memo(100, vector<int>(100, 0));
	sort(data.begin(), data.end(), [](vector<int>& a, vector<int>& b) { return a[0] != b[0] ? a[0] < b[0] : a[1] < b[1]; });

	for(vector<int>& x: data)
		memo[x[0]][x[1]] = 1;
	vector<vector<int>> toRight;
	vector<vector<int>> toSouth;
	int numRec = 0;
	for(int i=0; i <100;i++){
		for(int j = 0; j< 100;j++){
			if(!memo[i][j])
				continue;
			else{
				toRight = vector<vector<int>>{};
				toSouth = vector<vector<int>>{};
				for(int y = j+1; y < 100;y++)
					if(memo[i][y])
						toRight.push_back({i, y});
				for(int x = i+1;x <100;x++)
					if(memo[x][j])
						toSouth.push_back({x, j});
				if(!toRight.size() || !toSouth.size())
					continue;
				for(vector<int>& x: toRight){
					for(vector<int>& y: toSouth){
						if(memo[y[0]][x[1]])
							numRec++;
					}
				}
			}

		}
	}
	return numRec;
}

int main(){
	vector<vector<int>> data{
			{0, 0},
			{0, 1},
			{1, 1},
			{1, 0},
			{2, 1},
			{2, 0},
			{3, 1},
			{3, 0},
			{1, 3},
			{3, 3}
			};
	cout << "Expected: 8, Actual: " << rectangleMania(data) << endl;
	return 0;
}

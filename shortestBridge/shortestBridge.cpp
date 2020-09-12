#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<pair<int, int>> convert(vector<vector<int>>& A, vector<vector<bool>>& visited, int i, int j, int m, int n){
	stack<pair<int, int>> s;
	vector<pair<int, int>> zeros;
	s.push({i, j});
	visited[i][j] = true;
	while(!s.empty()){
		auto [x, y] = s.top();
		s.pop();

		A[x][y] = 2;
		if(x+1 < m){
			if(A[x+1][y]==1 && !visited[x+1][y])
				s.push({x+1, y});
			else{
				if(!visited[x+1][y])
					zeros.push_back({x+1, y});
			}
				visited[x+1][y] = true;
		}
		if(x-1 >=0){
			if(A[x-1][y]==1 && !visited[x-1][y])
				s.push({x-1, y});
			else{
				if(!visited[x-1][y])
					zeros.push_back({x-1, y});
			}
				visited[x-1][y] = true;
		}
		if(y+1 < n){
			if(A[x][y+1]==1 && !visited[x][y+1])
				s.push({x, y+1});
			else{
				if(!visited[x][y+1])
					zeros.push_back({x, y+1});
			}
				visited[x][y+1] = true;
		}
		if(y-1 >=0){
			if(A[x][y-1]==1 && !visited[x][y-1])
				s.push({x, y-1});
			else{
				if(!visited[x][y-1])
					zeros.push_back({x, y-1});
			}
				visited[x][y-1] = true;
		}
	}
	return zeros;
}

int shortestBridge(vector<vector<int>>& A){
	int m = A.size();
	int n = A[0].size();
	int numCells = 1;
	bool found = false;
	vector<pair<int, int>> zeros;
	vector<vector<bool>> visited(A.size(), vector<bool>(A[0].size(), false));
	
	for(int i = 0; i< m; i++){
		for(int j = 0 ; j < n; j++){
			if(A[i][j]){
				zeros = convert(A, visited, i, j, m, n);
				found = true;
				break;
			}
		}
		if(found)
			break;
	}

	while(!zeros.empty()){
		vector<pair<int, int>> nZeros;
		found = false;
		for(int i = 0; i<zeros.size() && !found;i++){
			auto& [x, y] = zeros[i];
			if(x-1 >=0){
				if(A[x-1][y]==1)
					found = true;
				else if(!A[x-1][y] && !visited[x-1][y]){
					visited[x-1][y] = true;
					nZeros.push_back({x-1, y});
				}
			}
			if(x+1 < m){
				if(A[x+1][y]==1)
					found = true;
				else if(!A[x+1][y] && !visited[x+1][y]){
					nZeros.push_back({x+1, y});
					visited[x+1][y] = true;
				}
			}
			if(y-1 >=0){
				if(A[x][y-1]==1)
					found = true;
				else if(!A[x][y-1] && !visited[x][y-1]){
					nZeros.push_back({x, y-1});
					visited[x][y-1] = true;
				}
			}
			if(y+1 <n){
				if(A[x][y+1]==1)
					found = true;
				else if(!A[x][y+1] && !visited[x][y+1]){
					nZeros.push_back({x, y+1});
					visited[x][y+1] = true;
				}
			}
		}
		if(found)
			break;
		zeros = nZeros;
		numCells++;
	}
	return numCells;
}

int main(){
	vector<vector<int>> test{{1,1,0,0,0},{1,0,0,0,0},{1,0,0,0,0},{0,0,0,1,1},{0,0,0,1,1}};
	cout << "Actual answer: " << shortestBridge(test) << endl;
	return 0;
}

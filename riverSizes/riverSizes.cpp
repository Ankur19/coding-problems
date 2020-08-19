#include <iostream>
#include <vector>

using namespace std;

void addNearby(int i, int j, vector<vector<int>>& earth, vector<pair<int, int>>& nearby){
	if(i-1>=0 && earth[i-1][j]){
		nearby.push_back({i-1, j});
		earth[i-1][j] = 0;
	}
	if(i+1 < earth.size() && earth[i+1][j]){
		nearby.push_back({i+1, j});
		earth[i+1][j] = 0;
	}
	if(j-1>=0 && earth[i][j-1]){
		nearby.push_back({i, j-1});
		earth[i][j-1] = 0;
	}
	if(j+1 < earth[0].size() && earth[i][j+1]){
		nearby.push_back({i, j+1});
		earth[i][j+1] = 0;
	}
	return;
}

vector<int> riverSizes(vector<vector<int>>& earth){
	vector<int> answer;
	for(int i=0;i<earth.size();i++){
		for(int j=0;j<earth[0].size();j++){
			if(earth[i][j]==1){
				int sum = 0;
				vector<pair<int, int>> data;
				data.push_back({i, j});
				earth[i][j] = 0;
				while(!data.empty()){
					pair<int, int> current = data.back();
					data.pop_back();
					addNearby(current.first, current.second, earth, data);
					sum++;
				}
				answer.push_back(sum);
			}
		}
	}
	return answer;
}

int main(){
	vector<vector<int>> data(5, vector<int>(5, 0));
	data[0][0] = 1;
	data[0][3] = 1;
	data[1][0] = 1;
	data[1][2] = 1;
	data[2][2] = 1;
	data[2][4] = 1;
	data[3][0] = 1;
	data[3][2] = 1;
	data[3][4] = 1;
	data[4][0] = 1;
	data[4][2] = 1;
	data[4][3] = 1;
	
	cout << "Provided array: " << endl;
	for(int i=0;i<data.size();i++){
		for(int j=0;j<data[0].size();j++){
			cout << data[i][j] << ", ";
		}
		cout << endl;
	}

	cout << endl;
	cout << "Expected Answer: [1, 2, 2, 2, 5]" << endl;
	cout << "Actual answer: ";

	vector<int> ans = riverSizes(data);

	for(int i: ans)
		cout << i << ", ";
	cout << endl;
	return 0;
}

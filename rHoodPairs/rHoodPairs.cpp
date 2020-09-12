#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> restoreArray(vector<vector<int>>& pairs){
	map<int, vector<int>> graph;
	for(vector<int>& p : pairs){
		if(graph.find(p[0])==graph.end())
			graph[p[0]] = vector<int>{};
		if(graph.find(p[1])==graph.end())
			graph[p[1]] = vector<int>{};
		graph[p[0]].push_back(p[1]);
		graph[p[1]].push_back(p[0]);
	}
	int startIdx = -1;
	for(auto& [idx, vec]: graph){
		if(vec.size()==1)
			startIdx = idx;
	}
	vector<int> traverse;
	vector<int> temp;
	map<int, bool> visited;
	visited[startIdx] = false;
	while(!visited[startIdx]){
		visited[startIdx] = true;
		traverse.push_back(startIdx);
		temp = graph[startIdx];
		if(temp.size()==1){
			startIdx = temp[0];
		}
		else if(temp.size()==2){
			for(int i: temp)
				if(visited.find(i)==visited.end())
					startIdx = i;
		}
		if(visited.find(startIdx)==visited.end()){
			visited[startIdx] = false;
		}
	}
	return traverse;
}

int main(){
	vector<vector<int>> pairs{{3, 5}, {1, 4}, {2, 4}, {1, 5}};
	vector<int> ret = restoreArray(pairs);

	for(int i: ret)
		cout << i << ", ";
	cout << endl;
	return 0;
}

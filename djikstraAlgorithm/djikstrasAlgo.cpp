#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Implementation of the Path with Maximum Probability

double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
	//save the graph edges and their probability
	vector<vector<pair<int, double>>> graph(n);
	for(int i=0;i<edges.size();i++){
		graph[edges[i][0]].push_back({edges[i][1], succProb[i]});
		graph[edges[i][1]].push_back({edges[i][0], succProb[i]});
	}

	//Now instantiate the priority_queue which will be sorted on the probability
	priority_queue<pair<double, int>> data;

	//Also instantiate the visited node list
	vector<bool> seen(n, false);
	
	//add the start index to queue which has probability 1
	data.push({1, start});

	//loop over the queue until its empty
	while(!data.empty()){
		auto [prob, idx] = data.top();
		data.pop();
		
		//If this is the end index then return the probability since it won't get updated again
		if(idx==end)
			return prob;

		seen[idx] = true;

		for(auto& [edge, sucProb] : graph[idx]){
			if(!seen[edge]){
				//If not visited then update the probability which is always going to decrease
				data.push({prob*sucProb, edge});
			}
		}
	}
	return 0;
}

int main(){
	cout << "Check Path with Maximum Probability problem in leetcode" << endl;
	return 0;
}

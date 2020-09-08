#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <numeric>

using namespace std;

void findUnreachable(vector<vector<int>>& graph, int start, vector<int>& unreachable){
	if(!unreachable[start])
		return;
	unreachable[start] = 0;
	for(int i : graph[start]){
		findUnreachable(graph, i, unreachable);
	}
	return;
}

void findNumConnected(vector<vector<int>>& graph, int start, pair<int, unordered_set<int>>& connected){
	for(int i: graph[start]){
		if(connected.second.find(i)==connected.second.end()){
			connected.second.insert(i);
			connected.first++;
			findNumConnected(graph, i, connected);
		}
	}
	return;
}

int minAirportConnections(vector<string>& airports, string start, vector<vector<string>>& connections){
	unordered_map<string, int> nums;
	for(int i = 0;i<airports.size();i++){
		nums[airports[i]] = i;
	}
	
	vector<vector<int>> graph(airports.size(), vector<int>{});
	
	for(vector<string> connect: connections){
		graph[nums[connect[0]]].push_back(nums[connect[1]]);
	}

	vector<int> unreachable(airports.size(), 1);
	findUnreachable(graph, nums[start], unreachable);

	priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<>> q;
	pair<int, unordered_set<int>> temp;
	vector<int> connects;
	int idx = 0;
	for(int i : unreachable){
		if(i){
			temp = {0, unordered_set<int>{}};
			connects = {idx};
			findNumConnected(graph, i, temp);
			for(const auto& x: temp.second)
				connects.push_back(x);
			q.push({temp.first, connects});
		}
		idx++;
	}
	vector<int> done(airports.size(), 0);
	int count = 0;
	while(!q.empty()){
		auto [cnt, vec] = q.top();
		q.pop();
		if(!done[vec[0]]){
			done[vec[0]] = 1;
			count++;
			for(int i = 1;i<vec.size();i++)
				done[vec[i]] = 1;
		}
	}
	return count;
}

int main(){
	vector<string> airports{"BGI",
	    "CDG",
	    "DEL",
	    "DOH",
	    "DSM",
	    "EWR",
	    "EYW",
	    "HND",
	    "ICN",
	    "JFK",
	    "LGA",
	    "LHR",
	    "ORD",
	    "SAN",
	    "SFO",
	    "SIN",
	    "TLV",
	    "BUD"};

	string start = "LGA";

	vector<vector<string>> connections{
		{"LGA", "DSM"},
			{"DSM", "ORD"},
			{"LGA", "EYW"},
			{"EYW", "JFK"},
			{"EYW", "EWR"},
			{"JFK", "ICN"},
			{"LGA", "ICN"},
			{"ICN", "ORD"},
			{"ICN", "EWR"},
			{"JFK", "DSM"},
			{"ICN", "JFK"},
			{"ORD", "DSM"},
			{"DSM", "LGA"},
			{"JFK", "LGA"},
			{"JFK", "HND"}
	};

	cout << "Expected: 10, Actual: " << minAirportConnections(airports, start, connections) << endl;

	return 0;
}

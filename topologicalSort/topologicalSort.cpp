#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> topologicalSort(vector<int>& jobs, vector<vector<int>>& deps){
	vector<vector<int>> prereq(jobs.size(), vector<int>{});
	for(vector<int> dep : deps){
		prereq[dep[1]].push_back(dep[0]);
	}
	vector<int> visited(jobs.size(), 0);
	vector<int> visiting(jobs.size(), 0);
	stack<int> vStack;
	vector<int> nJobs;
	int i = 0;
	while(i < jobs.size()){
		if(visited[i]){
			if(!vStack.empty()){
				i = vStack.top();
				vStack.pop();
			}
			else
				i++;
		}
		else if(prereq[i].size() == 0){
			if(!visited[i])
				nJobs.push_back(i);
			visited[i] = 1;
			if(!vStack.empty()){
				i = vStack.top();
				vStack.pop();
			}
			else i++;
		}
		else{
			if(visiting[i])
				return vector<int>{};
			visiting[i] = 1;
			vStack.push(i);
			for(int x: prereq[i]){
				vStack.push(x);	
			}
			prereq[i] = vector<int>{};
			i = vStack.top();
			vStack.pop();
		}
	}
	if(nJobs.size()==jobs.size())
		return nJobs;
	return vector<int>{};
}

int main(){
	vector<int> jobs{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
	vector<vector<int>> deps{
				{1, 2},
				{1, 3},
			    	{1, 4},
			        {1, 5},
			    	{1, 6},
			        {1, 7},
			    	{2, 8},
			        {3, 8},
			    	{4, 8},
			        {5, 8},
			    	{6, 8},
			        {7, 8},
			    	{2, 3},
			        {2, 4},
			    	{5, 4},
			        {7, 6},
			    	{6, 2},
			        {6, 3},
			    	{6, 5},
			        {5, 9},
			    	{9, 8},
			        {8, 0},
			    	{4, 0},
			        {5, 0},
			    	{9, 0},
			        {2, 0},
			    	{3, 9},
			        {3, 10},
			    	{10, 11},
			        {11, 12},
			    	{2, 12}
			};

	vector<int> res = topologicalSort(jobs, deps);

	cout << "[";
	for(int i:res)
		cout << i << ", ";
	cout << "]" << endl;
	return 0;
}

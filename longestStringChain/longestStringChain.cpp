#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool isPresent(vector<string>& data, int a, int b, vector<unordered_map<char, int>>& counts){
	if(data[a].size() <= data[b].size())
		return false;
	for(auto& [k, v] : counts[b]){
		if(counts[a].find(k) == counts[a].end() || counts[a][k] < v)
			return false;
	}
	return true;
}

vector<string> lsc(vector<string>& data, int start, vector<unordered_map<char, int>>& counts, vector<vector<string>>& memo, vector<bool>& done){
	if(start>=data.size())
		return vector<string>{};
	else if(done[start])
		return memo[start];
	else{
		vector<string> ret{data[start]};
		vector<string> temp{};
		vector<string> toAdd{};
		for(int i = start+1;i<data.size();i++){
			if(isPresent(data, start, i, counts)){
				temp = lsc(data, i, counts, memo, done);
				if(temp.size() > toAdd.size())
					toAdd = temp;
			}
		}
		for(string x: toAdd)
			ret.push_back(x);
		done[start] = true;
		memo[start] = ret;
		return ret;
	}
	return vector<string>{};
}

vector<string> longestStringChain(vector<string> data){
	sort(data.begin(), data.end(), [](string& a, string& b) { return a.size() > b.size(); });
	vector<unordered_map<char, int>> counts;
	for(string& s: data){
		unordered_map<char, int> temp;
		for(char c: s){
			if(temp.find(c)==temp.end())
				temp[c] = 1;
			else
				temp[c]++;
		}
		counts.push_back(temp);
	}
	vector<vector<string>> memo(data.size(), vector<string>{});
	vector<bool> done(data.size(), false);
	vector<string> ret{};
	vector<string> temp{};
	for(int i = 0;i<data.size();i++){
		temp = lsc(data, i, counts, memo, done);
		if(temp.size() > ret.size())
			ret = temp;
	}
	return ret;
}

int main(){
	vector<string> data{"lgoprt","12345678","algoxpert","abcde","123468","lgoxprt","abde","lgopt","1234678","ade","ae","algoxprt","a","1abde","lgpt","123456789","234678","algoexpert"};

	vector<string> ret = longestStringChain(data);

	for(string s: ret)
		cout << s << ", ";
	cout << endl;
	return 0;
}

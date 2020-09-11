#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool checkSame(vector<int>& count, vector<int>& cCount){
	for(int i = 0; i< count.size();i++){
		if(count[i] != cCount[i])
			return false;
	}
	return true;
}

vector<int> findAnagrams(string s, string p){
	if(s.size() < p.size())
		return {};
	unordered_map<char, int> vals;
	vector<int> currentCounts(26, 0);
	vector<int> counts(26, 0);
	vector<int> ret;
	int hashSum = 0;
	int currentSum = 0;
	int idx = p.size();

	for(int i = 0;i<27;i++){
		vals['a'+i] = i+1;
	}
	
	for(char c: p){
		counts[c-'a']++;
		hashSum+=vals[c];
	}
	
	for(int i = 0; i< p.size();i++){
		currentCounts[s[i]-'a']++;
		currentSum+=vals[s[i]];
	}
	
	if(currentSum==hashSum && checkSame(counts, currentCounts))
		ret.push_back(0);

	while(idx < s.size()){
		currentCounts[s[idx]-'a']++;
		currentCounts[s[idx-p.size()]-'a']--;
		currentSum+=vals[s[idx]];
		currentSum-=vals[s[idx-p.size()]];
		if(currentSum==hashSum && checkSame(counts, currentCounts))
			ret.push_back(idx-p.size()+1);
		idx++;
	}
	return ret;
}

int main(){
	string s = "cbaebabacd";
	string p = "abc";
	vector<int> ret = findAnagrams(s, p);
	cout << "Expected result: [0, 6], Actual: [";
	for(int i: ret)
		cout << i << ", ";
	cout << "]" << endl;
	return 0;
}

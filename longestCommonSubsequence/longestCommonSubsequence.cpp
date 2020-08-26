#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

vector<char> lcs(string& a, string& b, int aIdx, int bIdx, vector<vector<int>>& memo, unordered_map<string, vector<char>>& memoData){
	if (aIdx>=a.size() || bIdx>=b.size())
		return {};
	string key = to_string(aIdx) + "-" + to_string(bIdx);
	if(memo[aIdx][bIdx]==1){
		return memoData[key];
	}
	vector<char> current{};
	vector<char> c1{};
	vector<char> c2{};
	vector<char> nCur;
	if(a[aIdx]==b[bIdx]){
		current.push_back(a[aIdx]);
		nCur = lcs(a, b, aIdx+1, bIdx+1, memo, memoData);
		for(char c: nCur)
			current.push_back(c);
	}
	else{
		c1 = lcs(a, b, aIdx+1, bIdx, memo, memoData);
		c2 = lcs(a, b, aIdx, bIdx+1, memo, memoData);
		current = c1.size()>c2.size() ? c1 : c2;
	}
	memo[aIdx][bIdx] = 1;
	memoData[key] = current;
	return current;
}

vector<char> longestCommonSubsequence(string& a, string& b){
	vector<vector<int>> memo(a.size(), vector<int>(b.size(), 0));
	unordered_map<string, vector<char>> memoData;

	return lcs(a, b, 0, 0, memo, memoData);
}

int main(){
	string a = "8111111111111111142";
	string b = "222222222822222222222222222222433333333332";

	vector<char> res = longestCommonSubsequence(a, b);

	cout << "Expected: [\"8\", \"4\", \"2\"], Actual: [";
	for(char c: res)
		cout << c << ", ";
	cout << "]" << endl;
	
	a = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	b = "CCCDDEGDHAGKGLWAJWKJAWGKGWJAKLGGWAFWLFFWAGJWKAG";
	
	res = longestCommonSubsequence(a, b);

	cout << "Expected: \"C\", \"D\", \"E\", \"G\", \"H\", \"J\", \"K\", \"L\", \"W\", Actual: ";
	for(char c: res)
		cout << c << ", ";
	cout << "]" << endl;
	
	return 0;
}

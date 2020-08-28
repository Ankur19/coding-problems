#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

bool iwRec(string& a, string& b, string& target, int i, int j, int k, vector<vector<int>>& memo){
	if(i==a.size() && j==b.size() && k==target.size()){	
		return true;
	}
	else if((k>=target.size() && (i <a.size() || j < b.size())) || (k < target.size() && (i>=a.size() && j >=b.size()))){
		if(i<a.size() && j<b.size())
			memo[i][j] = 0;
		return false;
	}
	bool val;
	if(i < a.size() && j < b.size() && memo[i][j]>-1){
		return (bool)memo[i][j];
	}
	if(i < a.size() && j < b.size() && a[i]==b[j] && a[i]==target[k]){
		val = iwRec(a, b, target, i+1, j, k+1, memo) || iwRec(a, b, target, i, j+1, k+1, memo);
		memo[i][j] = (int)val;
		return memo[i][j];
	}
	else if(i < a.size() && a[i]==target[k]){
		val = iwRec(a, b, target, i+1, j, k+1, memo);
		memo[i][j] = (int)val;
		return memo[i][j];
	}
	else if(j < b.size() && b[j]==target[k]){
		val = iwRec(a, b, target, i, j+1, k+1, memo);
		memo[i][j] = (int)val;
		return memo[i][j];
	}
	memo[i][j] = 0;
	return false;
}

bool interweavingStrings(string& a, string& b, string& target){
	vector<vector<int>> memo(a.size()+1, vector<int>(b.size()+1, -1));
	return iwRec(a, b, target, 0, 0, 0, memo);
}

int main(){
	string t1 = "aabcc";
	string t2 = "dbbca";
	string target1 = "aadbbbaccc";

	cout << "Expected: false, Actual: " << interweavingStrings(t1, t2, target1) << endl;
	t1 = "algoexpert";
	t2 = "your-dream-job";
	target1 = "your-algodream-expertjob";
	cout << "Expected: true, Actual: " << interweavingStrings(t1, t2, target1) << endl;
	return 0;
}

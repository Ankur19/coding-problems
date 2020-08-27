#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

int smSpaces(string& s, unordered_set<string>& ss, vector<int>& memo, int idx){
	if(idx>=s.size())
		return 0;
	if(memo[idx]>-2)
		return memo[idx];
	int spaces = -1;
	int temp;
	string cur = "";
	for(int i = idx;i<s.size();i++){
		cur+=s[i];
		if(ss.find(cur)!= ss.end()){
			if(i==s.size()-1){
				spaces = 0;
				break;
			}
			temp = smSpaces(s, ss, memo, i+1);
			if(temp!= -1 && (temp+1 < spaces || spaces==-1)){
				spaces = temp+1;
			}
		}
	}
	memo[idx] = spaces;
	return memo[idx];
}

int smallestNoOfSpaces(string& s, vector<string>& smallStrs){
	unordered_set<string> ss;
	for(string& x: smallStrs)
		ss.insert(x);
	vector<int> memo(s.size(), -2);
	return smSpaces(s, ss, memo, 0);
}

int main(){
	string PI = "3141592653589793238462643383279";
	vector<string> tNumbers1{"3",
	            "1",
	            "4",
	            "592",
	            "65",
	            "55",
	            "35",
	            "8",
	            "9793",
	            "2384626",
	            "83279"};
	cout << "Expected: 13, Actual: " << smallestNoOfSpaces(PI, tNumbers1) << endl;
	return 0;
}

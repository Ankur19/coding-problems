#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

bool checkValid(string& s, string target, int start){
	if(start + target.size()>s.size())
		return false;
	for(int i = 0;i<target.size();i++){
		if(s[start+i] != target[i])
			return false;
	}
	return true;
}

string underscorify(string s, string target){
	vector<int> tests;
	for(int i=0;i<s.size();i++){
		if(s[i]==target[0])
			tests.push_back(i);
	}
	unordered_set<int> valid;
	for(int i: tests)
		if(checkValid(s, target, i))
			valid.insert(i);
	string nS = "";
	int previousEnd = 0;
	for(int i=0;i<s.size();i++){
		if(valid.find(i)==valid.end()){
			if(i==previousEnd)
				nS+="_";
			nS+= string(1, s[i]);
		}
		else{
			if(i==previousEnd)
				nS+="_";
			if(i>previousEnd){
				nS+="_" + string(1, s[i]);
			}
			else
				nS+=string(1, s[i]);
			previousEnd = i+target.size();
		}
	}
	return nS;
}

int main(){
	string s = "testthis is a testest to see if testestes it works";
	string target = "test";

	cout << underscorify(s, target) << endl;
	return 0;
}

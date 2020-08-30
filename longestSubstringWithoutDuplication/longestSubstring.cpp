#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

string longestSubstringWithoutDuplication(string s){
	int start = 0;
	int maxLen = 0;
	int maxStart = 0;
	int oldIdx;
	unordered_map<char, int> idx;

	for(int i=0;i<s.size();i++){
		if(idx.find(s[i]) == idx.end()){
			idx[s[i]] = i;
		}
		else{
			oldIdx = idx[s[i]];
			if(oldIdx < start)
				idx[s[i]] = i;
			else{
				if(i-start > maxLen){
					maxLen = i-start;
					maxStart = start;
				}
				start = oldIdx+1;
				idx[s[i]] = i;
			}
		}
	}
	return s.substr(maxStart, maxLen);
}

int main(){
	string s = "abacacacaaabacaaaeaaafa";

	cout << "Expected: bac, Actual: " << longestSubstringWithoutDuplication(s) << endl;
	return 0;
}

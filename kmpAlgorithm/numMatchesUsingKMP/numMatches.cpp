#include <bits/stdc++.h>

using namespace std;

vector<int> buildPattern(string& str){
	unordered_map<char, int> found;
	vector<int> pattern(str.size()+1, 0);
	for(int i =0; i< str.size(); i++){
		if(found.find(str[i])== found.end()){
			found[str[i]] = i+1;
			pattern[i+1] = 0;
		}
		else{
			pattern[i+1] = found[str[i]];
		}
	}
	return pattern;
}

int numMatches(string& s, string& substr){
	vector<int> pattern = buildPattern(substr);
	
	int i = 0; int j = 0; int count = 0;
	substr = " " + substr;

	while(i < s.size()){
		if(s[i]==substr[j+1]){
			i++;
			j++;
		}
		else{
			if(j==0)
				i++;
			else
				j = pattern[j];
		}
		if(j+1==pattern.size()){
			j = 0;
			i = i - substr.size()+2;
			count++;
		}
	}
	return count;
}


int main(){
	string s = "111000001111";
	string pattern = "0000";
	cout << numMatches(s, pattern) << endl;
	return 0;
}

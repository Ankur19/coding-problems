#include <bits/stdc++.h>

using namespace std;

pair<char, int> getSecondPosAndMap(string& pattern, char first, unordered_map<char, int>& count){
	int secondLen = -1;
	char second = first;
	count[first] = 1;
	for(int i = 1; i < pattern.size(); i++){
                if(count.find(pattern[i]) == count.end()){
                        second = pattern[i];
                        secondLen = i;
			count[pattern[i]] = 1;
		}
		else{
			count[pattern[i]]++;
		}
	}
	return {second, secondLen};
}

bool checkSame(string& a, string& b){
	for(int i = 0; i< a.size(); i++){
		if(a[i] != b[i])
			return false;
	}
	return true;
}

bool wordPatternMatch(string pattern, string str){
	if(!pattern.size() || !str.size()){
		return pattern.size() == str.size();
	}
	unordered_map<char, int> count;
	char first = pattern[0];
	int firstLen = 0;
	int secondLen = 0;
	string nS;
	auto [second, secondStart] = getSecondPosAndMap(pattern, first, count);
	if(secondStart == -1){
		firstLen = str.size() / count[first];
		if(firstLen*count[first] != str.size())
			return false;
		else{
			string x = str.substr(0, firstLen);
			nS = "";
			for(int i = 0; i< count[first];i++)
				nS+=x;
			return checkSame(nS, str);
		}
	}
	else{
		for(int i = 1; i < str.size(); i++){
			secondLen = (str.size() - i*count[first])/count[second];
			if(secondLen < 0 || (secondLen*count[second]) + (i*count[first]) != str.size())
				return false;
			else{
				string t1 = str.substr(0, i);
				string t2 = str.substr(i*secondStart, secondLen);
				nS = "";
				for(char c: pattern){
					if(c==first)
						nS+=t1;
					else
						nS+=t2;
				}
				//cout << i << "," << secondLen << ", " << count[first] << "-" << count[second] << endl;
				//cout << t1 << ", " << t2 << ", " << nS << endl;
				if(checkSame(nS, str))
					return true;
			}
		}
	}
	return false;
}

int main(){
	string pattern = "abab";
	string str = "redblueredblue";
	cout << "Expected True, Actual: " << wordPatternMatch(pattern, str) << endl;
	
	pattern = "aabb";
	str = "xyzabcxzyabc";
	cout << "Expected False, Actual: " << wordPatternMatch(pattern, str) << endl;

	return 0;
}

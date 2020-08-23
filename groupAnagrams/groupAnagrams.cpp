#include <iostream>
#include <string>
#include <vector>

using namespace std;

void swap(int i, int j, string& s){
	char temp = s[i];
	s[i] = s[j];
	s[j] = temp;
	return;
}

vector<string> groupAnagrams(string s, int start){
	if(start==s.size()-1)
		return vector<string>{string(1, s[start])};
	vector<string> ret;
	vector<string> temp;
	for(int i=start;i<s.size();i++){
		swap(start, i, s);
		vector<string> temp = groupAnagrams(s, start+1);
		for(string part: temp){
			string ns(1, s[start]);
			ret.push_back(ns+part);
		}
		swap(start, i, s);
	}
	return ret;
}

vector<string> groupAnagrams(string s){
	return groupAnagrams(s, 0);
}

int main(){
	string s = "cinema";

	vector<string> anagrams = groupAnagrams(s);

	for(string c: anagrams)
		cout << c << ", ";
	cout << endl;

	return 0;
}


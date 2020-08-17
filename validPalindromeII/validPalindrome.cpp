#include <string>
#include <iostream>

using namespace std;

bool isValidPalindromeRange(string s, int i, int j);

bool validPalindrome(string s){
	int i=0;
	int j = s.size()-1;
	bool skipped = false;
	while(i<j){
		if(s[i] != s[j]){
			return isValidPalindromeRange(s, i+1, j) || isValidPalindromeRange(s, i, j-1);
		}
		else{
			i++;
			j--;
		}
	}
	return true;
}

bool isValidPalindromeRange(string s, int i, int j){
	while(i<j){
		if(s[i] != s[j])
			return false;
		i++;
		j--;
	}
	return true;
}


int main(){
	string test("aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga");
	cout << "Expected: true. Answer: " << validPalindrome(test) << endl;
	return 0;
}

#include <iostream>
#include <string>

using namespace std;

pair<int, int> getPalindrome(int left, int right, string& s);

string longestValidPalindrome(string s){
	if(s.size()==0)
		return 0;
	pair<int, int> longest;
	pair<int, int> cur;
	int longestLen = 1;
	pair<int, int> even;
	pair<int, int> odd;
	for(int i=1; i< s.size();i++){
		even = getPalindrome(i-1, i, s);
		odd = getPalindrome(i-1, i+1, s);
		if(even.second-even.first > odd.second-odd.first){
			cur = even;
		}
		else
			cur = odd;
		if(cur.second-cur.first + 1 > longestLen){
			longest = cur;
			longestLen = cur.second-cur.first+1;
		}
	}
	if(longestLen==1)
		return "" + s[0];
	return s.substr(longest.first, longestLen);
}

pair<int, int> getPalindrome(int left, int right, string& s){
	if(right >=s.size() || s[left]!= s[right])
		return {left+1, left+1};
	while(s[left]==s[right]){
		left--;
		right++;
		if(left<0 || right >= s.size()){
			return {left+1, right-1};
		}
	}
	return {left+1, right-1};
}

int main(){
	string test = "abcdefgfedcbazzzzzzzzzzzzzzzzzzzz";

	string test1 = "abcdefgfedcba";

	cout << "Longest Palindrome: " << longestValidPalindrome(test) << endl;

	cout << "Longest Palindrome: " << longestValidPalindrome(test1) << endl;

	return 0;
}

#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string s){
	int i = 0;
	int j = s.size()-1;

	while(i<j){
		while(i<j && !isalnum(s[i]))
			i++;
		while(i<j && !isalnum(s[j]))
			j--;

		char first = tolower(s[i]);
		char second = tolower(s[j]);

		if(first != second)
			return false;
		i++;
		j--;
	}
	return true;
}


int main(){
	string test = "A man, a plan, a canal: Panama";

	cout << "Expected for input string \"A man, a plan, a canal: Panama\": true, Actual answer: " << isPalindrome(test) << endl;

	return 0;
}

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool checkValidBottomUp(string s);
bool checkValid(string s, int start, vector<char>& stack);

bool checkValidString(string s){
	return checkValidBottomUp(s);
	/*vector<char> stack;
	return checkValid(s, 0, stack);*/
}

bool checkValid(string s, int start, vector<char>& stack){
	if(start>=s.size()){
		if(stack.size()>0)
			return false;
		return true;
	}
	if(s[start]=='('){
		stack.push_back('(');
		return checkValid(s, start+1, stack);
	}
	else if(s[start]==')'){
		if(stack.size()==0 || stack.back()!='(')
			return false;
		else{
			stack.pop_back();
			return checkValid(s, start+1, stack);
		}
	}
	bool valid = false;
	vector<char> nStack(stack.begin(), stack.end());
	if(stack.size() !=0 && stack.back()=='('){
		stack.pop_back();
		valid = checkValid(s, start+1, stack);
		if(valid)
			return true;
		stack = vector<char>(nStack.begin(), nStack.end());
	}
	stack.push_back('(');
	valid = checkValid(s, start+1, stack);
	if(valid)
		return true;
	stack = vector<char>(nStack.begin(), nStack.end());
	return checkValid(s, start+1, stack);
}

bool checkValidBottomUp(string s){
	vector<int> valid;
	vector<int> star;

	for(int i=0;i<s.size();i++){
		if(s[i]=='(')
			valid.push_back(i);
		else if(s[i]=='*')
			star.push_back(i);
		else{
			if(valid.size()!=0)
				valid.pop_back();
			else if(star.size()!=0)
				star.pop_back();
			else
				return false;
		}
	}
	while(valid.size() && star.size()){
		if(valid.back() > star.back())
			return false;
		valid.pop_back();
		star.pop_back();
	}
	return valid.size()==0;
}

int main(){
	string s = "(*))";

	cout << "Expected: true, Actual: " << checkValidString(s) << endl;
	
	return 0;
}

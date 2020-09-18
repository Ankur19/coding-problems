#include <bits/stdc++.h>

using namespace std;

string minRemoveToMakeValid(string s) {
        vector<int> remains;
        vector<pair<char, int>> stack;
        unordered_set<int> n;
        for(int i = 0; i< s.size(); i++){
            if(s[i]=='('){
                stack.push_back({'(', i});
            }
            else if(s[i]==')'){
                if(stack.size()==0 || stack[stack.size()-1].first != '('){
                    remains.push_back(i);
                }
                else{
                    stack.pop_back();
                }
            }
        }
        for(int i: remains)
            n.insert(i);
        for(auto [c, i]: stack)
            n.insert(i);
        string ns = "";
        for(int i = 0; i< s.size(); i++){
            if(n.find(i) == n.end()){
                ns+=s[i];
            }
        }
        return ns;
    }

int main(){
	cout << "Check Leetcode: 1249" << endl;
	return 0;
}

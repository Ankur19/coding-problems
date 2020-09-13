#include <bits/stdc++.h>

using namespace std;

int monotoneIncreasingDigits(int N) {
        vector<char> S;
        for(char c: to_string(N))
            S.push_back(c);
        int i = 1;
        while(i < S.size() && S[i-1] <= S[i])
            i++;
        while(0 < i && i < S.size() && S[i-1] > S[i])
            S[--i]--;
        for(int j = i+1; j<S.size(); ++j)
            S[j] = '9';
        string s = "";
        for(char c: S){
            s+= string(1, c);
        }
        return stoi(s);
}

int main(){
	cout << "Expected ans for N=10: 9, Actual ans: " << monotoneIncreasingDigits(10) << endl;
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

bool isAlienSorted(vector<string>& words, string order) {
        char mapping[26];
        
	for(int i=0; i<order.size(); i++){
            mapping[order[i]-'a'] = char(i + 'a');
        }

        for(string& w: words){
            for(char& c: w){
                c = mapping[c-'a'];
            }
        }

        return is_sorted(words.begin(), words.end());
}

int main(){
	cout << "Check leetCode problem: 953" << endl;
}

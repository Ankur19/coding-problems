#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

string smallestSubstringContaining(string& a, string& b){
	unordered_map<char, int> count;
	unordered_map<char, int> cur;
	int fill = 0;
	string smallest = a;
	int numUnique = 0;
	for(char c: b){
		if(count.find(c)==count.end()){
			count[c] = 0;
			numUnique++;
		}
		count[c]++;
	}

	int l = 0;
	int r = 0;
	int curUnique = 0;
	while(r<a.size()){
		//cout<< a.substr(l, r-l+1) << ", "  << (bool)(numUnique==curUnique) << endl;
		if(count.find(a[r]) != count.end()){
			if(cur.find(a[r])==cur.end())
				cur[a[r]] = 0;
			cur[a[r]]++;
			if(cur[a[r]]==count[a[r]])
				curUnique++;
		}
		if(numUnique==curUnique){
			while(numUnique==curUnique && l <= r){
				if(smallest.size() > r-l+1){
					smallest = a.substr(l, r-l+1);
				}
				if(count.find(a[l]) != count.end()){
					if(cur[a[l]] == count[a[l]])
						curUnique--;
					cur[a[l]]--;
				}
				//cout<< a.substr(l, r-l+1) << ", " << a[l] << "-" << cur['a'] << ", " << count['a'] << ",, " << (bool)(numUnique==curUnique) << endl;
				l++;
			}
			r++;
		}
		else
			r++;
	}
	return smallest;
}

int main(){
	string a = "a$fuu+afff+affaffa+a$Affab+a+a+$a$";
	string b = "a+$aaAaaaa$++";

	cout << "Expected: affa+a$Affab+a+a+$a, Actual: " << smallestSubstringContaining(a, b) << endl;
	return 0;
}

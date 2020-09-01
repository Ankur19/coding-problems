#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

bool kmp(string& a , string& b){
	vector<int> lcp{0};
	unordered_map<char, int> found;
	for(int i=0;i<b.size();i++){
		if(found.find(b[i]) == found.end()){
			lcp.push_back(0);
			found[b[i]] = i+1;
		}
		else{
			lcp.push_back(found[b[i]]);
		}
	}
	b = " " + b;
	int i = 0;
	int j = 0;
	while(i < a.size()){
		if(a[i]==b[j+1]){
			i++;
			j++;
		}
		else{
			if(j==0)
				i++;
			else
				j = lcp[j];
		}
		if(j+1 == lcp.size())
			return true;
	}
	return false;
}

int main(){
    string s = "aefcdfaecdaefaefcdaefeaefcdcdeae";
    string b = "aefcdaefeaefcd";
    
    cout << "Expected: True, Actual: " << kmp(s, b) << endl;
    s = "decadaafcdf";
    b = "daf";
    
    cout << "Expected: False, Actual: " << kmp(s, b) << endl;
    return 0;
}

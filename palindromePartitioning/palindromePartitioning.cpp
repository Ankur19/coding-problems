#include <iostream>
#include <vector>
#include <string>
#include <climits>

using namespace std;

int minCuts(string& s){
	vector<vector<int>> memo(s.size(), vector<int>(s.size(), 0));

	for(int i = 0;i<s.size();i++){
		memo[i][i] = 1;
	}
	int j;
	for(int length = 2;length<=s.size();length++){
		for(int i = 0; i<s.size()-length+1;i++){
			j = i+length-1;
			if(length == 2)
				memo[i][j] = s[i]==s[j];
			else
				memo[i][j] = memo[i+1][j-1] && s[i]==s[j];
		}
	}
	
	vector<int> data(s.size(), INT_MAX);
	
	for(int i=0;i<s.size();i++){
		if(memo[0][i])
			data[i] = 0;
		else{
			data[i] = data[i-1]+1;
			for(int k = 1;k<i;k++){
				if(memo[k][i] && data[k-1]+1 < data[i])
					data[i] = data[k-1]+1;
			}
		}
	}
	return data[data.size()-1];
}

int main(){
	string s = "abbbacecffgbgffab";
	cout << "Expected: 4, Actual: " << minCuts(s) << endl;
	return 0;
}

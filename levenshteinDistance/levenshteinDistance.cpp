#include <iostream>
#include <string>
#include<vector>
#include<cmath>

using namespace std;

int levenshteinDistance(string& a, string& b){
	int la = a.size();
	int lb = b.size();
	vector<vector<int>> ans(la+1, vector<int>(lb+1, 0));
	for(int i=0;i<=lb;i++)
		ans[0][i] = i;
	for(int i=0;i<=la;i++)
		ans[i][0] = i;
	for(int i=1;i<=la;i++){
		for(int j=1;j<=lb;j++){
			if(a[i-1]==b[j-1])
				ans[i][j] = ans[i-1][j-1];
			else{
				int minimum = min(ans[i-1][j], ans[i][j-1]);
				minimum = min(minimum, ans[i-1][j-1]);
				ans[i][j] = 1+minimum;
			}
		}
	}
	return ans[la][lb];
}

int main(){
	vector<string> as{"", "", "abc", "abc", "abc", "abc", "algoexpert", "abcdefghij", "abcdefghij", "biting", "cereal", "cereal", "abbbbbbbbb", "abc", "xabc"};
	vector<string> bs{"", "abc", "abc", "abx", "abcx", "yabcx", "algozexpert", "1234567890", "a234567890", "mitten", "saturday", "saturdzz", "bbbbbbbbba", "yabd", "abcx"};
	vector<int> expected{0, 3, 0, 1, 1, 2, 1, 10, 9, 4, 6, 7, 2, 2, 2};
	for(int i=0;i<as.size();i++){
		cout << "Expected: " << expected[i] << ", Actual: " << levenshteinDistance(as[i], bs[i]) << endl;
	}
	return 0;
}

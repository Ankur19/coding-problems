#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        if(A.size()==0 || B.size()==0)
	            return {};
        vector<vector<int>> result;
        int i = 0;
        int j = 0;
        vector<int> temp;
        while(i < A.size() && j < B.size()){
		temp = vector<int>(2, 0);
		if(A[i][1] < B[j][0]){
	                i++;
	                continue;
        	}
		if(A[i][0] > B[j][1]){
			j++;
			continue;
		}
                if(A[i][1] <= B[j][1]){
	                temp[0] = max(A[i][0], B[j][0]);
	                temp[1] = A[i][1];
	                i++;
	                result.push_back(temp);
	                continue;
		}
		if(B[j][1] < A[i][1]){
			temp[0] = max(A[i][0], B[j][0]);
			temp[1] = B[j][1];
			j++;
			result.push_back(temp);
			continue;
                }
	}
        return result;
}

int main(){
	cout << "check Interval List Intersections. Leetcode 986" << endl;
	return 0;
}

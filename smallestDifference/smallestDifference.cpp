#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;

vector<int> smallestDifference(vector<int> first, vector<int> second){
	sort(first.begin(), first.end());
	sort(second.begin(), second.end());
	int smallest = INT_MAX;
	vector<int> answer;
	for(int i=0;i<first.size();i++){
		int j = 0;
		while(j<second.size() && second[j] < first[i])
			j++;
		if(j-1>=0){
			int val = first[i] - second[j-1];

			if(val==0){
				return {first[i], second[j-1]};
			}
			if(val < smallest){
				smallest = val;
				answer = {first[i], second[j-1]};
			}
		}
		if(j< second.size()){
			int upVal = second[j] - first[i];

			if(upVal==0)
				return {second[j], first[i]};
			if(upVal < smallest){
				smallest = upVal;
				answer = {second[j], first[i]};
			}
		}
	}
	return answer;
}

int main(){

	//Can be optimized by using a single loop for both first and second and then increasing just one index
	vector<int> first{10, 1000, 9124, 2142, 59, 24, 596, 591, 124, -123, 530};
	vector<int> second{-1441, -124, -25, 1014, 1500, 660, 410, 245, 530};

	vector<int> answer = smallestDifference(first, second);

	cout << answer[0] << ", " << answer[1] << endl;

	return 0;
}

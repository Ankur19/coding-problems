#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minNumberOfCoinsForChange(vector<int>& coins, int target){
	vector<int> answer(target+1, -1);
	sort(coins.begin(), coins.end());
	if(target < coins[0])
		return 0;
	answer[0] = 0;
	for(int i=1;i<=target;i++){
		int idx = 0;
		int count;
		while(coins[idx] <= i){
			count = 1 + answer[i-coins[idx]];
			if(answer[i]==-1 || (count>0 && count < answer[i]))
				answer[i] = count;
			idx++;
		}
	}
	return answer[target];
}

int main(){
	vector<int> test{1, 5, 10};
	vector<int> targets{4, 7, 10, 11, 24, 25};
	vector<int> answers{4, 3, 1, 2, 6, 3};

	for(int i=0;i<targets.size();i++)
		cout << "Expected answer when " << targets[i] << " is target : " << answers[i] << ", Actual answer: " << minNumberOfCoinsForChange(test, targets[i]) << endl;
	return 0;
}

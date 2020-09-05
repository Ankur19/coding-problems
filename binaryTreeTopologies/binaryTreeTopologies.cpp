#include <iostream>
#include <vector>

using namespace std;

int numTopologies(int n){
	vector<int> topologies(n+1, 0);
	if(n<=2)
		return n;
	topologies[1] = 1;
	topologies[2] = 2;
	int left;
	int right;
	for(int i = 3; i<=n;i++){
		left = i-1;
		right = 0;
		while(left >=0){
			if(right==0)
				topologies[i]+=topologies[left];
			else if(left==0)
				topologies[i]+=topologies[right];
			else{
				topologies[i]+= topologies[left]*topologies[right];
			}
			left--;
			right++;
		}
	}
	return topologies[n];
}

int main(){
	cout << "Expected: 132, Actual: " << numTopologies(6) << endl;
	cout << "Expected: 742900, Actual: " << numTopologies(13) << endl;
	return 0;
}

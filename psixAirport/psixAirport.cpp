#include <iostream>
#include <vector>

using namespace std;

int addTime(int time, int minutes){
	int hours = time/100;
	int mins = time%100;
	mins+= minutes;
	if(mins>=60){
		hours+=1;
		mins%=60;
	}	
	return hours*100+mins;
}

int maxGatesAirport(vector<int>& a, vector<int>& b, int maxWait){
	int minGates = 1;
	int remaining = 0;
	int i = 1;
	int j = 0;
	while(i < a.size()){
		while(j < b.size() && b[j] <= addTime(a[i], maxWait) && remaining < minGates){
			j++;
			remaining++;
		}
		if(remaining>0)
			remaining--;
		else{
			minGates++;
		}
		i++;
	}
	return minGates;
}

int main(){
	vector<int> a{900, 940, 950, 1100, 1500, 1800, 1900};
	vector<int> b{910, 1120, 1130, 1200, 1900, 2000};
	
	cout << maxGatesAirport(a, b, 30) << endl;
	return 0;
}

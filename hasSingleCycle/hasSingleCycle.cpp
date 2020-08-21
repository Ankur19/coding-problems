#include <iostream>
#include <vector>

using namespace std;

bool hasSingleCycle(vector<int>& data){
	vector<int> visited(data.size(), 0);
	int size = data.size();
	int i = 0;
	while(!visited[i]){
		visited[i] = 1;
		i+=data[i];
		if(i<0)
			i+=size;
		else if(i>=size)
			i-=size;
	}
	for(int i:visited){
		size-=i;
	}
	return size==0;
}


int main(){
	vector<int> test1{3, 5, 6, -5, -2, -5, -12, -2, -1, 2, -6, 1, 1, 2, -5, 2};
	vector<int> test2{3, 5, 5, -5, -2, -5, -12, -2, -1, 2, -6, 1, 1, 2, -5, 2};

	cout << "Expected: true, Actual: " << hasSingleCycle(test1) << endl;
	cout << "Expected: false, Actual: " << hasSingleCycle(test2) << endl;

	return 0;
}

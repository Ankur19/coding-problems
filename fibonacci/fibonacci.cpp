#include <iostream>

using namespace std;

int fibonacci(int n){
	if(n==1)
		return 0;
	else if(n==2)
		return 1;
	int data[n+1];
	data[1] = 0;
	data[2] = 1;
	int current = 2;
	while(current<n){
		data[current+1] = data[current]+data[current-1];
		current++;
	}
	return data[n];
}

int main(){
	int i;
	cout << "Please enter value of n: ";
	cin >> i;
	cout << "Answer: " << fibonacci(i) << endl;
	return 0;
}

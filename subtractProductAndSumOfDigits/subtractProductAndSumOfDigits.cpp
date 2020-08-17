#include <iostream>
#include <string>

using namespace std;

int subtractProductAndSum(int n){
	int sum = 0;
	int product = 1;
	while(n !=0){
		sum += n%10;
		product *= n%10;
		n/=10;
	}
	return sum>product? sum-product: product-sum;
}

int main(){
	cout << "Expected answer for 234: 15, Actual Answer: " << subtractProductAndSum(234) << endl;
	return 0;
}

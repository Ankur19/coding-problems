#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

class Program{
	public:
		priority_queue<int> left;
		priority_queue<int, vector<int>, greater<int>> right;
		int lSize;
		int rSize;
		Program(){
			lSize = 0;
			rSize = 0;
		}
		void insert(int a){
			if(lSize == rSize ){
				left.push(a);
				lSize++;
			}
			else{
				right.push(a);
				rSize++;
			}
			return;
		}

		double getMedian(){
			if(lSize>rSize)
				return (double)left.top();
			return (double)(right.top() + left.top())/2;
		}
};

int main(){
	Program* p = new Program();
	cout << "Initialized..!!" << endl;
	p->insert(5);
	cout << "Expected: 5, Actual: " << p->getMedian() << endl;
	p->insert(10);
	cout << "Expected: 7.5, Actual: " << p->getMedian() << endl;
	p->insert(100);
	cout << "Expected: 10, Actual: " << p->getMedian() << endl;
	p->insert(200);
	cout << "Expected: 55, Actual: " << p->getMedian() << endl;
	return 0;
}

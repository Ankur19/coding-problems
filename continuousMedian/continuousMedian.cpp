#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

class Program{
	public:
		priority_queue<int> left;
		priority_queue<int, vector<int>, greater<int>> right;
		int count;
        int lSize = 0;
        int rSize = 0;
		Program(){
			count = 0;
            lSize = 0;
            rSize = 0;
		}
		void insert(int a){
            count++;
            if(count==1 || a <= left.top()){
                left.push(a);
                lSize++;
            }
            else{
                right.push(a);
                rSize++;
            }
            if(count%2==0){
                if(lSize > rSize){
                    while(lSize>rSize){
                        right.push(left.top());
                        left.pop();
                        lSize--;
                        rSize++;
                    }
                }
                else{
                    while(lSize < rSize){
                        left.push(right.top());
                        right.pop();
                        lSize++;
                        rSize--;
                    }
                }
            }
            else if(count%2 && count>2){
                if(lSize>rSize){
                    while(lSize-1 != rSize){
                        right.push(left.top());
                        left.pop();
                        rSize++;
                        lSize--;
                    }
                }
                else{
                    while(rSize-1 != lSize){
                        left.push(right.top());
                        right.pop();
                        rSize--;
                        lSize++;
                    }
                }
            }
			return;
		}

		double getMedian(){
			if(count%2)
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

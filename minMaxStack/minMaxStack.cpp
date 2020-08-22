#include <iostream>
#include <vector>

using namespace std;

class MinMaxStack{
	public:
		vector<int> stack;
		vector<pair<int, int>> minMax;
		MinMaxStack() {}

		void push(int val){
			if(stack.size()==0){
				stack.push_back(val);
				minMax.push_back({val, val});
			}
			else{
				stack.push_back(val);
				pair<int, int> currentMinMax = minMax.back();

				if(val < currentMinMax.first)
					currentMinMax.first = val;
				if(val> currentMinMax.second)
					currentMinMax.second = val;
				minMax.push_back(currentMinMax);
			}
		}

		vector<int> minMaxPeek(){
			pair<int, int> cMinMax = minMax.back();
			vector<int> ret{cMinMax.first, cMinMax.second};
			return ret;
		}

		int pop(){
			int val = stack.back();
			stack.pop_back();
			minMax.pop_back();
			return val;
		}
};

int main(){
	MinMaxStack* mms = new MinMaxStack();
	
	mms->push(-1);
	mms->push(20);
	mms->push(200);

	cout << "Expected miin & max: -1, 200 .... Actual min & max: " << (mms->minMaxPeek())[0] << ", " << (mms->minMaxPeek())[1] << endl;

	mms->pop();

	cout << "Expected min & max: -1, 20 .... Actual min & max: " << (mms->minMaxPeek())[0] << ", " << (mms->minMaxPeek())[1] << endl;
	
	mms->pop();
	mms->push(-20);
	mms->push(250);

	cout << "Expected min & max: -20, 250 .... Actual min & max: " << (mms->minMaxPeek())[0] << ", " << (mms->minMaxPeek())[1] << endl;
	
	mms->pop();
	mms->pop();

	cout << "Expected min & max: -1, -1 .... Actual min & max: " << (mms->minMaxPeek())[0] << ", " << (mms->minMaxPeek())[1] << endl;
	return 0;
}

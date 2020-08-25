#include <iostream>
#include <vector>

using namespace std;

void goUp(int& crow, int& ccol, int& row, int& col, vector<vector<int>>& data, vector<int>& ret){			
	crow--;
	ccol++;
	while(crow>=0 && ccol < col){
		ret.push_back(data[crow][ccol]);
		crow--;
		ccol++;
	}
	crow++;
	ccol--;
}

void goDown(int& crow, int& ccol, int& row, int& col, vector<vector<int>>& data, vector<int>& ret){			
	crow++;
	ccol--;
	while(ccol>=0 && crow < row){
		ret.push_back(data[crow][ccol]);
		crow++;
		ccol--;
	}
	crow--;
	ccol++;
}

vector<int> zigzagTraverse(vector<vector<int>>& data){
	int row = data.size();
	int col = data[0].size();
	
	bool down = true;
	bool noIndicator = false;

	int crow = 0;
	int ccol = 0;
	vector<int> ret{data[0][0]};

	if(row==0)
		return data[row];

	while(crow < row && ccol < col){
		if(down){
			crow++;
			if(crow < row){
				ret.push_back(data[crow][ccol]);
				if(noIndicator)
					goDown(crow, ccol, row, col, data, ret);
				else
					goUp(crow, ccol, row, col, data, ret);
			}
			else{
				crow--;
				noIndicator = true;
			}	
	
			down = false;
		}
		else{
			ccol++;
			if(ccol < col){
				ret.push_back(data[crow][ccol]);
				if(noIndicator)
					goUp(crow, ccol, row, col, data, ret);
				else
					goDown(crow, ccol, row, col, data, ret);
			}
			else{
				ccol--;
				noIndicator = true;
			}

			down = true;
		}

		if(crow==row-1 && ccol==col-1)
			break;
	}
	return ret;
}

int main(){
	vector<int> t1{1, 3, 4, 10, 11};
	vector<int> t2{2, 5, 9, 12, 19};
	vector<int> t3{6, 8, 13, 18, 20};
	vector<int> t4{7, 14, 17, 21, 24};
	vector<int> t5{15, 16, 22, 23, 25};

	vector<vector<int>> test{t1, t2, t3, t4, t5};

	vector<int> ret = zigzagTraverse(test);
	
	cout << "Expected numbers in ascending order: ";
	for(int i : ret)
		cout << i << ", ";
	cout << endl;
	return 0;
}

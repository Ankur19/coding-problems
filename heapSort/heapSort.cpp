#include <iostream>
#include <vector>

using namespace std;

class Heap{
	public:
		vector<int> heap;
		Heap(vector<int> data){
			heap = data;
			int idx;
			for(int i = getLastParentIdx();i>=0;i--){
				idx = shiftDown(i);
				while(idx !=-1)
					idx = shiftDown(idx);
			}

		}
		int shiftDown(int idx){
			if(idx>=heap.size())
				return -1;
			int child1 = idx*2 + 1;
			int child2 = idx*2 + 2;
			int idxToCheck = child1 >=heap.size() ? -1 : child2>=heap.size() ? child1 : heap[child1] < heap[child2] ? child1 : child2;
			
			if(idxToCheck != -1 && heap[idx] > heap[idxToCheck])
				swap(idx, idxToCheck);

			return idxToCheck;

		}
		int remove(){
			swap(0, heap.size()-1);
			int ret = heap.back();
			heap.pop_back();
			int idx = shiftDown(0);
			while(idx!=-1)
				idx = shiftDown(idx);
			return ret;
		}
		int size(){
			return heap.size();
		}
	private:
		void swap(int i, int j){
			int temp = heap[i];
			heap[i] = heap[j];
			heap[j] = temp;
		}
		int getLastParentIdx(){
			return (heap.size()-2)/2;
		}

};


vector<int> heapSort(vector<int>& data){
	Heap* h = new Heap(data);
	vector<int> ret;
	while(h->size() > 0){
		ret.push_back(h->remove());
	}
	return ret;
}

int main(){
	vector<int> t1{-4,5,10,8,-10,-6,-4,-2,-5,3,5,-4,-5,-1,1,6,-7,-6,-7,8};

	vector<int> sorted = heapSort(t1);

	cout << "Expected sorted numbers: [";
	for(int i: sorted)
		cout << i << ", ";
	cout << "]" << endl;
	return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class MinHeap{
	public:
		vector<int> elem;
		MinHeap(vector<int> data){
			elem = vector<int>(data.begin(), data.end());
			for(int i=getLastParentIndex();i>=0;i--){
				minHeapify(i);
			}
		}
		void minHeapify(int index){
			bool swapped = false;
			int cIndex1 = 2*index;
			int cIndex2 = (2*index)+1;
			if(index<0 || cIndex1 >=elem.size())
				return;
			int temp = cIndex2 >= elem.size() ? cIndex1 : elem[cIndex1] < elem[cIndex2] ? cIndex1 : cIndex2;
			if(elem[temp] < elem[index]){
				swap(index, temp);
				swapped = true;
			}
			if(swapped)
				minHeapify(temp);
			return;
		}

		void shiftUp(int index){
			int parent = getParent(index);
			while(parent>=0 && elem[index]<elem[parent]){
				swap(index, parent);
				index = parent;
				parent = getParent(index);
			}
			return;
		}

		void insert(int val){
			elem.push_back(val);
			shiftUp(elem.size()-1);
			return;
		}

		int remove(){
			if(elem.size()==0)
				return -1;
			int temp = elem[0];
			elem[0] = elem[elem.size()-1];
			elem.pop_back();
			minHeapify(0);
			return temp;
		}
	private:
		int getLastParentIndex(){
			return (elem.size()-2)/2;
		}

		int getParent(int idx){
			return (idx-1)/2>=0 ? (idx-1)/2 : -1;
		}

		void swap(int i, int j){
			int temp = elem[i];
			elem[i] = elem[j];
			elem[j] = temp;
			return;
		}
};




int main(){
	vector<int> test{-823,
	        164,
	        48,
	        -987,
	        323,
	        399,
	        -293,
	        183,
	        -908,
	        -376,
	        14,
	        980,
	        965,
	        842,
	        422,
	        829,
	        59,
	        724,
	        -415,
	        -733,
	        356,
	        -855,
	        -155,
	        52,
	        328,
	        -544,
	        -371,
	        -160,
	        -942,
	        -51,
	        700,
	        -363,
	        -353,
	        -359,
	        238,
	        892,
	        -730,
	        -575,
	        892,
	        490,
	        490,
	        995,
	        572,
	        888,
	        -935,
	        919,
	        -191,
	        646,
	        -120,
	        125,
	        -817,
	        341,
	        -575,
	        372,
	        -874,
	        243,
	        610,
	        -36,
	        -685,
	        -337,
	        -13,
	        295,
	        800,
	        -950,
	        -949,
	        -257,
	        631,
	        -542,
	        201,
	        -796,
	        157,
	        950,
	        540,
	        -846,
	        -265,
	        746,
	        355,
	        -578,
	        -441,
	        -254,
	        -941,
	        -738,
	        -469,
	        -167,
	        -420,
	        -126,
	        -410,
	        59};

	MinHeap* m = new MinHeap(test);
	
	cout << "Elements before insert: [" ;
	for(int i : m->elem)
		cout << i << ", ";
	cout << "]" << endl << endl;

	m->insert(2);
	m->insert(22);
	m->insert(222);
	m->insert(2222);

	vector<int> sortedElements;
	cout << "Elements after insert: [" ;
        for(int i : m->elem){
		sortedElements.push_back(i);
                cout << i << ", ";
	}
        cout << "]" << endl << endl;

	sort(sortedElements.begin(), sortedElements.end());

	cout << "Elements after sort: [" ;
	for(int i : sortedElements){
		cout << i << ", ";
	}
	cout << "]" << endl << endl;
	
	cout << "Comparing removal of all elements." << endl;
	int remove;
	for(int i : sortedElements){
		remove = m->remove();
		if(i != remove)
			cout << "Failed..!! Expected: " << i << ", MinHeap remove() returned : " << remove << endl;
	}
	cout << "Done..!!" << endl;
	return 0;
}

/* DSA Fall 2016
 * Binary Heap
 */

#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;

template <typename Comparable>
class BinaryHeap{
public:
  vector<Comparable> heap;

  //constructor
  BinaryHeap<Comparable> (){
    vector<Comparable> heap;

  }

  void swap(int pos1, int pos2){
    Comparable temp = heap[pos1];
    heap[pos1] = heap[pos2];
    heap[pos2] = temp;
    //cool beans
  } 

  void printHeap(){
    //cout << heap.size() << endl;
    for(int i = 0; i < heap.size(); i++){
      cout << heap[i] << " ";
    }
    cout << endl;
  } 
  
  //insert
  void insert(Comparable elt){
    heap.push_back(elt);
    if (heap.size() == 1){
      return;}
    int pos = heap.size() - 1;
    int parentPos = (pos+1) / 2 - 1;
    while(heap[pos] < heap[parentPos]
	  && pos >= 0 && parentPos >= 0){
      swap(pos,parentPos);
      pos = parentPos;
      parentPos = (pos+1) / 2 - 1;
    }
  }

  int numChildren(int position){
    assert(position < heap.size());
    if(2*position+1 >= heap.size()){
      return 0;
    }
    if(2*(position + 1) < heap.size()){
      return 2;
    }
    return 1;
  }

  
  Comparable remove(){
    Comparable maxPriority = heap[0];
    heap.erase(heap.begin(), heap.begin() + 1);
    for(int i = 0; 2 * i + 1 < heap.size(); i++){
      int numChild = numChildren(i);
      if (numChild == 0){
	return maxPriority;
      }
      int childPos = 2 * i + 1;
      if(numChild == 2){
	if(heap[2*i+1] > heap[2*(i+1)]){
	  childPos = 2*(i+1);
	}
      }
      if(heap[childPos] < heap[i]){
	swap(i,childPos);
      }
    }
    //printHeap();
  }

};
/*int main(){
  BinaryHeap<int> jack = BinaryHeap<int>();
  jack.insert(17);
  jack.printHeap();
  jack.insert(38);
  jack.printHeap();
  jack.insert(5);
  jack.printHeap();
  jack.insert(226);
  jack.printHeap();
  jack.insert(34);
  jack.printHeap();
  jack.insert(236);
  jack.printHeap();
  jack.insert(26);
  jack.printHeap();
  jack.insert(52);
  jack.insert(9);
  jack.printHeap();
  for (int i = 0; i < 3; i++){
    jack.remove();
     }
     }*/
		

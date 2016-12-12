/* DSA Fall 2016
 * Binary Heap
 */

#include <iostream>
#include <vector>
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
    for(int i = 0; i < heap.size() - 1; i++){
      cout << heap[i] << ", ";
    }
    cout << heap[heap.size() - 1] << endl << flush;
  } 
  
  //insert
  void insert(Comparable elt){
    heap.push_back(elt);
    if (heap.size() == 1){
      return;}
    int pos = heap.size() - 1;
    int parentPos = (pos+1) / 2 - 1;

    while(heap[pos] > heap[parentPos]
	  && pos >= 0 && parentPos >= 0){
      swap(pos,parentPos);
      pos = parentPos;
      parentPos = (pos+1) / 2 - 1;
    }   
  }
  
  Comparable remove(){
    Comparable maxPriority = heap[0];
    heap.erase(heap.begin(), heap.begin() + 1);
    printHeap();
    //if(h
  }


};
		

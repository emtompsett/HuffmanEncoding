/* DSA
 * Heap for Huffman Encoding
 */

#include <iostream>
#include <vector>
#include <assert.h>
#include "HuffNode.cpp"
using namespace std;

class HuffHeap{
public:
  vector<HuffNode*> heap;

  HuffHeap(){
    vector<HuffNode*> heap;}

  void swap(int pos1, int pos2){
    HuffNode* temp = heap[pos1];
    heap[pos1] = heap[pos2];
    heap[pos2] = temp;
  }

  void printHeap(){
    for(int i = 0; i < heap.size(); i++){
      cout << heap[i] -> character << ": " << heap[i]->count<<" ";
    }
    cout << endl;
  }

  void insert(HuffNode* elt){
    heap.push_back(elt);
    if (heap.size() == 1)
      return;
    int pos = heap.size() - 1;
    int parentPos = (pos+1) / 2 - 1;
    while (pos > 0 && parentPos >= 0
	   && heap[pos]->count < heap[parentPos]->count){
      swap(pos, parentPos);
      pos = parentPos;
      parentPos = (pos + 1)/2 - 1;
    }
  }

  int numChildren(int position){
    assert(position < heap.size());
    if (2 * position + 1 >= heap.size()){
      return 0;
    }
    if (2 * (position + 1) < heap.size()){
      return 2;
    }
    return 1;
  }

  
  HuffNode* remove(){
    HuffNode* min = heap[0];
    heap.erase(heap.begin(), heap.begin()+1);
    for(int i = 0; 2 * i + 1 < heap.size(); i++){
      int numChild = numChildren(i);
      if (numChild == 0){
	return min;
      }
      int childPos = 2 * i + 1;
      if(numChild == 2){
	if(heap[2*i+1]->count > heap[2*(i+1)]->count){
	  childPos = 2*(i+1);
	}
      }
      if(heap[childPos]->count < heap[i]->count){
	swap(i,childPos);
      }
    }
    return min;
  }
};

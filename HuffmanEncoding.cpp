/* Huffman Encoding Starter Code
 * DSA
 * Fall 2016
 */

#include <iostream>
#include "HuffHeap.cpp"
//#include "HuffNode.cpp"

int main(){

  HuffHeap b = HuffHeap();
  cout<< "created the heap" << endl;
  b.insert(new HuffNode(2,'c'));
  b.insert(new HuffNode(1, 'a'));
  b.insert(new HuffNode(5, 'd'));
  b.insert(new HuffNode(1,'b'));
  b.printHeap();
  while (b.heap.size() > 1){
    b.printHeap();
    HuffNode* first = b.remove();
    HuffNode* second = b.remove();
    HuffNode* n = new HuffNode(first->count + second->count, '*');
    n->left = first;
    n->right = second;
    b.insert(n);
  }
  HuffNode* curr = b.heap[0];
  curr->showChildren();
}

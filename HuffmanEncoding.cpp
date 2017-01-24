/* Huffman Encoding Starter Code
 * DSA
 * Fall 2016
 */

#include <iostream>
#include "BinaryMinHeap.cpp"
#include "HuffNode.cpp"

int main(){
  //cout << "Enter the text to encrypt: ";
  //string message;
  //getline(cin, message);

  BinaryHeap<HuffNode> b = BinaryHeap<HuffNode>();
  b.insert(HuffNode(2,'c'));
  b.insert(HuffNode(1, 'a'));
  b.insert(HuffNode(5, 'd'));
  b.insert(HuffNode(1,'b'));
    
  b.printHeap();
  HuffNode first = b.remove();
  HuffNode second = b.remove();
  HuffNode n = HuffNode(first.count + second.count, '*');
  n.left = &first;
  n.right = &second;
  n.showChildren();
  b.insert(n);
  b.printHeap();
  //cout << b.size << endl;
    
}

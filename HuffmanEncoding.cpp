/* Huffman Encoding Starter Code
 * DSA
 * Fall 2016
 */

#include <iostream>
#include "BinaryHeap.cpp"
#include "HuffNode.cpp"

int main(){
  BinaryHeap<HuffNode> huff = BinaryHeap<HuffNode>();
  huff.insert(HuffNode(5, 'e'));
  huff.insert(HuffNode(6, 'r'));
  huff.insert(HuffNode(3, 's'));
  //cout << HuffNode(3, 's');
  huff.printHeap();
    
}

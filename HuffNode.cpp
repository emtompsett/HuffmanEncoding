/* Huffman Node
 * DSA
 * Fall 2016
 */
#include <iostream>
using namespace std;

class HuffNode{
public:
  int count;
  char character;
  HuffNode* left;
  HuffNode* right;

  HuffNode(int num, char c){
    count = num;
    character = c;
  }

  HuffNode(HuffNode l, HuffNode r){
    character = '*';
    count = l.count + r.count;
    left = &l;
    right = &r;
  }
  
  bool operator<(const HuffNode & h){
    return count < h.count;
  }
  bool operator<= (const HuffNode & h){
    return count <= h.count;
  }
  bool operator>(const HuffNode & h){
    return count > h.count;
  }
  bool operator>=(const HuffNode & h){
    return count >= h.count;
  }
  bool operator==(const HuffNode & h){
    return count == h.count;
  }
};

ostream& operator<<(ostream& os, const HuffNode& h)
{  
  os << h.character << ":" << h.count;
  return os;  
}  



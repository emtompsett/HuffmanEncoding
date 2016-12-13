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
  HuffNode left;
  HuffNode right;

  HuffNode(int num, char c){
    count = num;
    character = c;
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



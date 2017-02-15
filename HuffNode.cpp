/* Huffman Node
 * DSA
 * Fall 2016
 */
#include <iostream>
using namespace std;
//#include <vector>

class HuffNode{
public:
  int count;
  char character;
  HuffNode* left;
  HuffNode* right;

  HuffNode(int num, char c){
    count = num;
    character = c;
    left = nullptr;
    right = nullptr;
  }
    
  ~HuffNode(){
      delete left;
      delete right;
  }
  
  
  void showChildren(){
    cout << character << ":" << count << endl;
    if (character != '*'){
      return;
    }
    else{
      left->showChildren();
      right->showChildren();
    }
  }
 
      
  
  bool operator<(const HuffNode& h){
    return count < h.count;
  }
  bool operator<= (const HuffNode& h){
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



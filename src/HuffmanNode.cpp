#include "../headers/HuffmanNode.h"

// Huffman Node
RSSELI007::HuffmanNode::HuffmanNode() :
    letter('0'),
    frequency(0),
    leaf(false){}

// leaf node constructor
RSSELI007::HuffmanNode::HuffmanNode(char symbol, int freq) : 
    letter(symbol),
    frequency(freq),
    leaf(true),
    leftChild(nullptr),
    rightChild(nullptr){}

// non-leaf constructor
RSSELI007::HuffmanNode::HuffmanNode(int freq, HuffmanNode * left, HuffmanNode * right) : 
    frequency(freq),
    leaf(false){
        this->leftChild = std::shared_ptr<HuffmanNode>(left);
        this->rightChild = std::shared_ptr<HuffmanNode>(right);
    }

RSSELI007::HuffmanNode::~HuffmanNode(){}

// Overloads
bool RSSELI007::operator<(const HuffmanNode & lhs, const HuffmanNode & rhs){
    return lhs.frequency < rhs.frequency;
}
// Functions
bool RSSELI007::compareNode(const HuffmanNode & a, const HuffmanNode & b){
    return a.frequency > b.frequency;
}
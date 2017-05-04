#include "HuffmanNode.h"

RSSELI007::HuffmanNode::HuffmanNode() :
    letter('0'){
}

RSSELI007::HuffmanNode::HuffmanNode(char symbol) : 
    letter(symbol),
    leftChild(nullptr),
    rightChild(nullptr){
}

RSSELI007::HuffmanNode::~HuffmanNode(){

}
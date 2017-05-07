#ifndef HUFFMANNODE_H
#define HUFFMANNODE_H

#include <memory>

namespace RSSELI007{
    //Huffman Node
    class HuffmanNode{

        public: 
            char letter;
            int frequency;
            bool leaf;
            std::shared_ptr<HuffmanNode> leftChild;
            std::shared_ptr<HuffmanNode> rightChild;

            // constructors
            HuffmanNode(); // default
            HuffmanNode(char symbol, int freq); // leaf
            HuffmanNode(int freq, HuffmanNode * left, HuffmanNode * right); // non-leaf
            ~HuffmanNode();

            // copy constructor|assignment

            // move constructor|assignment
    };

    //overloads
    bool operator<(const HuffmanNode & lhs, const HuffmanNode & rhs);
    
    //Functions

    bool compareNode(const HuffmanNode & a, const HuffmanNode & b);
};

#endif
#ifndef HUFFMANNODE_H
#define HUFFMANNODE_H

#include <string>
#include <memory>
#include <iostream>

namespace RSSELI007{
    class HuffmanNode{

        public: 
            char letter;
            std::shared_ptr<HuffmanNode> leftChild;
            std::shared_ptr<HuffmanNode> rightChild;

            HuffmanNode();
            HuffmanNode(char symbol);
            ~HuffmanNode();
    };
};

#endif
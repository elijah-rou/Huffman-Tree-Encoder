#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H

#include <unordered_map>
#include <queue>
#include <string>
#include <vector>
#include "HuffmanNode.h"


namespace RSSELI007{
    // symbol-frequency map
    typedef std::unordered_map<char, int> symFreq_map;

    // priority queue of huff nodes
    typedef std::priority_queue<HuffmanNode*> huffNode_queue;

    // symbol-code map
    typedef std::unordered_map<char, std::string> symCode_map;

    // string vector
    typedef std::vector<std::string> str_vector;

    class HuffmanTree{
        private:
            // members
            //std::string bitCodes;
            str_vector inputText;
            symFreq_map symbolFreq;
            huffNode_queue nodes;
            symCode_map codes;

            // methods

            // read text file into a map
            bool read(std::string inputFile);

            // generate a priority queue of HuffmanNodes based on frequency
            void createQueue();

            // create trie from queue of HuffmanNodes
            void growTrie();

            // generates code map
            void genCodes(std::shared_ptr<HuffmanNode> node, std::string code);
            

        public:
            // members
            std::shared_ptr<HuffmanNode> rootNode;

            // constructors
            HuffmanTree();
            HuffmanTree(std::string & file);
            ~HuffmanTree();

            // copy constructor|assignment
            HuffmanTree(const HuffmanTree &obj);
            HuffmanTree & operator=(const HuffmanTree &obj);

            // move constructor|assignment
            HuffmanTree(HuffmanTree &&obj);
            HuffmanTree & operator=(HuffmanTree &&obj);

            // methods

            // save to an output file
            void save(std::string outputFile);


    };
};

#endif
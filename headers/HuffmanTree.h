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
    typedef std::priority_queue<HuffmanNode*, std::vector<HuffmanNode*>, decltype(&compareNode)> huffNode_queue;

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
            symCode_map codes;

            // methods

            // read text file into a map
            bool read(std::string inputFile);

            // create trie from queue of HuffmanNodes using priority queue
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
            //getters
            str_vector getInputText(void);
            symFreq_map getFreqMap(void);
            symCode_map getCodeMap(void);

            // save to an output file
            void save(std::string outputFile);


    };
};

#endif
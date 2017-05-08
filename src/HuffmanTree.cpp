#include "../headers/HuffmanTree.h"
#include <fstream>
#include <iostream>
#include <numeric>

/*
    HUFFMANTREE
*/
// Constructors
RSSELI007::HuffmanTree::HuffmanTree() : grown(false){}

RSSELI007::HuffmanTree::HuffmanTree(std::string & file){
	if(read(file)){
	    growTrie();
        genCodes(this->rootNode, "");
        this->grown = true;
    }
    else{
        this->grown = false;
    }
}

RSSELI007::HuffmanTree::~HuffmanTree(){
	rootNode = nullptr;
}

// Methods
// read in an input file, storing the text by line and each character in a umap
bool RSSELI007::HuffmanTree::read(std::string inputFile){
    std::ifstream file("bin/input/" + inputFile);
    std::string line;
    if(file.is_open()){
        while (getline(file, line)) {
            this->inputText.push_back(line);
            // for each symbol check map and adjust frequency
            for (char letter : line) {
                if (symbolFreq.find(letter) != symbolFreq.end()){
                    symbolFreq.at(letter) += 1;
                } 
                else{
                    symbolFreq.insert({letter, 1});
                }
            }
		}
		file.close();
        return true;
    }
    else return false;
}

 void RSSELI007::HuffmanTree::growTrie(){

    // build priority queue
    huffNode_queue nodes{RSSELI007::compareNode};
    for (const auto pair : this->symbolFreq) {
	    nodes.push(new HuffmanNode(pair.first, pair.second));
    }

     // loop through queue until 1 node left
     while (nodes.size() > 1){
	    // obtain 2 minimum freq nodes
		RSSELI007::HuffmanNode * leftNode = nodes.top();
		nodes.pop();
		RSSELI007::HuffmanNode * rightNode = nodes.top();
		nodes.pop();

        // create parent node and push to queue
		nodes.push(new HuffmanNode(leftNode->frequency + rightNode->frequency, leftNode, rightNode));
	}
    // assign last node in queue to root
	this->rootNode = std::shared_ptr<HuffmanNode>(nodes.top());
 }

// recursive function to print codes for symbols
 void RSSELI007::HuffmanTree::genCodes(std::shared_ptr<HuffmanNode> node, std::string code){
     // base case
    if (!node){
        return;
    }
    // if the node is a leaf, then assign code
    if (node->leaf){
        this->codes.insert({node->letter, code});
    }
    genCodes((node->leftChild), code + "0");
    genCodes((node->rightChild), code + "1");
 }

 void RSSELI007::HuffmanTree::save(std::string fileName){
     // write file
	std::ofstream file("bin/output/"+fileName, std::ios::out | std::ios::binary);
	if (file.good()){
		std::string str;
		str = std::accumulate(begin(this->inputText), end(this->inputText), str);
		file.write(str.c_str(), str.size());
		file.close();
	}
	size_t index;

	// write code header
	index = fileName.find('.');
	if (index != std::string::npos) {
        file.open("bin/output/"+fileName.substr(0, index)+".hdr");
	}
    else{
        file.open("bin/output/"+fileName+".hdr");
    }
	if (file.is_open()){
        file << this->codes.size() << std::endl;
		for(const auto pair : this->codes){
			file << pair.first << '\t' << pair.second << std::endl;
		}
		file.close();
	}

    // write frequency map file
    index = fileName.find('.');
	if (index != std::string::npos) {
        file.open("bin/output/"+fileName.substr(0, index)+"-freq");
	}
    else{
        file.open("bin/output/"+fileName+"-freq");
    }
	if (file.is_open()){
        file << this->symbolFreq.size() << std::endl;
		for(const auto pair : this->symbolFreq){
			file << pair.first << '\t' << pair.second << std::endl;
		}
		file.close();
	}
}

// getters
RSSELI007::str_vector RSSELI007::HuffmanTree::getInputText(void){
    return this->inputText;
}

RSSELI007::symFreq_map RSSELI007::HuffmanTree::getFreqMap(void){
    return this->symbolFreq;
}

RSSELI007::symCode_map RSSELI007::HuffmanTree::getCodeMap(void){
    return this->codes;
}
 


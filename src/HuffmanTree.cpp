#include "../headers/HuffmanTree.h"
#include <fstream>
#include <iostream>
#include <numeric>

/*
    HUFFMANTREE
*/
// Constructors
RSSELI007::HuffmanTree::HuffmanTree(){}

RSSELI007::HuffmanTree::HuffmanTree(std::string & file){
	if(read(file)){
        createQueue();
	    growTrie();
        genCodes(this->rootNode, "");
    }
}

RSSELI007::HuffmanTree::~HuffmanTree(){
	rootNode = nullptr;
}

// Methods
// read in an input file, storing the text by line and each character in a umap
bool RSSELI007::HuffmanTree::read(std::string inputFile){
    //std::cout << "STARt" << std::endl;
    std::ifstream file("bin/input/" + inputFile);
    std::string line;
    if(file.is_open()){
        //std::cout << "file open" << std::endl;
        while (getline(file, line)) {
            this->inputText.push_back(line);
            for (char letter : line) {
                //std::cout << letter << std::endl;
                if (symbolFreq.find(letter) != symbolFreq.end()){
                    symbolFreq.at(letter) += 1;
                } 
                else{
                    symbolFreq.insert({letter, 1});
                }
            }
		}
		file.close();
        /*
        for(auto k : symbolFreq){
            std::cout << k.first << std::endl;
            std::cout << k.second << std::endl;
        }
        */
        //std::cout << "WAOW" << std::endl;
        return true;
    }
    else return false;
}

void RSSELI007::HuffmanTree::createQueue(){
    for (const auto pair : this->symbolFreq) {
		this->nodes.push(new HuffmanNode(pair.first, pair.second));
    }
 }

 void RSSELI007::HuffmanTree::growTrie(){
     // loop until 1 node left
     //std::cout << std::to_string(this->nodes.size()) << std::endl;
     while (this->nodes.size() > 1){
	    // obtain 2 minimum freq nodes
        //std::cout << "sigh" << std::endl;
		RSSELI007::HuffmanNode * leftNode = this->nodes.top();
		nodes.pop();
		RSSELI007::HuffmanNode * rightNode = this->nodes.top();
		nodes.pop();

        // create parent node and push to queue
		nodes.push(new HuffmanNode(leftNode->frequency + rightNode->frequency, leftNode, rightNode));
	}
	this->rootNode = std::shared_ptr<HuffmanNode>(this->nodes.top());
 }

// check is leaf

// recursive function to print codes for symbols
 void RSSELI007::HuffmanTree::genCodes(std::shared_ptr<HuffmanNode> node, std::string code){
    if (!node){
        return;
    }
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

    // write frequency file
    size_t index = fileName.find('.');
	if (index != std::string::npos) {
		fileName = "bin/output/" + fileName.substr(0, index) + "-freq.txt";
	}
	file.open(fileName);
	if (file.is_open()){
        file << this->symbolFreq.size() << std::endl;
		for(const auto pair : this->symbolFreq){
			file << pair.first << '\t' << pair.second << std::endl;
		}
		file.close();
	}
	
	// write header
    //std::cout << "sigh" << std::endl;
	index = fileName.find('-');
	if (index != std::string::npos) {
		fileName = fileName.substr(0, index) + ".hdr";
	}
    //std::cout << fileName << std::endl;
	file.open(fileName);
    //std::cout << "sigh" << std::endl;
	if (file.is_open()){
        //std::cout << "sigh" << std::endl;
        file << this->codes.size() << std::endl;
		for(const auto pair : this->codes){
			file << pair.first << '\t' << pair.second << std::endl;
		}
		file.close();
	}
}
 


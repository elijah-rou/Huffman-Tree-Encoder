#include "../headers/HuffmanTree.h"
#include <iostream>

int main(int argc, char ** argv){
    if (argc >= 2){
		//create tree
		std::string inputFile(argv[1]);
		RSSELI007::HuffmanTree tree(inputFile);
		std::string outputFile(argv[2]);
		tree.save(outputFile);
	}else{
		std::cout << "Error" << std::endl;
	}
}
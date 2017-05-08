#include "../headers/HuffmanTree.h"
#include <iostream>

int main(int argc, char ** argv){
    if (argc >= 3){
		//create tree
		std::string inputFile(argv[1]);
		RSSELI007::HuffmanTree tree(inputFile);
		if(tree.grown){
			std::string outputFile(argv[2]);
			tree.save(outputFile);
			std::cout << "Compression successful. Outputted to bin/" << std::endl;
		}
		else{
			std::cout << "Error: Invalid input file" << std::endl;
		}
	
	}else{
		std::cout << "Error: Incorrect arguments, please try again" << std::endl;
	}
}
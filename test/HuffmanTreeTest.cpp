#define CATCH_CONFIG_MAIN

#include <iostream>
#include "../headers/catch.hpp"
#include "../headers/HuffmanNode.h"
#include "../headers/HuffmanTree.h"

using namespace RSSELI007;

std::string file("test.txt");
HuffmanTree tree(file);

TEST_CASE("Symbol map generation"){
    std::cout << "Checking input text size = 1" << std::endl;
    REQUIRE(tree.getInputText().size() == 1);
    std::cout << "PASSED" << std::endl;
    std::cout << "Checking freq-map size = 8" << std::endl;
    REQUIRE(tree.getFreqMap().size() ==  8);
    std::cout << "PASSED" << std::endl;
    std::cout << "Checking 'T' maps to 1" << std::endl;
    REQUIRE(tree.getFreqMap().at('T') == 1);
    std::cout << "PASSED" << std::endl;
    std::cout << "Checking ' ' maps to 3" << std::endl;
    REQUIRE(tree.getFreqMap().at(' ') == 3);
    std::cout << "PASSED" << std::endl;
}

TEST_CASE("Queue generation"){
    std::cout << "Checking root is not leaf" << std::endl;
    REQUIRE(!tree.rootNode->leaf);
    std::cout << "PASSED" << std::endl;
}
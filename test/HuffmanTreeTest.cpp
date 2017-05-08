#define CATCH_CONFIG_MAIN

#include <iostream>
#include "../headers/catch.hpp"
#include "../headers/HuffmanNode.h"
#include "../headers/HuffmanTree.h"

using namespace RSSELI007;

std::string file("test.txt");
HuffmanTree tree(file);

TEST_CASE("Symbol-Freq map generation", "[node, freqMap]"){
    std::cout << std::endl << "Symbol-Freq map generation TEST" << std::endl;
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

TEST_CASE("Huffman coding", "[tree]"){
    // tests that format is fine and priority queue worked
    SECTION("Tree Formation"){
        std::cout << std::endl << "Tree generation TEST" << std::endl;
        std::cout << "Checking root is not leaf" << std::endl;
        REQUIRE(!tree.rootNode->leaf);
        std::cout << "PASSED" << std::endl;
        std::cout << "Checking root frequency = total frequency" << std::endl;
        REQUIRE(tree.rootNode->frequency == 14);
        std::cout << "PASSED" << std::endl;
    }
    SECTION("Code Assignment"){
        // tests that tree is formed correctly with the right codes
        std::cout << std::endl << "Code generation TEST" << std::endl;
        std::cout << "Checking code table is non-empty" << std::endl;
        REQUIRE(!tree.getCodeMap().empty());
        std::cout << "PASSED" << std::endl;
        std::cout << "Checking code table is corrct size" << std::endl;
        REQUIRE(tree.getCodeMap().size() == 8);
        std::cout << "PASSED" << std::endl;
        std::cout << "Checking codes are correct" << std::endl;
        REQUIRE(tree.getCodeMap()[' '] == "00");
        REQUIRE(tree.getCodeMap()['s'] == "01");
        REQUIRE(tree.getCodeMap()['t'] == "101");
        REQUIRE(tree.getCodeMap()['h'] == "1000");
        REQUIRE(tree.getCodeMap()['T'] == "1001");
        REQUIRE(tree.getCodeMap()['i'] == "110");
        REQUIRE(tree.getCodeMap()['e'] == "1110");
        REQUIRE(tree.getCodeMap()['a'] == "1111");
        std::cout << "PASSED" << std::endl;
    }
}
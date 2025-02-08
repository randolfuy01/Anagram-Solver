#include "anagram_solver.h"

int main() {
    std::string file;
    std::string word;

    std::cout << "\nFile to parse: ";
    std::cin >> file;

    std::cout << "\nWord to find anagrams of: ";
    std::cin >> word;

    std::cout << "\nInstantiating solver";
    Anagram_Solver solver = Anagram_Solver(file, word);

    std::cout << "\nParsing the text";
    solver.parse_text();
}
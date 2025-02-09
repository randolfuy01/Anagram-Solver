#include "anagram_solver.h"

int main() {
    std::string file;
    std::string word;

    std::cout << "\nFile to parse: ";
    std::cin >> file;

    std::cout << "\nWord to find anagrams of: ";
    std::cin >> word;

    std::cout << "\nInstantiating solver\n";
    Anagram_Solver solver = Anagram_Solver(file, word);

    std::cout << "Parsing the text\n";
    solver.parse_text();

    solver.solver();
    
}

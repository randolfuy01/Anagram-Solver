#include "anagram_solver.h"
#include <chrono>

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

    auto start_time = std::chrono::high_resolution_clock::now();

    solver.solver();

    auto end_time = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);

    std::cout << "Elapsed time: " << duration.count() << " milliseconds" << std::endl;

    return 0;
}

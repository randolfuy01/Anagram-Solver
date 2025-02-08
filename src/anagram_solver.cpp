#include "anagram_solver.h"

int Anagram_Solver::parse_text() {
    std::ifstream file(Anagram_Solver::file_name);
    std::string str;

    if (!file.is_open()) {
        std::cerr << "\nCannot open the file\n";
        return 0;
    }

    while (std::getline(file, str)) {

        if (file.fail()) {
            std::cerr << "\nError while parsing the file\n";
            file.close();
            return 0;
        }

        // Ensure only alphabetical words
        bool alph = true;
        for (char c: str) {
            if (!std::isalpha(c)) {
                alph = false;
            }
        }

        if (alph) {
            Anagram_Solver::bag_of_words.push_back(str);
        }
    }

    std::cout << "\nFinished parsing all words from file";
    std::cout << "\nNumber of words parsed: " << Anagram_Solver::bag_of_words.size();
    std::cout << "\nExample text: " << Anagram_Solver::bag_of_words[100] << "\n";
    return 1;
}
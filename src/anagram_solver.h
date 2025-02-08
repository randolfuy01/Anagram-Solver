#include <fstream>
#include <string>
#include <iostream>
#include <vector>

/*
    Anagram means that you are able to reconstruct a word using the same amount
    of letter regardless of the location. In this case we can say that "aab" is an anagram of "aba".
    Furthermore the restriction is that there are x amount of words in the english language. The goal is
    to construct x amount of words maximizing the score possible based on such an algorithm.
*/

/**
 * Class for solving the classical game of anagrams for imesssage games
 *
 */
class Anagram_Solver
{
private:
    std::vector<std::string> bag_of_words;

public:
    std::string file_name;
    std::string anagram;
    int anagram_length;

    /**
     * Constructor for creating an instance of this class
     */
    Anagram_Solver(std::string file, std::string word) : file_name(file), anagram(word), anagram_length(word.length()) {}

    /**
     * @brief Parse every word in the file
     *
     * @return 1 on success, 0 on failure. 1 means we were able to successfullly parse the txt file and separate out the words
     */
    int parse_text();

    /**
     * @brief Individual parse in order to determine correct number of letters
     *
     * @param word: The word we are trying to determine number of characters
     * @return 1 on success, 0 on failure. 1 means we were able to successfully identify correct lettering for that specific word
     */
    int aggregate_letters(std::string *word);

    /**
     * @brief Solves what words from the list can be created from the original word based on its letters
     */
    std::vector<std::string> solver();
};

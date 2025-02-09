#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <map>

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
    std::vector<std::string> words;

public:
    std::string file_name;
    std::string anagram;
    std::unordered_map<char, int> anagram_letters;
    int anagram_length;

    /**
     * Constructor for creating an instance of this class
     */
    Anagram_Solver(std::string file, std::string word) : file_name(file), anagram(word), anagram_length(word.length())
    {
        for (char c : anagram)
        {
            const auto &found = anagram_letters.find(c);
            if (found == anagram_letters.end())
            {
                anagram_letters.insert({c, 1});
            }
            else
            {
                anagram_letters[c]++;
            }
        }
    }

    /**
     * @brief Parse text in the file
     *
     * @return 1 on success, 0 on failure. 1 means we were able to successfullly parse the txt file and separate out the words
     */
    int parse_text();

    /**
     * @brief Individual parse in order to determine correct number of letters
     *
     * @param word: The word we are trying to determine number of characters
     * @return 1 on success, 0 on failure. 1 means that all characters found within the word can be created from the letters
     */
    bool character_validator(std::string word);

    /**
     * @brief Solves what words from the list can be created from the original word based on its letters
     */
    void solver();
};

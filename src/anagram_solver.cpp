#include "anagram_solver.h"

int Anagram_Solver::parse_text()
{
    std::ifstream file(Anagram_Solver::file_name);
    std::string str;

    if (!file.is_open())
    {
        std::cerr << "\nCannot open the file\n";
        return 0;
    }

    while (std::getline(file, str))
    {

        if (file.fail())
        {
            std::cerr << "\nError while parsing the file\n";
            file.close();
            return 0;
        }

        // Ensure only alphabetical words
        bool alph = true;
        for (char c : str)
        {
            if (!std::isalpha(c))
            {
                alph = false;
            }
        }

        if ((alph) && (str.length() <= anagram_length) && (str.length() > 3))
        {
            Anagram_Solver::words.push_back(str);
        }
    }

    std::cout << "Finished parsing all words from file\n";
    return 1;
}

bool Anagram_Solver::character_validator(std::string word)
{

    std::map<char, int> hash;

    for (const auto &letter : word)
    {
        auto it = hash.find(letter);
        if (it == hash.end())
        {
            hash.insert({letter, 1});
        }
        else
        {
            hash[letter]++;
        }
    }

    for (std::unordered_map<char, int>::const_iterator it = anagram_letters.cbegin(); it != anagram_letters.cend(); ++it)
    {
        auto found = hash.find(it->first);
        if (found != hash.end() || (found->second > it->second))
        {
            return false;
        }
    }

    return true;
}

void Anagram_Solver::solver()
{
    std::cout << "\nFinding all matching criterias" << std::endl;
    int counter = 0;
    for (const auto &word : Anagram_Solver::words)
    {
        counter += 1;
        std::cout << word << std::endl;
        if (!Anagram_Solver::character_validator(word))
        {
            Anagram_Solver::words.erase(std::remove(Anagram_Solver::words.begin(), Anagram_Solver::words.end(), word), Anagram_Solver::words.end());
        }
        else
        {
            std::cout << word << std::endl;
        }
        if (counter == 15) {
            break;
        }
    }
}
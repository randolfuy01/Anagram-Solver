#include "anagram_solver.h"
#include <iostream>
#include <fstream>
#include <cctype>
#include <unordered_map>
#include <vector>
#include <algorithm>

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

        bool alph = true;
        for (char c : str)
        {
            if (!std::isalpha(c))
            {
                alph = false;
            }
        }

        if ((alph) && (str.length() >= 3 && str.length() <= anagram_length))
        {
            str = strip_non_alphanumeric(str);
            std::cout << str << std::endl;
            Anagram_Solver::words.push_back(str);
        }
    }

    std::cout << "Finished parsing all words from file\n";
    return 1;
}

bool Anagram_Solver::character_validator(std::string word)
{
    std::unordered_map<char, int> word_hash;
    for (const auto &letter : word)
    {
        word_hash[letter]++;
    }

    for (const auto &key : word_hash)
    {
        auto found = Anagram_Solver::anagram_hash.find(key.first);
        if (found == Anagram_Solver::anagram_hash.end() || key.second > found->second)
        {
            return false;
        }
    }

    return true;
}

void Anagram_Solver::solver()
{
    std::cout << "Starting solver\n";
    std::vector<std::string> valid;
    for (const auto &word : Anagram_Solver::words)
    {
        if (Anagram_Solver::character_validator(word))
        {
            valid.push_back(word);
        }
    }

    std::cout << "Sorting words in descending length\n";
    std::sort(valid.begin(), valid.end(), [](const std::string &a, const std::string &b)
              { return a.length() > b.length(); });

    std::cout << "\nPrinting valid words: \n"
              << std::endl;
    for (const auto &word : valid)
    {
        std::cout << word << "\n";
    }
}

std::string strip_non_alphanumeric(const std::string &input)
{
    std::string result;
    for (char c : input)
    {
        if (std::isalnum(c))
        {
            result.push_back(c);
        }
    }
    return result;
}
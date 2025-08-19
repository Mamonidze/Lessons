#include <iostream>
#include <vector>

bool arrayStringsAreEqual(const std::vector<std::string>& word1, const std::vector<std::string>& word2);

int main()
{
    const std::vector<std::string>& word1{"ab","a"};
    const std::vector<std::string>& word2{"ab","a"};

    std::cout << arrayStringsAreEqual(word1, word2);
}

bool arrayStringsAreEqual(const std::vector<std::string>& word1, const std::vector<std::string>& word2)
{
    std::string FirstWord{};
    std::string SecondWord{};

    for (auto word : word1)
    {
        FirstWord += word;
    }
    for (auto word : word2)
    {
        SecondWord += word;
    }

    if (FirstWord == SecondWord)
    {
        return true;
    }
    return false;
}

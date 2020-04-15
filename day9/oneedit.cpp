/* 
Sample Problem
Write a function to return if two words are exactly "one edit" away, where an edit is:

    Inserting one character anywhere in the word (including at the beginning and end)
    Removing one character
    Replacing exactly one character
*/

#include <iostream>

bool isOneEditAway(std::string& correctWord, std::string& offWord)
{
    size_t count = 0;

    int8_t diff = correctWord.size() - offWord.size();

    if (diff < -1 || diff > 1) {
        return false;
    }

    size_t correctSize = correctWord.size();
    size_t offWordSize = offWord.size();

    size_t correctIndex = 0;
    size_t offWordIndex = 0;

    while (offWordIndex < offWordSize || correctIndex < correctSize) {
        if (correctWord.at(correctIndex) != offWord.at(offWordIndex)) {
            count++;

            if (diff == 0) {
                correctIndex++;
                offWordIndex++;
            } else if (diff == 1) {
                correctIndex++;
            } else {
                offWordIndex++;
            }
        } else {
            correctIndex++;
            offWordIndex++;
        }

        if (count > 1) {
            return false;
        }
    }

    return (count < 2);
}

int main()
{
    std::string correctWord = "abde";
    std::string offWord = "abc";

    std::cout << std::boolalpha << isOneEditAway(correctWord, offWord) << "\n";

    correctWord = "woahdude";
    offWord = "wohdude";

    std::cout << std::boolalpha << isOneEditAway(correctWord, offWord) << "\n";

    correctWord = "mannn";
    offWord = "mannn";

    std::cout << std::boolalpha << isOneEditAway(correctWord, offWord) << "\n";

    return 0;
}

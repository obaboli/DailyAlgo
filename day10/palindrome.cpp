/*
 Given a non-empty string s, you may delete at most one character. Judge whether you can make it a palindrome.

Example 1:

Input: "aba"
Output: True

Example 2:

Input: "abca"
Output: True
Explanation: You could delete the character 'c'.
*/

#include <iostream>

bool isPalindrome(std::string& str)
{

    auto begin = 0;
    auto end = str.size() - 1;

    while (begin < end) {
        if (str[begin] != str[end]) {
            return false;
        }
        begin++;
        end--;
    }

    return true;
}

//Death by if
bool isPalindromeD(std::string& str)
{

    auto begin = 0;
    auto end = str.size() - 1;
    bool checked = false;

    while (begin < end) {
        if (str[begin] != str[end]) {
            if (checked) {
                return false;
            }

            if ((begin + 1) >= end || (end - 1) <= begin) {
                return true;
            } else if (str[begin + 1] == str[end]) {
                checked = true;
                begin++;
            } else if (str[end - 1] == str[begin]) {
                checked = true;
                end--;
            } else {
                return false;
            }

        } else {
            begin++;
            end--;
        }
    }

    return true;
}

int main()
{

    std::string str("aabbaa");

    std::cout << std::boolalpha << isPalindrome(str) << "\n";
    std::cout << std::boolalpha << isPalindromeD(str) << "\n";

    return 0;
}

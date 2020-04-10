#include <algorithm>
#include <cstring>
#include <iostream>

void reverseString(char* str)
{
    size_t low = 0;
    size_t high = strlen(str) - 1;

    while (low < high) {
        std::swap(str[low], str[high]);
        low++;
        high--;
    }
}

void hexStringToBytes(char* string, uint8_t* bytes, size_t size)
{

    //needs some error checking in real life
    for (size_t i = 0; i < size; i++) {
        sscanf(string, "%02hhX", &bytes[i]);
        string += 2;
    }
}

void byteArrayToHexString(char* string, uint8_t* bytes, size_t size)
{

    //needs some error checking in real life
    for (size_t i = 0; i < size; i++) {
        //return number of character written without null terminator
        string += snprintf(string, 3, "%02X", bytes[i]);
    }
}

char* my_strstr(char* str1, char* str2)
{
    size_t strlen1 = strlen(str1);
    size_t strlen2 = strlen(str2);

    for (size_t i = 0; i < strlen1; i++) {
        if (str1[i] == str2[0]) {
            size_t j = 1;
            for (; j < strlen2; j++) {
                if ((i + j) >= strlen1) {
                    return nullptr;
                }

                if (str1[i + j] != str2[j]) {
                    break;
                }
            }

            if (j == strlen2) {
                return &str1[i];
            }
        }
    }
    return nullptr;
}

//returns number of unique characters
uint8_t countArray(uint8_t* arr, char* str)
{
    size_t size = strlen(str);
    uint8_t count = 0;

    for (size_t i = 0; i < size; i++) {
        arr[str[i] - 'a']++;
        if (arr[str[i] - 'a'] == 1) {
            count++;
        }
    }

    return count;
}

void compressString(uint8_t* arr, char* newString)
{
    size_t strIndex = 0;
    for (size_t i = 0; i < 26; i++) {
        if (arr[i] > 0) {
            newString[strIndex++] = i + 'a';
            newString[strIndex++] = arr[i] + '0';
        }
    }

    newString[strIndex] = '\0';
}

int main()
{

    //Problem 1:
    // reverse string in place
    char test[] = "whydidthathappentoyou";
    std::string testS("whydidthathappentoyou");

    reverseString(test);
    std::reverse(testS.begin(), testS.end());

    if (testS == test) {
        std::cout << "TRUE"
                  << "\n";
    } else {
        std::cout << "FALSE"
                  << "\n";
    }

    //Problem 2:
    // hex string to byte array + byte array to hex string
    char hexString[] = "0F12345E68";
    size_t size = strlen(hexString) / 2;
    uint8_t byteArray[size] = { 0 };

    hexStringToBytes(hexString, byteArray, size);

    size_t stringSize = sizeof(byteArray) * 2 + 1;
    char hexStringOutput[stringSize];

    byteArrayToHexString(hexStringOutput, byteArray, size);

    if (strncmp(hexStringOutput, hexString, stringSize) == 0) {
        std::cout << "TRUE"
                  << "\n";
    } else {
        std::cout << "FALSE"
                  << "\n";
    }

    //Problem 3:
    // strstr

    char s1[] = "Fun with Str";
    char s2[] = "Str";

    char* p = my_strstr(s1, s2);

    if (p != nullptr) {
        std::cout << "TRUE"
                  << "\n";
    } else {
        std::cout << "FALSE"
                  << "\n";
    }

    //Problem 4:
    // compress string to number of occurrence and letter
    char s3[] = "abejzabaabbbbol";
    uint8_t charCount[26] = { 0 };
    size_t count = countArray(charCount, s3) + 1;

    char s4[count] = "";

    compressString(charCount, s4);

    std::cout << s4 << "\n";

    return 0;
}

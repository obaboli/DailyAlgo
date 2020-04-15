/*
https://en.wikipedia.org/wiki/Look-and-say_sequence
*/

#include <iostream>

void outputValue(std::string& seq)
{

    size_t count = 1;
    std::string copy = "";
    size_t i = 1;

    for (; i < seq.size(); i++) {
        if (seq[i] == seq[i - 1]) {
            count++;
        } else {
            copy.push_back(count + '0');
            copy.push_back(seq.at(i - 1));
            count = 1;
        }
    }

    copy.push_back(count + '0');
    copy.push_back(seq.at(i - 1));

    std::cout << copy << "\n";

    // copy new string back
    seq = copy;
}

void lookAndSay(size_t value)
{

    if (value == 0) {
        return;
    }

    //Base Case
    std::string seq = "1";
    std::cout << seq << "\n";

    for (size_t i = 1; i < value; i++) {
        outputValue(seq);
    }
}

int main()
{

    lookAndSay(10);

    return 0;
}

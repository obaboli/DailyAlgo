//https://adventofcode.com/2019/day/2

#include <fstream>
#include <vector>
#include <iostream>
#include <sstream>

void program_print(const std::vector<uint32_t> &program) {
    for (std::size_t i = 0; i < program.size(); i++) {
        if( i % 4 == 0 && i != 0) {
            std::cout << "\n";
        }

        std::cout << program.at(i) << " ";
    }
}

uint32_t program_output(std::vector<uint32_t> program, uint32_t noun, uint32_t value) {
    program.at(1) = noun;
    program.at(2) = value;

    for (std::size_t i = 0; i < program.size(); i += 4) {
        switch(program.at(i)) {
            case 1: 
                program.at(program.at(i + 3)) = program.at(program.at(i + 1)) + program.at(program.at(i + 2));
                break;
            case 2:
                program.at(program.at(i + 3)) = program.at(program.at(i + 1)) * program.at(program.at(i + 2));
                break;

            default:
                return program.at(0);
        }
    }
    
    return program.at(0);
}

uint32_t find_none_verb(const std::vector<uint32_t> &program, uint32_t expected_output) {
    for(std::size_t noun = 0; noun < 99; noun++) {
        for(std::size_t verb = 0; verb < 99; verb++) {
            if(program_output(program, noun, verb) == expected_output) {
                return 100 * noun + verb;
            }            
        }
    }
    return 0;
}

int main() {
    std::ifstream file("input.txt");
    std::vector<uint32_t> program;
    std::stringstream ss;

    if (file) {
        ss << file.rdbuf();    
        file.close();
    }

    uint32_t i = 0;
    while (ss >> i) {
        program.push_back(i);    
        if (ss.peek() == ',')
            ss.ignore();
    }

    std::cout << program_output(program, 12, 2) << "\n";
    std::cout << find_none_verb(program, 19690720) << "\n";

}

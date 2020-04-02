// convert string to float aka std::stof

#include <iostream>
#include <math.h>

float stringToFloat(std::string &input) {

  bool isNegative = false;
  bool postDecimal = false;
  std::string::iterator it = input.begin();

  float preDecimalValue = 0.0f;
  float postDecimalValue = 0.0f;
  uint8_t postDecimalCount = 0;

  if (*it == '-') {
    isNegative = true;
    std::advance(it, 1);
  }

  for (; it != input.end(); ++it) {
    if (*it == '.' && !postDecimal) {
      postDecimal = true;
    } else if (std::isdigit(*it)) {
      if (postDecimal) {
        postDecimalValue = postDecimalValue * 10 + (*it - '0');
        postDecimalCount++;
      } else {
        preDecimalValue = preDecimalValue * 10 + (*it - '0');
      }
    } else {
      // could expand this so an invalid char is just skipped and number is
      // restarted
      break;
    }
  }

  if (postDecimalCount > 0) {
    postDecimalValue = postDecimalValue * pow(10, -(postDecimalCount));
    preDecimalValue += postDecimalValue;
  }

  if (isNegative) {
    preDecimalValue *= -1;
  }

  return preDecimalValue;
}

int main() {

  std::string input = "-123.45";
  // hard way aka my way
  std::cout << stringToFloat(input) << "\n";
  // easy way
  std::cout << std::stof(input) << "\n";

  input.clear();
  input = "-123.4.5";
  std::cout << stringToFloat(input) << "\n";

  input.clear();
  input = "123345";
  std::cout << stringToFloat(input) << "\n";

  input.clear();
  input = ".56";
  std::cout << stringToFloat(input) << "\n";

  input.clear();
  input = "-.56";
  std::cout << stringToFloat(input) << "\n";

  input.clear();
  input = "ab.5de6";
  std::cout << stringToFloat(input) << "\n";
  // std::stof throws exception on this case
  // std::cout << std::stof(input) << "\n";

  return 0;
}

// Linear interpolation with a range of values.

#include <cstddef>
#include <iostream>
#include <stdexcept>

static constexpr double x[] = {0.0, 1.0, 2.0, 3.0, 4.0};
static constexpr double y[] = {2.5, 3.7, 5.0, 3.5, 2.0};
static constexpr uint8_t ERROR = 0xFF;
static constexpr uint8_t GREAT_SUCCESS = 0x00;

uint8_t my_lerd(double target, double &guess) {
  std::size_t size = sizeof(x) / sizeof(*x);
  uint8_t x1 = 0;
  uint8_t x2 = 0;

  if (target > x[size - 1]) {
    //  throw std::invalid_argument("OUT OF RANGE VALUE \n");
    return ERROR;
  }
  if (target < x[0]) {
    // throw std::invalid_argument("OUT OF RANGE VALUE \n");
    return ERROR;
  }

  // find a valid range for the target
  for (std::size_t i = 0; i < size; i++) {
    if (target < x[i]) {
      x1 = i - 1;
      x2 = i;
      break;
    }
  }

  double slope = (y[x2] - y[x1]) / (x[x2] - x[x1]);
  guess = y[x1] + slope * (target - x[x1]);

  return GREAT_SUCCESS;
}

int main() {
  double guess = 0.0;

  if (my_lerd(2.5, guess) == GREAT_SUCCESS) {
    std::cout << guess << "\n";
  } else {
    std::cout << "ERROR \n";
  }

  if (my_lerd(5.5, guess) == GREAT_SUCCESS) {
    std::cout << guess << "\n";
  } else {
    guess = 0.0; //??? /shrug
    std::cout << "ERROR \n";
  }
  return 0;
}

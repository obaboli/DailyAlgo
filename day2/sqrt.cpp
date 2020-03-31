// implement sqrt

#include <iostream>
#include <math.h>

using namespace std;

static constexpr float errorRate = 0.0001f;

// binary search
float my_sqrt(const float x) {
  if (x <= 0.0f) {
    return 0.0f;
  }

  float low = 0.0f;
  float high = x;

  // https://ai.googleblog.com/2006/06/extra-extra-read-all-about-it-nearly.html
  float guess = low + (high - low) / 2;
  float errorMargin = x * errorRate;

  while (fabs(x - (guess * guess)) > errorMargin) {
    if ((guess * guess) > x) {
      high = guess;
    } else {
      low = guess;
    }
    guess = low + (high - low) / 2;
  }

  return guess;
}

template <class T> double my_sqrtT(T x) {
  if (x <= 0.0) {
    return 0.0;
  }

  double low = 0.0;
  double high = x;

  double guess = low + (high - low) / 2;
  double errorMargin = x * errorRate;

  while (fabs(x - (guess * guess)) > errorMargin) {
    if ((guess * guess) > x) {
      high = guess;
    } else {
      low = guess;
    }
    guess = low + (high - low) / 2;
  }

  return guess;
}

// fancy newton's method rearranged to babylonian method?
// not my solution. found online
double my_sqrtN(double x) {
  if (x <= 0.0) {
    return 0.0;
  }

  double r = x;
  while (r * r > x) {
    r = (r + x / r) / 2;
  }
  return r;
}

int main() {
  cout << my_sqrt(9.0f) << "\n";

  cout << my_sqrtT(8000000) << "\n";

  cout << my_sqrtN(16) << "\n";
  return 0;
}

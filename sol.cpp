#include <iostream>
#include <string>
#include <vector>
const size_t kResult = 200;
int count = 0;

void printSol(const std::vector<int>& sol) {
  std::cout << "Number " << ++count << ". solution{";
  for (auto x : sol) {
    std::cout << (x >= 0 ? "+" : "") << x;
  }
  std::cout << "}";
  std::cout << std::endl;
}

void FindExpr(std::vector<int>& vec, int ans = 0, int num = 9) {
  if (num < 0) {
    if (ans == kResult) {
      printSol(vec);
    }
    return;
  }
  vec.push_back(num);
  FindExpr(vec, ans + vec[vec.size() - 1], num - 1);
  vec[vec.size() - 1] = -num;
  FindExpr(vec, ans + vec[vec.size() - 1], num - 1);
  if (vec.size() > 1) {
    vec.pop_back();
    ans -= vec[vec.size() - 1];
    if (vec[vec.size() - 1] > 0) {
      vec[vec.size() - 1] *= 10;
      vec[vec.size() - 1] += (num);
    } else {
      vec[vec.size() - 1] *= 10;
      vec[vec.size() - 1] -= (num);
    }

    FindExpr(vec, ans + vec[vec.size() - 1], num - 1);
    vec[vec.size() - 1] /= 10;
  }
};

int main() {
  std::vector<int> vec;
  FindExpr(vec);
}

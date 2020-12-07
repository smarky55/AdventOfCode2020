#include "Day1.h"

static Day1 s_day{};

Day1::Day1() :Day(1) {}

void Day1::run() {
  std::cout << "Part 1" << std::endl;
  if (expenseReport(testCase()) != 514579) {
    std::cout << "Test case failed" << std::endl;
    return;
  } else {
    std::cout << "Test case passed!" << std::endl;
  }

  std::cout << "Answer: " << expenseReport(readInput()) << std::endl;

  std::cout << "Part 2" << std::endl;
  if (expenseReport2(testCase()) != 241861950) {
    std::cout << "Test case failed" << std::endl;
    return;
  } else {
    std::cout << "Test case passed!" << std::endl;
  }

  std::cout << "Answer: " << expenseReport2(readInput()) << std::endl;
}

std::unordered_set<int> Day1::testCase() {
  return {1721,979,366,299,675,1456};
}

std::unordered_set<int> Day1::readInput() {
  std::unordered_set<int> res;

  if (std::ifstream inputFile{"Day1/input.txt"}) {
    int i = 0;
    while (inputFile >> i) {
      res.insert(i);
    }
  }

  return res;
}

int Day1::expenseReport(const std::unordered_set<int>& expenses) {
  for (auto i : expenses) {
    int target = 2020 - i;
    if (expenses.count(target) > 0) {
      return i * target;
    }
  }
  return 0;
}

int Day1::expenseReport2(const std::unordered_set<int>& expenses) {
  auto i = expenses.begin();
  while (i != expenses.end()) {
    auto j = ++i;
    --i;
    while (j != expenses.end()) {
      int target = 2020 - (*i + *j);
      if (expenses.count(target) > 0) {
        return *i * *j * target;
      }
      j++;
    }
    i++;
  }
  return 0;
}

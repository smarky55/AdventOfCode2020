#pragma once
#include <Core/Day.h>

#include <unordered_set>

class Day1 : public Day {
public:
  Day1();
  ~Day1() = default;

  void run() override;


private:
  std::unordered_set<int> testCase();

  std::unordered_set<int> readInput();

  int expenseReport(const std::unordered_set<int>& expenses);
  int expenseReport2(const std::unordered_set<int>& expenses);
};


#pragma once

#include <Core/Day.h>

class Day5 : Day<std::vector<std::string>> {
public:
  Day5();

private:
  std::vector<std::string> testCase() override;

  std::vector<std::string> readInput() override;

  uint64_t  part1(const std::vector<std::string>& input) override;
  uint64_t  part2(const std::vector<std::string>& input) override;

  int parseString(const std::string& string) const;
};


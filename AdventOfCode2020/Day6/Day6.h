#pragma once

#include <Core/Day.h>

class Day6 : Day<std::vector<std::vector<std::string>>> {
public:
  Day6();

private:
  std::vector<std::vector<std::string>> testCase() override;
  std::vector<std::vector<std::string>> readInput() override;

  uint64_t part1(const std::vector<std::vector<std::string>>& input) override;
  uint64_t part2(const std::vector<std::vector<std::string>>& input) override;
};


#pragma once

#include <Core/Day.h>

#include <map>
#include <set>

class Day7 : Day<std::map<std::string, std::map<std::string, int>>> {
public:
  Day7();

private:
  std::map<std::string, std::map<std::string, int>> testCase() override;
  std::map<std::string, std::map<std::string, int>> testCase2() override;
  std::map<std::string, std::map<std::string, int>> readInput() override;

  uint64_t part1(const std::map<std::string, std::map<std::string, int>>& input) override;
  uint64_t part2(const std::map<std::string, std::map<std::string, int>>& input) override;

  std::pair<std::string, std::map<std::string, int>> parseRule(const std::string& ruleStr) const;

  std::set<std::string> canContain(const std::map<std::string, std::map<std::string, int>>& input, const std::string& target) const;
  uint64_t contains(const std::map<std::string, std::map<std::string, int>>& input, const std::string& target) const;
};
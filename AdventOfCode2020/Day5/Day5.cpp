#include "Day5.h"

#include <set>

static Day5 s_day;

Day5::Day5() : Day(5, 820, 120) {}

std::vector<std::string> Day5::testCase() {
  return {"BFFFBBFRRR", "FFFBBBFRRR", "BBFFBBFRLL"};
}

std::vector<std::string> Day5::readInput() {
  std::vector<std::string> result;

  if (std::ifstream inputFile{"Day5/input.txt"}) {
    std::string line;
    while (std::getline(inputFile, line)) {
      result.push_back(line);
    }
  }
  return result;
}

uint64_t Day5::part1(const std::vector<std::string>& input) {
  uint64_t result = 0;

  for (auto& string : input) {
    int val = parseString(string);
    if (val > result) {
      result = val;
    }
  }

  return result;
}

uint64_t Day5::part2(const std::vector<std::string>& input) {
  std::set<int> values;

  for (auto& string : input) {
    values.insert(parseString(string));
  }

  std::set<int> candidates;
  for (int i : values) {
    if (!values.contains(i + 1)) {
      candidates.insert(i);
    }
  }
  return *(candidates.begin())+1;
}

int Day5::parseString(const std::string& string) const {
  int val = 0;
  int n = 1;
  for (auto i = string.rbegin(); i != string.rend(); ++i) {
    if (*i == 'B' || *i == 'R') {
      val += n;
    }
    n = n << 1;
  }
  return val;
}


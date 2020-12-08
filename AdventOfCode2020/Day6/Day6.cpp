#include "Day6.h"

#include <set>
#include <sstream>

static Day6 s_day;

Day6::Day6() : Day(6, 11, 6) {}

std::vector<std::vector<std::string>> Day6::testCase() {
  return {{"abc"}, {"a","b","c"},{"ab","ac"},{"a","a","a","a"},{"b"}};
}

std::vector<std::vector<std::string>> Day6::readInput() {
  std::vector<std::vector<std::string>> result;

  if (std::ifstream inputFile{"Day6/input.txt"}) {
    std::stringstream buffer;
    buffer << inputFile.rdbuf();
    std::vector<std::string> groups = tokenize(buffer.str(), std::regex(R"(\n\n)"));

    for (auto& group : groups) {
      result.push_back(tokenize(group, std::regex(R"(\n)")));
    }
  }

  return result;
}

uint64_t Day6::part1(const std::vector<std::vector<std::string>>& input) {
  uint64_t result = 0;

  for (auto& group : input) {
    std::set<char> questions;
    for (auto& person : group) {
      questions.insert(person.begin(), person.end());
    }
    result += questions.size();
  }

  return result;
}

uint64_t Day6::part2(const std::vector<std::vector<std::string>>& input) {
  uint64_t result = 0;

  for (auto& group : input) {
    std::set<char> questions(group[0].begin(), group[0].end());
    for (auto& person : group) {
      std::set<char> last = questions;
      questions.clear();
      std::set<char> myQs(person.begin(), person.end());
      std::set_intersection(last.begin(), last.end(), myQs.begin(), myQs.end(), 
                            std::inserter(questions, questions.begin()));
    }
    result += questions.size();
  }

  return result;
}


#include "Day7.h"

static Day7 s_day;

Day7::Day7() : Day(7, 4, 126) {}

std::map<std::string, std::map<std::string, int>> Day7::testCase() {
  std::vector<std::string> input = {"light red bags contain 1 bright white bag, 2 muted yellow bags.",
                                    "dark orange bags contain 3 bright white bags, 4 muted yellow bags.",
                                    "bright white bags contain 1 shiny gold bag.",
                                    "muted yellow bags contain 2 shiny gold bags, 9 faded blue bags.",
                                    "shiny gold bags contain 1 dark olive bag, 2 vibrant plum bags.",
                                    "dark olive bags contain 3 faded blue bags, 4 dotted black bags.",
                                    "vibrant plum bags contain 5 faded blue bags, 6 dotted black bags.",
                                    "faded blue bags contain no other bags.",
                                    "dotted black bags contain no other bags."
  };

  std::map<std::string, std::map<std::string, int>> result;
  for (auto& line : input) {
    result.insert(parseRule(line));
  }

  return result;
}

std::map<std::string, std::map<std::string, int>> Day7::testCase2() {
  std::vector<std::string> input = {"shiny gold bags contain 2 dark red bags.",
                                    "dark red bags contain 2 dark orange bags.",
                                    "dark orange bags contain 2 dark yellow bags.",
                                    "dark yellow bags contain 2 dark green bags.",
                                    "dark green bags contain 2 dark blue bags.",
                                    "dark blue bags contain 2 dark violet bags.",
                                    "dark violet bags contain no other bags."
  };

  std::map<std::string, std::map<std::string, int>> result;
  for (auto& line : input) {
    result.insert(parseRule(line));
  }

  return result;
}

std::map<std::string, std::map<std::string, int>> Day7::readInput() {
  std::map<std::string, std::map<std::string, int>> result;

  if (std::ifstream inputFile{"Day7/input.txt"}) {
    std::string line;
    while (std::getline(inputFile, line)) {
      result.insert(parseRule(line));
    }
  }
  return result;
}

uint64_t Day7::part1(const std::map<std::string, std::map<std::string, int>>& input) {
  std::string target = "shiny gold";

  auto bags = canContain(input, target);
  return bags.size();
}

uint64_t Day7::part2(const std::map<std::string, std::map<std::string, int>>& input) {
  std::string target = "shiny gold";
  return contains(input, target);
}

std::pair<std::string, std::map<std::string, int>> Day7::parseRule(const std::string& ruleStr) const {
  std::regex re{R"(((\d) )?(\w+\s\w+) bags?)"};
  std::sregex_iterator i{ruleStr.begin(), ruleStr.end(), re};
  auto end = std::sregex_iterator();

  std::map<std::string, int> contains;

  auto match = *(i++);
  std::string myColor = match[3];
  while (i != end) {
    match = *(i++);
    if (match[3] != "no other") {
      contains.emplace(match[3], stoi(match[2]));
    }
  }

  return std::make_pair(myColor, contains);
}

std::set<std::string> Day7::canContain(const std::map<std::string, std::map<std::string, int>>& input, const std::string& target) const {
  std::set<std::string> myContainers;

  for (auto& [bag, contains] : input) {
    if (contains.contains(target)) {
      myContainers.insert(bag);
      auto nextContainers = canContain(input, bag);
      myContainers.insert(nextContainers.begin(), nextContainers.end());
    }
  }

  return myContainers;
}

uint64_t Day7::contains(const std::map<std::string, std::map<std::string, int>>& input, const std::string& target) const {
  uint64_t result = 0;

  if (input.contains(target)) {
    for (auto& [bag, count] : input.at(target)) {
      result += count + count * contains(input, bag);
    }
  }
  
  return result;
}

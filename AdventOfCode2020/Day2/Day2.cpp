#include "Day2.h"

#include <regex>

static Day2 s_day{};

Day2::Day2() : DayBase(2) {}

void Day2::run() {
  std::cout << "Part 1" << std::endl;
  if (part1(testCase()) != 2) {
    std::cout << "Test case failed" << std::endl;
    return;
  } else {
    std::cout << "Test case passed!" << std::endl;
  }

  std::cout << "Answer: " << part1(readInput()) << std::endl;

  std::cout << "Part 2" << std::endl;
  if (part2(testCase()) != 1) {
    std::cout << "Test case failed" << std::endl;
    return;
  } else {
    std::cout << "Test case passed!" << std::endl;
  }

  std::cout << "Answer: " << part2(readInput()) << std::endl;
}

std::vector<Day2::Password> Day2::testCase() {
  return {
    {1,3,'a',"abcde"},
    {1,3,'b',"cdefg"},
    {2,9,'c',"ccccccccc"},
  };
}

std::vector<Day2::Password> Day2::readInput() {
  std::vector<Password> res;

  if (std::ifstream inputFile{"Day2/input.txt"}) {
    std::string line;
    std::regex re{R"([-|\s|:]+)"};
    Password p;
    while (std::getline(inputFile, line)) {
      auto tokens = tokenize(line, re);
      p.min = stoi(tokens[0]);
      p.max = stoi(tokens[1]);
      p.letter = tokens[2][0];
      p.password = tokens[3];
      res.push_back(p);
    }
  }

  return res;
}

int Day2::part1(const std::vector<Password>& input) {
  int valid = 0;
  for (auto& password : input) {
    int count = 0;
    for (auto& letter : password.password) {
      if (letter == password.letter) {
        count++;
      }
    }
    if (count >= password.min && count <= password.max) {
      valid++;
    }
  }
  return valid;
}

int Day2::part2(const std::vector<Password>& input) {
  int valid = 0;
  for (auto& password : input) {
    if (password.password.size() < password.max) continue;
    bool first = password.password[password.min - 1] == password.letter;
    bool second = password.password[password.max - 1] == password.letter;
    if (first != second) {
      valid++;
    }
  }
  return valid;
}

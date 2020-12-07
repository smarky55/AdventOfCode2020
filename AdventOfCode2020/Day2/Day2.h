#pragma once

#include <Core/Day.h>

#include <string>
#include <vector>

class Day2 : public DayBase {
public:
  Day2();

  void run() override;

private:
  struct Password {
    int min;
    int max;
    char letter;
    std::string password;
  };

  std::vector<Password> testCase();

  std::vector<Password> readInput();

  int part1(const std::vector<Password>& input);
  int part2(const std::vector<Password>& input);

};


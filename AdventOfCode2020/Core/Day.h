// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <vector>

class DayBase {
protected:
  DayBase(int num);
  virtual ~DayBase() = default;

  std::vector<std::string> tokenize(const std::string str, const std::regex re) const;

public:
  virtual void run() = 0;
};

template <typename InputT>
class Day : public DayBase {
public:
  Day(int num, uint64_t testResult1, uint64_t testResult2);

  void run() override;

protected:
  uint64_t m_testCaseResult1;
  uint64_t m_testCaseResult2;

  virtual InputT testCase() = 0;
  virtual InputT testCase2();
  virtual InputT readInput() = 0;

  virtual uint64_t part1(const InputT& input) = 0;
  virtual uint64_t part2(const InputT& input) = 0;
};

template<typename InputT>
inline Day<InputT>::Day(int num, uint64_t testResult1, uint64_t testResult2)
  : DayBase(num), m_testCaseResult1(testResult1), m_testCaseResult2(testResult2) {}

template<typename InputT>
inline void Day<InputT>::run() {
  std::cout << "Part 1" << std::endl;
  if (part1(testCase()) != m_testCaseResult1) {
    std::cout << "Test case failed" << std::endl;
    return;
  } else {
    std::cout << "Test case passed!" << std::endl;
  }

  std::cout << "Answer: " << part1(readInput()) << std::endl;

  std::cout << "Part 2" << std::endl;
  if (part2(testCase2()) != m_testCaseResult2) {
    std::cout << "Test case failed" << std::endl;
    return;
  } else {
    std::cout << "Test case passed!" << std::endl;
  }

  std::cout << "Answer: " << part2(readInput()) << std::endl;
}

template<typename InputT>
inline InputT Day<InputT>::testCase2() {
  return testCase();
}

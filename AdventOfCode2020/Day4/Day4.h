#pragma once

#include <Core/Day.h>

#include <optional>
#include <string>

struct Passport {
  std::optional<std::string> byr;
  std::optional<std::string> iyr;
  std::optional<std::string> eyr;
  std::optional<std::string> hgt;
  std::optional<std::string> hcl;
  std::optional<std::string> ecl;
  std::optional<std::string> pid;
  std::optional<std::string> cid;
};

class Day4 : Day<std::vector<Passport>>{
public:
  Day4();

private:
  std::vector<Passport> testCase() override;

  std::vector<Passport> readInput() override;

  uint64_t  part1(const std::vector<Passport>& input) override;
  uint64_t  part2(const std::vector<Passport>& input) override;

  std::vector<Passport> parseString(const std::string& string) const;
  Passport parsePassport(const std::string& passString) const;
};


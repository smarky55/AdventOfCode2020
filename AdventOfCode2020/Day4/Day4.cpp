#include "Day4.h"

#include <sstream>

static Day4 s_day;

Day4::Day4() : Day(4, 2, 2) {}

std::vector<Passport> Day4::testCase() {
  return parseString("ecl:gry pid:860033327 eyr:2020 hcl:#fffffd\n"
                     "byr:1937 iyr : 2017 cid : 147 hgt : 183cm\n\n"
                     "iyr : 2013 ecl : amb cid : 350 eyr : 2023 pid : 028048884\n"
                     "hcl : #cfa07d byr : 1929\n\n"
                     "hcl : #ae17e1 iyr : 2013\n"
                     "eyr : 2024\n"
                     "ecl : brn pid : 760753108 byr : 1931\n"
                     "hgt : 179cm\n\n"
                     "hcl : #cfa07d eyr : 2025 pid : 166559648\n"
                     "iyr : 2011 ecl : brn hgt : 59in");
}

std::vector<Passport> Day4::readInput() {
  if (std::ifstream inputFile{"Day4/input.txt"}) {
    std::stringstream buffer;
    buffer << inputFile.rdbuf();
    return parseString(buffer.str());
  }

  return std::vector<Passport>();
}

uint64_t Day4::part1(const std::vector<Passport>& input) {
  uint64_t valid = 0;

  for (auto& pass : input) {
    if (pass.byr.has_value()
        && pass.ecl.has_value()
        && pass.eyr.has_value()
        && pass.hcl.has_value()
        && pass.hgt.has_value()
        && pass.iyr.has_value()
        && pass.pid.has_value()) {
      valid++;
    }
  }

  return valid;
}

uint64_t Day4::part2(const std::vector<Passport>& input) {
  uint64_t valid = 0;

  for (auto& pass : input) {
    try {
      std::string value;
      if (!pass.byr.has_value()) {
        continue;
      }
      value = pass.byr.value();
      if (value.size() != 4 || stoi(value) < 1920 || stoi(value) > 2002) {
        continue;
      }

      if (!pass.iyr.has_value()) {
        continue;
      }
      value = pass.iyr.value();
      if (value.size() != 4 || stoi(value) < 2010 || stoi(value) > 2020) {
        continue;
      }

      if (!pass.eyr.has_value()) {
        continue;
      }
      value = pass.eyr.value();
      if (value.size() != 4 || stoi(value) < 2020 || stoi(value) > 2030) {
        continue;
      }

      if (!pass.hgt.has_value()) {
        continue;
      }
      value = pass.hgt.value();
      if (value.size() < 3) {
        continue;
      }
      std::string unit = value.substr(value.size() - 2);
      int num = stoi(value.substr(0, value.size() - 2));
      if (!((unit == "cm" && num >= 150 && num <= 193) || (unit == "in" && num >= 59 && num <= 76))) {
        {
          continue;
        }
      }

      if (!pass.hcl.has_value()) {
        continue;
      }
      value = pass.hcl.value();
      if (!std::regex_match(value, std::regex("#[0-9|a-f]{6}"))) {
        continue;
      }

      if (!pass.ecl.has_value()) {
        continue;
      }
      value = pass.ecl.value();
      if (!std::regex_match(value, std::regex("amb|blu|brn|gry|grn|hzl|oth"))) {
        continue;
      }

      if (!pass.pid.has_value()) {
        continue;
      }
      value = pass.pid.value();
      if (!(value.size() == 9 && stol(value) >= 0)) {
        continue;
      }


      valid++;
    } catch (const std::invalid_argument&) {
      continue;
    }
  }

  return valid;
}

std::vector<Passport> Day4::parseString(const std::string& string) const {
  std::vector<std::string> strings = tokenize(string, std::regex(R"(\n\n)"));
  std::vector<Passport> passports;
  for (auto& s : strings) {
    passports.push_back(parsePassport(s));
  }
  return passports;
}

Passport Day4::parsePassport(const std::string& passString) const {
  Passport pass;
  std::vector<std::string> strings = tokenize(passString, std::regex(R"([\s|:])"));
  for (auto i = strings.begin(); i != strings.end(); i += 2) {
    std::string key = *i;
    std::string value = *(i + 1);
    if (key == "byr") {
      pass.byr = value;
    } else if (key == "iyr") {
      pass.iyr = value;
    } else if (key == "eyr") {
      pass.eyr = value;
    } else if (key == "hgt") {
      pass.hgt = value;
    } else if (key == "hcl") {
      pass.hcl = value;
    } else if (key == "ecl") {
      pass.ecl = value;
    } else if (key == "pid") {
      pass.pid = value;
    } else if (key == "cid") {
      pass.cid = value;
    }
  }
  return pass;
}

// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <vector>

class Day {
protected:
  Day(int num);
  virtual ~Day() = default;

  std::vector<std::string> tokenize(const std::string str, const std::regex re);

public:
  virtual void run() = 0;
};


#pragma once

#include <Core/Day.h>

struct Map {
  int width;
  int height;
  std::vector<std::vector<bool>> myMap;

  bool getPoint(int x, int y) const;
};

class Day3 : public Day<Map> {
public:
  Day3();

private:

  Map testCase() override;

  Map readInput() override;

  uint64_t part1(const Map& input) override;
  uint64_t part2(const Map& input) override;

  int countTrees(const Map& input, int stepx, int stepy);
};


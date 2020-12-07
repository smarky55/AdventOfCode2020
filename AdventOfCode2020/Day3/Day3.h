#pragma once

#include <Core/Day.h>
class Day3 : public Day {
public:
  Day3();

  void run() override;

private:
  struct Map {
    int width;
    int height;
    std::vector<std::vector<bool>> myMap;

    bool getPoint(int x, int y) const;
  };

  Map testCase();

  Map readInput();

  int part1(const Map& input);
  long long part2(const Map& input);

  int countTrees(const Map& input, int stepx, int stepy);
};


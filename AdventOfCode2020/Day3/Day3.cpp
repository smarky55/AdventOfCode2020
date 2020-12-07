#include "Day3.h"

static Day3 s_day{};

Day3::Day3() : Day(3, 7, 336) {}

Map Day3::testCase() {
  std::vector<std::string> input{
    "..##.......",
    "#...#...#..",
    ".#....#..#.",
    "..#.#...#.#",
    ".#...##..#.",
    "..#.##.....",
    ".#.#.#....#",
    ".#........#",
    "#.##...#...",
    "#...##....#",
    ".#..#...#.#"
  };
  Map map;
  map.height = input.size();
  map.width = input[0].size();
  for (auto& row : input) {
    std::vector<bool> mapRow;
    for (auto& point : row) {
      mapRow.push_back(point == '#');
    }
    map.myMap.push_back(mapRow);
  }
  return map;
}

Map Day3::readInput() {
  Map res;

  if (std::ifstream inputFile{"Day3/input.txt"}) {
    std::string line;
    while (std::getline(inputFile, line)) {
      std::vector<bool> mapRow;
      for (auto& point : line) {
        mapRow.push_back(point == '#');
      }
      res.myMap.push_back(mapRow);
    }
    res.height = res.myMap.size();
    res.width = res.myMap[0].size();
  }

  return res;
}

uint64_t Day3::part1(const Map& input) {
  return countTrees(input, 3, 1);
}

uint64_t Day3::part2(const Map& input) {
  uint64_t acc = countTrees(input, 1, 1);
  acc *= countTrees(input, 3, 1);
  acc *= countTrees(input, 5, 1);
  acc *= countTrees(input, 7, 1);
  acc *= countTrees(input, 1, 2);

  return acc;
}

int Day3::countTrees(const Map& input, int stepx, int stepy) {
  int x = stepx, y = stepy, trees = 0;
  while (y < input.height) {
    if (input.getPoint(x, y)) {
      trees++;
    }
    x += stepx;
    y += stepy;
  }
  return trees;
}

bool Map::getPoint(int x, int y) const {
  return myMap[y % height][x % width];
}

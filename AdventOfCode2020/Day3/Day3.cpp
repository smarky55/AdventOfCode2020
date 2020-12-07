#include "Day3.h"

static Day3 s_day{};

Day3::Day3() : Day(3) {}

void Day3::run() {
  std::cout << "Part 1" << std::endl;
  if (part1(testCase()) != 7) {
    std::cout << "Test case failed" << std::endl;
    return;
  } else {
    std::cout << "Test case passed!" << std::endl;
  }

  std::cout << "Answer: " << part1(readInput()) << std::endl;

  std::cout << "Part 2" << std::endl;
  if (part2(testCase()) != 336) {
    std::cout << "Test case failed" << std::endl;
    return;
  } else {
    std::cout << "Test case passed!" << std::endl;
  }

  std::cout << "Answer: " << part2(readInput()) << std::endl;
}

Day3::Map Day3::testCase() {
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

Day3::Map Day3::readInput() {
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

int Day3::part1(const Map& input) {
  return countTrees(input, 3, 1);
}

long long Day3::part2(const Map& input) {
  long long acc = countTrees(input, 1, 1);
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

bool Day3::Map::getPoint(int x, int y) const {
  return myMap[y % height][x % width];
}

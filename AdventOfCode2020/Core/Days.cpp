#include "Days.h"

#include "Day.h"

std::map<int, Day*>& getDays() {
  static std::map<int, Day*> s_days;
  return s_days;
}

void runday(int day) {
  if (getDays().count(day)) {
    getDays().at(day)->run();
  }
}
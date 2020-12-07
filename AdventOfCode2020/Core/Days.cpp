#include "Days.h"

#include "Day.h"

void runday(int day) {
  if (s_days.count(day)) {
    s_days.at(day)->run();
  }
}
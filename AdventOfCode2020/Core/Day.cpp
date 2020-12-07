#include "Day.h"

#include "Days.h"

Day::Day(int num) {
  s_days.try_emplace(num, this);
}

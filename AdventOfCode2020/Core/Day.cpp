#include "Day.h"

#include "Days.h"

Day::Day(int num) {
  getDays()[num] = this;
}

/**
 * @brief Tokenize the given vector
   according to the regex
 * and remove the empty tokens.
 *
 * @param str
 * @param re
 * @return std::vector<std::string>
 */
std::vector<std::string> Day::tokenize(
  const std::string str,
  const std::regex re) {
  std::sregex_token_iterator it{str.begin(),
                           str.end(), re, -1};
  std::vector<std::string> tokenized{it, {}};

  // Additional check to remove empty strings 
  tokenized.erase(
    std::remove_if(tokenized.begin(),
                   tokenized.end(),
                   [](std::string const& s) {
                     return s.size() == 0;
                   }),
    tokenized.end());

  return tokenized;
}
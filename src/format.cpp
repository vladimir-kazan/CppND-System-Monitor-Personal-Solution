#include <sstream>
#include <string>

#include "format.h"

using std::ostringstream;
using std::string;

// DONE: Complete this helper function
// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
string Format::ElapsedTime(long seconds) {
  std::ostringstream oss;
  long hours = seconds / 3600.0;
  int minutes = (seconds % 3600) / 60;
  int sec = seconds - (hours * 3600 + minutes * 60);
  oss << (hours < 10 ? "0" : "") << hours;
  oss << ':';
  oss << (minutes < 10 ? "0" : "") << minutes;
  oss << ':';
  oss << (sec < 10 ? "0" : "") << sec;
  return oss.str();
}

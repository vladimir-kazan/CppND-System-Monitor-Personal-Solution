#include <string>

#include "linux_parser.h"
#include "processor.h"

using LinuxParser::kProcDirectory;
using LinuxParser::kStatFilename;
using std::string;

// DONE: Return the aggregate CPU utilization
float Processor::Utilization() {
  string line;
  string key;
  float user, nice, system, idle, iowait, irq, softirq, steal, guest,
      guest_nice;
  float result;
  std::ifstream stream(kProcDirectory + kStatFilename);
  if (stream.is_open()) {
    while (std::getline(stream, line)) {
      std::istringstream linestream(line);
      linestream >> key >> user >> nice >> system >> idle >> iowait >> irq >>
          softirq >> steal >> guest >> guest_nice;
      if (key == "cpu") {
        float PrevIdle = previdle_ + previowait_;
        float Idle = idle + iowait;

        float PrevNonIdle = prevuser_ + prevnice_ + prevsystem_ + previrq_ +
                            prevsoftirq_ + prevsteal_;
        float NonIdle = user + nice + system + irq + softirq + steal;

        float PrevTotal = PrevIdle + PrevNonIdle;
        float Total = Idle + NonIdle;

        // # differentiate: actual value minus the previous one
        float totald = Total - PrevTotal;
        float idled = Idle - PrevIdle;
        if (totald == 0.0) {
          return 0.0;
        }
        result = (totald - idled) / totald;

        // update previous values
        prevuser_ = user;
        prevnice_ = nice;
        prevsystem_ = system;
        previdle_ = idle;
        previowait_ = iowait;
        previrq_ = irq;
        prevsoftirq_ = softirq;
        prevsteal_ = steal;
        prevguest_ = guest;
        prevguest_nice_ = guest_nice;
        return result;
      }
    }
  }
  return result;
}
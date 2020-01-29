#ifndef PROCESSOR_H
#define PROCESSOR_H

class Processor {
 public:
  float Utilization();  // DONE: See src/processor.cpp

  // DONE: Declare any necessary private members
 private:
  float prevuser_;
  float prevnice_;
  float prevsystem_;
  float previdle_;
  float previowait_;
  float previrq_;
  float prevsoftirq_;
  float prevsteal_;
  float prevguest_;
  float prevguest_nice_;
};

#endif
#include "paramchecker.h"
#include <vector>

IVitalCheck* vitalCheckers[] = {
  [bpm] = new VitalRangeCheck(70, 150),
  [spo2] = new VitalRangeCheck(80, 100),
  [respRate] = new VitalRangeCheck(30, 60),
  [avgECG] = new VitalValueCheck(0),
};

std::vector<bool> vitalsAreOk(const std::vector<Measurement>& measurements) {
  std::vector<bool> results;
  for(auto t = measurements.begin(); t != measurements.end(); t++) {
    results.push_back(vitalCheckers[t->id]->measurementIsOk(t->measured_value));
  }
  return results;
}

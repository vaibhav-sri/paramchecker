#include "paramchecker.h"
#include <gtest/gtest.h>
 
TEST(VitalsTest, when_a_vital_is_in_range_vital_range_check_is_ok) {
    VitalRangeCheck vitalChecker(60, 100);
    ASSERT_EQ(true, vitalChecker.measurementIsOk(70));
}

TEST(VitalsTest, when_a_vital_is_off_limit_it_is_reported_with_vital_id) { 
    std::vector<Measurement> measurements = {
        {bpm, 100},
        {spo2, 50},
        {respRate, 50},
    };
    auto results = vitalsAreOk(measurements);
    ASSERT_EQ(sizeof(measurements)/sizeof(measurements[0]), results.size());
    ASSERT_EQ(false, results[spo2]);
    ASSERT_EQ(true, results[bpm]);
    ASSERT_EQ(true, results[respRate]);
}
 
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

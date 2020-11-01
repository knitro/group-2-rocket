#include "unity.h"
// #include "../../src/pre_flight/launch_sequence.hh"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}


// void test_launch_sequence_check_should_pass_countdown_tick_check(void) {

//     /*Set Up*/
//     uint8_t countdown_length = 10;
//     launch_sequence_ns::init_start_time();
//     unsigned long start_time = millis();
//     countdown_tick();
//     TEST_ASSERT_INT_WITHIN(1, countdown_length, millis()-start_time);
// }

int main(void) {
    UNITY_BEGIN();
//     RUN_TEST();
    return UNITY_END();
}
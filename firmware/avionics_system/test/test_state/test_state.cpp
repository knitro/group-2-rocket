#include "unity.h"
#include <iostream>
#include "../../src/state/state.hh"
#include "../../src/state/state.cc"

// using namespace state_ns;

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void test_change_state_initialisation(void) {

    /*Set Up*/
    state_ns::current_state = state_ns::state::initialisation;
    
    /*Perform Action*/
    int returnValue = state_ns::next_state();

    /*Check for Correct Result*/
    TEST_ASSERT(state_ns::current_state == state_ns::state::test);
}

void test_change_state_test(void) {

    /*Set Up*/
    state_ns::current_state = state_ns::state::test;
    
    /*Perform Action*/
    int returnValue = state_ns::next_state();

    /*Check for Correct Result*/
    TEST_ASSERT(state_ns::current_state == state_ns::state::idle);
}

void test_change_state_idle(void) {

    /*Set Up*/
    state_ns::current_state = state_ns::state::idle;
    
    /*Perform Action*/
    int returnValue = state_ns::next_state();

    /*Check for Correct Result*/
    TEST_ASSERT(state_ns::current_state == state_ns::state::launch_sequence);
}

void test_change_state_launch_sequence(void) {

    /*Set Up*/
    state_ns::current_state = state_ns::state::launch_sequence;
    
    /*Perform Action*/
    int returnValue = state_ns::next_state();

    /*Check for Correct Result*/
    TEST_ASSERT(state_ns::current_state == state_ns::state::ignition);
}

void test_change_state_ignition(void) {

    /*Set Up*/
    state_ns::current_state = state_ns::state::ignition;
    
    /*Perform Action*/
    int returnValue = state_ns::next_state();

    /*Check for Correct Result*/
    TEST_ASSERT(state_ns::current_state == state_ns::state::flight);
}

void test_change_state_flight(void) {

    /*Set Up*/
    state_ns::current_state = state_ns::state::flight;
    
    /*Perform Action*/
    int returnValue = state_ns::next_state();

    /*Check for Correct Result*/
    TEST_ASSERT(state_ns::current_state == state_ns::state::post_flight);
}

void test_change_state_post_flight(void) {

    /*Set Up*/
    state_ns::current_state = state_ns::state::post_flight;
    
    /*Perform Action*/
    int returnValue = state_ns::next_state();

    /*Check for Correct Result*/
    TEST_ASSERT(state_ns::current_state == state_ns::state::finished);
}

void test_change_state_finished(void) {

    /*Set Up*/
    state_ns::current_state = state_ns::state::finished;
    
    /*Perform Action*/
    int returnValue = state_ns::next_state();

    /*Check for Correct Result*/
    TEST_ASSERT(state_ns::current_state == state_ns::state::finished);
}

void test_change_state_fail(void) {

    /*Set Up*/
    state_ns::current_state = state_ns::state::fail;
    
    /*Perform Action*/
    int returnValue = state_ns::next_state();

    /*Check for Correct Result*/
    TEST_ASSERT(state_ns::current_state == state_ns::state::fail);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_change_state_initialisation);
    RUN_TEST(test_change_state_test);
    RUN_TEST(test_change_state_idle);
    RUN_TEST(test_change_state_launch_sequence);
    RUN_TEST(test_change_state_ignition);
    RUN_TEST(test_change_state_flight);
    RUN_TEST(test_change_state_post_flight);
    RUN_TEST(test_change_state_finished);
    RUN_TEST(test_change_state_fail);
    return UNITY_END();
}
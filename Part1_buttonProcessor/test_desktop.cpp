#include <main.cpp>
#include <unity.h>

void reset_test(void){
    btns_step();
    TEST_ASSERT_EQUAL(IN_Reset, rtDW.is_c3_btns);
}

void press_one_btn_more_than_20ms(void){
    rtU.Inport = 1;
    btns_step();
    TEST_ASSERT_EQUAL(IN_one_bounce, rtDW.is_c3_btns);
    btns_step();
    TEST_ASSERT_EQUAL(IN_one_press, rtDW.is_c3_btns);
    rtU.Inport = 0;
    btns_step();
    TEST_ASSERT_EQUAL(IN_Reset, rtDW.is_c3_btns);
    btns_step();
}

void press_one_btn_less_than_20ms(void){
    rtU.Inport = 1;
    btns_step();
    TEST_ASSERT_EQUAL(IN_one_bounce, rtDW.is_c3_btns);
    rtU.Inport = 0;
    btns_step();
    TEST_ASSERT_EQUAL(IN_Reset, rtDW.is_c3_btns);
    btns_step();
}

void press_two_btn_more_than_20ms(void){
    rtU.Inport1 = 1;
    btns_step();
    TEST_ASSERT_EQUAL(IN_two_bounce, rtDW.is_c3_btns);
    btns_step();
    TEST_ASSERT_EQUAL(IN_two_press, rtDW.is_c3_btns);
    rtU.Inport1 = 0;
    btns_step();
    TEST_ASSERT_EQUAL(IN_Reset, rtDW.is_c3_btns);
    btns_step();
}

void press_two_btn_less_than_20ms(void){
    rtU.Inport1 = 1;
    btns_step();
    TEST_ASSERT_EQUAL(IN_two_bounce, rtDW.is_c3_btns);
    rtU.Inport1 = 0;
    btns_step();
    TEST_ASSERT_EQUAL(IN_Reset, rtDW.is_c3_btns);
    btns_step();
}


void press_three_btn_more_than_20ms(void){
    rtU.Inport2 = 1;
    btns_step();
    TEST_ASSERT_EQUAL(IN_three_bounce, rtDW.is_c3_btns);
    btns_step();
    TEST_ASSERT_EQUAL(IN_three_press, rtDW.is_c3_btns);
    rtU.Inport2 = 0;
    btns_step();
    TEST_ASSERT_EQUAL(IN_Reset, rtDW.is_c3_btns);
    btns_step();
}

void press_three_btn_less_than_20ms(void){
    rtU.Inport2 = 1;
    btns_step();
    TEST_ASSERT_EQUAL(IN_three_bounce, rtDW.is_c3_btns);
    rtU.Inport2 = 0;
    btns_step();
    TEST_ASSERT_EQUAL(IN_Reset, rtDW.is_c3_btns);
    btns_step();
}

void press_stop_btn_more_than_20ms(void){
    rtU.Inport3 = 1;
    btns_step();
    TEST_ASSERT_EQUAL(IN_stop_bounce, rtDW.is_c3_btns);
    btns_step();
    TEST_ASSERT_EQUAL(IN_stop_press, rtDW.is_c3_btns);
    rtU.Inport3 = 0;
    btns_step();
    TEST_ASSERT_EQUAL(IN_Reset, rtDW.is_c3_btns);
    btns_step();
}


void press_stop_btn_less_than_20ms(void){
    rtU.Inport3 = 1;
    btns_step();
    TEST_ASSERT_EQUAL(IN_stop_bounce, rtDW.is_c3_btns);
    rtU.Inport3 = 0;
    btns_step();
    TEST_ASSERT_EQUAL(IN_Reset, rtDW.is_c3_btns);
    btns_step();
}


void door_status_more_than_20ms(void){
    rtU.Inport4 = 1;
    btns_step();
    TEST_ASSERT_EQUAL(IN_door_bounce, rtDW.is_c3_btns);
    btns_step();
    TEST_ASSERT_EQUAL(IN_door_status, rtDW.is_c3_btns);
    rtU.Inport4 = 0;
    btns_step();
    TEST_ASSERT_EQUAL(IN_Reset, rtDW.is_c3_btns);
    btns_step();
}

void door_status_less_than_20ms(void){
    rtU.Inport4 = 1;
    btns_step();
    TEST_ASSERT_EQUAL(IN_door_bounce, rtDW.is_c3_btns);
    rtU.Inport4 = 0;
    btns_step();
    TEST_ASSERT_EQUAL(IN_Reset, rtDW.is_c3_btns);
    btns_step();
}

void floor_status_more_than_20ms(void){
    rtU.Inport5 = 1;
    btns_step();
    TEST_ASSERT_EQUAL(IN_floor_bounce, rtDW.is_c3_btns);
    btns_step();
    TEST_ASSERT_EQUAL(IN_floor_pos, rtDW.is_c3_btns);
    rtU.Inport5 = 0;
    btns_step();
    TEST_ASSERT_EQUAL(IN_Reset, rtDW.is_c3_btns);
    btns_step();
}

void floor_status_less_than_20ms(void){
    rtU.Inport5 = 1;
    btns_step();
    TEST_ASSERT_EQUAL(IN_floor_bounce, rtDW.is_c3_btns);
    rtU.Inport5 = 0;
    btns_step();
    TEST_ASSERT_EQUAL(IN_Reset, rtDW.is_c3_btns);
    btns_step();
}

int main(int argc, char **argv){
    btns_initialize();
    UNITY_BEGIN();
    RUN_TEST(reset_test);
    RUN_TEST(press_one_btn_more_than_20ms);
    RUN_TEST(press_one_btn_less_than_20ms);
    RUN_TEST(press_two_btn_more_than_20ms);
    RUN_TEST(press_two_btn_less_than_20ms);
    RUN_TEST(press_three_btn_more_than_20ms);
    RUN_TEST(press_three_btn_less_than_20ms);
    RUN_TEST(press_stop_btn_more_than_20ms);
    RUN_TEST(press_stop_btn_less_than_20ms);
    RUN_TEST(door_status_more_than_20ms);
    RUN_TEST(door_status_less_than_20ms);
    RUN_TEST(floor_status_more_than_20ms);
    RUN_TEST(floor_status_less_than_20ms);
    UNITY_END();
    return 0;
}
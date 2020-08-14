#include <main.cpp>
#include <unity.h>


void test_restart(void){
    safety_step();
    TEST_ASSERT_EQUAL(IN_monitor , rtDW.is_c3_safety);
    TEST_ASSERT_EQUAL(0,rtY.Out1);//stop is 0
}

void door_open_between_floors(void){
    rtU.Inport1 = 1.0;//door sensor
    rtU.Inport = -1;//at_floor = -1 which means we are between floors
    safety_step();
    TEST_ASSERT_EQUAL(IN_door_stop,rtDW.is_c3_safety);
    TEST_ASSERT_EQUAL(1,rtY.Out1);//stop is 1
    safety_step();//door is still open
    TEST_ASSERT_EQUAL(IN_door_stop,rtDW.is_c3_safety);
    TEST_ASSERT_EQUAL(1,rtY.Out1);//stop is 1
    rtU.Inport1 = 0;
    safety_step();
}

void stop_btn_pressed(void){
    safety_step();
    TEST_ASSERT_EQUAL(IN_monitor , rtDW.is_c3_safety);
    TEST_ASSERT_EQUAL(0,rtY.Out1);//stop is 0
    rtU.Inport5 = 1.0;//stop btn is pressed
    safety_step();
    TEST_ASSERT_EQUAL(IN_stop_button, rtDW.is_c3_safety);
    TEST_ASSERT_EQUAL(1,rtY.Out1);//stop is 1
    //stop_btn is still 1
    safety_step();
    TEST_ASSERT_EQUAL(IN_stop_button, rtDW.is_c3_safety);
    TEST_ASSERT_EQUAL(1,rtY.Out1);//stop is 1
    rtU.Inport5 = 0;
    safety_step();
}

void invalid_speed(void){
    safety_step();
    TEST_ASSERT_EQUAL(IN_monitor , rtDW.is_c3_safety);
    TEST_ASSERT_EQUAL(0,rtY.Out1);//stop is 0
    rtU.Inport4 = 100; //speed can not be more than 50
    safety_step();
    TEST_ASSERT_EQUAL(IN_speed_stop, rtDW.is_c3_safety);
    TEST_ASSERT_EQUAL(1,rtY.Out1);//stop is 1
    rtU.Inport4 = 70;// it reduces from 100 to 70 which is still invalid
    safety_step();
    TEST_ASSERT_EQUAL(IN_speed_stop, rtDW.is_c3_safety);
    TEST_ASSERT_EQUAL(1,rtY.Out1);//stop is 1
    rtU.Inport4 = 50;
    safety_step();
}

void third_floor_with_upward(void){
    safety_step();
    TEST_ASSERT_EQUAL(IN_monitor , rtDW.is_c3_safety);
    TEST_ASSERT_EQUAL(0,rtY.Out1);//stop is 0
    rtU.Inport6 = 1; //upward is activated
    rtU.Inport = -1; // at_floor is -1
    rtU.Inport3 = 800; // position is 800
    safety_step();
    TEST_ASSERT_EQUAL(IN_top_stop, rtDW.is_c3_safety);
    TEST_ASSERT_EQUAL(1,rtY.Out1);//stop is 1
    //still we are in danger
    safety_step();
    TEST_ASSERT_EQUAL(IN_top_stop, rtDW.is_c3_safety);
    TEST_ASSERT_EQUAL(1,rtY.Out1);//stop is 1
    rtU.Inport6 = 0;
    safety_step();
}

void first_floor_with_downward(void){
    safety_step();
    TEST_ASSERT_EQUAL(IN_monitor , rtDW.is_c3_safety);
    TEST_ASSERT_EQUAL(0,rtY.Out1);//stop is 0
    rtU.Inport2 = 1; //downward is activated
    rtU.Inport = -1; // at_floor is -1
    rtU.Inport3 = 0; // position is 0
    safety_step();
    TEST_ASSERT_EQUAL(IN_down_stop, rtDW.is_c3_safety);
    TEST_ASSERT_EQUAL(1,rtY.Out1);//stop is 1
    //still we are in danger
    safety_step();
    TEST_ASSERT_EQUAL(IN_down_stop, rtDW.is_c3_safety);
    TEST_ASSERT_EQUAL(1,rtY.Out1);//stop is 1
    rtU.Inport2 = 0;
    rtU.Inport = 0; // at_floor is -1
    safety_step();
}

void both_upward_downward(void){
    safety_step();
    TEST_ASSERT_EQUAL(IN_monitor , rtDW.is_c3_safety);
    TEST_ASSERT_EQUAL(0,rtY.Out1);//stop is 0
    rtU.Inport2 = 1; //upward is activated
    rtU.Inport6 = 1; //downward is activated
    safety_step();
    TEST_ASSERT_EQUAL(IN_both_dir_stop, rtDW.is_c3_safety);
    TEST_ASSERT_EQUAL(1,rtY.Out1);//stop is 1
    //still we are in danger
    safety_step();
    TEST_ASSERT_EQUAL(IN_both_dir_stop, rtDW.is_c3_safety);
    TEST_ASSERT_EQUAL(1,rtY.Out1);//stop is 1
    rtU.Inport2 = 0;
    rtU.Inport6 = 0;
    safety_step();
}

int main(){
    safety_initialize();
    UNITY_BEGIN();
    RUN_TEST(test_restart);
    RUN_TEST(door_open_between_floors);
    RUN_TEST(stop_btn_pressed);
    RUN_TEST(invalid_speed);
    RUN_TEST(third_floor_with_upward);
    RUN_TEST(first_floor_with_downward);
    RUN_TEST(both_upward_downward);
    UNITY_END();
    return 0;
}
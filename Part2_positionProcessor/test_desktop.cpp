#include <main.cpp>
#include <unity.h>

void restart_test(void){
    position_signalGenerator_step();
    TEST_ASSERT_EQUAL(IN_init,rtDW.is_c3_position_signalGenerator);
    TEST_ASSERT_EQUAL(0,rtY.Out3);//pos is 0 in init state
    TEST_ASSERT_EQUAL(0,rtDW.counter);//counter is 0 in init state
    TEST_ASSERT_EQUAL(0,rtY.Outport1);//speed is 0 in init state
}

void check_reset_position(void){
    position_signalGenerator_step();
    TEST_ASSERT_EQUAL(IN_pos_detection,rtDW.is_c3_position_signalGenerator);    
    TEST_ASSERT_EQUAL(IN_floor_1,rtDW.was_pos_cal);
    TEST_ASSERT_EQUAL(1,rtY.Outport);//at_floor = 1 
    TEST_ASSERT_EQUAL(0,rtY.Out3);//position = 400
}

void check_reset_speed(void){
    position_signalGenerator_step();
    TEST_ASSERT_EQUAL(IN_pos_detection,rtDW.is_c3_position_signalGenerator);
    TEST_ASSERT_EQUAL(0,rtY.Outport1); //speed is 0 at first after 1 sec it will turn to 50
}

void check_test_speed(void){
    //the state machine will calculate speed after one second
    for(int i = 0 ; i < 150 ; i++)
        position_signalGenerator_step();
    TEST_ASSERT_EQUAL(IN_pos_detection,rtDW.is_c3_position_signalGenerator);
    TEST_ASSERT_EQUAL(50,rtY.Outport1);//speed must be 50
}

void check_test_pos_between12(void){
    //as we step forward the square generator will lead us to moving up
    TEST_ASSERT_EQUAL(IN_pos_detection,rtDW.is_c3_position_signalGenerator);
    TEST_ASSERT_EQUAL(IN_between_1_2,rtDW.was_pos_cal);
    TEST_ASSERT_EQUAL(-1,rtY.Outport);//at_floor = -1 
    TEST_ASSERT_EQUAL(50,rtY.Outport1);//speed must be 50
}

void check_test_pos_floor2(void){
    for(int i = 0 ; i < 1048 ; i++)
        position_signalGenerator_step();
    TEST_ASSERT_EQUAL(IN_pos_detection,rtDW.is_c3_position_signalGenerator);
    TEST_ASSERT_EQUAL(IN_floor_2,rtDW.was_pos_cal);
    TEST_ASSERT_EQUAL(2,rtY.Outport);//at_floor = 2
    TEST_ASSERT_EQUAL(400,rtY.Out3);//position = 400
    TEST_ASSERT_EQUAL(50,rtY.Outport1);//speed must be 50
}

void check_test_pos_between23(void){
    //as we step forward the square generator will lead us to moving up
    position_signalGenerator_step();
    TEST_ASSERT_EQUAL(IN_pos_detection,rtDW.is_c3_position_signalGenerator);
    TEST_ASSERT_EQUAL(IN_between_2_3,rtDW.was_pos_cal);
    TEST_ASSERT_EQUAL(-1,rtY.Outport);//at_floor = -1 
    TEST_ASSERT_EQUAL(50,rtY.Outport1);//speed must be 50
}

void check_test_pos_floor3(void){
    for(int i = 0 ; i < 1200 ; i++)
        position_signalGenerator_step();
    TEST_ASSERT_EQUAL(IN_pos_detection,rtDW.is_c3_position_signalGenerator);
    TEST_ASSERT_EQUAL(IN_floor_3,rtDW.was_pos_cal);
    TEST_ASSERT_EQUAL(3,rtY.Outport);//at_floor = 3
    TEST_ASSERT_EQUAL(800,rtY.Out3);//position = 800
    TEST_ASSERT_EQUAL(50,rtY.Outport1);//speed must be 50
}

int main(){
    position_signalGenerator_initialize();
    UNITY_BEGIN();
    RUN_TEST(restart_test);
    RUN_TEST(check_reset_position);
    RUN_TEST(check_reset_speed);
    RUN_TEST(check_test_speed);
    RUN_TEST(check_test_pos_between12);
    RUN_TEST(check_test_pos_floor2);
    RUN_TEST(check_test_pos_between23);
    RUN_TEST(check_test_pos_floor3);
    UNITY_END();
    return 0;
}
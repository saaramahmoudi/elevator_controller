#include <main.cpp>
#include <unity.h>

void restart_test(void){
    planning_step();
    TEST_ASSERT_EQUAL(IN_init,rtDW.is_c3_planning);
    TEST_ASSERT_EQUAL(0,rtDW.one_pressed);
    TEST_ASSERT_EQUAL(0,rtDW.two_pressed);
    TEST_ASSERT_EQUAL(0,rtDW.three_pressed);
}

void step_after_init(void){
    planning_step();
    TEST_ASSERT_EQUAL(IN_floor1,rtDW.is_plan_handle);//at first we are in floor 1
    TEST_ASSERT_EQUAL(0,rtDW.one_pressed);
    TEST_ASSERT_EQUAL(0,rtDW.two_pressed);
    TEST_ASSERT_EQUAL(0,rtDW.three_pressed);
}

void one_pressed_at_floor1(void){
    rtU.Inport1 = 1.0;//btn 1 is pressed
    planning_step();
    TEST_ASSERT_EQUAL(IN_floor1,rtDW.is_plan_handle);//we are in floor 1 and btn 1 has been pressed so we stay in floor 1
    TEST_ASSERT_EQUAL(1,rtDW.one_pressed);//one_pressed must be 1
    rtU.Inport1 = 0;

}

void two_pressed_at_floor1_goto_floor2(void){
    rtU.Inport3 = 1.0;//btn 2 is pressed 
    for(int i = 0 ; i <= 25 ; i++){
        planning_step();
    }
    TEST_ASSERT_EQUAL(1,rtDW.two_pressed);
    //in here we are moving up
    TEST_ASSERT_EQUAL(IN_move_up,rtDW.is_plan_handle);//btn 2 is pressed and we are in floor 1 so we go to MOVE UP state
    TEST_ASSERT_EQUAL(2,rtY.Outport);//des must change to 2
    TEST_ASSERT_EQUAL(1,rtY.Outport3);//upward must change to 1
    //reach at floor 2
    rtU.Inport4 = 200; //position = 200
    rtU.Inport = 2;    //at_floor = 2
    rtU.Inport3 = 0; 
    planning_step();
    TEST_ASSERT_EQUAL(IN_floor2,rtDW.is_plan_handle);//we have reached to FLOOR2 state
    TEST_ASSERT_EQUAL(1,rtY.Outport2);//door is open
    TEST_ASSERT_EQUAL(1,rtY.Outport1);//stop is 1
    TEST_ASSERT_EQUAL(0,rtDW.two_pressed);
}

void two_pressed_at_floor2(void){
    rtU.Inport3 = 1.0;//btn 2 is pressed
    planning_step();
    TEST_ASSERT_EQUAL(IN_floor2,rtDW.is_plan_handle);//we are in floor 2 and btn 2 has been pressed so we stay in floor 2
    TEST_ASSERT_EQUAL(1,rtDW.two_pressed);//two_pressed must be 1
    rtU.Inport3 = 0;

}

void three_pressed_at_floor2_goto_floor3(void){
    rtU.Inport2 = 1.0;//btn 3 is pressed 
    for(int i = 0 ; i <= 25 ; i++){
        planning_step();
    }
    TEST_ASSERT_EQUAL(1,rtDW.three_pressed);
    //moving up
    TEST_ASSERT_EQUAL(IN_move_up,rtDW.is_plan_handle);//btn 3 is pressed and we are in floor 2 so we go to MOVE UP state
    TEST_ASSERT_EQUAL(3,rtY.Outport);//des must change to 3
    TEST_ASSERT_EQUAL(1,rtY.Outport3);//upward must change to 1
    //reach at floor 3
    rtU.Inport = 3;    //at_floor = 3
    rtU.Inport2 = 0;
    planning_step();
    TEST_ASSERT_EQUAL(IN_floor3,rtDW.is_plan_handle);//we have reached to FLOOR3 state
    TEST_ASSERT_EQUAL(1,rtY.Outport2);//door is open
    TEST_ASSERT_EQUAL(1,rtY.Outport1);//stop is 1
    TEST_ASSERT_EQUAL(0,rtDW.three_pressed);
}

void three_pressed_at_floor3(void){
    rtU.Inport2 = 1.0;//btn 3 is pressed
    planning_step();
    TEST_ASSERT_EQUAL(IN_floor3,rtDW.is_plan_handle);//we are in floor 3 and btn 3 has been pressed so we stay in floor 3
    TEST_ASSERT_EQUAL(1,rtDW.three_pressed);//three_pressed must be 1
    rtU.Inport2 = 0;

}

void two_pressed_at_floor3_goto_floor2(void){
    rtU.Inport3 = 1.0;//btn 2 is pressed 
    for(int i = 0 ; i <= 25 ; i++){
        planning_step();
    }
    TEST_ASSERT_EQUAL(1,rtDW.two_pressed);
    //in here we are moving down
    TEST_ASSERT_EQUAL(IN_move_down,rtDW.is_plan_handle);//btn 2 is pressed and we are in floor 3 so we go to MOVE DOWN state
    TEST_ASSERT_EQUAL(2,rtY.Outport);//des must change to 2
    TEST_ASSERT_EQUAL(1,rtY.Outport4);//downward must change to 1
    //reach at floor 2
    rtU.Inport = 2;    //at_floor = 2
    rtU.Inport3 = 0; 
    planning_step();
    TEST_ASSERT_EQUAL(IN_floor2,rtDW.is_plan_handle);//we have reached to FLOOR2 state
    TEST_ASSERT_EQUAL(1,rtY.Outport2);//door is open
    TEST_ASSERT_EQUAL(1,rtY.Outport1);//stop is 1
    TEST_ASSERT_EQUAL(0,rtDW.two_pressed);
}

void one_pressed_at_floor2_goto_floor1(){
    rtU.Inport1 = 1.0;//btn 1 is pressed 
    for(int i = 0 ; i <= 25 ; i++){
        planning_step();
    }
    TEST_ASSERT_EQUAL(1,rtDW.one_pressed);
    //in here we are moving down
    TEST_ASSERT_EQUAL(IN_move_down,rtDW.is_plan_handle);//btn 1 is pressed and we are in floor 2 so we go to MOVE DOWN state
    TEST_ASSERT_EQUAL(1,rtY.Outport);//des must change to 1
    TEST_ASSERT_EQUAL(1,rtY.Outport4);//downward must change to 1
    //reach at floor 1
    rtU.Inport = 1;    //at_floor = 1
    rtU.Inport1 = 0; 
    planning_step();
    TEST_ASSERT_EQUAL(IN_floor1,rtDW.is_plan_handle);//we have reached to FLOOR1 state
    TEST_ASSERT_EQUAL(1,rtY.Outport2);//door is open
    TEST_ASSERT_EQUAL(1,rtY.Outport1);//stop is 1
    TEST_ASSERT_EQUAL(0,rtDW.one_pressed);
}

void three_pressed_at_floor1_goto_floor3(void){
    rtU.Inport2 = 1.0;//btn 3 is pressed 
    for(int i = 0 ; i <= 25 ; i++){
        planning_step();
    }
    TEST_ASSERT_EQUAL(1,rtDW.three_pressed);
    //moving up
    TEST_ASSERT_EQUAL(IN_move_up,rtDW.is_plan_handle);//btn 3 is pressed and we are in floor 1 so we go to MOVE UP state
    TEST_ASSERT_EQUAL(3,rtY.Outport);//des must change to 3
    TEST_ASSERT_EQUAL(1,rtY.Outport3);//upward must change to 1
    //reach at floor 3
    rtU.Inport = 3;  //at_floor = 3
    rtU.Inport2 = 0;
    planning_step();
    TEST_ASSERT_EQUAL(IN_floor3,rtDW.is_plan_handle);//we have reached to FLOOR3 state
    TEST_ASSERT_EQUAL(1,rtY.Outport2);//door is open
    TEST_ASSERT_EQUAL(1,rtY.Outport1);//stop is 1
    TEST_ASSERT_EQUAL(0,rtDW.three_pressed);
}

void one_pressed_at_floor3_goto_floor1(){
    rtU.Inport1 = 1.0;//btn 1 is pressed 
    for(int i = 0 ; i <= 25 ; i++){
        planning_step();
    }
    TEST_ASSERT_EQUAL(1,rtDW.one_pressed);
    //in here we are moving up
    TEST_ASSERT_EQUAL(IN_move_down,rtDW.is_plan_handle);//btn 1 is pressed and we are in floor 3 so we go to MOVE DOWN state
    TEST_ASSERT_EQUAL(1,rtY.Outport);//des must change to 1
    TEST_ASSERT_EQUAL(1,rtY.Outport4);//downward must change to 1
    //reach at floor 1
    rtU.Inport = 1;    //at_floor = 1
    rtU.Inport1 = 0; 
    planning_step();
    TEST_ASSERT_EQUAL(IN_floor1,rtDW.is_plan_handle);//we have reached to FLOOR1 state
    TEST_ASSERT_EQUAL(1,rtY.Outport2);//door is open
    TEST_ASSERT_EQUAL(1,rtY.Outport1);//stop is 1
    TEST_ASSERT_EQUAL(0,rtDW.one_pressed);
}

int main(){
    planning_initialize();
    UNITY_BEGIN();
    RUN_TEST(restart_test);
    RUN_TEST(step_after_init);
    RUN_TEST(one_pressed_at_floor1);
    RUN_TEST(two_pressed_at_floor1_goto_floor2);
    RUN_TEST(two_pressed_at_floor2);
    RUN_TEST(three_pressed_at_floor2_goto_floor3);
    RUN_TEST(three_pressed_at_floor3);
    RUN_TEST(two_pressed_at_floor3_goto_floor2);
    RUN_TEST(one_pressed_at_floor2_goto_floor1);
    RUN_TEST(three_pressed_at_floor1_goto_floor3);
    RUN_TEST(one_pressed_at_floor3_goto_floor1);
    UNITY_END();
    return 0;
}
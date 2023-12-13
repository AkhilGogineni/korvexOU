#include "devices.hpp"
#include "autons.hpp"
#include "drivercontrol.hpp"

void doNothing() {}

ASSET(test_txt)
ASSET(leftsidequalsv3_txt)
ASSET(elimsLeftPath1_txt)
ASSET(elimsLeftPath2_txt)
ASSET(elimsLeftPath3_txt)
ASSET(elimsLeftPath4_txt)
ASSET(elimsLeftPath5_txt)
ASSET(elimsLeftPath6_txt)
ASSET(skillsPath1_txt)
ASSET(skillsPath2_txt)
ASSET(skillsPath3_txt)

const int DRIVE_SPEED = 110; // This is 110/127 (around 87% of max speed).  We don't suggest making this 127.
                             // If this is 127 and the robot tries to heading correct, it's only correcting by
                             // making one side slower.  When this is 87%, it's correcting by making one side
                             // faster and one side slower, giving better heading correction.
const int TURN_SPEED  = 90;
const int SWING_SPEED = 90;

void default_constants() {
  EzTempChassis.set_slew_min_power(80, 80);
  EzTempChassis.set_slew_distance(7, 7);
  EzTempChassis.set_pid_constants(&EzTempChassis.headingPID, 11, 0, 20, 0);
  EzTempChassis.set_pid_constants(&EzTempChassis.forward_drivePID, 0.45, 0, 5, 0);
  EzTempChassis.set_pid_constants(&EzTempChassis.backward_drivePID, 0.45, 0, 5, 0);
  EzTempChassis.set_pid_constants(&EzTempChassis.turnPID, 5, 0.003, 35, 15);
  EzTempChassis.set_pid_constants(&EzTempChassis.swingPID, 7, 0, 45, 0);
}

void modified_exit_condition() {
  EzTempChassis.set_exit_condition(EzTempChassis.turn_exit, 10, 3, 10, 7, 10, 10);
  EzTempChassis.set_exit_condition(EzTempChassis.swing_exit, 10, 3, 10, 7, 10, 10);
  EzTempChassis.set_exit_condition(EzTempChassis.drive_exit, 10, 50, 10, 150, 10, 10);
}


// function definitions

//       chassis.setPose(x, y, theta); 
//       chassis.turnTo(x, y, timeout);    
//       chassis.follow(path file, timeout, lookahead distance, isAsynchronous, forwards (false makes the robot run the path backwards));
//
//       chassis.waitUntil(inches); use this to have your bot wait until the path is finished
//       a really big number means just wait until the path has finished



// example auto for clearing matchload area and touching pole
void leftSideQual() {

}

void leftSideElims() {

}

void rightSideQuals() {
    
}


void Descore() {

}

void GoalSide() {

}

void Elims() {

}

void test() {
    EzTempChassis.set_drive_pid(24, DRIVE_SPEED, false);
    EzTempChassis.wait_drive();
    
    pros::delay(600);

    EzTempChassis.set_drive_pid(-24, DRIVE_SPEED);
    EzTempChassis.wait_drive();
}

void skills() {
    
}


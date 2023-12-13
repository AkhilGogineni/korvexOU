#include "devices.hpp"
#include "autons.hpp"
#include "drivercontrol.hpp"

void doNothing() {}

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

// function definitions

//       chassis.setPose(x, y, theta); 
//       chassis.turnTo(x, y, timeout);    
//       chassis.follow(path file, timeout, lookahead distance, isAsynchronous, forwards (false makes the robot run the path backwards));
//
//       chassis.waitUntil(inches); use this to have your bot wait until the path is finished
//       a really big number means just wait until the path has finished


const int DRIVE_SPEED = 110; // This is 110/127 (around 87% of max speed).  We don't suggest making this 127.
                             // If this is 127 and the robot tries to heading correct, it's only correcting by
                             // making one side slower.  When this is 87%, it's correcting by making one side
                             // faster and one side slower, giving better heading correction.
const int TURN_SPEED  = 90;
const int SWING_SPEED = 90;


// example auto for clearing matchload area and touching pole
void leftSideQual() {
    chassis.setPose(-48.428, -55.617, 135); // X: 0, Y: 0, Heading: 0

    chassis.follow(elimsLeftPath5_txt, 15, 1500, true, false);
    chassis.waitUntil(1000000);

    intake = 127;
    wing1.set_value(true);
    wing2.set_value(true);
    chassis.follow(elimsLeftPath6_txt, 15, 2000, true);
    chassis.waitUntil(1000000);
    intake = 0;

    
    chassis.turnTo(-11.918, -55.484, 500);    
    chassis.follow(leftsidequalsv3_txt, 15, 2000, true);
    chassis.waitUntil(3);
    wing1.set_value(false);
    wing2.set_value(false);
    chassis.waitUntil(5000);
    chassis.turnTo(999999, -55.484, 500);    

}

// example auto for matchload elims
// for video check: https://www.youtube.com/live/bE180c_xft8?si=eTFYuLUq1aH28cv-&t=37856
void leftSideElims() {
    chassis.setPose(-37.194, -53.076, 15); // X: 0, Y: 0, Heading: 0

    chassis.follow(elimsLeftPath1_txt, 15, 2000, true);
    intake = 127;
    chassis.waitUntilDone();

    // chassis.follow(elimsLeftPath2_txt, 15, 2000, true, false);
    // chassis.waitUntil(5);
    // intake = 0;
    // chassis.waitUntil(1000000);

    // chassis.turnTo(9999999, -15, 500, true);  
    // chassis.waitUntil(1000000);
    // pros::delay(250); 
    // pros::delay(750); 

    // chassis.follow(elimsLeftPath3_txt, 15, 1000, true);
    // chassis.waitUntil(1000000);

    // intake = 0;

    // chassis.follow(elimsLeftPath4_txt, 15, 2000, true, false);
    // chassis.waitUntil(1000000);

    // chassis.turnTo(9999999, -60, 1000, true);  
    // chassis.waitUntil(1000000);

    // chassis.follow(elimsLeftPath5_txt, 15, 1500, true, false);
    // chassis.waitUntil(1000000);

    // chassis.setPose(-59.662, -30.609, 180);

    // wing1.set_value(true);
    // wing2.set_value(true);
    // chassis.follow(elimsLeftPath6_txt, 15, 2000, true);
    // chassis.waitUntil(1000000);

    // wing1.set_value(false);
    // wing2.set_value(false);

    // chassis.turnTo(9999999, -60, 500, true);  

    // intake = -127;
}


void Descore() {

}

void GoalSide() {

}

void Elims() {

}

void test() {
    EzTempChassis.set_drive_pid(24, DRIVE_SPEED);
    EzTempChassis.wait_drive();

    // EzTempChassis.set_drive_pid(-24, DRIVE_SPEED);
    // EzTempChassis.wait_drive();

}

void skills() {
    
}


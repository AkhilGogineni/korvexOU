#pragma once

#include "pros/rtos.hpp"
#include "lemlib/api.hpp"

// . . .
// 
//  DRIVER CONTROL
//
// . . .
void resetPistons();
void toggleWings();
void fourBarUp();
void fourBarDown();
bool getShiftKey();

void tank_drive(double curve = 4.0);
void set_drive_to_coast();
void set_drive_to_hold();
#include "lemlib/api.hpp"
#include "main.h"
#include "devices.hpp"
#include "drivercontrol.hpp"



pros::ADIDigitalOut wing1('E');
pros::ADIDigitalOut wing2('D');
pros::ADIDigitalOut stick ('B');
pros::ADIDigitalOut lift1('F');
pros::ADIDigitalOut lift2('C');
pros::ADIDigitalOut hang1('G');

pros::Motor intake (-16, pros::E_MOTOR_GEARSET_36, true, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor slapper1 (10, pros::E_MOTOR_GEARSET_36, true, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor slapper2 (2, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES);

pros::MotorGroup slapper ({slapper1, slapper2});

pros::Motor leftFront(5, pros::E_MOTOR_GEARSET_06, true);  
pros::Motor leftBack(4, pros::E_MOTOR_GEARSET_06, true); 
pros::Motor leftTop(3, pros::E_MOTOR_GEARSET_06, true); 

pros::Motor rightFront(14, pros::E_MOTOR_GEARSET_06, false); 
pros::Motor rightBack(9, pros::E_MOTOR_GEARSET_06, false); 
pros::Motor rightTop(12, pros::E_MOTOR_GEARSET_06, false); 

// this is for the controller screen to alert you if a motor is unplugged
// and tell you the temperature of the drivetrain
std::vector<pros::Motor> motors = { 
        leftFront, leftBack, leftTop, rightFront, rightBack, rightTop,
        // add more motors here
    };

pros::MotorGroup left_side_motors({leftFront, leftBack, leftTop});
pros::MotorGroup right_side_motors({rightFront, rightBack, rightTop});

pros::Imu imu(17); 

pros::Controller controller(pros::E_CONTROLLER_MASTER);




lemlib::Drivetrain drivetrain (
    &left_side_motors, // left drivetrain motors
    &right_side_motors, // right drivetrain motors
    8, // track width
    2.75, // wheel diameter
    450, // wheel rpm
    2 // chase power
);

lemlib::OdomSensors sensors (
    nullptr, 
    nullptr, 
    nullptr, 
    nullptr,
    &imu // inertial sensor
);

// forward/backward PID
lemlib::ControllerSettings lateralController (
    0.45, // kP
    5, // kD
    1, // smallErrorRange
    80, // smallErrorTimeout
    3, // largeErrorRange
    300, // largeErrorTimeout
    7 // slew rate
);
 
// turning PID
lemlib::ControllerSettings angularController (
    5, // kP
    35, // kD
    1, // smallErrorRange
    100, // smallErrorTimeout
    3, // largeErrorRange
    500, // largeErrorTimeout
    0 // slew rate
);

lemlib::Chassis chassis(drivetrain, lateralController, angularController, sensors);

void checkMotorsAndReturnTemperature() {
    while (true) {
        double totalTemp = 0.0;
        int count = 0;

        for (auto& motor : motors) {
            double temp = motor.get_temperature();
            if (temp == PROS_ERR_F) { // PROS_ERR_F is returned when the motor is unplugged
                master.set_text(0, 0, "Motor " + std::to_string(motor.get_port()) + " unplugged.");
                pros::delay(250);
                master.rumble("---");
            }

            if (count < 6) {
                totalTemp += temp;
            }
            ++count;
        }

        if (count == 0) master.set_text(0, 0, "No motors found.");

        double averageTempCelsius = totalTemp / count;
        double averageTempFahrenheit = averageTempCelsius * 9.0 / 5.0 + 32.0;
        master.set_text(0, 0, "Avg Temp: " + std::to_string(averageTempFahrenheit));

        pros::delay(250);
    }
}



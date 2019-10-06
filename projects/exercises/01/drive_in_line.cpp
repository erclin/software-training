#include <STSL/RJRobot.h>
#include <cmath>

void driveForward(float x, RJRobot& robot) {
    robot.setDriveMotors(0.5, -0.5);

    robot.wait(std::chrono::milliseconds(x*800)); 
    robot.stopMotors(); //Stop the motors
}

void turn(float angle, RJRobot& robot) {
    robot.setDriveMotors(0.4, 0.4);
    robot.wait(std::chrono::milliseconds(angle*4));
    robot.stopMotors();
}

void driveToPoint(int x, int y, RJRobot& robot) {
    float angle = atan2(x, y) * 180 / M_PI;
    float distance = std::sqrt(x*x + y*y);
    turn(angle, robot);
    driveForward(distance, robot);
    
}

int main()
{
    RJRobot robot; //Initialize a RJ Robot
    //driveForward(2, robot);
    //turn(180, robot);
    
    driveToPoint(1, 2, robot);

    return 0;
}

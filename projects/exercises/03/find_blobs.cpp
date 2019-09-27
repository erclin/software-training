#include <iostream>

#include <STSL/RJRobot.h>  // includes OpenCV for us

int main() 
{
    std::cout << "starting capture..." << std::endl;
    
    RJRobot robot;
    
    cv::Mat image;
    for (int i = 0; i < 10; i++) {
        image = robot.getImage();
        
        /**************** TODO ******************
         * Modify image using OpenCV functions  *
         *                                      *
         * Try making a binary image to show    *
         * where the camera sees brighter than  *
         * 127 in grayscale                     *
         * *************************************/
        
        // convert image to grayscale
        cv::cvtColor(image, image, cv::COLOR_BGR2GRAY);
        
        // threshold using inRange. Don't forget that the thresholds are cv::Scalar objects
        cv::inRange(image, cv::Scalar(128), cv::Scalar(255), image);
        
        /* ^^^ put your code up here ^^^ */
        
        std::string fname = "frames/frame" + std::to_string(i) + ".jpg";
        cv::imwrite(fname, image);
        robot.wait(1000ms);
    }
    
    return 0;
}

#include<opencv2/opencv.hpp>
#include "mergeContours.hpp"
#include<iostream>

void mergeContours ( ::std::vector< std::vector< cv::Point > > contours, std::vector< cv::RotatedRect > boundedBoxes, int pixelThreshold, std::vector< std::vector < cv::Point > > mergedContours) {
    for(int i = 0;i<contours.size();i++) {
        for(int j = i+1;j<contours.size();i++) {

            //Find pixel Distance between Two Centersj
            if(cv::norm(boundedBoxes[i].center, boundedBoxes[j].center) < pixelThreshold){

            }
            else {

            }
                
        }
    }
}

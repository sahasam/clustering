#include<iostream>
#include<opencv2/opencv.hpp>
#include "clustering.hpp"
bool applyGaussianBlur = true;

bool applyHSVFilters = true;
bool HSVDebug = true;
bool PixelDebug = true;

int h_min = 36, s_min = 112, v_min = 65;
int h_max = 141, s_max = 189, v_max = 179;

//Maximum Number of Pixels to merge contours
const int pixelDistanceThreshold = 150;

void applyFilters(cv::Mat img, cv::Mat filteredImage);

int main (int, char**) {
    cv::VideoCapture cam(0);

    cv::namedWindow("Original Image", CV_WINDOW_AUTOSIZE);
    
    if(HSVDebug) {
        cv::namedWindow("hsv-trackbars", CV_WINDOW_AUTOSIZE);
        cv::createTrackbar("Hue Min", "hsv-trackbars", &h_min, 180, on_hmin_trackbar);
        cv::createTrackbar("Hue Max", "hsv-trackbars", &h_max, 180, on_hmax_trackbar);
        cv::createTrackbar("Saturation Min", "hsv-trackbars", &s_min, 255, on_smin_trackbar);
        cv::createTrackbar("Saturation Max", "hsv-trackbars", &s_max, 255, on_smax_trackbar);
        cv::createTrackbar("Value Min", "hsv-trackbars", &v_min, 255, on_vmin_trackbar);
        cv::createTrackbar("Value Max", "hsv-trackbars", &v_max, 255, on_vmax_trackbar);
    }

    std::string mins;
    std::string maxs;
    
    cv::Mat frame, imgHSV, imgCanny;
    cv::Mat frame_threshold;
    std::vector < std::vector < cv::Point > > contours;
//    std::vector < cv::Vec4i > hierarchy;
 //`   std::vector < std::vector < cv::Point > > mergedContours;
    for(;;) {
        cam >> frame;

        //Apply filters to Original Image
        applyFilters(frame, frame);
        
        cv::cvtColor(frame, imgHSV, CV_BGR2HSV);
        //Narrow Image using HSV Filters
        cv::inRange(imgHSV , cv::Scalar(h_min,s_min,v_min), cv::Scalar(h_max,s_max,v_max),frame_threshold);
        
        if(HSVDebug) {
            mins = "Hue Min: "+std::to_string(h_min)+", Sat Min: "+std::to_string(s_min)+", Val Min: "+std::to_string(v_min);
            maxs = "Hue Max: "+std::to_string(h_max)+", Sat Max: "+std::to_string(s_max)+", Val Max: "+std::to_string(v_max);

            cv::putText(frame_threshold, mins, cv::Point(30,30), cv::FONT_HERSHEY_COMPLEX_SMALL, 0.8, cv::Scalar(200,200,250), 1, CV_AA);
            cv::putText(frame_threshold, maxs, cv::Point(30,50), cv::FONT_HERSHEY_COMPLEX_SMALL, 0.8, cv::Scalar(200,200,250), 1, CV_AA);
        }   
    /*        
        cv::Canny(frame_threshold,imgCanny, 100, 200, 3); 
        cv::findContours( imgCanny, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, cv::Point(0, 0) );
       
        std::vector < cv::RotatedRect > boundingBoxes(contours.size());
        for( int i = 0; i< contours.size(); i++ )
        {
            cv::Scalar color = cv::Scalar(132, 144,12 );
            drawContours( frame, contours, i, color, 2, 8, hierarchy, 0, cv::Point() );;
            boundingBoxes[i] = cv::minAreaRect(cv::Mat(contours[i]));
            
            //draw minAreaRects
            cv::Point2f vertices[4];
            boundingBoxes[i].points(vertices);
            for (int i = 0; i < 4; i++)
               cv::line(frame, vertices[i], vertices[(i+1)%4], cv::Scalar(0,255,0), 2);

            //Pixel Distance Threshold
        }
*/
        //mergedContours = mergeContours(contours, pixelDistanceThreshold); 

    //        cv::imshow("Canny Image", imgCanny);
//        cv::imshow("Original Image", frame);
        cv::imshow("HSV Threshold Image", frame_threshold);

        if(cv::waitKey(30) >  0) break;
    }
}

void on_hmin_trackbar (int, void *) {
    h_min = cv::min(h_max-1,h_min);
    cv::setTrackbarPos("Hue Min", "hsv-trackbars", h_min);
}
void on_hmax_trackbar (int, void *) {
    h_max = cv::max(h_min+1, h_max);
    cv::setTrackbarPos("Hue max", "hsv-trackbars", h_max);
}
void on_smin_trackbar (int, void *) {
    s_min = cv::min(s_max-1,s_min);
    cv::setTrackbarPos("Saturation Min", "hsv-trackbars", s_min);
}
void on_smax_trackbar (int, void *) {
    s_max = cv::max(s_min+1, s_max);
    cv::setTrackbarPos("Saturation max", "hsv-trackbars", s_max);
}
void on_vmin_trackbar (int, void *) {
    v_min = cv::min(v_max-1,v_min);
    cv::setTrackbarPos("Value Min", "hsv-trackbars", v_min);
}
void on_vmax_trackbar (int, void *) {
    v_max = cv::max(v_min+1, v_max);
    cv::setTrackbarPos("Value max", "hsv-trackbars", v_max);
}

void applyFilters(cv::Mat img, cv::Mat filteredImage) {
    if(applyGaussianBlur) {
        cv::GaussianBlur(img, filteredImage, cv::Size(5,5), 0, 0, 0);
    }
}

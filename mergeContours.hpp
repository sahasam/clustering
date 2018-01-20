#ifndef MERGE_CONTOURS_HPP
#define MERGE_CONTOURS_HPP

void mergeContours ( ::std::vector< std::vector< cv::Point > > contours, std::vector< cv::RotatedRect > boundedBoxes, int pixelThreshold, std::vector< std::vector < cv::Point > > mergedContours);

#endif //MERGE_CONTOURS_HPP

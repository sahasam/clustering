#ifndef CLUSTERING_HPP 
#define CLUSTERING_HPP

void on_hmin_trackbar (int, void *);
void on_hmax_trackbar (int, void *);
void on_smin_trackbar (int, void *);
void on_smax_trackbar (int, void *);
void on_vmin_trackbar (int, void *);
void on_vmax_trackbar (int, void *);
void applyFilters(cv::Mat img, cv::Mat filteredImage);

#endif

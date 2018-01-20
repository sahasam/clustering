#include<opencv2/opencv.hpp>
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

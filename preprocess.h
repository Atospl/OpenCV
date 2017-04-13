//
// Created by atos on 4/13/17.
//

#ifndef OPENCV_PREPROCESS_H
#define OPENCV_PREPROCESS_H


#include <opencv2/core/core.hpp> //imread
#include <opencv2/highgui/highgui.hpp> //imshow, waitKey
#include <opencv2/core/hal/interface.h>

cv::Mat sharpenImage(const cv::Mat& originalImage);

cv::Mat filterImage(const cv::Mat& originalImage, cv::Mat& filterMat);

#endif //OPENCV_PREPROCESS_H

#include "preprocess.h"

#include <opencv2/core/core.hpp> //imread
#include <opencv2/highgui/highgui.hpp> //imshow, waitKey
#include <iostream>

using namespace cv;

/**
 *
 * @param originalImage
 * @param filter
 * @return
 */
cv::Mat sharpenImage(const cv::Mat& originalImage) {
    int data[9] = { 0, -1, 0,
                    -1, 5, -1,
                    0, -1, 0 };
    Mat filter = Mat(3, 3, CV_32S, &data);
    return filterImage(originalImage, filter);
}


cv::Mat filterImage(const cv::Mat& originalImage, cv::Mat& filterMat) {
    CV_Assert(originalImage.depth() == CV_8U);
    Mat_<int> filter(filterMat);
    Mat_<cv::Vec3b> res(originalImage.size(), originalImage.type());
    for(int i = filter.rows/2; i < originalImage.rows-1; ++i) {
        for(int j = filter.cols/2; j < originalImage.cols-1; ++j) {
            Mat_<cv::Vec3b> roi(originalImage, Rect(j-1, i-1, filter.cols, filter.rows));
            int sumB, sumG, sumR;
            sumB = sumG = sumR = 0;
            //calculate output values of pixel
            for(int x = 0; x < roi.rows; ++x) {
                for(int y = 0; y < roi.cols; ++y) {
                    //std::cout << filter.at<int>(x,y) << std::endl;
                    sumB += roi(x, y)[0] * filter(x, y);
                    sumG += roi(x,y)[1] * filter(x,y);
                    sumR += roi(x,y)[2] * filter(x,y);
                }
            }
            sumB = sumB > 255 ? 255 : sumB;
            sumG = sumG > 255 ? 255 : sumG;
            sumR = sumR > 255 ? 255 : sumR;

            sumB = sumB < 0 ? 0 : sumB;
            sumG = sumG < 0 ? 0 : sumG;
            sumR = sumR < 0 ? 0 : sumR;

            res(i,j)[0] = sumB;
            res(i,j)[1] = sumG;
            res(i,j)[2] = sumR;
        }
    }

    Mat result(res);
    return result;
}
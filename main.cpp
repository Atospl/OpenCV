#include "preprocess.h"

#include <opencv2/core/core.hpp> //imread
#include <opencv2/highgui/highgui.hpp> //imshow, waitKey

#include <iostream>

/**Dostępne funkcje OpenCV (Wszystko inne piszemy sami!!!)
cv::imread - czytanie obrazu z pliku
cv::imwrite - zapis obrazu do pliku
        cv::Mat i cv::_Mat - konstruktory
        cv::imshow - wyświetlenie obrazu
cv::waitkey - czekanie na klawisz
        std::cout - wypisywanie informacji na konsolę ;-)
*/

using namespace cv;

int main() {
    cv::Mat a;
    a = imread("/home/atos/Projects/POBR/OpenCV/Lena.png");

    Mat b = sharpenImage(a);
    std::cout << "Hello, World!" << std::endl;

    imshow("Lena", a);
    imshow("OstraLena", b);
    waitKey();
    return 1;
}
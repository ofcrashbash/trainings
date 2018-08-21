#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;

int DisplayImage(int argc, char** argv)
{
	if (argc != 2)
	{
		cout << " Usage: display_image ImageToLoadAndDisplay" << endl;
		return -1;
	}

	cv::Mat image;
	image = cv::imread(argv[1], cv::IMREAD_COLOR); // Read the file

	if (image.empty()) // Check for invalid input
	{
		cout << "Could not open or find the image" << std::endl;
		return -1;
	}

	cv::namedWindow("Display window", cv::WINDOW_AUTOSIZE); // Create a window for display.
	imshow("Display window", image); // Show our image inside it.

	cv::waitKey(0); // Wait for a keystroke in the window
	return 0;
}
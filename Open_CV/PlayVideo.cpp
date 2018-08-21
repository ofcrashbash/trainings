#include <opencv2/opencv.hpp>
#include <iostream>

int PlayVideo(void)
{
	cv::VideoCapture cap("C:/Users/ofcra/Documents/Adobe/Premiere Pro/11.0/A long way home2.mp4");
	
	if (!cap.isOpened())
	{
		std::cout << "Failed to open file" << std::endl;
		std::cin.get();
		return -1;
	}

	double dWidth = cap.get(cv::CAP_PROP_FRAME_WIDTH);
	double dHeight = cap.get(cv::CAP_PROP_FRAME_HEIGHT);

	std::cout << "Resolution of the video: " << dWidth << "x" << dHeight << std::endl;


	double fps = cap.get(cv::CAP_PROP_FPS);
	std::cout << "Frames per second: " << fps << std::endl;

	std::string window_name = "Movie Player";
	cv::namedWindow(window_name, cv::WINDOW_NORMAL);

	
	while (true) {
		cv::Mat frame;
		bool bSuccess = cap.read(frame);

		if (!bSuccess)
		{
			std::cout << "Video is completed" << std::endl;
			break;
		}

		cv::imshow(window_name, frame);

		if (cv::waitKey(10) == 27)
		{
			std::cout << "Esc key is pressed by user. Stoppig the video" << std::endl;
			break;
		}

	}

	std::cin.get();

	return 0;
}
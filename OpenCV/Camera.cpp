#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

enum class tFilters {erode, dilate, gaussian, laplacian, invert, eq_hist, color_tracking, LAST_EL};
// Special behavior for ++Colors
tFilters& operator++(tFilters &f) {
	using IntType = typename std::underlying_type<tFilters>::type;
		f = static_cast<tFilters>(static_cast<IntType>(f) + 1);
	if (f == tFilters::LAST_EL)
		f = static_cast<tFilters>(0);
	return f;
}

void CallBackFunc(int event, int x, int y, int flags, void* userdata)
{
	if (event == EVENT_LBUTTONDOWN)
		cout << "Left button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
	else if (event == EVENT_RBUTTONDOWN)
		cout << "Right button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
	else if (event == EVENT_MBUTTONDOWN)
		cout << "Middle button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
	else if (event == EVENT_MOUSEMOVE)
		cout << "Mouse move over the window - position (" << x << ", " << y << ")" << endl;
}

int main(int argc, char* argv[])
{
	VideoCapture cap_back(1);
	if (!cap_back.isOpened()){
		cout << "Cannot open camera" << endl;
		cin.get();
		return -1;
	}
	
	VideoCapture cap_front(0);
	if (!cap_front.isOpened()){
		cout << "Cannot open camera" << endl;
		cin.get();
		return -1;
	}

	//Creating main window
	string window_name_1 = "camera feed";
	namedWindow(window_name_1);

	Mat frame_line;
	int iLowH = 136, iHighH = 179;
	int iLowS = 70, iHighS = 255;
	int iLowV = 0, iHighV = 255;

	int iLastX = -1;
	int iLastY = -1;

	//Create trackbars in "Control" window
	createTrackbar("LowH", window_name_1, &iLowH, 179); //Hue (0 - 179)
	createTrackbar("HighH", window_name_1, &iHighH, 179);

	createTrackbar("LowS", window_name_1, &iLowS, 255); //Saturation (0 - 255)
	createTrackbar("HighS", window_name_1, &iHighS, 255);

	createTrackbar("LowV", window_name_1, &iLowV, 255); //Value (0 - 255)
	createTrackbar("HighV", window_name_1, &iHighV, 255);

	setMouseCallback(window_name_1, CallBackFunc, NULL);

	//Adding slider to UI
	int iSliderValue1 = 0;
	createTrackbar("Brightness", window_name_1, &iSliderValue1, 360);

	auto width = cap_back.get(CAP_PROP_FRAME_WIDTH);
	auto height = cap_back.get(CAP_PROP_FRAME_HEIGHT);

	
	double dM01, dM10, dArea;
	Moments oMoments;

	tFilters cur_filter = tFilters::invert;
	while (true)
	{
		Mat frame_front, frame_back, cur_frame, frame_thresholded;
		

		bool bSuccess = cap_front.read(frame_front);
		if (!bSuccess)
		{
			cout << "Failed to get frame" << endl;
			cin.get();
			break;
		}

		bSuccess = cap_back.read(frame_back);
		if (!bSuccess)
		{
			cout << "Failed to get frame" << endl;
			cin.get();
			break;
		}

		if( frame_line.empty())
			frame_line = Mat::zeros(Size((int)width, (int)height), frame_back.type());
		/*
		Make changes to frame
			1 - Constrast
			2 - Brightness
			3 - Draw shapes
		etc..
		*/


		cur_frame = frame_back;
		//Rotation matrix
		Mat matRot = getRotationMatrix2D(Point((int)(width / 2.), (int)(height / 2)), (double)iSliderValue1, 1.);
		//Affine transformation
		warpAffine(cur_frame, cur_frame, matRot, cur_frame.size(), INTER_LINEAR, 1, Scalar());

		vector<Mat> vec_channels;
		switch (cur_filter)
		{
		case tFilters::eq_hist:
			cvtColor(cur_frame, cur_frame, COLOR_BGR2YCrCb);
			split(cur_frame, vec_channels);
			equalizeHist(vec_channels[0], vec_channels[0]);
			equalizeHist(vec_channels[1], vec_channels[1]);
			equalizeHist(vec_channels[2], vec_channels[2]);
			merge(vec_channels, cur_frame);
			cvtColor(cur_frame, cur_frame, COLOR_YCrCb2BGR);
			break;
		case tFilters::erode:
			erode(cur_frame, cur_frame, getStructuringElement(MORPH_RECT, Size(5, 5)));
			break;
		case tFilters::gaussian:
			blur(cur_frame, cur_frame, Size(3, 3));
			break;
		case tFilters::invert:
			cur_frame.convertTo(cur_frame, -1, -1, 255);
			break;
		case tFilters::dilate:
			dilate(cur_frame, cur_frame, getStructuringElement(MORPH_RECT, Size(5, 5)), Point(-1, -1), 2);
			break;
		case tFilters::laplacian:
			Laplacian(cur_frame, cur_frame, 0);
			break;
		case tFilters::color_tracking:
			cvtColor(frame_back, frame_back, COLOR_BGR2HSV); //Convert the captured frame from BGR to HSV
			inRange(frame_back, Scalar(iLowH, iLowS, iLowV), Scalar(iHighH, iHighS, iHighV), frame_back); //Threshold the image

			//morphological opening (remove small objects from the foreground)
			erode(frame_back, frame_back, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
			dilate(frame_back, frame_back, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));

			//morphological closing (fill small holes in the foreground)
			dilate(frame_back, frame_back, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
			erode(frame_back, frame_back, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));

			oMoments = moments(frame_back);
			dM01 = oMoments.m01;
			dM10 = oMoments.m10;
			dArea = oMoments.m00;
			if (dArea > 0)
			{
				int posY = (int) (dM01 / dArea);
				int posX = (int) (dM10 / dArea);
				if (iLastX >= 0 && iLastY >= 0 && posX >= 0 && posY >= 0) {
					//Draw a red line from the previous point to the current point
					
					line(frame_line, Point(posX, posY), Point(iLastX, iLastY), Scalar(25, 255, 255), 2);
				}
				cur_frame += frame_line;
				iLastX = posX;
				iLastY = posY;
			}
			break;
		default:
			cout << "No such filter" << endl;
			break;
		}

		imshow(window_name_1, cur_frame);



		auto key = waitKey(2);
		if (key == 27)
		{
			cout << "Esc is presse by user" << endl;
			break;
		}
		else if (key == 32)
		{
			++cur_filter;
		}
	}

	cap_back.release();
	cap_front.release();
	destroyAllWindows();
	return 0;
}

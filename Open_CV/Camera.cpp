#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

enum class tFilters {erode, dilate, gaussian, laplacian, invert, eq_hist, LAST_EL};
// Special behavior for ++Colors
tFilters& operator++(tFilters &f) {
	using IntType = typename std::underlying_type<tFilters>::type;
		f = static_cast<tFilters>(static_cast<IntType>(f) + 1);
	if (f == tFilters::LAST_EL)
		f = static_cast<tFilters>(0);
	return f;
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


	string window_name_1 = "camera feed";
	namedWindow(window_name_1);

	tFilters cur_filter = tFilters::invert;
	while (true)
	{
		Mat frame_front, frame_back, cur_frame;

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
		/*
		Make changes to frame
			1 - Constrast
			2 - Brightness
			3 - Draw shapes
		etc..
		*/

		cur_frame = frame_back;

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
			blur(cur_frame, cur_frame, Size(3,3));
			break;
		case tFilters::invert:
			cur_frame.convertTo(cur_frame, -1, -1, 255);
			break;
		case tFilters::dilate:
			dilate(cur_frame, cur_frame, getStructuringElement(MORPH_RECT, Size(5, 5)), Point(-1,-1), 2);
			break;
		case tFilters::laplacian:
			Laplacian(cur_frame, cur_frame, 0);
			break;
		default:
			cout << "No such filter" << endl;
			break;
		}

		imshow(window_name_1, cur_frame);

		auto key = waitKey(10);
		cout << "Pressed key: " << key << endl;
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

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char* argv[])
{
	VideoCapture cap(1);
	if (!cap.isOpened())
	{
		cout << "Cannot open camera" << endl;
		cin.get();
		return -1;
	}

	double dWidth = cap.get(CAP_PROP_FRAME_WIDTH);
	double dHeight = cap.get(CAP_PROP_FRAME_HEIGHT);

	int frame_width = static_cast<int>(cap.get(CAP_PROP_FRAME_WIDTH));
	int frame_height = static_cast<int>(cap.get(CAP_PROP_FRAME_HEIGHT));
	Size frame_size(frame_width, frame_width);

	cout << dWidth << "x" << dHeight << "?=" << frame_width << "x" << frame_height << endl;

	int frames_per_sec = 5;
	auto codec = VideoWriter::fourcc('M', 'J', 'P', 'G');
	VideoWriter oVideoWriter("out.avi", codec, frames_per_sec, frame_size, true);
	if (!oVideoWriter.isOpened())
	{
		cout << "Cannot save the video to a file" << endl;
		cin.get();
		return -1;
	}

	string window_name = "camera feed";
	namedWindow(window_name);

	while (true)
	{
		Mat frame, bgr_frame;
		bool bSuccess = cap.read(frame);
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
		//color conversion
		//cvtColor(frame, bgr_frame, COLOR_RGB2BGR);

		oVideoWriter.write(bgr_frame);


		imshow(window_name, frame);

		if (waitKey(10) == 27)
		{
			cout << "Esc is presse by user" << endl;
			break;
		}
	}

	cap.release();
	oVideoWriter.release();
	destroyAllWindows();
	return 0;
}

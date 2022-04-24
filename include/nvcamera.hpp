#ifndef CAM_HPP
#define CAM_HPP
#include <thread>
#include <mutex>
#include <opencv4/opencv2/core.hpp>

class NVCamera{
	private:
	public:
		NVCamera();
		cv::Mat get_image();
		cv::Mat get_depth();
		cv::Mat get_ir();
		~NVCamera();
};

#endif
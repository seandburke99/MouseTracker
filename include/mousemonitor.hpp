#ifndef MOUSEMONITOR_HPP
#define MOUSEMONITOR_HPP
#include <list>
#include <opencv4/opencv2/core.hpp>
#include <nvcamera.hpp>

class MouseFinder{
	private:
		NVCamera _cam;
		std::list<cv::Mat> _irBuffer;
		uint8_t _fps = 30;
		uint8_t _saveTime = 10;
		bool trigger = false;
		uint32_t _saves = 0;
	public:
		MouseFinder(uint8_t fps, uint8_t saveTime);
		void run(double threshold);
		bool save_buffer();
		~MouseFinder();
};

#endif
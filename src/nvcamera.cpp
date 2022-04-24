#include <nvcamera.hpp>
#include <libfreenect_sync.h>
#include <iostream>

NVCamera::NVCamera(){
};

cv::Mat NVCamera::get_image(){
	uint8_t *data = nullptr;
	uint32_t tstamp;
	freenect_sync_get_video((void**)&data, &tstamp, 0, FREENECT_VIDEO_RGB);
	if(data){
		cv::Mat m(480, 640, CV_8UC3, data);
		return m;
	}else{
		std::cout << "Unable to retrieve RGB image\n";
	}
	return cv::Mat();
}

cv::Mat NVCamera::get_depth(){
	uint16_t *data = nullptr;
	uint32_t tstamp;
	freenect_sync_get_depth((void**)&data, &tstamp, 0, FREENECT_DEPTH_MM);
	if(data){
		cv::Mat m(480, 640, CV_16U, data);
		return m;
	}else{
		std::cout << "Unable to retrieve IR image\n";
	}
	return cv::Mat();
}

cv::Mat NVCamera::get_ir(){
	uint8_t *data = nullptr;
	uint32_t tstamp;
	freenect_sync_get_video((void**)&data, &tstamp, 0, FREENECT_VIDEO_IR_8BIT);
	if(data){
		cv::Mat m = cv::Mat::zeros(cv::Size(640,480), CV_8UC1);
		std::memcpy(m.data, data, 640*480);
		return m;
	}else{
		std::cout << "Unable to retrieve IR image\n";
	}
	return cv::Mat();
}

NVCamera::~NVCamera(){
	freenect_sync_stop();
}
#include <mousemonitor.hpp>
#include <iostream>
#include <opencv4/opencv2/highgui.hpp>
#include <opencv4/opencv2/imgproc.hpp>
#include <opencv4/opencv2/imgcodecs.hpp>

MouseFinder::MouseFinder(uint8_t fps = 0, uint8_t saveTime = 0){
	if(fps){
		this->_fps = fps;
	}
	if(saveTime){
		this->_saveTime = saveTime;
	}
	this->_irBuffer.push_back(this->_cam.get_ir());
	return;
}

void MouseFinder::run(double threshold){
	std::cout << "In main loop\n";
	double last = 0, current = 0;
	while(true){
		cv::Mat m = this->_cam.get_ir();
		current = (double) cv::sum(this->_irBuffer.back()-m)[0] / (640.0*480.0);
		if(!this->trigger && ((current + last)/2 > threshold)){
			this->trigger = true;
			std::cout << "Triggered with difference of " << (current + last)/2 << std::endl;
		}
		last = current;
		this->_irBuffer.push_back(m);
		if(!this->trigger && (this->_irBuffer.size() > this->_saveTime*this->_fps/2)){
			this->_irBuffer.pop_front();
		}else if(this->_irBuffer.size() > this->_saveTime*this->_fps){
			this->save_buffer();
			for(int i=0;i<this->_saveTime*this->_fps/2;i++){
				this->_irBuffer.pop_front();
			}
			this->trigger = false;
		}
		cv::imshow("Feed", m);
		if(cv::waitKey(1000/30)=='q'){
			break;
		}
	}
	return;
}

bool MouseFinder::save_buffer(){
	std::string fname = "recordings/" + std::to_string(this->_saves) + ".mp4";
	cv::VideoWriter vw(
		fname,
		cv::VideoWriter::fourcc('m','p','4','v'),
		(double)this->_fps,
		this->_irBuffer.front().size(),
		false
	);
	for(auto const &img : this->_irBuffer){
		vw.write(img);
	}
	this->_saves++;
	return true;
}

MouseFinder::~MouseFinder(){
	return;
}
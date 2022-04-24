#include <iostream>
#include <mousemonitor.hpp>

int main(int argc, char *argv[]){
	// NVCamera nvc;
	MouseFinder mf(30, 10);
	mf.run(1);
	// while(true){
		// cv::Mat m = nvc.get_ir();
		// if(!m.empty()){
		// 	cv::imshow("Feed", m);
		// 	if(cv::waitKey(1000/33)=='q'){
		// 		break;
		// 	}
		// }else{
		// 	sleep(1);
		// }
	// }
	return 0;
}
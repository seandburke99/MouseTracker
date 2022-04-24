# Mouse Finder
OpenCV cpp mouse finder application. Not to overcomplicate things, 
this simply compares two frames and if average number of pixels over time changes over a threshold value, the save is triggered and a 10 second period (5 before trigger, 5 after) is saved to a
recordings folder

## Requirements
OpenCV 4
Open Kinect synchronous library
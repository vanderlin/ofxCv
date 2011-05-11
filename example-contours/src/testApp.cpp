#include "testApp.h"

void testApp::setup() {
	cam.initGrabber(640, 480);
	thresh.allocate(640, 480, OF_IMAGE_GRAYSCALE);
}

void testApp::update() {
	cam.update();
	if(cam.isFrameNew()) {
		convertColor(toCv(cam), toCv(thresh), CV_RGB2GRAY);
		float thresholdValue = ofMap(mouseX, 0, ofGetWidth(), 0, 255);
		threshold(toCv(thresh), thresholdValue);
		thresh.update();
	}
}

void testApp::draw() {
	cam.draw(0, 0);
	thresh.draw(640, 0);
}
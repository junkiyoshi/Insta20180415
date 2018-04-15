#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofBackground(39);
	ofSetWindowTitle("Insta");
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);

	int radius = 300;
	int deg_span = 5;
	for (int deg = 0; deg <= 360; deg += deg_span) {

		ofColor color;
		color.setHsb(ofMap(deg, 0, 360, 0, 255), 239, 239);
		ofSetColor(color);

		ofPoint noise_point = ofPoint(radius * cos((deg + deg_span / 2) * DEG_TO_RAD) * 0.005, radius * sin((deg + deg_span / 2) * DEG_TO_RAD));
		float noise_value = ofNoise(noise_point.x * 0.05, noise_point.y * 0.05, ofGetFrameNum() * 0.01);

		vector<ofPoint> vertices;
		vertices.push_back(ofPoint(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD)));
		vertices.push_back(ofPoint(radius * cos((deg + deg_span) * DEG_TO_RAD), radius * sin((deg + deg_span) * DEG_TO_RAD)));
		vertices.push_back(ofPoint(radius * noise_value * cos((deg + deg_span) * DEG_TO_RAD), radius * noise_value * sin((deg + deg_span) * DEG_TO_RAD)));
		vertices.push_back(ofPoint(radius * noise_value * cos(deg * DEG_TO_RAD), radius * noise_value * sin(deg * DEG_TO_RAD)));

		ofBeginShape();
		ofVertices(vertices);
		ofEndShape(true);
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}
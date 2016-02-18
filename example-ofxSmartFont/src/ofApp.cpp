#include "ofApp.h"

void ofApp::setup()
{
    ofSetWindowShape(1620, 900);
    ofSetBackgroundColor(ofColor::white);
    ofSetWindowPosition(ofGetScreenWidth()/2 - ofGetWidth()/2, 0);
    
// let's load up some fonts //
    int pointSize = 28;
    ofxSmartFont::add("raleway/Raleway-Medium.ttf", pointSize);
    ofxSmartFont::add("raleway/Raleway-Regular.ttf", pointSize);
    ofxSmartFont::add("raleway/Raleway-Thin.ttf", pointSize);
    ofxSmartFont::add("raleway/Raleway-Bold.ttf", pointSize);
    ofxSmartFont::add("raleway/Raleway-SemiBold.ttf", pointSize);
    ofxSmartFont::add("raleway/Raleway-Italic.ttf", pointSize);
    ofxSmartFont::add("raleway/Raleway-SemiBoldItalic.ttf", pointSize);
    ofxSmartFont::add("raleway/Raleway-ExtraBold.ttf", pointSize);
    ofxSmartFont::add("raleway/Raleway-ExtraBoldItalic.ttf", pointSize);
    ofxSmartFont::add("raleway/Raleway-Black.ttf", pointSize);

// attempts to add a font twice will be ignored //
    ofxSmartFont::add("raleway/Raleway-Black.ttf", pointSize);
}

void ofApp::draw()
{
    ofSetColor(ofColor::black);
    for (int i=0; i<ofxSmartFont::mFonts.size(); i++) {
        shared_ptr<ofxSmartFont> f = ofxSmartFont::mFonts[i];
        string s = f->name() + " @ "+ std::to_string(f->size()) + " :: The quick brown fox jumps over the lazy dog";
        f->draw(s, ofGetWidth()/2 - f->width(s)/2, 190 + (i * f->size()*2));
    }
}

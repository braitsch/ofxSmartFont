/*
    Copyright (C) 2016 Stephen Braitsch [http://braitsch.io]

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in all
    copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
    SOFTWARE.
*/


#include "ofxSmartFont.h"
vector<shared_ptr<ofxSmartFont>> ofxSmartFont::mFonts;

/*
    instance methods
*/

void ofxSmartFont::draw(string s, int x, int y)
{
    ttf.drawString(s, x, y);
}

string ofxSmartFont::name()
{
    return mName;
}

void ofxSmartFont::name(string name)
{
    mName = name;
}

string ofxSmartFont::file()
{
    return mFile;
}

int ofxSmartFont::size()
{
    return mSize;
}

ofRectangle ofxSmartFont::rect(string s, int x, int y)
{
    return ttf.getStringBoundingBox(s, x, y);
}

float ofxSmartFont::width(string s, int x, int y)
{
    return ttf.getStringBoundingBox(s, x, y).width;
}

float ofxSmartFont::height(string s, int x, int y)
{
    return ttf.getStringBoundingBox(s, x, y).height;
}

float ofxSmartFont::getLineHeight()
{
    return ttf.getLineHeight();
}

/*
    static methods
*/

shared_ptr<ofxSmartFont> ofxSmartFont::add(string file, int size, string name)
{
    for(auto f:mFonts){
        if (f->file()==file && f->size()==size){
            log("cached font found");
            return f;
        }
    }
    struct make_shared_sf : public ofxSmartFont {
        make_shared_sf(string file, int size, string name) : ofxSmartFont(file, size, name){}
    };
    mFonts.push_back(make_shared<make_shared_sf>(file, size, name));
    return mFonts.back();
}

shared_ptr<ofxSmartFont> ofxSmartFont::get(string name, int size)
{
    for(auto f:mFonts){
        if (f->name()==name && f->size()==size){
            return f;
        }
    }
    log("requested font : "+ name +" @ " +std::to_string(size)+ "not found");
}

void ofxSmartFont::list()
{
    log("----------------------------------");
    log("total # of fonts cached = " + std::to_string(mFonts.size()));
    for(auto f:mFonts){
        log(f->name() + " : " + std::to_string(f->size()));
    }
    log("----------------------------------");
}

void ofxSmartFont::log(string msg)
{
    cout << "ofxSmartFont :: "<< msg << endl;
}


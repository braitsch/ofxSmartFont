##ofxSmartFont

A sane & simple approach to managing [ofTrueType](http://openframeworks.cc/documentation/graphics/ofTrueTypeFont.html) instances.

**ofxSmartFont** creates, caches and manages [ofTrueType](http://openframeworks.cc/documentation/graphics/ofTrueTypeFont.html) instances over the lifecycle of your [OpenFrameworks](http://openframeworks.cc/) application.

It generates [smart pointers](https://msdn.microsoft.com/en-us/library/hh279674.aspx) that you can pass around your application without fear of dangling pointers and dead references when an [ofTrueType](http://openframeworks.cc/documentation/graphics/ofTrueTypeFont.html) instance inadvertantly goes out of scope.

Fonts are cached to ensure you never load the same one twice and are easily retrieved by a name you assign.

--

####Adding a font

	string file = "fonts/helvetica_neue.ttf";
	int size = 12;
	string name = helvetica_12;
	shared_ptr<ofxSmartFont> helvetica_12pt = ofxSmartFont::add(file, size, name);
 
####Retrieving a font

	shared_ptr<ofxSmartFont> helvetica_12pt = ofxSmartFont::get("helvetica_12");

At any time you can list all of the fonts that have been cached via:

	ofxSmartFont::list();
	>> ofxSmartFont :: ------------------------------------------------
	>> ofxSmartFont :: total # of fonts cached = 1
	>> ofxSmartFont :: ofxbraitsch/fonts/HelveticaNeueLTStd-Md.otf : 28
	>> ofxSmartFont :: ------------------------------------------------


--

Once you have a pointer to an ofxSmartFont instance you can call any [ofTrueType](http://openframeworks.cc/documentation/graphics/ofTrueTypeFont.html) method on it + a few additional convenience methods:

	// draw a string at 100, 100 // 
	helvetica_12pt->draw("hello", 100, 100);
	
	// get the bounding box for a string // 
	ofRectangle rect = helvetica_12pt->rect("hello");
	
	// get the width of a string // 
	int width = helvetica_12pt->width("hello");
	
	// get the height of a string // 
	int height = helvetica_12pt->height("hello");
	
	// set the name //
	helvetica_12pt->name("my_first_font");
	
	// get the name //
	string name = helvetica_12pt->name();
	
	// get the font size //
	int size = helvetica_12pt->size();
	
	// get the file name //
	string file = helvetica_12pt->file();
	
	
	

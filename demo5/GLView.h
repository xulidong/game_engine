#ifndef __GLVIEW_H__
#define __GLVIEW_H__

#include "Geometry.h"

#include <iostream>

class GLView {
    public:
        virtual ~GLView() {}
        virtual void setViewName(const std::string& viewname);
        virtual void setFrameSize(float width, float height); 
        virtual bool windowShouldClose(); 
    protected:
        std::string _viewName;
        Size _designResolutionSize;
        Size _screenSize;
};

void GLView::setViewName(const std::string& viewname) {
    _viewName = viewname; 
}

void GLView::setFrameSize(float width, float height) {
    _designResolutionSize = _screenSize = Size(width, height);
}

bool GLView::windowShouldClose() { 
    return false;
};

#endif

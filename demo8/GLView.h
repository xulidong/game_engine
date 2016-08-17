#ifndef __GLVIEW_H__
#define __GLVIEW_H__

#include "Geometry.h"
#include "Ref.h"

#include <iostream>

class GLView: public Ref {
    public:
        virtual ~GLView() {}
        virtual void setViewName(const std::string& viewname);
        virtual void setFrameSize(float width, float height); 
        virtual bool windowShouldClose(); 
        virtual void pollEvents();
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

void GLView::pollEvents() {
}

#endif

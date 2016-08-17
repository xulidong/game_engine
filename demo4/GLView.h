#ifndef __GLVIEW_H__
#define __GLVIEW_H__

#include "Geometry.h"

class GLView {
    public:
        virtual ~GLView() {}
        virtual void setViewName(const std::string& viewname) {
            _viewName = viewname; 
        }
        virtual void setFrameSize(float width, float height) {
            _designResolutionSize = _screenSize = Size(width, height);
        }
    protected:
        std::string _viewName;
        Size _designResolutionSize;
        Size _screenSize;
};

#endif

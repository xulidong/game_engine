#ifndef __GLVIEWIMPL_H__
#define __GLVIEWIMPL_H__

#include "GLView.h"

class GLViewImpl: public GLView {
    public:
        static GLViewImpl* createWithRect(const std::string& viewName, Rect rect); 
        bool initWithRect(const std::string& viewName, Rect rect);
};

GLViewImpl* GLViewImpl::createWithRect(const std::string& viewName, Rect rect) {
    GLViewImpl* ret = new GLViewImpl; 
    if (ret && ret->initWithRect(viewName, rect)) {
        // ret->autorelease;// 后面再看内存管理
        return ret;
    }
    if (ret != NULL) {
        delete ret;
        ret = NULL;
    }
    return NULL;
}

bool GLViewImpl::initWithRect(const std::string& viewName, Rect rect) {
    setViewName(viewName);
    setFrameSize(rect.size.width, rect.size.height);
}

#endif

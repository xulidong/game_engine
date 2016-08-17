#ifndef __GLVIEWIMPL_H__
#define __GLVIEWIMPL_H__

#include "GLView.h"

/*
 * GLView在不同平台下的实现
 * 因平台不同会有差异
 * */

class GLViewImpl: public GLView {
    public:
        static GLViewImpl* createWithRect(const std::string& viewName, Rect rect); 

        virtual bool windowShouldClose(); 

        void pollEvents();
    protected:
        bool initWithRect(const std::string& viewName, Rect rect);
        // GLFWwindow* _mainWindow;
};

GLViewImpl* GLViewImpl::createWithRect(const std::string& viewName, Rect rect) {
    GLViewImpl* ret = new GLViewImpl; 
    if (ret && ret->initWithRect(viewName, rect)) {
        ret->autorelease();// 后面再看内存管理
        return ret;
    }
    if (ret != NULL) {
        delete ret;
        ret = NULL;
    }
    return NULL;
}

bool GLViewImpl::windowShouldClose() { 
    /*
    // 判断OpenGL窗口是否关闭
    if (_mainWindow) {
        return glfwWindowShouldClose(_mainWindow) ? true : false; 
    } else {
        return true; 
    }
    */
    return false;
};

bool GLViewImpl::initWithRect(const std::string& viewName, Rect rect) {
    setViewName(viewName);
    setFrameSize(rect.size.width, rect.size.height);
    // glfwCreateWindow() 创建主窗口
    return true;
}

void GLViewImpl::pollEvents() {
    // 可以参考:http://bullteacher.com/4-hello-window.html
    // glfwPollEvents();
}

#endif

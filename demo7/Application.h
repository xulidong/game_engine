#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "ApplicationProtocol.h"
#include "Director.h"
#include "GLView.h"

#include <iostream>

class Application: public ApplicationProtocol {
    public:
        Application(); 
        static Application* getInstance(); 
        int run(); 
    protected:
        static Application * sm_pSharedApplication;
};

Application * Application::sm_pSharedApplication = 0;

Application::Application() {
    sm_pSharedApplication = this;
}

Application* Application::getInstance() {
    return sm_pSharedApplication;
}

int Application::run() {
    if (!applicationDidFinishLaunching()) {
        return 1;
    }
    Director* director = Director::getInstance();
    GLView* glview = director->getOpenGLView();
    glview->retain();
   
    while(!glview->windowShouldClose()) {
        director->mainLoop();
        glview->pollEvents();
    }

    glview->release();
    
    return 0;
}

#endif

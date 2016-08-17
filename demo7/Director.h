#ifndef __DIRECTOR_H__
#define __DIRECTOR_H__

#include "GLView.h"
#include "Renderer.h"
#include "Ref.h"
#include "AutoreleasePool.h"

#include <iostream>

class Director: public Ref {
    public:
        static Director* getInstance();

        Director(); 
        virtual ~Director();
        virtual bool init();
        virtual void mainLoop() = 0;
        
        GLView* getOpenGLView(); 
        void setOpenGLView(GLView *openGLView); 
        void drawScene();
    private:
        GLView *_openGLView;
        Renderer *_renderer;
};

class DisplayLinkDirector : public Director {
    public:
       virtual void mainLoop();
};

static DisplayLinkDirector *s_SharedDirector = NULL;

Director* Director::getInstance()
{
    if (!s_SharedDirector) {
        s_SharedDirector = new DisplayLinkDirector;
        s_SharedDirector->init();
    }
    return s_SharedDirector;
}

Director::Director() {
    _openGLView = NULL;
}

Director::~Director() {
    if (NULL == _renderer) {
        delete _renderer;
        _renderer = NULL;
    }
}

GLView* Director::getOpenGLView() { 
    return _openGLView;
}

bool Director::init(){ 
    _renderer = new Renderer;
    return true; 
}

void Director::setOpenGLView(GLView *openGLView) {
    if (_openGLView != openGLView) {
        if (_openGLView) {
            // 释放已经存在的视图对象, 后面再看
        }
        _openGLView = openGLView;
    }
}

void Director::drawScene() {
    _renderer->render();
}

/*
 * DisplayLinkDirector
 * */
void DisplayLinkDirector::mainLoop() {
    drawScene();
    // 每一帧都会检测自动释放池
    PoolManager::getInstance()->getCurrentPool()->clear();
}

#endif

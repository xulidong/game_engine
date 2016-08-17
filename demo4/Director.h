#ifndef __DIRECTOR_H__
#define __DIRECTOR_H__

#include "GLView.h"

class Director {
    public:
        Director() {
            _openGLView = NULL;
        }
        virtual ~Director() {}
        static Director* getInstance();
        GLView* getOpenGLView() { return _openGLView; }
        virtual bool init(){ return true; }
        void setOpenGLView(GLView *openGLView) {
            if (_openGLView != openGLView) {
                if (_openGLView) {
                    // 释放已经存在的视图对象, 后面再看
                }
                _openGLView = openGLView;
            }
        }
    private:
        GLView *_openGLView;
};

class DisplayLinkDirector : public Director {
    public:

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

#endif

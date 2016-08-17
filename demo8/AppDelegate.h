#ifndef __APP_DELEGATE_H__
#define __APP_DELEGATE_H__

#include "Application.h"
#include "Director.h"
#include "GLView.h"
#include "GLViewImpl.h"
#include "Geometry.h"
#include "Node.h"

#include <iostream>

class AppDelegate: private Application {
    public:
        virtual bool applicationDidFinishLaunching(); 
};

bool AppDelegate::applicationDidFinishLaunching() {
    Director* director = Director::getInstance();
    GLView* glview = director->getOpenGLView();
    if (!glview) {
        glview = GLViewImpl::createWithRect("WinName", Rect(0, 0, 960, 640));
        director->setOpenGLView(glview);
    }
    Node* node = Node::create();
    node->setName("parent");
    Node* lnode = Node::create();
    lnode->setName("child");
    node->addChild(lnode);

    std::cout << lnode->getParent()->getName() << std::endl;
    std::cout << lnode->getName() << std::endl;

    return true;
}

#endif

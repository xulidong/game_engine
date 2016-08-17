#ifndef __APP_DELEGATE_H__
#define __APP_DELEGATE_H__

#include "Application.h"

class AppDelegate: private Application {
    virtual bool applicationDidFinishLaunching() { 
        std::cout << "delegate applicationDidFinishLaunching" << std::endl;
        return true;
    }
};

#endif

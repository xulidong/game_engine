#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "ApplicationProtocol.h"

#include <iostream>

class Application: public ApplicationProtocol {
    public:
        Application() {
            sm_pSharedApplication = this;
        }
        static Application* getInstance() {
            return sm_pSharedApplication;
        }
        int run() {
            if (!applicationDidFinishLaunching()) {
                return 1;
            }
        }
    protected:
        static Application * sm_pSharedApplication;
};

Application * Application::sm_pSharedApplication = 0;

#endif

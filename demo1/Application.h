#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include <iostream>

class Application {
    public:
        Application() {
            sm_pSharedApplication = this;
        }
        static Application* getInstance() {
            return sm_pSharedApplication;
        }
        int run() {
            std::cout << "App run ..." << std::endl;
        }
    protected:
        static Application * sm_pSharedApplication;
};

Application * Application::sm_pSharedApplication = 0;

#endif

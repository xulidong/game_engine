#ifndef __APPLICATION_PROTOCOL_H__
#define __APPLICATION_PROTOCOL_H__

class ApplicationProtocol {
    public:
        virtual ~ApplicationProtocol(){}
        virtual bool applicationDidFinishLaunching() = 0;        
};

#endif

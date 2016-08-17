#ifndef __DIRECTOR_H__
#define __DIRECTOR_H__

class Director {
    public:
        virtual ~Director() {}
        static Director* getInstance();
        virtual bool init(){ return true; }
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

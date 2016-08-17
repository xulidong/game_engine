#ifndef __REF_H__
#define __REF_H__

class Ref {
    public:
        void retain();
        void release();
        Ref* autorelease();
        unsigned int getReferenceCount() const;
    public:
        virtual ~Ref();
        unsigned int _referenceCount;
    
    protected:
        Ref();
        friend class AutoreleasePool;
};

// 默认引用计数为1
Ref::Ref() : _referenceCount(1) {
}

Ref::~Ref() {
}

void Ref::retain() {
    ++_referenceCount;
}

void Ref::release() {
    --_referenceCount;
    if (0 == _referenceCount) {
        delete this;  
    }
}

#include "AutoreleasePool.h"

unsigned int Ref::getReferenceCount() const{
    return _referenceCount;
}

Ref* Ref::autorelease()
{
    PoolManager::getInstance()->getCurrentPool()->addObject(this);
    return this;
}

#endif

#ifndef __REF_H__
#define __REF_H__

class Ref {
    public:
        void retain();
        void release();
        unsigned int getReferenceCount() const;

    public:
        virtual ~Ref();
        unsigned int _referenceCount;
    
    protected:
        Ref();
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

unsigned int Ref::getReferenceCount() const{
    return _referenceCount;
}

#endif

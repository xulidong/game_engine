#ifndef __AUTORELEASEPOOL_H__
#define __AUTORELEASEPOOL_H__

#include <string>
#include <vector>
#include "Ref.h"

class AutoreleasePool {
    public:
        AutoreleasePool();
        AutoreleasePool(const std::string &name);
        ~AutoreleasePool();
        void addObject(Ref *object);
        void clear();
        bool contains(Ref* object) const;
    private:
        std::vector<Ref*> _managedObjectArray;// 对象数组，存放自动释放的对象
        std::string _name;// 释放池名字
};

class PoolManager {
    public:
        static PoolManager* getInstance();
        static void destroyInstance();

        AutoreleasePool *getCurrentPool() const;
        bool isObjectInPools(Ref* obj) const;

        friend class AutoreleasePool; 
    private:
        PoolManager();
        ~PoolManager();
    
        void push(AutoreleasePool *pool);
        void pop();

        static PoolManager* s_singleInstance;
        std::vector<AutoreleasePool*> _releasePoolStack;
};

AutoreleasePool::AutoreleasePool(): _name("") {
    _managedObjectArray.reserve(150);
   PoolManager::getInstance()->push(this);
}

AutoreleasePool::AutoreleasePool(const std::string &name): _name(name) {
    _managedObjectArray.reserve(150);
   PoolManager::getInstance()->push(this);
}

AutoreleasePool::~AutoreleasePool() {
    clear();
    PoolManager::getInstance()->pop();
}

void AutoreleasePool::clear() {
    // 与一个默认大小的vector交换，使其恢复到默认大小
    // 再释放临时的vector对象，已达到释放内存，恢复到默认大小的目的
    std::vector<Ref*> releasings;
    releasings.swap(_managedObjectArray);
    std::vector<Ref*>::iterator it = releasings.begin();
    for (; it != releasings.end(); it++) {
        (*it)->release();
    }
}

bool AutoreleasePool::contains(Ref* object) const {
    std::vector<Ref*>::const_iterator it = _managedObjectArray.begin();
    for (; it != _managedObjectArray.end(); it++) {
        if(object == (*it)) {
            return true;
        }
    }
    return false;
}

void AutoreleasePool::addObject(Ref* object) {
    _managedObjectArray.push_back(object);
}

/*
 * PoolManager
 * */
PoolManager* PoolManager::s_singleInstance = NULL;

PoolManager* PoolManager::getInstance() {
    if (NULL == s_singleInstance) {
        s_singleInstance = new PoolManager();
        // 创建单例的后悔初始化自动释放池
        new AutoreleasePool("cocos2d autorelease pool");
    }
    return s_singleInstance;
}

void PoolManager::destroyInstance() {
    delete s_singleInstance;
    s_singleInstance = NULL;
}

PoolManager::PoolManager() {
    _releasePoolStack.reserve(10);
}

PoolManager::~PoolManager() {
    while (!_releasePoolStack.empty()) {
        AutoreleasePool* pool = _releasePoolStack.back();
        delete pool;
    }
}

AutoreleasePool* PoolManager::getCurrentPool() const {
    return _releasePoolStack.back();
}

bool PoolManager::isObjectInPools(Ref* obj) const {
    std::vector<AutoreleasePool*>::const_iterator it =  _releasePoolStack.begin();
    for (;it != _releasePoolStack.end(); ++it) {
       if ((*it)->contains(obj)) {
            return true; 
       } 
    }
    return false;
}

void PoolManager::push(AutoreleasePool *pool) {
    _releasePoolStack.push_back(pool);
}

void PoolManager::pop() {
    if (!_releasePoolStack.empty()) {
        _releasePoolStack.pop_back();
    }
}

#endif

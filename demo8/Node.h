#ifndef __NODE_H__
#define __NODE_H__

#include "Ref.h"

#include <vector>

class Node: Ref {
    public:
        static const int INVALID_TAG = -1;
        static Node* create();

        Node();
        virtual ~Node();
        virtual bool init();

        virtual void setTag(int tag);
        virtual int getTag() const;
        virtual const std::string& getName() const; 
        virtual void setName(const std::string& name);

        virtual void addChild(Node * child);
        virtual void addChild(Node * child, int localZOrder);
        virtual void addChild(Node* child, int localZOrder, int tag);
        virtual void addChild(Node* child, int localZOrder, const std::string &name);
        
        virtual Node* getParent();
    protected:
        void childrenAlloc(void);
        void insertChild(Node* child, int z);
        void setParent(Node * parent);


        Node *_parent;
        std::vector<Node*> _children;//所有子节点集合
        int _localZOrder;// z轴
        int _tag;// node标记
        std::string _name;// node名字
    private:
        void addChildHelper(Node* child, int localZOrder, int tag, const std::string &name, bool setTag);
};

Node::Node()
: _parent(NULL)
, _localZOrder(0) 
, _tag(INVALID_TAG)
, _name("")
{}

Node::~Node() {
}

Node* Node::create() {
    Node* ret = new Node();
    if (ret && ret->init()) {
        ret->autorelease();
    } else {
        if (ret != NULL) {
            delete ret;
            ret = NULL;
        }
    }
    return ret;
}

bool Node::init() {
    return true;
}

void Node::childrenAlloc() {
    _children.reserve(4);
}

void Node::insertChild(Node* child, int z) {
    _children.push_back(child);
    child->_localZOrder = z;
}
void Node::setParent(Node * parent) {
    _parent = parent;
}

Node* Node::getParent() { 
    return _parent; 
}

void Node::setTag(int tag) {
    _tag = tag ;
}

int Node::getTag() const {
    return _tag;
}

void Node::setName(const std::string& name) {
    _name = name;
}

const std::string& Node::getName() const {
    return _name;
}

void Node::addChild(Node *child, int zOrder) {
    this->addChild(child, zOrder, child->_name);
}

void Node::addChild(Node *child) {
    addChild(child, child->_localZOrder, child->_name);
}

void Node::addChild(Node *child, int localZOrder, int tag) {
   addChildHelper(child, localZOrder, tag, "", true);
}

void Node::addChild(Node* child, int localZOrder, const std::string &name) {
    addChildHelper(child, localZOrder, INVALID_TAG, name, false);
}

void Node::addChildHelper(Node* child, int localZOrder, int tag, const std::string &name, bool setTag) {
    if (_children.empty()) {
       childrenAlloc(); 
    }    
    insertChild(child, localZOrder);
    child->setParent(this);

    if (setTag) {
        child->setTag(tag);
    } else {
        child->setName(name); 
    }
}

#endif

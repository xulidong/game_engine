#ifndef __GEMMETRY_H__
#define __GEMMETRY_H__

class Size {
    public:
        Size() {}
        Size(float width, float height) {
            this->width = width;
            this->height = height;
        }

        float width;
        float height;
};

class Vec2 {
    public:
        Vec2() {}
        Vec2(float x, float y) {
            this->x = x;
            this->y = y;
        }
        float x;
        float y;
};

class Rect {
    public:
        Rect() {}
        Rect(float x, float y, float width, float height) {
            origin.x = x;
            origin.y = y;

            size.width = width;
            size.height = height;
        }
        Vec2 origin;
        Size  size;
};

#endif

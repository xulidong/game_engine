#ifndef __RENDERER_H__
#define __RENDERER_H__

#include <iostream>

class Renderer {
    public:
        void render();
};

void Renderer::render() {
    // 调用OpenGL接口渲染
    std::cout << "render..." << std::endl;
}

#endif

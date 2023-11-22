//
// Created by ffernandoalves on 16/11/2023.
//

#ifndef NSENGINE_RENDERER_HPP
#define NSENGINE_RENDERER_HPP

//#include "debug.h"

#include "shader.hpp"

class RendererBase {
public:
    virtual void render() {}
};

class Renderer: public RendererBase {
public:
    void render() override;
};

#endif //NSENGINE_RENDERER_HPP
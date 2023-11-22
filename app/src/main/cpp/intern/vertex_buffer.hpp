//
// Created by ffernandoalves on 18/11/2023.
//

#ifndef NSENGINE_VERTEX_BUFFER_HPP
#define NSENGINE_VERTEX_BUFFER_HPP

#include "types.hpp"
#include "renderer.hpp"

using namespace NSEngine::types;

class VertexBuffer {
private:
    id_type m_renderer_id;
public:
    VertexBuffer(const vec<GLfloat>& vertices);
    VertexBuffer() = default;
    ~VertexBuffer();

    void Set(const vec<GLfloat>& vertices);
    void Bind() const;
    void Unbind() const;
};

#endif //NSENGINE_VERTEX_BUFFER_HPP
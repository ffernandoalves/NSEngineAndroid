//
// Created by ffernandoalves on 18/11/2023.
//

#ifndef NSENGINE_INDEX_BUFFER_HPP
#define NSENGINE_INDEX_BUFFER_HPP

#include "types.hpp"
#include "renderer.hpp"

using namespace NSEngine::types;

class IndexBuffer {
private:
    id_type m_renderer_id;
    GLuint m_count;
public:
    IndexBuffer(const vec<GLuint>& index);
    IndexBuffer() = default;
    ~IndexBuffer();

    void Set(const vec<GLuint>& index);
    void Bind() const;
    void Unbind() const;

    inline GLuint GetCount() const {
        return m_count;
    }
};

#endif //NSENGINE_INDEX_BUFFER_HPP
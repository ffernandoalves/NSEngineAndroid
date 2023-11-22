//
// Created by ffernandoalves on 18/11/2023.
//

#include "index_buffer.hpp"


IndexBuffer::IndexBuffer(const vec<GLuint>& index)
    : m_count(static_cast<GLuint>(index.size())) {
    GLCall(glGenBuffers(1, &m_renderer_id));
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_renderer_id));
    GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, static_cast<GLsizeiptr>(m_count * sizeof(GLuint)),index.data(), GL_STATIC_DRAW));
}

void IndexBuffer::Set(const vec<GLuint>& index) {
    m_count = static_cast<GLuint>(index.size());
    GLCall(glGenBuffers(1, &m_renderer_id));
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_renderer_id));
    GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, static_cast<GLsizeiptr>(m_count * sizeof(index[0])), index.data(), GL_STATIC_DRAW));
}

IndexBuffer::~IndexBuffer() {
    GLCall(glDeleteBuffers(1, &m_renderer_id));
}

void IndexBuffer::Bind() const {
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_renderer_id));
}

void IndexBuffer::Unbind() const {
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}
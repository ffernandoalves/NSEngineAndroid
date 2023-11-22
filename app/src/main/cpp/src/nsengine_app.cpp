//
// Created by ffernandoalves on 18/11/2023.
//

#include "nsengine_app.hpp"


using namespace NSEngine;

// for debug
void printMat4(const glm::mat4& M) {
    ALOGE("%s\n", glm::to_string(M).c_str());
}

Engine::Engine() {
    engine_clock.setClock();
}

void Engine::Init(vec<GLfloat>& positions, const vec<GLuint>& indices) {
    last_time = engine_clock.getEngineCurrentTime();

    GLCall(glViewport(0, 0, m_screen_width, m_screen_height));

    shader.init_shader();

    GLCall(glGenVertexArrays(1, &vao));
    GLCall(glBindVertexArray(vao));

    for(float & position : positions) {
        position *= .7f;
    }

    vb.Set(positions);
    GLCall(glEnableVertexAttribArray(0));
    GLCall(glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr));

    ib.Set(indices);

    vb.Unbind();
    ib.Unbind();
}

void Engine::Resize(u16 width, u16 height) {
    m_screen_height = height;
    m_screen_width = width;
    glViewport(0, 0, m_screen_width, m_screen_height);
}

void Engine::Render() {
    GLCall(glClearColor(0.2f, 0.3f, 0.3f, 1.0f));
    GLCall(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));

    shader.useProgram();

    current_time = engine_clock.getEngineCurrentTime();
    double dt = current_time - last_time;
    cube_angle += static_cast<float>(dt) * 150.0f;
    if (cube_angle >= 360.0) {
        cube_angle = 0.0f;
    }

    GLCall(GLint vcolor = glGetUniformLocation(shader.GetShaderId(), "vcolor"));
    GLCall(glUniform3f(vcolor, 1.0f, 0.0f, 0.0f));

    glm::mat4 model = glm::mat4(1.0f);
    glm::mat4 view = glm::mat4(1.0f);
    glm::mat4 projection = glm::mat4(1.0f);

    model = glm::translate(model, cube_pos) * glm::rotate(model, glm::radians(cube_angle), glm::vec3(0.0f, 1.0f, 0.0f));
    view = glm::lookAt(cam_pos, target_pos, up);
    projection = glm::perspective(glm::radians(45.0f), static_cast<float>(m_screen_width)/static_cast<float>(m_screen_height), 0.1f, 100.0f);

    GLint model_loc, view_loc, proj_loc;
    GLCall(model_loc = glGetUniformLocation(shader.GetShaderId(), "model"));
    GLCall(glUniformMatrix4fv(model_loc, 1, GL_FALSE, glm::value_ptr(model)));

    GLCall(view_loc = glGetUniformLocation(shader.GetShaderId(), "view"));
    GLCall(glUniformMatrix4fv(view_loc, 1, GL_FALSE, glm::value_ptr(view)));

    GLCall(proj_loc = glGetUniformLocation(shader.GetShaderId(), "projection"));
    GLCall(glUniformMatrix4fv(proj_loc, 1, GL_FALSE, glm::value_ptr(projection)));

    GLCall(glBindVertexArray(vao));
    ib.Bind();

    GLCall(glDrawElements(GL_LINE_STRIP, static_cast<GLsizei>(ib.GetCount()), GL_UNSIGNED_INT, nullptr));

    // update timer
    last_time = current_time;
}
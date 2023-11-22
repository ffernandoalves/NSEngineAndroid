//
// Created by ffernandoalves on 18/11/2023.
//

#ifndef NSENGINE_NSENGINE_APP_HPP
#define NSENGINE_NSENGINE_APP_HPP

#include "base.hpp"
#include "utils.hpp"
#include "types.hpp"
#include "vertex_buffer.hpp"
#include "index_buffer.hpp"


using namespace NSEngine::types;

namespace NSEngine {
    class Engine {
    private:
        GLuint vao = 0;
        Shader shader;
        f32 cube_angle = 0.0f;
        glm::vec3 cube_pos{0.0f, 0.0f, -5.0f};
        glm::vec3 cam_pos{0.0f, 0.0f, 0.0f};
        glm::vec3 target_pos{0.0f, 0.0f, -1.0f};
        glm::vec3 up{0.0f, 1.0f, 0.0f};

        u16 m_screen_height = 0;
        u16 m_screen_width = 0;

        VertexBuffer vb;
        IndexBuffer ib;

        // timer
        Utils::Clock engine_clock;
        double current_time, last_time;

    public:
        Engine();
        void Init(vec<GLfloat>& positions, const vec<GLuint>& indices);
        void Resize(u16 width, u16 height);
        void Render(void);
    };
}

#endif //NSENGINE_NSENGINE_APP_HPP
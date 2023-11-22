//
// Created by ffernandoalves on 15/11/2023.
//

#ifndef NSENGINE_SHADER_HPP
#define NSENGINE_SHADER_HPP

#include "debug.hpp"

static const char VERTEX_SHADER[] =
"#version 300 es\n"
"layout(location = 0) in vec3 position;\n"
"uniform vec3 vcolor;\n"
"uniform mat4 model;\n"
"uniform mat4 view;\n"
"uniform mat4 projection;\n"
"out vec3 frag_color;\n"
"void main() {\n"
"    gl_Position = projection * view * model * vec4(position, 1.0);\n"
//"    gl_Position = vec4(position, 1.0);\n"
"    frag_color = vcolor;\n"
"}\n";

static const char FRAGMENT_SHADER[] =
"#version 300 es\n"
"precision mediump float;\n"
"in vec3 frag_color;\n"
"out vec4 outColor;\n"
"void main() {\n"
//"    outColor = vec4(1.0, 0.0, 0.0, 1.0);\n"
"    outColor = vec4(frag_color, 1.0);\n"
"}\n";

struct ShaderProgramSource {
    std::string vertex_source;
    std::string fragment_source;
};

class Shader {
private:
    GLuint shader_program;
public:
    Shader(): shader_program(0) {}
    void init_shader();
    void useProgram() const;
    void SetShaderId(GLuint id);
    GLuint GetShaderId() const;
    GLuint loadShader(GLenum shader_type, const std::string&);
    GLuint createProgram(const std::string&, const std::string&);
    ShaderProgramSource parserShader(const std::string& filepath) {
        std::ifstream stream(filepath);
        enum class ShaderType {
            NONE = -1, VERTEX = 0, FRAGMENT = 1
        };
        std::string line;
        std::stringstream ss[2];
        ShaderType type = ShaderType::NONE;
        while (std::getline(stream, line)) {
            if (line.find("#shader") != std::string::npos) {
                if (line.find("vertex") != std::string::npos) {
                    type = ShaderType::VERTEX;
                } else if (line.find("fragment") != std::string::npos) {
                    type = ShaderType::FRAGMENT;
                }
            } else {
                if (type != ShaderType::NONE) {
                    ss[static_cast<int>(type)] << line << "\n";
                } else {
                    std::cerr << "Não foi possível encontrar nenhum shader no arquivo \"" << filepath << "\"." << std::endl;
                }
//                ss[static_cast<int>(type)] << line << "\n";
            }
        }
        return {ss[0].str(), ss[1].str()};
    }
};

#endif //NSENGINE_SHADER_HPP
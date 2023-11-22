//
// Created by ffernandoalves on 16/11/2023.
//

#include "shader.hpp"

GLuint Shader::loadShader(GLenum shader_type, const std::string& shader_source) {
    GLuint shader_id = 0;
    GLCall(shader_id = glCreateShader(shader_type));
    const char* source = shader_source.c_str();
    GLCall(glShaderSource(shader_id, 1, &source, nullptr));
    GLCall(glCompileShader(shader_id));

    //Verifique se a compilação foi bem-sucedida
    GLint success;
    GLCall(glGetShaderiv(shader_id, GL_COMPILE_STATUS, &success));
    if (success == GL_FALSE) {
        GLint length;
        GLCall(glGetShaderiv(shader_id, GL_INFO_LOG_LENGTH, &length));
        GLsizei log_length = 0;
        int max_length = 1024;
        GLchar message[max_length];
        GLCall(glGetShaderInfoLog(shader_id, max_length, &log_length, message));

        std::string t = shader_type == GL_VERTEX_SHADER ? "vertex" : "fragment";
        ALOGE("Failed to compile %s shader!\n", t.c_str());
        ALOGE("%s\n", message);

        GLCall(glDeleteShader(shader_id));
        return 0;
    }

    return shader_id;
}

void Shader::SetShaderId(GLuint id) {
    shader_program = id;
}

GLuint Shader::GetShaderId() const {
    return shader_program;
}

void Shader::init_shader() {
    GLuint id = createProgram(VERTEX_SHADER, FRAGMENT_SHADER);
    SetShaderId(id);
    useProgram();
}

void Shader::useProgram() const {
    GLCall(glUseProgram(shader_program));
}

GLuint Shader::createProgram(const std::string& vertex_shader_source, const std::string& fragment_shader_source) {
    GLuint vertex_shader_id = loadShader(GL_VERTEX_SHADER, vertex_shader_source);
    GLuint fragment_shader_id = loadShader(GL_FRAGMENT_SHADER, fragment_shader_source);

    GLuint shader_program_id = 0;
    GLCall(shader_program_id = glCreateProgram());
    GLCall(glAttachShader(shader_program_id, vertex_shader_id));
    GLCall(glAttachShader(shader_program_id, fragment_shader_id));
    GLCall(glLinkProgram(shader_program_id));
    GLCall(glValidateProgram(shader_program_id));

    // Verifique se a ligação foi bem-sucedida
    GLint success;
    GLCall(glGetProgramiv(shader_program_id, GL_LINK_STATUS, &success));
    if (success == GL_FALSE) {
        char info_log[512];
        GLCall(glGetProgramInfoLog(shader_program_id, 512, nullptr, info_log));
        ALOGE("Erro na ligação do programa: %s\n", info_log);
        return 0;
    }
    GLCall(glDeleteShader(vertex_shader_id));
    GLCall(glDeleteShader(fragment_shader_id));
    return shader_program_id;
}

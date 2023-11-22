//
// Created by ffernandoalves on 15/11/2023.
//

#ifndef NSENGINE_DEBUG_HPP
#define NSENGINE_DEBUG_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <csignal>


#include <android/log.h>
#define DEBUG 1

#define LOG_TAG "GLES3JNI"
#define ALOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)
#if DEBUG
#define ALOGV(...) \
  __android_log_print(ANDROID_LOG_VERBOSE, LOG_TAG, __VA_ARGS__)
#else
#define ALOGV(...)
#endif


#include <GLES3/gl3.h>

#define DEBUG_BREAK raise(SIGTRAP);
#define PATH_SEP "/"

#define ASSERT(x) if (!(x)) DEBUG_BREAK;
#define GLCall(x) GLClearError();\
    x;\
    ASSERT(GLLogCall(#x, __FILE__, __LINE__))

[[maybe_unused]] static void GLClearError() {
    while (glGetError() != GL_NO_ERROR);
}

[[maybe_unused]] static bool GLLogCall(const char* function, const char* file, int line) {
    while (GLenum error = glGetError()) {
        std::stringstream  s;
        s << std::hex << error << std::dec;
        std::string result = s.str();
        ALOGE("[OpenGL Error] (%s) %s: %s\n", result.c_str(), file, std::to_string(line).c_str());
        return false;
    }
    return true;
}

#endif //NSENGINE_DEBUG_HPP
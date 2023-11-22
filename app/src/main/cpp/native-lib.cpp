#include <jni.h>
#include <string>

#include "nsengine_app.hpp"

using namespace NSEngine;

Engine nsengine_app;


vec<f32> vertices {
        // Vértice frontal
        -1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 1.0f,
        1.0f, -1.0f, 1.0f,
        -1.0f, -1.0f, 1.0f,
        // Vértice superior
        -1.0f, 1.0f, -1.0f,
        1.0f, 1.0f, -1.0f,
        1.0f, 1.0f, 1.0f,
        -1.0f, 1.0f, 1.0f,
        // Vértice esquerdo
        -1.0f, 1.0f, 1.0f,
        -1.0f, 1.0f, -1.0f,
        -1.0f, -1.0f, -1.0f,
        -1.0f, -1.0f, 1.0f,
        // Vértice inferior
        -1.0f, -1.0f, 1.0f,
        1.0f, -1.0f, 1.0f,
        1.0f, -1.0f, -1.0f,
        -1.0f, -1.0f, -1.0f,
        // Vértice direito
        1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, -1.0f,
        1.0f, -1.0f, -1.0f,
        1.0f, -1.0f, 1.0f,
        // Vértice traseiro
        -1.0f, -1.0f, -1.0f,
        1.0f, -1.0f, -1.0f,
        1.0f, 1.0f, -1.0f,
        -1.0f, 1.0f, -1.0f
};

const vec<GLuint> indices {
        // Face frontal
        0, 1, 1, 2,
        2, 3, 3, 0,
        // Face superior
        4, 5, 5, 6,
        6, 7, 7, 4,
        // Arestas entre faces
        0, 4, 1, 5,
        2, 6, 3, 7,
        // Face traseira
        8, 9, 9, 10,
        10, 11, 11, 8,
        // Face inferior
        12, 13, 13, 14,
        14, 15, 15, 12,
        // Arestas entre faces
        8, 12, 9, 13,
        10, 14, 11, 15,
        // Face esquerda
        16, 17, 17, 18,
        18, 19, 19, 16,
        // Arestas entre faces
        12, 16, 13, 17,
        14, 18, 15, 19,
        // Face direita
        20, 21, 21, 22,
        22, 23, 23, 20,
        // Arestas entre faces
        16, 20, 17, 21,
        18, 22, 19, 23
};


// for tests
//extern "C" JNIEXPORT jstring JNICALL
//Java_com_codexspark_nsengine_MainActivity_stringFromJNI(
//        JNIEnv* env,
//        jobject /* this */) {
//    std::string hello = "Hello from C++";
//    return env->NewStringUTF(hello.c_str());
//}

extern "C" JNIEXPORT void JNICALL Java_com_codexspark_nsengine_NSEngineLib_init(JNIEnv* env, jobject obj) {
    nsengine_app.Init(vertices, indices);
}

extern "C" JNIEXPORT void JNICALL Java_com_codexspark_nsengine_NSEngineLib_resize(JNIEnv* env, jobject obj, jint width, jint height) {
    nsengine_app.Resize(static_cast<u16>(width), static_cast<u16>(height));
}

extern "C" JNIEXPORT void JNICALL Java_com_codexspark_nsengine_NSEngineLib_render(JNIEnv* env, jobject obj) {
    nsengine_app.Render();
}
/*
  ==============================================================================

    OpenGL.cpp
    Created: 25 Aug 2018 4:35:09pm
    Author:  Daniel Almeida

  ==============================================================================
*/

#include "OpenGL.h"
OpenGL::OpenGL()
{
    //initVAO();
    initVBO();
    
    initShaders();
}

OpenGL::~OpenGL()
{
    
}


void OpenGL::draw()
{
    //GLint posAttrib = glGetAttribLocation(shaderProgram, "position");
    //glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 0, 0);
    //glEnableVertexAttribArray(posAttrib);
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glUseProgram(shaderProgram);
   
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glVertexAttribPointer(0,
                          3,
                          GL_FLOAT,
                          GL_FALSE,
                          0,
                          (void*) 0);
    
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glDisableVertexAttribArray(0);
}

GLuint OpenGL::loadShader(
                          GLuint shaderType,
                          const char* source
                          )
{
    GLuint shader;
    
    shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(shader, 1, &source, NULL);
    glCompileShader(shader);
    
    GLint status;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
    if (status != GL_TRUE) {
        char buffer[512];
        glGetShaderInfoLog(shader, 512, NULL, buffer);
        
        throw std::runtime_error(buffer);
    }

    
    return shader;
}


void OpenGL::initVAO(){
    /*
    void* ptr = OpenGLHelpers::getExtensionFunction("glGenVertexArrays");
    typedef void(*func_type)(GLsizei n, const GLuint *arrays);
    ((func_type)ptr)(1, &vao);
    
    ptr = OpenGLHelpers::getExtensionFunction("glBindVertexArray");
    typedef void(*func_type_2)(GLuint p1);
    ((func_type_2)ptr)(vao);
     */
    
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
}

void OpenGL::initVBO() {
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
}

void OpenGL::initShaders() {
    vertexShader = loadShader(GL_VERTEX_SHADER, vertexSource);
    fragmentShader = loadShader(GL_FRAGMENT_SHADER, fragmentSource);
    
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    //glLinkProgram(shaderProgram);
    
    // check program
    /*
    GLint result;
    int infoLogLength;
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &result);
    glGetProgramiv(shaderProgram, GL_INFO_LOG_LENGTH, &infoLogLength);
    if (infoLogLength > 0) {
        std::vector<char> programErrorMessage(infoLogLength + 1);
        //glGetProgramInfoLog(shaderProgram, infoLogLength, NULL, & (GLchar)programErrorMessage[0]);
        //throw new std::runtime_error(&programErrorMessage[0]);
    }
     */
    
    
    //glBindFragDataLocation(shaderProgram, 0, "outColor");
    //
    //glUseProgram(shaderProgram);
}

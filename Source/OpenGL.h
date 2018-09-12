/*
  ==============================================================================

    OpenGL.h
    Created: 25 Aug 2018 4:35:09pm
    Author:  Daniel Almeida

  ==============================================================================
 
    Information Sources:
    - https://open.gl/drawing
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

class OpenGL {
    /*!
     The Vertices to draw a rectangle that occupies the whole screen.
     This will produce the output area
     
     A (-1,1)    B (1,1)
     +-----------+
     |           |
     +-----------+
     D (-1,-1)   C (-1,1)
     */
    /*
    float vertices[8] = {
        -1.0f,  1.0f,  // A
        1.0f,  1.0f,   // B
        -1.0f,  1.0f,  //C
        -1.0f, -1.0f   //D
    };
     */
    float vertices[9] = {
    -1.0f, -1.0f, 0.0f,
    1.0f, -1.0f, 0.0f,
    0.0f,  1.0f, 0.0f,
    };
    
    /**! The Vertice Buffer */
    GLuint vbo;
    
    /**! Vertex Array Object */
    GLuint vao;
    
    /*!
     Vertex shader code
     */
    const char* vertexSource = R"glsl(
    varying vec2 position;
    
    void main()
    {
        gl_Position = vec4(position, 0.0, 1.0);
    }
    )glsl";
    
    
    /*!
     Fragment Shader code
     */
    const char* fragmentSource = R"glsl(
    varying vec4 outColor;
    
    void main()
    {
        outColor = vec4(0.1, 0.1, 0.1, 1.0);
    }
    )glsl";
    
    
    
    GLuint vertexShader, fragmentShader, shaderProgram;
public:
    
    /*!
     Constructor. Sets up everything for using OpenGL to render on the screen
     */
    OpenGL();
    
    /*!
     Destructor. Cleans up everything
     */
    ~OpenGL();
    
    
    /*!
     Draws the content
     */
    void draw();
    
private:
    
    /*!
     
     @param shaderType GL_VERTEX_SHADER
     
     @return GLuint
     */
    GLuint loadShader(
                      GLuint shaderType,
                      const char* source
                      );
    
    
    // STUFF
    
    void initShaders();
    void initVAO();
    void initVBO();
    
};

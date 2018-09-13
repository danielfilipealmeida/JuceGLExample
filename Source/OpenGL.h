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
    
    
    /*!
     Vertex shader code
     */
    const char* vertexSource = R"glsl(
    attribute vec4 position;
    attribute vec4 sourceColour;
    attribute vec2 textureCoordIn;
    
    uniform mat4 projectionMatrix;
    uniform mat4 viewMatrix;
    
    varying vec4 destinationColour;
    varying vec2 textureCoordOut;
    
    void main()
    {
        destinationColour = sourceColour;
        textureCoordOut = textureCoordIn;
        gl_Position = vec4(position);
    }
    )glsl";
    
    
    /*!
     Fragment Shader code
     */
    const char* fragmentSource = R"glsl(
    varying vec4 destinationColour;
    varying vec2 textureCoordOut;
    
    void main()
    {
        vec4 color = vec4(0.1, 0.5, 1.0, 1.0);
        gl_FragColor = color;
    }
    )glsl";
    
    
    
    GLuint vertexShader, fragmentShader, shaderProgram;
    
    std::unique_ptr<OpenGLShaderProgram::Attribute> position, normal, sourceColour, textureCoordIn;
    
public:
    
    /*!
     Constructor. Sets up everything for using OpenGL to render on the screen
     */
    OpenGL(OpenGLContext *context);
    
    /*!
     Destructor. Cleans up everything
     */
    ~OpenGL();
    
    
    /*!
     Draws the content
     */
    void draw();
    
private:
    std::unique_ptr<OpenGLShaderProgram> shader;
    OpenGLContext *openGLContext;
    
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
    void initVBO();
    
    static OpenGLShaderProgram::Attribute* createAttribute (OpenGLContext& context,
                                                            OpenGLShaderProgram& shader,
                                                            const String& name);
    
};

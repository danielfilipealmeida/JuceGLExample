/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    // Make sure you set the size of the component after
    // you add any child components.
    setSize (800, 600);
    
    
}

MainComponent::~MainComponent()
{
    delete gl;
    
    // This shuts down the GL system and stops the rendering calls.
    shutdownOpenGL();
}

//==============================================================================
void MainComponent::initialise()
{
    // Initialise GL objects for rendering here.
    
    try {
        gl = new OpenGL(&openGLContext);
    }
    catch(std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    
    
}

void MainComponent::shutdown()
{
    // Free any GL objects created for rendering here.
}

void MainComponent::render()
{
    jassert(OpenGLHelpers::isContextActive());
    
    
    auto desktopScale = (float) openGLContext.getRenderingScale();
    OpenGLHelpers::clear (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
    

}

//==============================================================================
void MainComponent::paint (Graphics& g)
{
    // You can add your component specific drawing code here!
    // This will draw over the top of the openGL background.
    
    gl->draw();
    
}

void MainComponent::resized()
{
    // This is called when the MainComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
}

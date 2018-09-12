/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "OpenGL.h"

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
 
 Reference:
 https://learnopengl.com/Advanced-OpenGL/Framebuffers
*/
class MainComponent   : public OpenGLAppComponent
{
    
    OpenGL *gl;
    
public:
    //==============================================================================
    MainComponent();
    ~MainComponent();

    //==============================================================================
    void initialise() override;
    void shutdown() override;
    void render() override;

    //==============================================================================
    void paint (Graphics& g) override;
    void resized() override;

private:
    //==============================================================================
    // Your private member variables go here...


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};

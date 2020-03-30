#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
using namespace sf;

int main()
{
    // Create the main window
    RenderWindow window(VideoMode(800, 600), "SFML window");
    
    //declare all of my variables that I need. Do any intializations here.
   
    // Start the game loop -- this is where my logic happens
    while (window.isOpen())
    {
        // Process events
        Event event;
        
        
        while (window.pollEvent(event))
        {
            
            // Close window: exit
            if (event.type == Event::Closed) {
                window.close();
            }
            
            // Escape pressed: exit
            if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape) {
                window.close();
            }
        }

        // Clear screen
        window.clear();

       
        // Draw any of the things that I declared to the screen that I want to be visible
        

        // Update the window
        window.display();
    }

    return 0;
}

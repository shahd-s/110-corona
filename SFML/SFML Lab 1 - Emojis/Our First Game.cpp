#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
using namespace sf;

int main()
{
    // Create the main window
    RenderWindow window(VideoMode(800, 600), "SFML window");
    
    //declare all of my variables that I need. Do any intializations here.
    CircleShape sad, cute;
    sad.setRadius(50);
    sad.setPosition(400, 300);
    
    cute.setRadius(50);
    cute.setPosition(300,400);
    
    Texture sadt, cutet;
    sadt.loadFromFile("/Users/ShahdSherif/Downloads/SadFace.png");
    cutet.loadFromFile("/Users/ShahdSherif/Downloads/CuteFace.png");
    
    sad.setTexture(&sadt);
    cute.setTexture(&cutet);
    
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
            
            //if my user pressed a button on their keyboard
            if (event.type == Event::KeyPressed) {
                //what is the button they pressed?
                
                switch (event.key.code) {
                    case Keyboard::Escape:
                        window.close();
                        break;
                        
                        
                    //moving the cute emoji
                    case Keyboard::Left:
                        cute.move(-10, 0);
                        break;
                    case Keyboard::Right:
                        cute.move(10, 0);
                        break;
                    case Keyboard::Up:
                        cute.move(0, -10);
                        break;
                    case Keyboard::Down:
                        cute.move(0, 10);
                        break;
                        
                    //moving the sad emoji
                    case Keyboard::A:
                        sad.move(-10, 0);
                        break;
                    case Keyboard::D:
                        sad.move(10, 0);
                        break;
                    case Keyboard::W:
                        sad.move(0, -10);
                        break;
                    case Keyboard::S:
                        sad.move(0, 10);
                        break;
                        
                    default:
                        break;
                }
            }
            
        }

        // Clear screen
        window.clear();

       
        // Draw any of the things that I declared to the screen that I want to be visible
        
        window.draw(sad);
        window.draw(cute);
        
        // Update the window
        window.display();
    }
    
    
    return 0;
}

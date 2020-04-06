#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <cmath>
#include<iostream>
using namespace sf;
using namespace std;
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
                
                
                //get position of the cute circle. Note that a circles position is, in x, the position of the left most point on the circle's circumference, and in y, the position of the top most point on the circumferance.
                Vector2f pos = cute.getPosition();
                Vector2f sadpos=sad.getPosition();
                
           
                
                switch (event.key.code) {
                    case Keyboard::Escape:
                        window.close();
                        break;
                        
                        
                        
                        //moving the cute emoji
                    case Keyboard::Left:
                        if(pos.x > 0)
                           {
                               //need to check for collision. A collision happens if the distance between the centers is less than the sum of the radii
                               
                               
                               //get position
                               Vector2f colcutepos = cute.getPosition();
                               
                              //get the center for cute, and see, IF I wereto move it left, would a collision happen? if so, then I won't allow it to move left.
                               colcutepos.x-=10;
                               
                               //remember, the .getPosition() function returns position and left most and topmost points. So we must add the radius to each, to get the center
                               Vector2f center;
                               center.x = colcutepos.x+50;
                               center.y =colcutepos.y+50;
                               
                               Vector2f sadcenter;
                               sadcenter.x=sadpos.x+50;
                               sadcenter.y=sadpos.y+50;
                               
                               //calculate the distance between the circle's centers using the pythagerous distance formula
                               float d_between_c = sqrt(pow((sadcenter.x-center.x), 2) + pow((sadcenter.y-center.y),2));
                               
                               //if this theoretical moving left would cause a collision, don't allow it to move left.
                               if(d_between_c >= 100)
                        cute.move(-10, 0);
                               
                           }
                        break;
                    case Keyboard::Right:
                      if (pos.x < 800-50*2) //if the position is 800, which is the window size's x position, minus the diameter of the circle, which is 2r which is 50 (the radius)*2
                          {
                              Vector2f colcutepos = cute.getPosition();
                              colcutepos.x+=10;
                              
                              Vector2f center;
                              center.x = colcutepos.x+50;
                              center.y =colcutepos.y+50;
                              
                              Vector2f sadcenter;
                              sadcenter.x=sadpos.x+50;
                              sadcenter.y=sadpos.y+50;
                              
                              float d_between_c = sqrt(pow((sadcenter.x-center.x), 2) + pow((sadcenter.y-center.y),2));
                              
                              if(d_between_c >= 100)
                              cute.move(10, 0);
                              
                          }
                        break;
                    case Keyboard::Up:
                        if (pos.y > 0)
                            {
                                Vector2f colcutepos = cute.getPosition();
                                colcutepos.y-=10;
                                
                                Vector2f center;
                                center.x = colcutepos.x+50;
                                center.y =colcutepos.y+50;
                                
                                Vector2f sadcenter;
                                sadcenter.x=sadpos.x+50;
                                sadcenter.y=sadpos.y+50;
                                
                                float d_between_c = sqrt(pow((sadcenter.x-center.x), 2) + pow((sadcenter.y-center.y),2));
                                
                                if(d_between_c >= 100)
                        cute.move(0, -10);
                                
                            }
                        break;
                    case Keyboard::Down:
                         if (pos.y < 600-50*2) //if the position is 600, which is the window size's y position, minus the diameter of the circle, which is 2r which is 50 (the radius)*2
                             {
                                 Vector2f colcutepos = cute.getPosition();
                                 colcutepos.y+=10;
                                 
                                 Vector2f center;
                                 center.x = colcutepos.x+50;
                                 center.y =colcutepos.y+50;
                                 
                                 Vector2f sadcenter;
                                 sadcenter.x=sadpos.x+50;
                                 sadcenter.y=sadpos.y+50;
                                 
                                 float d_between_c = sqrt(pow((sadcenter.x-center.x), 2) + pow((sadcenter.y-center.y),2));
                                 
                                 if(d_between_c >= 100)
                                 cute.move(0, 10);}
                        break;
                        
                        
                        
                        //moving the sad emoji
                    case Keyboard::A:
                        if(sadpos.x > 0){
                            //need to check for collision. A collision happens if the distance between the centers is less than the sum of the radii
                            
                            
                            //get position
                            Vector2f colcutepos = sad.getPosition();
                            
                            //get the center for cute, and see, IF I wereto move it left, would a collision happen? if so, then I won't allow it to move left.
                            colcutepos.x-=10;
                            
                            //remember, the .getPosition() function returns position and left most and topmost points. So we must add the radius to each, to get the center
                            Vector2f center;
                            center.x = colcutepos.x+50;
                            center.y =colcutepos.y+50;
                            
                            Vector2f sadcenter;
                            sadcenter.x=pos.x+50;
                            sadcenter.y=pos.y+50;
                            
                            //calculate the distance between the circle's centers using the pythagerous distance formula
                            float d_between_c = sqrt(pow((sadcenter.x-center.x), 2) + pow((sadcenter.y-center.y),2));
                            
                            //if this theoretical moving left would cause a collision, don't allow it to move left.
                            if(d_between_c >= 100)
                             
                        sad.move(-10, 0);
                        }
                        break;
                    case Keyboard::D:
                        if(sadpos.x < 800-50*2)
                        {
                            Vector2f colcutepos = sad.getPosition();
                            colcutepos.x+=10;
                            
                            Vector2f center;
                            center.x = colcutepos.x+50;
                            center.y =colcutepos.y+50;
                            
                            Vector2f sadcenter;
                            sadcenter.x=pos.x+50;
                            sadcenter.y=pos.y+50;
                            
                            float d_between_c = sqrt(pow((sadcenter.x-center.x), 2) + pow((sadcenter.y-center.y),2));
                            
                            if(d_between_c >= 100)
                            sad.move(10, 0);}
                        break;
                    case Keyboard::W:
                        if (sadpos.y > 0)
                        {
                            Vector2f colcutepos = sad.getPosition();
                            colcutepos.y-=10;
                            
                            Vector2f center;
                            center.x = colcutepos.x+50;
                            center.y =colcutepos.y+50;
                            
                            Vector2f sadcenter;
                            sadcenter.x=pos.x+50;
                            sadcenter.y=pos.y+50;
                            
                            float d_between_c = sqrt(pow((sadcenter.x-center.x), 2) + pow((sadcenter.y-center.y),2));
                            
                            if(d_between_c >= 100)
                                sad.move(0, -10);}
                        break;
                    case Keyboard::S:
                        if(sadpos.y < 600-50*2)
                        {
                            Vector2f colcutepos = sad.getPosition();
                            colcutepos.y+=10;
                            
                            Vector2f center;
                            center.x = colcutepos.x+50;
                            center.y =colcutepos.y+50;
                            
                            Vector2f sadcenter;
                            sadcenter.x=pos.x+50;
                            sadcenter.y=pos.y+50;
                            
                            float d_between_c = sqrt(pow((sadcenter.x-center.x), 2) + pow((sadcenter.y-center.y),2));
                            
                            if(d_between_c >= 100)
                            sad.move(0, 10);}
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

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
using namespace std;
using namespace sf;

const int rows = 7;
const int cols = 7;

void init(char arr[][cols], Sprite maze[][cols], Sprite& player, int& playerx, int& playery, Texture& grass, Texture& brick, Texture& playert){
    ifstream sin;
    sin.open("/Users/ShahdSherif/Documents/110 ta/online labs/sfml maze/maze.txt");
    
    
    
    for (int i =0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            
            sin >> arr[i][j];
            //if it is brick
            if (arr[i][j] == 'h'){
                maze[i][j].setTexture(brick);
                maze[i][j].setPosition(j*100, i*100);
                maze[i][j].scale(0.47, 0.47);
            }
            else
            {
                //if it is anything else
                if (arr[i][j] == 'e') {
                    playerx=i;
                    playery=j;
                }
                
                maze[i][j].setTexture(grass);
                maze[i][j].setPosition(j*100,i*100);
                maze[i][j].scale(0.47,0.47);
            }
        }
    }
    
    //init player:
    player.setTexture(playert);
    player.setPosition(playery*100, playerx*100);
    player.scale(0.2, 0.2);
    
}

int main()
{
    // Create the main window
    RenderWindow window(VideoMode(700, 700), "SFML window");
    
    //declare all of my variables that I need. Do any intializations here.
    
    //Declare textures
    Texture grass, brick, playert;
    grass.loadFromFile("/Users/ShahdSherif/Documents/110 ta/online labs/sfml maze/Grass.png");
    brick.loadFromFile("/Users/ShahdSherif/Documents/110 ta/online labs/sfml maze/Bricks.png");
    playert.loadFromFile("/Users/ShahdSherif/Documents/110 ta/online labs/sfml maze/player.png");
    
    //need my char 2d array
    char arr[rows][cols];
    
   
    //need my Sprite 2d array
    Sprite maze[rows][cols];
    
    
    //need my player
    Sprite player;
    int playeri, playerj;
    
    init(arr, maze, player, playeri, playerj, grass, brick, playert);
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            cout<<arr[i][j];
        }
        cout<<endl;
    }
    
    
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
            
            if (event.type == Event::KeyPressed) {
                switch (event.key.code) {
                    case Keyboard::Escape:
                        window.close();
                        break;
                        
                    case Keyboard::Left:
                        if(arr[playeri][playerj-1] !='h'){
                        
                            //move the sfml sprite
                        player.move(-100,0);
                            
                            //change my int pos
                        playerj--;
                        
                        }
                        break;
                        
                    case Keyboard::Right:
                        if(arr[playeri][playerj+1] !='h')
                        { player.move(100,0);
                            playerj++;
                        }
                        break;
                    case Keyboard::Up:
                         if(arr[playeri-1][playerj] !='h')
                         {player.move(0,-100);
                             playeri--;
                         }
                        break;
                    case Keyboard::Down:
                        if(arr[playeri+1][playerj] !='h')
                        {  player.move(0,100);
                            playeri++;
                        }
                        break;
                    default:
                        break;
                }
            }
           
        }
        
        // Clear screen
        window.clear();
        
        
        // Draw any of the things that I declared to the screen that I want to be visible
       
        for (int i=0; i<rows; i++) {
            for (int j=0; j<cols; j++) {
                window.draw(maze[i][j]);
            }
        }
        window.draw(player);
        
        // Update the window
        window.display();
    }
    
    return 0;
}

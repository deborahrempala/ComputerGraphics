#include <SDL.h>
#include "SDL_image.h"
#include <SDL_mixer.h>
#include <iostream>
#include <stdio.h>

SDL_Window* window;
SDL_Renderer* renderer;
// makes sure sdl sets up correctly
// if not then it prints out an error
void setupSDL()
  {
  if (SDL_Init(SDL_INIT_TIMER|SDL_INIT_AUDIO|SDL_INIT_VIDEO) != 0)
    {
    printf("SDL failed to init: %s\n", SDL_GetError());
    exit(1);
    }
      //Initialize SDL_mixer
               /* if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
                {
                    printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
                    exit(1);
                }*/
  // Create window and renderer
  // creates window for graphics
  // if it fails to set up correctly an error is given
  SDL_CreateWindowAndRenderer(600,400, SDL_WINDOW_SHOWN,&window, &renderer);

  if ((window == NULL) || (renderer == NULL))
    {
    printf("SDL_CreateWindowAndRenderer Error: %s\n", SDL_GetError() );
    exit(1);
    }
    
  }
  
 
// if it is not loaded correctly it gives an error message 
SDL_Texture* loadImage(const char* filename)
  {
  SDL_Texture *texture;

  texture = IMG_LoadTexture(renderer, filename);
  if (texture == NULL)
    {
    printf("IMG_LoadTexture Error: %s\n", IMG_GetError() );
    exit(1);
    }
                                                             
                                                             
  return texture;                                            
  }                


SDL_Texture* loadKeyedImage(const char* filename)
	{
	SDL_Surface* surface;
	SDL_Texture* texture;

	surface = IMG_Load(filename);
	SDL_SetColorKey(surface, SDL_TRUE, 0xff00ff);
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	return texture;
	}

 
              

           
    
// makes sure sdl quits when the user wants its to
void postSDLCleanup()                                        
    {                                                        
    SDL_DestroyRenderer(renderer);                           
    SDL_DestroyWindow(window);                               
    SDL_Quit();                                              
    }  
	


	// main program
int main(int argc, char* argv[])
{

SDL_Event event;
// logo
SDL_Texture* boat;
SDL_Rect bsrc;
SDL_Rect bdest;

int x =0;
int y =0;
Mix_Music *gMusic = NULL;
setupSDL();
// loads giant logo
 boat = loadImage("boat.png");
 bsrc.w = 600; bsrc.h = 400; 
 bsrc.x = 0;   bsrc.y =0;
 bdest.w =550;   bdest.h=350;
 bdest.x = 500;  bdest.y = 300;


 
 
 

while(1)
{
 	SDL_RenderClear(renderer);
 SDL_RenderCopy(renderer, boat, &bsrc, &bdest);
  
	   //gMusic = Mix_LoadMUS( "boathorn.wav" );
 SDL_RenderPresent(renderer);
// when the start is pushed
// another frame is loaded
// probably using mouse event and pixels
 if (SDL_PollEvent(&event) > 0)
                       {
                       switch(event.type)
                         {
						    Mix_FreeMusic( gMusic );
                         case SDL_QUIT: 
                           exit(0);
                         }
                       }
					   
SDL_Delay(50);




}
}



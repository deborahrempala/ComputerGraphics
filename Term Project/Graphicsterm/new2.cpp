#include <SDL.h>
#include "SDL_image.h"
#include "SDL_mixer.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <istream>
#include <stdio.h>
#include "Fixed_print.h"
SDL_Window* window;
SDL_Renderer* renderer;



Mix_Chunk* sounds[10];
Mix_Music* musics[10];
// global game variables
int finalscore =0;
int totalplays = 0;
int lose =0;
int wins = 0;

// i have no idea why i need this but i do
using namespace std;

#define NUM_CHANNELS 16
// makes sure sdl sets up correctly
// if not then it prints out an error
void setupSDL()
  { 
  int test;
  if (SDL_Init(SDL_INIT_TIMER|SDL_INIT_AUDIO|SDL_INIT_VIDEO) != 0)
    {
    printf("SDL failed to init: %s\n", SDL_GetError());
    exit(1);
    }
      //Initialize SDL_mixer
               if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
                {
                    printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
                    exit(1);
                }
  // Create window and renderer
  // creates window for graphics
  // if it fails to set up correctly an error is given
  SDL_CreateWindowAndRenderer(1000,600, SDL_WINDOW_SHOWN,&window, &renderer);

  if ((window == NULL) || (renderer == NULL))
    {
    printf("SDL_CreateWindowAndRenderer Error: %s\n", SDL_GetError() );
    exit(1);
    }
	 FixedPrint_Setup();
 test = Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 1024);

  if (test == -1)
    {
    printf("Mix_OpenAudio error\n");
    printf("Oh My Goodness, an error : %s", Mix_GetError());

    exit(1);
    }
	
	 // Channel setup
  Mix_AllocateChannels(NUM_CHANNELS);
  Mix_ReserveChannels(NUM_CHANNELS);
  Mix_GroupChannels(0,15,1); // All channels in one group!
    
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





              
void do_sounds(Mix_Chunk* what)
  {
  int channel;

  channel = Mix_GroupAvailable(1);
  if (channel == -1)
    channel = Mix_GroupOldest(1);
  Mix_PlayChannel(channel, what, 0);
  }
           
    
// makes sure sdl quits when the user wants its to
void postSDLCleanup()                                        
    {                                                        
    SDL_DestroyRenderer(renderer);                           
    SDL_DestroyWindow(window);                               
    SDL_Quit();                                              
    }  
	
void start();
void instructions();
void gameplay();
void pause();
void loses();
void win();
void recordscore();
void lifetimescore();
	// main program
int main(int argc, char* argv[])
{
setupSDL();
 // functions used to play gme 
 start();
 instructions();
gameplay();
 win();

 recordscore();
 lifetimescore();
// loses();
 }
 
 
 void start()
 {
 // once the program begins
 // load these graphics 
 SDL_Event event;
 int x;
 int y;
 // load audio 
  sounds[0] = Mix_LoadWAV("boathorn2.wav");
 // load textures
  
 // logo
SDL_Texture* Logo;
SDL_Rect lsrc;
SDL_Rect ldest;
// start
SDL_Texture* Start;
SDL_Rect ssrc;
SDL_Rect sdest;
// becky's head1
SDL_Texture* head;
SDL_Rect hsrc;
SDL_Rect hdest;
// becky head 2
SDL_Texture* head2;
SDL_Rect h2src;
SDL_Rect h2dest;
 
 // loads giant logo
 Logo = loadKeyedImage("logo.png");
 lsrc.w = 600; lsrc.h = 400; 
 lsrc.x = 0;   lsrc.y =0;
 ldest.w =600; ldest.h=400;
 ldest.x = 160;  ldest.y = 130;
// loads start button
  Start = loadKeyedImage("start.png");
 ssrc.w = 150; ssrc.h = 50; 
 ssrc.x = 0;   ssrc.y =0;
 sdest.w =150; sdest.h=50;
 sdest.x = 215; sdest.y = 330;
 // loads first head
  head = loadKeyedImage("becky_head.png");
 hsrc.w = 200; hsrc.h = 200; 
 hsrc.x = 0;   hsrc.y =0;
 hdest.w =75;  hdest.h=75;
 hdest.x = 165; hdest.y = 320;
 // loads second head
 
 head2 = loadKeyedImage("becky_head2.png");
 h2src.w = 200; h2src.h = 200; 
 h2src.x = 0;   h2src.y =0;
 h2dest.w =75;  h2dest.h=75;
 h2dest.x = 340; h2dest.y = 320;
 while(1)
 {
     SDL_RenderClear(renderer);
     SDL_RenderCopy(renderer, Logo, &lsrc, &ldest);
	 SDL_RenderCopy(renderer, Start, &ssrc, &sdest);
     SDL_RenderCopy(renderer, head, &hsrc, &hdest);
	 SDL_RenderCopy(renderer, head2, &h2src, &h2dest);
     SDL_RenderPresent(renderer);
     SDL_Delay(50);
 // when the start is pushed
// the start screen will disapper
// then the first screen will load
 if(SDL_GetMouseState(&x, &y) & SDL_BUTTON(SDL_BUTTON_LEFT) )

{    
      if( x>=165 & x<= 350 & y>=320 & y<=350)
	  {

	    	do_sounds(sounds[0]);
			return;
	  }
 }

  if (SDL_PollEvent(&event) > 0)
                       {
                       switch(event.type)
                         {
					
                         case SDL_QUIT: 
                           exit(0);
                         }
                       }
 }
 }
 // once the button is pushed
 // the instruction screen will load
 void instructions()
 {
   sounds[0] = Mix_LoadWAV("boathorn2.wav");
 SDL_Event event;
 //load instruction logo
SDL_Texture* instruction;
SDL_Rect isrc;
SDL_Rect idest;
// load left arrow
SDL_Texture* larrow;
SDL_Rect lasrc;
SDL_Rect ladest;
// load right arrow
SDL_Texture* rarrow;
SDL_Rect rasrc;
SDL_Rect radest;
// load up arrow
SDL_Texture* uarrow;
SDL_Rect uasrc;
SDL_Rect uadest;
// loads pause button
SDL_Texture* pause;
SDL_Rect pasrc;
SDL_Rect padest;
// load go button
SDL_Texture* go;
SDL_Rect gsrc;
SDL_Rect gdest;
int x =0;
int y =0;
 // load instruction logo
 instruction = loadKeyedImage("logoins.png");
 isrc.w = 932; isrc.h = 200; 
 isrc.x = 0;   isrc.y =0;
 idest.w =932; idest.h=200;
 idest.x = 95; idest.y = -60;
 
 // loads left arrow imagw
 larrow = loadKeyedImage("leftarrowpic.png");
 lasrc.w = 80; lasrc.h = 80; 
 lasrc.x = 0;   lasrc.y =0;
 ladest.w =40; ladest.h=40;
 ladest.x = 400; ladest.y = 290;
 
 // loads right arrow image
 rarrow = loadKeyedImage("rightarrowpic.png");
 rasrc.w = 80;  rasrc.h = 80; 
 rasrc.x = 0;   rasrc.y =0;
 radest.w =40;  radest.h=40;
 radest.x =400; radest.y = 340;
 // loads up arrow 
 uarrow = loadKeyedImage("uparrowpic.png");
 uasrc.w = 80;  uasrc.h = 80; 
 uasrc.x = 0;   uasrc.y =0;
 uadest.w =40;  uadest.h=40;
 uadest.x =400; uadest.y = 390;
 
 // loads pause button
 pause = loadKeyedImage("pausebuttonpic.png");
 pasrc.w = 80;  pasrc.h = 80; 
 pasrc.x = 0;   pasrc.y =0;
 padest.w =40;  padest.h=40;
 padest.x =400; padest.y = 440;
 
 // loads go button
  // loads pause button
 go = loadKeyedImage("go_button.png");
 gsrc.w = 200;  gsrc.h = 70; 
 gsrc.x = 0;   gsrc.y =0;
 gdest.w =200;  gdest.h=70;
 gdest.x =400; gdest.y = 490;
 
 // loads string 
 SDL_Surface *s;
	char string[100];
	SDL_Color c;
	
	while(1)
	{
	 SDL_RenderClear(renderer);
         
		 	// for the left arrow 
		  sprintf(string, "Moves Becky Left");
		  c.r = 255; c.g = 255; c.b = 255;
		  FixedPrint(renderer, 450, 300, string, &c, 2);
		  SDL_RenderCopy(renderer, larrow, &lasrc, &ladest);
		  // for the right arrow 
		  sprintf(string, "Moves Becky Right");
		  c.r = 255; c.g = 255; c.b = 255;
		  FixedPrint(renderer, 450, 355, string, &c, 2);
		  SDL_RenderCopy(renderer, rarrow, &rasrc, &radest);
		  SDL_RenderCopy(renderer, instruction, &isrc, &idest);
		  // up arrow 
		  SDL_RenderCopy(renderer, uarrow, &uasrc, &uadest);
		  sprintf(string, "Makes Becky Jump");
		  c.r = 255; c.g = 255; c.b = 255;
		  FixedPrint(renderer, 450, 405, string, &c, 2);
		  // for the pause button 
		  sprintf(string, "Pauses The Game");
		  c.r = 255; c.g = 255; c.b = 255;
		  FixedPrint(renderer, 450, 450, string, &c, 2);
            SDL_RenderCopy(renderer, pause, &pasrc, &padest);
		 // for the go button
		   SDL_RenderCopy(renderer, go, &gsrc, &gdest);
	        SDL_RenderPresent(renderer);
			SDL_Delay(50);
			
	if(SDL_GetMouseState(&x, &y) & SDL_BUTTON(SDL_BUTTON_LEFT) )

{    
      if( x>=400 & x<= 600 & y>= 450 & y<=520)
	  {
        do_sounds(sounds[0]);
		 return;
	  }

}
			
 if (SDL_PollEvent(&event) > 0)
                       {
                       switch(event.type)
                         {
					
                         case SDL_QUIT: 
                           exit(0);
                         }
                       }  
        } 
 }
 
 // once resume is hit 
 // the game will begin
 // timer will begin
 // penguins will begin
 // score will begin
 void gameplay()
 { 
	sounds[1] = Mix_LoadWAV("runmusic.wav");
  	sounds[2] = Mix_LoadWAV("jump.wav"); 
  int time = 2000;
 int  score = 5000;
  totalplays ++;
  // random varibles
    SDL_Event event;
	int x;
	int y;
	
	 
	 const Uint8 *state;
  
	SDL_Surface *s;
	char string[100];
	SDL_Color c;
   int co =0;
 // load textures
 // load gameplay run
	SDL_Texture* gameplay;
	SDL_Rect gsrc;
	SDL_Rect gdest;
// load becky
	SDL_Texture* becky;
	SDL_Rect besrc;
	SDL_Rect bedest;
// load time 
SDL_Texture* timer;
	SDL_Rect tsrc;
	SDL_Rect tdest;
	// load score
	SDL_Texture* scorer;
	SDL_Rect ssrc;
	SDL_Rect sdest;
	// life ring variable 
	SDL_Texture* rings;
	SDL_Rect rsrc;
	SDL_Rect rdest;
 // load intial start postion
	gameplay = loadKeyedImage("run.png");
	gsrc.w = 1000;  gsrc.h = 400; 
	gsrc.x = 0;     gsrc.y =0;
	gdest.w =1000;   gdest.h=400;
	gdest.x = 0; 	  gdest.y = 240;
 // loads becky intial postition
	becky = loadKeyedImage("mainbecky.png");
	besrc.w = 50; besrc.h = 50; 
	besrc.x = 0;   besrc.y =0;
	bedest.w =80;  bedest.h=80;
	bedest.x = 0;   bedest.y = 385;
	// load time 
	timer = loadKeyedImage("time.png");
	tsrc.w = 200; tsrc.h = 94; 
	tsrc.x = 0;   tsrc.y =0;
	tdest.w =150; tdest.h=50;
	tdest.x = 0;  tdest.y = 0;
	// load score label
	
	scorer = loadKeyedImage("score.png");
	ssrc.w = 150; ssrc.h = 94; 
	ssrc.x = 0;   ssrc.y =0;
	sdest.w =150; sdest.h=50;
	sdest.x = 300;  sdest.y = 0;
	
// load penguins
   	SDL_Texture* penguin;
	SDL_Rect psrc;
	SDL_Rect pdest;
	penguin= loadKeyedImage("zombie_penguin.png");
	psrc.w = 60; psrc.h = 60; 
	psrc.x = 0;   psrc.y =0;
	pdest.w =40; pdest.h=40;
	pdest.x = 1000;  pdest.y = 432;
   // load some more penguins
   SDL_Texture* penguin2;
	SDL_Rect p2src;
	SDL_Rect p2dest;
    penguin2= loadKeyedImage("zombie_penguin.png");
	p2src.w = 60; p2src.h = 60; 
	p2src.x = 0;   p2src.y =0;
	p2dest.w =40; p2dest.h=40;
	p2dest.x = 500;  p2dest.y = 432;
 // load life rings 
	rings= loadKeyedImage("lifering.png");
	rsrc.w = 225; rsrc.h = 210; 
	rsrc.x = 0;   rsrc.y =0;
	rdest.w =70;  rdest.h=70;
	rdest.x = 250; rdest.y = 310;
	
 // start while
 // counter
 // play sound
  do_sounds(sounds[1]);
 while(1)
 {
 
  
	 SDL_RenderClear(renderer);
	 SDL_RenderCopy(renderer, gameplay, &gsrc, &gdest);
	 SDL_RenderCopy(renderer, becky, &besrc, &bedest);
	SDL_RenderCopy(renderer, timer, &tsrc, &tdest);
	SDL_RenderCopy(renderer, scorer, &ssrc, &sdest);
	SDL_RenderCopy(renderer, penguin, &psrc, &pdest);
	SDL_RenderCopy(renderer, penguin2, &p2src, &p2dest);
	SDL_RenderCopy(renderer, rings, &rsrc, &rdest);
	 pdest.x -=10;
	 p2dest.x -=10;
	// load time string
	sprintf(string, "%d",time/10);
		c.r = 255; c.g = 255; c.b = 255;
		FixedPrint(renderer, 145, 21, string, &c, 2);
		sprintf(string, "%d",score/10);
		c.r = 255; c.g = 255; c.b = 255;
		FixedPrint(renderer, 450, 19, string, &c, 2);
		time --;
      score -= 5;
      rdest.x -=10;
	SDL_PumpEvents();
  state = SDL_GetKeyboardState(NULL);
	if( time == 0)
	{

         loses();

	}	
 // movement
 
 

 // right
	if (state[SDL_SCANCODE_RIGHT] && gsrc.x< 4420)
		{
		
		
			gsrc.x +=20;
			gsrc.y = 0;
			gdest.h=400;
			bedest.x +=1;
		   bedest.y = 385;
    
	/*if(bedest.x == 4692)
			{
			return;
			 }*/
 }

 // left 
 
 if (state[SDL_SCANCODE_LEFT] && gsrc.x >0)
		{
			gsrc.x -=20;
			gsrc.y = 0;
			gdest.h=400;
			bedest.x -=1;
			   bedest.y = 385;
		}
 
 // up

 
  if( pdest.x == 0)
  {
  
  psrc.w = 60; psrc.h = 60; 
	psrc.x = 0;   psrc.y =0;
	pdest.w =40; pdest.h=40;
	pdest.x = 1000;  pdest.y = 432;
 
  
  }
   if( p2dest.x == 0)
  {
  
  p2src.w = 60; p2src.h = 60; 
	p2src.x = 0;   p2src.y =0;
	p2dest.w =40; p2dest.h=40;
	p2dest.x = 1000;  p2dest.y = 432;
  
  
  }
  if(rdest.x== 0)
  {
  
    rsrc.w = 225; rsrc.h = 210; 
	rsrc.x = 0;   rsrc.y =0;
	rdest.w =70;  rdest.h=70;
	rdest.x = 1000; rdest.y = 310;
  
  
  }
  bool jump = false;

 
 if (state[SDL_SCANCODE_UP]&& gsrc.x< 4420 && gsrc.x>0)
    {
	       do_sounds(sounds[2]);
		    SDL_Surface *s;
		char string[100];
		SDL_Color c;
	  // when becky jumps she will jump then fall
	  // because gravity is a bitch 
	  jump = true;
	   co++;
	    
	
	  
	 } 
	  

   
 if(jump == true)
	  {
	
	  bedest.y = 325;
      bedest. x += 10;
	  gsrc.x -= 05;
	   gsrc.y = 0;
	 
	  	   //sprintf(string, "JUMP");
		//c.r = 255; c.g = 255; c.b = 255;
		//FixedPrint(renderer, 200, 200, string, &c, 2);
	
	  // make counter that waits for 3 durations 
	  // make if statement 
	  // if count reaches change jump to false
	     
	  }	
  if(co == 3)
	   {
	   
       jump = false;
	
	   co = 0;
	   } 
	  if(jump == false){
	    bedest.y = 385;
		}	  
	
	  
	  
	 
	
// pause

 bool hit = false;
// penguin collision one 
if(bedest.x  >= pdest.x + 2 && bedest.x  <= pdest.x + 20 && bedest.y <= pdest.y - 5)
 {
    
      hit = true;
	  // add score 
     score += 100;
 if( hit == true)
 {
 
 //SDL_Surface *s;
		/*  testing 
		char string[100];
		SDL_Color c;
	
	   sprintf(string, "HIT");
		c.r = 255; c.g = 255; c.b = 255;
	FixedPrint(renderer, 300, 300, string, &c, 2);
	*/
	// makes penguins dissappear
      psrc.w = 60; psrc.h = 60; 
	psrc.x = 0;   psrc.y =0;
	pdest.w =40; pdest.h=40;
	pdest.x = 1000;  pdest.y = 432;
	
 
 }
 }
  // penguin collison 2
 if(bedest.x  >= p2dest.x + 2 && bedest.x  <= p2dest.x + 20 && bedest.y <= p2dest.y - 5  )
 {
    
      hit = true;
     score += 100;
 if( hit == true)
 {
    // makes penguin dissappear
	p2src.w = 60; p2src.h = 60; 
	p2src.x = 0;   p2src.y =0;
	p2dest.w =40; p2dest.h=40;
	p2dest.x = 1000;  p2dest.y = 432;
	
	 /*Testing 
		SDL_Surface *s;
		char string[100];
		SDL_Color c;
	// score added
	   sprintf(string, "HIT");
		c.r = 255; c.g = 255; c.b = 255;
	FixedPrint(renderer, 300, 300, string, &c, 2);
    */
 

 }
 }
 // hitting life rings
   // life rings will be placed above becky
   // once she hits them 
   // 200 points will be added to her score and they will dissappear
  if(bedest.x  >= rdest.x + 2 && bedest.x  <= rdest.x + 50 && bedest.y <= rdest.y + 60 )
 {
    
      hit = true;
	  // add score 
     score += 300;
 if( hit == true)
 {
 
 //SDL_Surface *s;
		/*  testing 
		char string[100];
		SDL_Color c;
	
	   sprintf(string, "HIT");
		c.r = 255; c.g = 255; c.b = 255;
	FixedPrint(renderer, 300, 300, string, &c, 2);
	*/
	// makes life rings dissappear
    rsrc.w = 225; rsrc.h = 210; 
	rsrc.x = 0;   rsrc.y =0;
	rdest.w =70;  rdest.h=70;
	rdest.x = 1000; rdest.y = 310;
	
 
 }
 } 
 
 
 

 
 	if (state[SDL_SCANCODE_P])
    {
	 pause();
	time = time;
	score = score; 
	  
	 }
	 

 // once becky gets to the end 
 // you will win

 
 
 if(gsrc.x >4300 )
 {
    wins++;
	// adding time bonuses to score 
    if( time > 170)
	score += 1500;
	if( time > 170 && time < 140)
	score += 1000;
	if(time> 140 && time < 100)
	score += 500;
    finalscore = finalscore + (score/10);
  // once becky and gsrc hit 4000 a win will be detected
 // game win
   return;
 
 }
 

 
 
 
  SDL_RenderPresent(renderer);
  SDL_Delay(50);
 
 
 
 if (SDL_PollEvent(&event) > 0)
                       {
                       switch(event.type)
                         {
					
                         case SDL_QUIT: 
                           exit(0);
                         }
                       }
					   





}// end while
 

 
 }
 
 void pause()
 {
 
	SDL_Event event;
	int x;
	int y;
	SDL_PumpEvents();
	const Uint8 *state;
    state = SDL_GetKeyboardState(NULL);
	 // loads string 
	SDL_Surface *s;
	char string[100];
	SDL_Color c;
  // load pause 
	SDL_Texture* pause;
	SDL_Rect psrc;
	SDL_Rect pdest;
	 pause = loadKeyedImage("pause.png");
	psrc.w = 600; psrc.h = 400; 
	psrc.x = 0;   psrc.y =0;
	pdest.w =600; pdest.h=400;
	pdest.x = 200;  pdest.y = 90;
	
while(1)
 {
	 SDL_RenderClear(renderer);
	 SDL_RenderCopy(renderer, pause, &psrc, &pdest);
			// once c is pressed the game will resume
	 	  sprintf(string, "Press C to Continue");
		  c.r = 255; c.g = 255; c.b = 255;
	FixedPrint(renderer, 400, 400, string, &c, 2);
		 SDL_RenderPresent(renderer);
		 if (state[SDL_SCANCODE_C])
    {
	 return;
	
	  
	  
	 }
		 
		 
	  if (SDL_PollEvent(&event) > 0)
                       {
                       switch(event.type)
                         {
					
                         case SDL_QUIT: 
                           exit(0);
                         }
                       }
	 
	}
 

 }

 void win()
 {
      

 // once a win occurs 
 // the time will stop 
	
	SDL_Event event;
	int x;
	int y;
	SDL_Surface *s;
	char string[100];
	SDL_Color c;
	// load congratulations
	SDL_Texture* win;
	SDL_Rect wsrc;
	SDL_Rect wdest;
	// load congratulations
	 win = loadKeyedImage("congratulations.png");
	wsrc.w = 600; wsrc.h = 100; 
	wsrc.x = 0;   wsrc.y =0;
	wdest.w =600; wdest.h=100;
	wdest.x = 200;  wdest.y = 0;
	// load you have won
	SDL_Texture* youwin;
	SDL_Rect usrc;
	SDL_Rect udest;
	// load play again graphic
	SDL_Texture* again;
	SDL_Rect asrc;
	SDL_Rect adest;
	// loads yes 
	SDL_Texture* yes;
	SDL_Rect ysrc;
	SDL_Rect ydest;
	// loads no
	SDL_Texture* no;
	SDL_Rect nsrc;
	SDL_Rect ndest;
		// put you have won on screen
	youwin = loadKeyedImage("youwon.png");
	usrc.w = 400; usrc.h = 100; 
	usrc.x = 0;   usrc.y =0;
	udest.w =400; udest.h=100;
	udest.x = 300;  udest.y = 80;
	// puts play again on screen
	again = loadKeyedImage("playagain.png");
	asrc.w = 200; asrc.h = 70; 
	asrc.x = 0;   asrc.y =0;
	adest.w =200; adest.h=70;
	adest.x = 400;  adest.y = 300;
	// puts the yes option on a screen 
	yes = loadKeyedImage("yes.png");
	ysrc.w = 200; ysrc.h = 70; 
	ysrc.x = 0;   ysrc.y =0;
	ydest.w =200; ydest.h=70;
	ydest.x = 150;  ydest.y = 300;
	// puts no on screen
	no = loadKeyedImage("no.png");
	nsrc.w = 200; nsrc.h = 70; 
	nsrc.x = 0;   nsrc.y =0;
	ndest.w =200; ndest.h=70;
	ndest.x = 650;  ndest.y = 300;
	while(1)
 {
	 SDL_RenderClear(renderer);
	 SDL_RenderCopy(renderer, win, &wsrc, &wdest);
	 SDL_RenderCopy(renderer, youwin, &usrc, &udest);	
	 SDL_RenderCopy(renderer, again, &asrc, &adest);
	 SDL_RenderCopy(renderer, yes, &ysrc, &ydest);
	  SDL_RenderCopy(renderer, no, &nsrc, &ndest);
	  // testing purpose
	
	  
		 SDL_RenderPresent(renderer);
	if(SDL_GetMouseState(&x, &y) & SDL_BUTTON(SDL_BUTTON_LEFT) )

{      // if the player hits yes resume game play
      if( x>=150 & x<= 350 & y>= 300 & y<=370)
	  {
         gameplay();
	  }
	     // else return to the results page 
	        if( x>=650 & x<= 850 & y>= 300 & y<=370)
	  {
         return;
		 exit(0);
	  }
	  
	  

}	
		 
		 
	  if (SDL_PollEvent(&event) > 0)
                       {
                       switch(event.type)
                         {
					
                         case SDL_QUIT: 
                           exit(0);
                         }
                       }
	 
	}
 
 
 
 
 }
 void loses()
 {SDL_Event event;
	lose++;
	int x;
	int y;
	// lose variables
	SDL_Texture* lose1;
	SDL_Rect lsrc;
	SDL_Rect ldest;
	// play again variable
	SDL_Texture* again;
	SDL_Rect asrc;
	SDL_Rect adest;
	
	// yes variable
	SDL_Texture* yes;
	SDL_Rect ysrc;
	SDL_Rect ydest;
	
	// no variable 
	SDL_Texture* no;
	SDL_Rect nsrc;
	SDL_Rect ndest;
	
	// puts loser on screen
	lose1 = loadKeyedImage("loser.png");
	lsrc.w = 430; lsrc.h = 200; 
	lsrc.x = 0;   lsrc.y =0;
	ldest.w =600; ldest.h=200;
	ldest.x = 200;  ldest.y = 0;
	// puts play again on screen
	again = loadKeyedImage("playagain.png");
	asrc.w = 200; asrc.h = 70; 
	asrc.x = 0;   asrc.y =0;
	adest.w =200; adest.h=70;
	adest.x = 400;  adest.y = 300;
	// puts yes on screen
	yes = loadKeyedImage("yes.png");
	ysrc.w = 200; ysrc.h = 70; 
	ysrc.x = 0;   ysrc.y =0;
	ydest.w =200; ydest.h=70;
	ydest.x = 150;  ydest.y = 300;
	// puts no on screen
	no = loadKeyedImage("no.png");
	nsrc.w = 200; nsrc.h = 70; 
	nsrc.x = 0;   nsrc.y =0;
	ndest.w =200; ndest.h=70;
	ndest.x = 650;  ndest.y = 300;
	while(1)
	{
	 SDL_RenderClear(renderer);
	 SDL_RenderCopy(renderer, lose1, &lsrc, &ldest);
	  SDL_RenderCopy(renderer, again, &asrc, &adest);
	   SDL_RenderCopy(renderer, yes, &ysrc, &ydest);
	    SDL_RenderCopy(renderer, no, &nsrc, &ndest);
	  	 SDL_RenderPresent(renderer);
	 // mouse clicks
	 	if(SDL_GetMouseState(&x, &y) & SDL_BUTTON(SDL_BUTTON_LEFT) )

{      // if the player hits yes resume game play
      if( x>=150 & x<= 350 & y>= 300 & y<=370)
	  {
         gameplay();
	  }
	     // else return to the results page 
	        if( x>=650 & x<= 850 & y>= 300 & y<=370)
	  {
         recordscore();
	  }
	  
	  

}	
	 
	 
	 
	 
	 
	  if (SDL_PollEvent(&event) > 0)
                       {
                       switch(event.type)
                         {
					
                         case SDL_QUIT: 
                           exit(0);
                         }
                       }
	 
	}
 
 
 }
 
void recordscore()
 {
	// load a results screen
	// include total plays
	// include total wins
	// include high score
	// include total losses
	// once quit is hit 
	// save to a text file?
		ofstream output;
	// have a button that can bring up lifetime scores?
    SDL_Event event;
	int x;
	int y;
	SDL_Surface *s;
	char string[100];
	SDL_Color c;
   // load result variable
  SDL_Texture* results;
  SDL_Rect     rsrc;
  SDL_Rect	   rdest;
  // total wins variable
  SDL_Texture* twins;
  SDL_Rect     wsrc;
  SDL_Rect	   wdest;
  // total losses variable
  SDL_Texture* lost;
  SDL_Rect     lsrc;
  SDL_Rect	   ldest;
  // total plays variable
  SDL_Texture* plays;
  SDL_Rect     psrc;
  SDL_Rect	   pdest;
  // total score variable 
  SDL_Texture* tscores;
  SDL_Rect     ssrc;
  SDL_Rect	   sdest;
  // quit button variable
  SDL_Texture* quit;
  SDL_Rect     qsrc;
  SDL_Rect	   qdest;
  // life time results variable
   SDL_Texture* lifetime;
  SDL_Rect     lrsrc;
  SDL_Rect	   lrdest;
  //puts results on screen
    results = loadKeyedImage("resultshead.png");
	rsrc.w = 640; rsrc.h = 200; 
	rsrc.x = 0;   rsrc.y =0;
	rdest.w =640; rdest.h=200;
	rdest.x = 200;  rdest.y = 0;
 // puts total wins on screen
	twins = loadKeyedImage("totalwins.png");
	wsrc.w = 250; 	wsrc.h = 80; 
	wsrc.x = 0;   	wsrc.y =0;
	wdest.w =250; 	wdest.h=80;
	wdest.x = 100;  wdest.y = 200;
// puts total losses on screen	
	lost = loadKeyedImage("totalloss.png");
	lsrc.w = 250; 	lsrc.h = 80; 
	lsrc.x = 0;   	lsrc.y =0;
	ldest.w =250; 	ldest.h=80;
	ldest.x = 100;  ldest.y = 260;
	// puts total plays on the screen
	plays = loadKeyedImage("totalplays.png");
	psrc.w = 250; 	psrc.h = 80; 
	psrc.x = 0;   	psrc.y =0;
	pdest.w =250; 	pdest.h=80;
	pdest.x = 100;  pdest.y = 310;
	// puts total score on screen
	tscores = loadKeyedImage("totalscore.png");
	ssrc.w = 250; 	ssrc.h = 80; 
	ssrc.x = 0;   	ssrc.y =0;
	sdest.w =250; 	sdest.h=80;
	sdest.x = 100;  sdest.y = 360;
	// puts the quit button on screen
	quit = loadKeyedImage("quitbut.png");
	qsrc.w = 250; 	qsrc.h = 80; 
	qsrc.x = 0;   	qsrc.y =0;
	qdest.w =250; 	qdest.h=80;
	qdest.x = 700;  qdest.y = 200;
	// puts lifetime results on screen
	lifetime = loadKeyedImage("lifetimeresults.png");
	lrsrc.w = 250; 	lrsrc.h = 80; 
	lrsrc.x = 0;   	lrsrc.y =0;
	lrdest.w =250; 	lrdest.h=80;
	lrdest.x = 700;  lrdest.y = 400;
	 

	while(1)
	{
	 SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, results, &rsrc, &rdest);
	SDL_RenderCopy(renderer, twins, &wsrc, &wdest);
	// total wins string
	 sprintf(string, "%d",wins);
	c.r = 255; c.g = 255; c.b = 255;
	FixedPrint(renderer, 360, 232, string, &c, 2);
	SDL_RenderCopy(renderer, lost, &lsrc, &ldest);
	// loses win string
	 sprintf(string, "%d",lose);
	c.r = 255; c.g = 255; c.b = 255;
	FixedPrint(renderer, 360, 285, string, &c, 2);
	SDL_RenderCopy(renderer, plays, &psrc, &pdest);
	// total plays string
	 sprintf(string, "%d",totalplays);
	c.r = 255; c.g = 255; c.b = 255;
	FixedPrint(renderer, 360, 337, string, &c, 2);
	SDL_RenderCopy(renderer, tscores, &ssrc, &sdest);
	// final score string
    sprintf(string, "%d",finalscore);
	c.r = 255; c.g = 255; c.b = 255;
	FixedPrint(renderer, 360, 387, string, &c, 2);
	SDL_RenderCopy(renderer, quit, &qsrc, &qdest);
	SDL_RenderCopy(renderer, lifetime, &lrsrc, &lrdest);
	 SDL_RenderPresent(renderer);	

if(SDL_GetMouseState(&x, &y) & SDL_BUTTON(SDL_BUTTON_LEFT) )

{    
      if( x>=700 & x<= 950 & y>= 200 & y<=280)
	  {
         // save to a file 
		
		 output.open("gamescore1.txt");
		 
		     // write wins to file
		    output<<wins<<endl;
			// write lose to file
			output<<lose<<endl;
			// write total plays to file
			output<<totalplays<<endl;
			// write final score to file
			output<<finalscore<<endl;
		 
		 output.close();
		 return;
	  }
  if( x>=700 & x<= 950 & y>= 400 & y<=480)
	  {
         // save to a file 
		 output.open("gamescore1.txt");
		 
		     // write wins to file
		    output<<wins<<endl;
			// write lose to file
			output<<lose<<endl;
			// write total plays to file
			output<<totalplays<<endl;
			// write final score to file
			output<<finalscore<<endl;
		 
		 output.close();
		 lifetimescore();
	  }
}



	 
	  if (SDL_PollEvent(&event) > 0)
                       {
                       switch(event.type)
                         {
					
                         case SDL_QUIT: 
                           exit(0);
                         }
                       }
	 
	}
 
 }
 
 
  void lifetimescore()
{
 // once a button is hit 
  //a lifetime score page will pop up
 // this will load the information from a textfile
 // to the final score variables
 
     int lifescore =0;
	 int lifeplay = 0;
	 int lifewins =0;
	 int lifeloss =0;
	 int tempscore =0;
	 int tempplay =0;
	 int tempwins = 0;
	 int temploss = 0;
	 
     SDL_Event event;
	int x;
	int y;
	SDL_Surface *s;
	char string[100];
	SDL_Color c;
   // load result variable
	SDL_Texture* liferesults;
	SDL_Rect     lrsrc;
	SDL_Rect	 lrdest;
  // total wins variable
  SDL_Texture* twins;
  SDL_Rect     wsrc;
  SDL_Rect	   wdest;
  // total losses variable
  SDL_Texture* lost;
  SDL_Rect     lsrc;
  SDL_Rect	   ldest;
  // total plays variable
  SDL_Texture* plays;
  SDL_Rect     psrc;
  SDL_Rect	   pdest;
  // total score variable 
  SDL_Texture* tscores;
  SDL_Rect     ssrc;
  SDL_Rect	   sdest;
  // quit button variable
  SDL_Texture* quit;
  SDL_Rect     qsrc;
  SDL_Rect	   qdest;
  
  // puts lifetime results on screen
    liferesults = loadKeyedImage("liferesults.png");
	lrsrc.w = 600; lrsrc.h = 100; 
	lrsrc.x = 0;   lrsrc.y =0;
	lrdest.w =600; lrdest.h=100;
	lrdest.x = 200;  lrdest.y = 0;
	// puts total wins on screen
	twins = loadKeyedImage("totalwins.png");
	wsrc.w = 250; 	wsrc.h = 80; 
	wsrc.x = 0;   	wsrc.y =0;
	wdest.w =250; 	wdest.h=80;
	wdest.x = 100;  wdest.y = 200;
	// puts total losses on screen	
	lost = loadKeyedImage("totalloss.png");
	lsrc.w = 250; 	lsrc.h = 80; 
	lsrc.x = 0;   	lsrc.y =0;
	ldest.w =250; 	ldest.h=80;
	ldest.x = 100;  ldest.y = 260;
	// puts total plays on the screen
	plays = loadKeyedImage("totalplays.png");
	psrc.w = 250; 	psrc.h = 80; 
	psrc.x = 0;   	psrc.y =0;
	pdest.w =250; 	pdest.h=80;
	pdest.x = 100;  pdest.y = 310;
	// puts total score on screen
	tscores = loadKeyedImage("totalscore.png");
	ssrc.w = 250; 	ssrc.h = 80; 
	ssrc.x = 0;   	ssrc.y =0;
	sdest.w =250; 	sdest.h=80;
	sdest.x = 100;  sdest.y = 360;
	// puts quit button on the screen
	quit = loadKeyedImage("quitbut.png");
	qsrc.w = 250; 	qsrc.h = 80; 
	qsrc.x = 0;   	qsrc.y =0;
	qdest.w =250; 	qdest.h=80;
	qdest.x = 700;  qdest.y = 200;
	ifstream input;
	ofstream output;
	input.open("gamescore1.txt");
	while(!(input.eof()))
	{
	   input>> tempwins;
	   input>> temploss;
	   input>> tempplay;
	   input>> tempscore;
	   }
	   
	 input.close();
	   lifewins = tempscore + wins;
	   lifeloss = temploss + lose;
	   lifeplay = tempplay + totalplays;
	   lifescore = tempscore + finalscore;
	input.open("gamescore2.txt");
	while(!(input.eof()))
	{
	   input>> tempwins;
	   input>> temploss;
	   input>> tempplay;
	   input>> tempscore;
	   }
	    input.close();
	   lifewins = tempscore + wins;
	   lifeloss = temploss + lose;
	   lifeplay = tempplay + totalplays;
	   lifescore = tempscore + finalscore;
	while(1)
	{
		 SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, liferesults, &lrsrc, &lrdest);
		SDL_RenderCopy(renderer, twins, &wsrc, &wdest);
		// print life wins
		 sprintf(string, "%d",lifewins);
	c.r = 255; c.g = 255; c.b = 255;
	FixedPrint(renderer, 360, 232, string, &c, 2);
	   SDL_RenderCopy(renderer, lost, &lsrc, &ldest);
	   // print life loss
	    sprintf(string, "%d",lifeloss);
	c.r = 255; c.g = 255; c.b = 255;
	FixedPrint(renderer, 360, 285, string, &c, 2);
	   SDL_RenderCopy(renderer, plays, &psrc, &pdest);
	   // print life plays
	    sprintf(string, "%d",lifeplay);
	c.r = 255; c.g = 255; c.b = 255;
	FixedPrint(renderer, 360, 337, string, &c, 2);
	   SDL_RenderCopy(renderer, tscores, &ssrc, &sdest);
	   // print life score
	    sprintf(string, "%d",lifescore);
	c.r = 255; c.g = 255; c.b = 255;
	FixedPrint(renderer, 360, 387, string, &c, 2);
		SDL_RenderCopy(renderer, quit, &qsrc, &qdest);

		
		if(SDL_GetMouseState(&x, &y) & SDL_BUTTON(SDL_BUTTON_LEFT) )
{    
      if( x>=700 & x<= 950 & y>= 200 & y<=280)
	  {
         // write to a file
		  output.open("gamescore2.txt");
		 
		     // write wins to file
		    output<<lifewins<<endl;
			// write lose to file
			output<<lifeloss<<endl;
			// write total plays to file
			output<<lifeplay<<endl;
			// write final score to file
			output<<lifescore<<endl;
		 
		 output.close();
		 exit(0);
	  }
		}
		 SDL_RenderPresent(renderer);	


	 if (SDL_PollEvent(&event) > 0)
                       {
                       switch(event.type)
                         {
					
                         case SDL_QUIT: 
                           exit(0);
                         }
                       }
	}
	
		


} 
 
 //////////////////////////////////// END OF CODE!!!!///////////////////
 
 
 
 
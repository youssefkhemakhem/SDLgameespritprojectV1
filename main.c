
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "head.h"
int main(int argc, char * argv){
	
	int x =0;
	int y =0;
	int vc = 11;
	int change=0;
	int hover1 = 0;
	int hover2 = 0;
	SDL_Init(SDL_INIT_EVERYTHING);
	Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 );
	TTF_Init();
	SDL_Rect startpos;
	SDL_Rect Sprite[2];
        SDL_Rect logopos;

	SDL_Rect setpos;
	
	
	TTF_Font * police = TTF_OpenFont("Distorted.ttf",60);
	TTF_Font * policeset = TTF_OpenFont("Distorted.ttf",65);
	SDL_Surface * start = NULL;
	SDL_Surface * settings = NULL;
	SDL_Surface* settingsback = NULL;
	SDL_Surface* volumebarf = NULL;
	Mix_Chunk * bref= Mix_LoadWAV("button.wav");
	Mix_Music * music = Mix_LoadMUS("gamesound.mp3");
	Mix_FadeInMusic(music,-1,132);
	
	int curscre = 0;
	

	int cont = 0;
	int i =0;
	int ic;
	SDL_Surface * logo=NULL;
	SDL_Surface * soundchar=NULL;
	SDL_Rect soundcharp;
	SDL_Rect mainmexitp;
	
	
	SDL_Rect soundfp[11];
	
	
	SDL_Surface * exitset;
	SDL_Rect exitsetp;
	
	SDL_Rect settingsbackr;
	settingsbackr.x = 400;
	settingsbackr.y = 100;
	
	exitsetp.x = 690;
	exitsetp.y = 450;
	exitsetp.w = 100;
	exitsetp.h = 50;
	
	soundcharp.x = 430;
	soundcharp.y = 220;
	
	
	startpos.x = 680;
	setpos.x = 655;
	mainmexitp.x = 705;
	startpos.y = 425;
	startpos.h = 50;
	startpos.w = 100;
	
	setpos.y = 525;
	setpos.h = 50;
	setpos.w = 150;
	
	mainmexitp.y =625;
	mainmexitp.w= 100;
	mainmexitp.h=50;
	
	SDL_Surface * control;
	SDL_Event event = {0};
	SDL_Surface * background = NULL;

	
	SDL_Surface * screen = NULL;
	screen = SDL_SetVideoMode(1650,800,32, SDL_DOUBLEBUF | SDL_HWSURFACE |SDL_RESIZABLE);
	
	background = IMG_Load("black.png");
	settingsback = IMG_Load("frameoption.png");
	logo = IMG_Load("spritesheet.png");
	volumebarf = IMG_Load("rsz_soundcaseblank.jpg");
	SDL_Surface * volumebarff = IMG_Load("rsz_soundcase.jpg");
	SDL_Surface * mainmexit = IMG_Load("exit.png");
	
	
	backg(background, screen);
	
	
	
	int cc = 1;
	while(cc == 1){
	switch(curscre){
	
	case 0:
	screen = SDL_SetVideoMode(1650,800,32, SDL_DOUBLEBUF | SDL_HWSURFACE);
	
	cc =mainmenuf(curscre, change, screen, police, policeset,start,settings,  startpos, setpos, i, logo, Sprite,logopos,background, event, cont,mainmexit,mainmexitp,bref);
	
       printf("%d cc",cc);
					
	curscre = 1;
	
	break;
	
	
	
	
	case 1:
	
	SDL_FreeSurface(screen);
	
	screen = SDL_SetVideoMode(1650,800,32, SDL_DOUBLEBUF | SDL_HWSURFACE );
	printf("Cur screen %d\n", curscre);
	
	optionmenu(screen,settingsback,volumebarf,volumebarff,soundchar,exitset,soundfp,settingsbackr,exitsetp,soundcharp ,event, police, policeset,ic, vc,cont,curscre,change);
	curscre = 0;
	break;
	
	

	
	}
	if(cc==0){break;}
	printf("Still in maingame\n");
	}

	
	printf("Exit game\n");
	

	SDL_FreeSurface(screen);
	SDL_FreeSurface(logo);
	SDL_FreeSurface(background);
	TTF_CloseFont(police);
	Mix_FreeMusic(music);
	TTF_Quit();
	SDL_Quit();
	return 0;
	

	
}






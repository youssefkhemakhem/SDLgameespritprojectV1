#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "head.h"

int animation(int i,SDL_Surface * screen, SDL_Surface *logo, SDL_Rect Sprite[2],SDL_Rect logopos){
       int s=i;
        int elapsed=SDL_GetTicks();
	int wait=SDL_GetTicks()-elapsed;
 	
        
        logopos.x = 675;
	logopos.y = 100;
        Sprite[0].x=1;
	Sprite[0].y = 1;
	Sprite[0].h =250;
	Sprite[0].w = 250;
	Sprite[1].x=261;
	Sprite[1].y = 1;
	Sprite[1].h =250;
	Sprite[1].w = 250;
	Sprite[2].x=521;
	Sprite[2].y = 1;
	Sprite[2].h =250;
	Sprite[2].w = 250;
	s++;
	if(s>2){
		s=0;
	}
	switch(s){
	case 0:
	SDL_Delay(100);
	break;
	case 1:
	SDL_Delay(250);
	break;
	case 2:
	SDL_Delay(250);
	break;
	}
	
	SDL_BlitSurface(logo,&Sprite[s],screen,&logopos);
	return s;
	

}
void text1(SDL_Surface * screen, TTF_Font * police, TTF_Font *policeset,SDL_Surface * start,SDL_Surface * settings, SDL_Rect startpos, SDL_Rect setpos,char * message1,char* message2){

	
	SDL_Color white = {255,255,255};

	
	
	
	start= IMG_Load(message1);
	settings = IMG_Load(message2);
	
	
	SDL_BlitSurface(settings,NULL,screen,&setpos);
	SDL_BlitSurface(start,NULL,screen,&startpos);
}



void backg(SDL_Surface *background, SDL_Surface * screen){
	SDL_Rect backpos;
	backpos.x = 325;
	backpos.y = 850;
	
	SDL_BlitSurface(background,&backpos,screen,&backpos);

}
void volume(SDL_Surface * screen, SDL_Surface * volumebarf, SDL_Rect soundfp[11]){

	soundfp[0].x = 720;
	soundfp[0].y = 235;
	
	soundfp[1].x = 750;
	soundfp[1].y = 235;
	
	soundfp[2].x = 780;
	soundfp[2].y = 235;
	
	soundfp[3].x = 810;
	soundfp[3].y = 235;
	
	soundfp[4].x =840;
	soundfp[4].y = 235;
	
	soundfp[5].x = 870;
	soundfp[5].y = 235;
	
	soundfp[6].x = 900;
	soundfp[6].y = 235;
	
	soundfp[7].x = 930;
	soundfp[7].y = 235;
	
	soundfp[8].x = 960;
	soundfp[8].y = 235;
	
	soundfp[9].x = 990;
	soundfp[9].y = 235;
	
	soundfp[10].x = 1020;
	soundfp[10].y = 235;
	
	soundfp[11].x = 1050;
	soundfp[11].y = 235;


		SDL_BlitSurface(volumebarf, NULL, screen, &soundfp[0]);
		SDL_BlitSurface(volumebarf, NULL, screen, &soundfp[1]);
		SDL_BlitSurface(volumebarf, NULL, screen, &soundfp[2]);
		SDL_BlitSurface(volumebarf, NULL, screen, &soundfp[3]);
		SDL_BlitSurface(volumebarf, NULL, screen, &soundfp[4]);
		SDL_BlitSurface(volumebarf, NULL, screen, &soundfp[5]);
		SDL_BlitSurface(volumebarf, NULL, screen, &soundfp[6]);
		SDL_BlitSurface(volumebarf, NULL, screen, &soundfp[7]);
		SDL_BlitSurface(volumebarf, NULL, screen, &soundfp[8]);
		SDL_BlitSurface(volumebarf, NULL, screen, &soundfp[9]);
		SDL_BlitSurface(volumebarf, NULL, screen, &soundfp[10]);
		SDL_BlitSurface(volumebarf, NULL, screen, &soundfp[11]);
		


}

void optionmenu(SDL_Surface *screen,SDL_Surface * settingsback, SDL_Surface *volumebarf,SDL_Surface *volumebarff,SDL_Surface * soundchar,SDL_Surface *exitset,SDL_Rect soundfp[11],SDL_Rect settingsbackr, SDL_Rect exitsetp, SDL_Rect soundcharp ,SDL_Event event, TTF_Font * police, TTF_Font * policeset, int ic, int vc,int cont,int curscre, int change){
	
	int x,y;
	
	if(curscre ==1){
		if(change ==1 ){
		
		change = 0;	
		}
		
		
		SDL_BlitSurface(settingsback, NULL, screen, &settingsbackr);
		volume(screen,volumebarf,soundfp);
		text1(screen,police,policeset,soundchar,exitset,exitsetp,soundcharp,"exit.png","volume.png");
		while(cont==0){
			
	
			SDL_WaitEvent(&event);
			
				
				if(event.motion.x>=exitsetp.x && event.motion.x<=exitsetp.x+exitsetp.w && event.motion.y>=exitsetp.y && event.motion.y<=exitsetp.y+exitsetp.h){
						printf("%d %d %d second sheet\n",event.motion.x, event.motion.y,x);
						if(event.type == SDL_MOUSEBUTTONDOWN){
       					 {
       					
       					printf("%d %d %d\n",event.motion.x, event.motion.y,x);
           					printf("lovelydown\n");
        				 	printf("Click\n");
        				 	
        				 	cont = 1;
        				 	break;
        				

       				
       					}
           					 
       					}
       					}
       		
       			
       					
				if (event.type == SDL_QUIT){
				cont=1;
				break;
				
				}
				
	
				
			
                    	
                    		else if (event.key.keysym.sym == SDLK_RIGHT){
                    		vc+=1;}
                    		if(vc>11){vc=11;}
                    		
                    		
                    		else if (event.key.keysym.sym ==SDLK_LEFT){
                    		vc-=1;
                    		if(vc<-2){vc=-2;}}
                    		
                    		
				
				
				
				
                	
                	if(vc<=11){
                	for(ic=0; vc+1>ic;ic++){
                			
					SDL_BlitSurface(volumebarff,NULL,screen,&soundfp[ic]);
					
				
				}
			
			}
			for(ic=10; vc<ic;ic--){
			
					SDL_BlitSurface(volumebarf,NULL,screen,&soundfp[ic+1]);
					
				
				}
			printf("VC %d", vc);
                	Mix_VolumeMusic(vc*11);
	
			SDL_Flip(screen);
			
			}

		}
		
		}
		
		
		
		
		int mainmenuf(int curscre, int change, SDL_Surface* screen, TTF_Font * police, TTF_Font * policeset, SDL_Surface * start, SDL_Surface * settings, SDL_Rect startpos, SDL_Rect setpos, int i, SDL_Surface* logo, SDL_Rect Sprite[3],SDL_Rect logopos,  SDL_Surface * background, SDL_Event event, int cont, SDL_Surface *mainmexit, SDL_Rect mainmexitp){
		int x;
		int y;
		background = IMG_Load("black.png");
		logo = IMG_Load("spritesheet.png");
		backg(background, screen);
		
		if(change ==1){
		
		change = 0;	
		}
		backg(background,screen);
		text1(screen,police,policeset,start,settings,startpos,setpos,"start.png","option.png");
		SDL_BlitSurface(mainmexit,NULL,screen,&mainmexitp);
		
		
		while(cont==0){
			
	
				
				
	
			i =animation(i,screen,logo,Sprite,logopos);
				
				
				while(SDL_PollEvent(&event)){
				
				switch(event.type){
					case SDL_QUIT:
					printf("Continuer\n");
					cont=1;
					
					return 0;
					case SDL_MOUSEBUTTONDOWN:
					x = event.motion.x;
       				y = event.motion.y;
       				if(event.motion.x>=setpos.x && event.motion.x<=setpos.x+setpos.w && event.motion.y>=setpos.y && event.motion.y<=setpos.y+setpos.h)

       					 {
       					
       					printf("%d %d %d\n",setpos.w, setpos.h,x);
           					 curscre = 1;
           					 if( event.button.button == SDL_BUTTON_LEFT )
        					{
        				 	printf("Click\n");
        				 	curscre =1;
        				 	cont = 1;
        				 	break;
        				

       				
       					}
           					 
       					}
       				else if(event.motion.x>=mainmexitp.x && event.motion.x<=mainmexitp.x+mainmexitp.w && event.motion.y>=mainmexitp.y && event.motion.y<=mainmexitp.y+mainmexitp.h)

       					 {
       					
       					printf("%d %d %d exit button main menu\n",mainmexitp.w, mainmexitp.h,x);
           					 curscre = 1;
           					 if( event.button.button == SDL_BUTTON_LEFT )
        					{
        				 	printf("Click\n");
        				 	
        				 	return 0;
        				 	break;
        				

       				
       					}
           					 
       					}
				
					
       				break;
				
				
				}
				}
				
			
			SDL_Flip(screen);
			
		}
		
		return 1;
	
	
	
	
		
		
		}

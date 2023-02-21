#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
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
	int ex =0;
	int backo = 1;
	
	if(curscre ==1){
		if(change ==1 ){
		
		change = 0;	
		}
		
		
		
		volume(screen,volumebarf,soundfp);
		
		while(cont==0){
		if(backo ==0){
		SDL_BlitSurface(settingsback, NULL, screen, &settingsbackr);
		backo = 1;}
		if(ex == 0){
		text1(screen,police,policeset,soundchar,exitset,exitsetp,soundcharp,"exit.png","volume.png");}
		else if(ex ==1){text1(screen,police,policeset,soundchar,exitset,exitsetp,soundcharp,"exita.jpg","volume.png");}
		
		
			
	
			SDL_WaitEvent(&event);
			
			
				
				if(event.motion.x>=exitsetp.x && event.motion.x<=exitsetp.x+exitsetp.w+100 && event.motion.y>=exitsetp.y && event.motion.y<=exitsetp.y+exitsetp.h){
						ex = 1;
						if(event.type == SDL_MOUSEBUTTONDOWN){
       					 {
       					

        				 	
        				 	cont = 1;
        				 	break;
        				

       				
       					}
           					 
       					}
       					}
       			else if(!(event.motion.x>=exitsetp.x && event.motion.x<=exitsetp.x+exitsetp.w+100 && event.motion.y>=exitsetp.y && event.motion.y<=exitsetp.y+exitsetp.h)){ex = 0;}
       			
       		
       			
       					
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
                    		else if( event.key.keysym.sym == SDLK_ESCAPE){
                    		cont = 1;
                    		break;}
                    		
                    		
				
				
				
				
                	
                	if(vc<=11){
                	for(ic=0; vc+1>ic;ic++){
                			
					SDL_BlitSurface(volumebarff,NULL,screen,&soundfp[ic]);
					
				
				}
			
			}
			for(ic=10; vc<ic;ic--){
			
					SDL_BlitSurface(volumebarf,NULL,screen,&soundfp[ic+1]);
					
				
				}
			
                	Mix_VolumeMusic(vc*11);
			
			SDL_Flip(screen);
			
			backo = 0;
			
			}

		}
		
		}
		
		
		
		
		int mainmenuf(int curscre, int change, SDL_Surface* screen, TTF_Font * police, TTF_Font * policeset, SDL_Surface * start, SDL_Surface * settings, SDL_Rect startpos, SDL_Rect setpos, int i, SDL_Surface* logo, SDL_Rect Sprite[3],SDL_Rect logopos,  SDL_Surface * background, SDL_Event event, int cont, SDL_Surface *mainmexit, SDL_Rect mainmexitp, Mix_Chunk* bref){
		
		
		
		int x;
		int y;
		int backgc = 1;
		int set= 0;
		int strt = 1;
		int ex = 0;
		SDL_Color white = {255,255,255};
		
		background = IMG_Load("black.png");
		logo = IMG_Load("spritesheet.png");
		backg(background, screen);
		SDL_Surface *black = IMG_Load("black.png");
		Mix_Chunk * effect = Mix_LoadWAV("button.wav");
		SDL_Surface * optionsf = IMG_Load("option.png");
		SDL_Rect blackp1;
		blackp1.x =600;
		blackp1.y = 250;
		blackp1.w = 100;
		blackp1.h =200;
		SDL_Rect blackp;
		SDL_Surface * exita = IMG_Load("exita.jpg");
		SDL_Surface * starta = IMG_Load("starta.jpg");
		TTF_Font * policec = TTF_OpenFont("fonty.ttf",10);
		SDL_Surface * copy = TTF_RenderText_Blended(policec,"Made by S.H.A.P.E", white);
		SDL_Rect copyp;
		copyp.x = 50;
		copyp.y = 780;
		blackp.w = 100;
		blackp.h =200;
		blackp.x =600;
		blackp.y = 250;
		if(change ==1){
		
		change = 0;	
		}


		
		
		while(cont==0){
		printf("set %d\n",set);
		if(set == 1){text1(screen,police,policeset,start,optionsf,startpos,setpos,"start.png","optiona.jpg");}
		else{text1(screen,police,policeset,start,settings,startpos,setpos,"start.png","option.png");}
		backg(background,screen);
		if(ex ==0){
		SDL_BlitSurface(mainmexit,NULL,screen,&mainmexitp);
		}
		else{SDL_BlitSurface(exita,NULL,screen,&mainmexitp);}
		if(strt ==1){
		SDL_BlitSurface(starta,NULL,screen,&startpos);
		
		printf("Start = 1\n");
		}
		else if(strt ==0){
		SDL_BlitSurface(start,NULL,screen,&startpos);
		
		
		}
		
		
		
		
			
	
				
				
	
			i =animation(i,screen,logo,Sprite,logopos);
				SDL_BlitSurface(copy,NULL,screen,&copyp);
				
				while(SDL_PollEvent(&event)){
				
				
				if(event.key.keysym.sym == SDLK_DOWN){
					
					if(set == 1){strt = 0; set =0; ex =1;}
					else if(strt == 1){strt = 0; set = 1; ex =0;}
	
					else if(ex == 0 && set == 0 && strt ==0) {strt = 1;}
					break;
					
					}
					
					else if(event.key.keysym.sym == SDLK_UP){
					
					if(set == 1){strt =1; set =0; ex =0;}
					else if(ex == 1){strt = 0; set = 1; ex =0;}
					else if(ex == 0 && set == 0 && strt ==0){strt =1;}
					
					}
					
					if(event.key.keysym.sym== SDLK_RETURN){
					if(strt == 1){printf("Starting game\n");}
					 else if(set == 1){cont = 1;}
					else if(ex ==1) {return 0;}
					
					}
					if(event.key.keysym.sym== SDLK_o){
						curscre =1;
        				 	cont = 1;
        				 	break;
					
					}
					if(event.key.keysym.sym== SDLK_ESCAPE){return 0;}
				switch(event.type){
					case SDL_QUIT:
				
					cont=1;
					
					return 0;
					break; 
					
					
					
					
					
					case SDL_MOUSEBUTTONDOWN:
					x = event.motion.x;
       				y = event.motion.y;
       				if(event.motion.x>=setpos.x && event.motion.x<=setpos.x+setpos.w+100 && event.motion.y>=setpos.y && event.motion.y<=setpos.y+setpos.h)

       					 {
       					
       					
           					 curscre = 1;
           					 if( event.button.button == SDL_BUTTON_LEFT )
        					{
        				 	printf("Click\n");
        				 	Mix_PlayChannel( -1, effect, 0 );
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
        					Mix_PlayChannel( -1, effect, 0 );
        				 	printf("Click\n");
        				 	
        				 	return 0;
        				 	break;
        				

       				
       					}
           					 
       					}
				
					
       				break;
       				
       				
				case SDL_MOUSEMOTION:
         	  
              	  
             
 		
              if (event.motion.x > setpos.x && event.motion.y > setpos.y-50 && event.motion.x < setpos.x + setpos.w +100&& event.motion.y < setpos.y + setpos.h)
                {
                    set= 1;
                    printf("button hover on setting\n");
                    Mix_PlayChannel(0,bref,1);
                   
                  
                    
                    
                }
                else if(!((event.motion.x > setpos.x && event.motion.y > setpos.y-50 && event.motion.x < setpos.x + setpos.w+100 && event.motion.y < setpos.y + setpos.h))){
                
                set =0;
                 }
                 if(event.motion.x>=mainmexitp.x && event.motion.x<=mainmexitp.x+mainmexitp.w && event.motion.y>=mainmexitp.y && event.motion.y<=mainmexitp.y+mainmexitp.h){
                 
                 ex = 1;
                 }
                 else{
                 ex = 0;}
                 if(event.motion.x>=startpos.x && event.motion.x<=startpos.x+startpos.w && event.motion.y>=startpos.y && event.motion.y<=startpos.y+startpos.h){
                 
                 strt = 1;
                 printf("Turning start = 1\n");
                 }
                 else if (!(event.motion.x>=startpos.x && event.motion.x<=startpos.x+startpos.w && event.motion.y>=startpos.y && event.motion.y<=startpos.y+startpos.h)){strt = 0; }
                 
               
				
		}
		}
				
			
			SDL_Flip(screen);
			screen = SDL_SetVideoMode(1650,800,32, SDL_DOUBLEBUF | SDL_HWSURFACE );
			
		}
		
		return 1;
	
	
	
	
		
		
		}

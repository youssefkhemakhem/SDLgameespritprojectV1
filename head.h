#ifndef HEADER_FILE
#define HEADER_FILE
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>


int animation(int i,SDL_Surface * screen, SDL_Surface *logo, SDL_Rect Sprite[2],SDL_Rect logopos);
void text1(SDL_Surface * screen, TTF_Font * police, TTF_Font *policeset,SDL_Surface * start,SDL_Surface * settings, SDL_Rect startpos, SDL_Rect setpos,char * message1, char * message2);

void backg(SDL_Surface *background, SDL_Surface * screen);
void volume(SDL_Surface * screen, SDL_Surface * volumebarf, SDL_Rect soundfp[11]);
void optionmenu(SDL_Surface *screen,SDL_Surface * settingsback, SDL_Surface *volumebarf,SDL_Surface *volumebarff,SDL_Surface * soundchar,SDL_Surface *exitset,SDL_Rect soundfp[11],SDL_Rect settingsbackr, SDL_Rect exitsetp, SDL_Rect soundcharp ,SDL_Event event, TTF_Font * police, TTF_Font * policeset, int ic, int vc,int cont,int curscre, int change);
int mainmenuf(int curscre, int change, SDL_Surface * screen, TTF_Font * police, TTF_Font * policeset, SDL_Surface * start, SDL_Surface * settings, SDL_Rect startpos, SDL_Rect setpos, int i, SDL_Surface * logo, SDL_Rect Sprite[3],SDL_Rect logopos, SDL_Surface * background, SDL_Event event, int cont,SDL_Surface *mainmexit, SDL_Rect mainmexitp);

#endif

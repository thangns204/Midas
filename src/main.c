#include "SDL2/SDL.h"
#include "main.h"
#include "application.h"
#include "images.h"
#include "draw.h"
#include "phisics.h"

static int gameRunning;

int main(int argc, char *argv[]) {	
	if (argc > 1) 	Resource_init(argv[0]);
	else 			Resource_init("levels");

	Game_init();
	Main_loop();
	Clean_up();

	return 0;
}

static void Resource_init(char* levels_file_path) {
	Init_window(SCREEN_TITLE, SCREEN_WIDTH, SCREEN_HEIGHT);
	Load_imgs();
	Load_levels(levels_file_path);
	/*Set_heads_imgs();*/
}

static void Game_init() {
	gameRunning = 1;
}

static void Process_events() {
	SDL_Event event;
	
	while (SDL_PollEvent(&event))
		if (event.type == SDL_QUIT){
			gameRunning = 0;
			break;
		}
		else if( event.type == SDL_KEYDOWN ){
			SDL_Keycode keycode = event.key.keysym.sym;

			if 		(keycode == SDLK_UP    	|| keycode == SDLK_w)	Key_up_event();
			else if (keycode == SDLK_LEFT  	|| keycode == SDLK_a)	Key_left_event();
            else if (keycode == SDLK_RIGHT 	|| keycode == SDLK_d)	Key_right_event();
            else if (keycode == SDLK_1 		|| keycode == SDLK_q)	Key_prev_level_event();
            else if (keycode == SDLK_3 		|| keycode == SDLK_e)	Key_next_level_event();
            else if (keycode == SDLK_2 		|| keycode == SDLK_r)	Key_restart_level_event();
			else {
				/*
				do nothing
				 */
			}
		}
}

static void Main_loop() {
	while( gameRunning ) {
		Process_events();
		Render();
	}	
}

static void Clean_up() {
	CleanUp_images();
	CleanUp_screen();
	CleanUp_window();

	SDL_Quit();
}

static void Key_up_event(void){

}

static void Key_left_event(void){

}

static void Key_right_event(void){

}

static void Key_restart_level_event(void){

}

static void Key_next_level_event(void){

}

static void Key_prev_level_event(void){

}

static void Render(void){
	Draw_background();

	Update_window();
}

static void Load_levels(char* levels_file_path){
	printf("%s\n",levels_file_path);
}
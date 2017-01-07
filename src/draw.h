#ifndef _DRAW_H_
	#define _DRAW_H_
	
	enum {
		GOLD_BLOCK,
		GRAY_BLOCK
	};

	#define GOLD_COLOR_R 255
	#define GOLD_COLOR_G 204
	#define GOLD_COLOR_B 51
	
	#define GRAY_COLOR_R 192
	#define GRAY_COLOR_G 192
	#define GRAY_COLOR_B 192

	#define BORDER_COLOR_R 0
	#define BORDER_COLOR_G 0
	#define BORDER_COLOR_B 0

	int Draw_img		(SDL_Surface* dest_surface, SDL_Surface* src_surface, size_t x, size_t y);
	int Draw_block		(SDL_Surface* dest_surface, size_t block_type, size_t x, size_t y, size_t w, size_t h);
	int Draw_background	(SDL_Surface* dest_surface, SDL_Surface* src_surface);
#endif
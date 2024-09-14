#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdbool.h>

#define WIDTH 16
#define HEIGHT 9
#define SIZE_FACTOR 100

#define FPS 60

// SDL  
SDL_Window *window;
SDL_Renderer *renderer;
// SDL_Renderer *debugRenderer;

// Framerate variables
const int frameDelay = 1000 / FPS;
Uint64 frameStart;
Uint64 frameTime;

void fix_framerate(  ) {
    frameTime = SDL_GetTicks() - frameStart;

    if ( frameDelay > frameTime ) {
        SDL_Delay( frameDelay - frameTime );
    }
}

int game_loop( ) {
    window = SDL_CreateWindow( 
    "Cnake", 
    SDL_WINDOWPOS_UNDEFINED, 
    SDL_WINDOWPOS_UNDEFINED, 
    WIDTH * SIZE_FACTOR, HEIGHT * SIZE_FACTOR, 
    SDL_WINDOW_ALLOW_HIGHDPI );
    
    if ( NULL == window ) {
      SDL_Log("Could not create window");
      return 1;
    }

    renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );
    if ( NULL == renderer ) {
      SDL_Log("Could not create renderer");
      return 1;
    }


    SDL_SetRenderDrawColor( renderer, 0, 0, 0, 255 );
    SDL_RenderClear( renderer );
    SDL_RenderPresent( renderer );

    SDL_Event windowEvent;

    bool is_running = true;

    SDL_Log("Starting Main loop fixed at %dHz\n", FPS);
    // Main Program LOOP
    while ( is_running )
    {
        frameStart = SDL_GetTicks();
        while ( SDL_PollEvent( &windowEvent ) )
        {
            // Check for SDL Events
            if ( SDL_QUIT == windowEvent.type )
            {
                is_running = false;
            }
        }
        
        // Clear full screen
        SDL_SetRenderDrawColor( renderer, 0, 0, 0, SDL_ALPHA_OPAQUE );
        SDL_RenderClear( renderer );

        // FILL FRAME BUFFER HERE

        // Display the buffer on the screen
        SDL_RenderPresent( renderer );

        // Fix the framerate
        fix_framerate( );
    }

    SDL_DestroyWindow( window );
    SDL_Quit( );

    return EXIT_SUCCESS;
}
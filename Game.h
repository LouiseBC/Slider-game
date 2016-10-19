#ifndef Game_h
#define Game_h
#include <vector>
#include <SDL2/SDL.h>
#include "Graphics.h"

class GameState;

class Game {
public:
    Game();
    
    bool init(GameState* state);
    void loop();
    
    void pushState(GameState* state);
    void popState();
    int statesSize() { return states.size(); }
    void setQuit();
    
    void toggleCatMode();
    bool isCatMode() { return catMode; }
private:
    void update();
    void render();
    void quitGame();
    
    bool quit    { false };
    bool catMode { false };
    
    Graphics graphics;
    SDL_Event event;
    std::vector<GameState*> states;
};

#endif

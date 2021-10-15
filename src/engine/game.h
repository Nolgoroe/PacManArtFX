#ifndef GAME_H
#define GAME_H

#include <GL/glew.h>
#include <SDL.h>

#include <memory>
#include <array>

//#include "Shader.h"

#include "Cube.h"

#include <vector>

using std::array;
using std::vector;

// This game class runs a simple game loop
class Game {
   public:
    Game();
    virtual ~Game();

    void init(int screenWidth, int screenHeight);
    void load();
    void handleInputs();

    Shader shader;
    //void update(Cube c, float dt);
    //void render();
    //void clean();

    bool isRunning;
    int windowWidth, windowHeight;

    //vector<Cube> GetArrayCubes();

    vector<Cube> cubesToMove;
   private:

    // GLuint vao;
    // GLuint buffer;
    // float timeSinceStart;

    // Matrix4 transform;
     Matrix4 projection;
};

#endif
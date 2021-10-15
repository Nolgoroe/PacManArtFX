#ifndef CUBE_H
#define CUBE_H

#include <GL/glew.h>
#include <SDL.h>

#include <memory>
#include <array>

#include "Shader.h"

#include <ctime>

class Cube
{
    private:
    
    static GLfloat vertexPositions[108];

    int type;
    int x;
    int y;
    int z;

    GLuint vao;
    GLuint buffer;
    float timeSinceStart;

    Matrix4 transform;
    Matrix4 projection;
    //Shader shader;

    public:
    Cube();
    Cube(int inX, int inY, int inZ);
    ~Cube();

    void GetVertxPositions();

    int getType() 
	{
		return type;
	}

    int getX() 
	{
		return x;
	}

    int getY()
    {
        return y;
    }

    void getxy(int *, int*);
	void setType(int);


    void Load(int windowWidth, int windowHeight, Shader &shader);
    void Update(float dt);
    void Render(Shader &shader);
    void Clean();
    
};

#endif

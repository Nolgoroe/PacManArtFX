#include "Cube.h"

    GLfloat Cube::vertexPositions[108]
    {
            -0.25f,  0.25f, -0.25f,
            -0.25f, -0.25f, -0.25f,
             0.25f, -0.25f, -0.25f,

             0.25f, -0.25f, -0.25f,
             0.25f,  0.25f, -0.25f,
            -0.25f,  0.25f, -0.25f,

             0.25f, -0.25f, -0.25f,
             0.25f, -0.25f,  0.25f,
             0.25f,  0.25f, -0.25f,

             0.25f, -0.25f,  0.25f,
             0.25f,  0.25f,  0.25f,
             0.25f,  0.25f, -0.25f,

             0.25f, -0.25f,  0.25f,
            -0.25f, -0.25f,  0.25f,
             0.25f,  0.25f,  0.25f,

            -0.25f, -0.25f,  0.25f,
            -0.25f,  0.25f,  0.25f,
             0.25f,  0.25f,  0.25f,

            -0.25f, -0.25f,  0.25f,
            -0.25f, -0.25f, -0.25f,
            -0.25f,  0.25f,  0.25f,

            -0.25f, -0.25f, -0.25f,
            -0.25f,  0.25f, -0.25f,
            -0.25f,  0.25f,  0.25f,

            -0.25f, -0.25f,  0.25f,
             0.25f, -0.25f,  0.25f,
             0.25f, -0.25f, -0.25f,

             0.25f, -0.25f, -0.25f,
            -0.25f, -0.25f, -0.25f,
            -0.25f, -0.25f,  0.25f,

            -0.25f,  0.25f, -0.25f,
             0.25f,  0.25f, -0.25f,
             0.25f,  0.25f,  0.25f,

             0.25f,  0.25f,  0.25f,
            -0.25f,  0.25f,  0.25f,
            -0.25f,  0.25f, -0.25f
    };

Cube::Cube()
: x(0), y(0), z(-4), type(0)
{
}

Cube::Cube(int inX,int inY,int inZ) 
{
	x=inX;
	y=inY;
    z= inZ;
}

void Cube::setType(int t) 
{
	type=t;
}

void Cube::getxy(int *mx,int *my) 
{
	*mx=x;
	*my=y;
}

Cube::~Cube()
{
}

void Cube::Load(int windowWidth, int windowHeight, Shader &shader) {
    

        glGenVertexArrays(1, &vao);
        glBindVertexArray(vao);

        glGenBuffers(1, &buffer);
        glBindBuffer(GL_ARRAY_BUFFER, buffer);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertexPositions), &vertexPositions, GL_STATIC_DRAW);

        // Setup vertex attribute
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
        glEnableVertexAttribArray(0);

        // glEnable(GL_CULL_FACE);
        // glFrontFace(GL_CW);

        // glEnable(GL_DEPTH_TEST);
        // glDepthFunc(GL_LEQUAL);

        // shader.compileVertexShader();
        // shader.compileFragmentShader();
        // shader.createShaderProgram();

        // shader.use();
}

void Cube::Update(float dt) 
{
    std::srand((int) std::time(nullptr));
    timeSinceStart += dt;
    const float t = timeSinceStart * 0.3f;
    Matrix4 basePosition = Matrix4::createTranslation(Vector3(x , y, z));
    //Matrix4 move = Matrix4::createTranslation(Vector3( x + 0.0f,y + 0.0f,z + 0.0f));
    Matrix4 move = Matrix4::createTranslation(Vector3(Maths::sin(2.1f * t) * 0.5f, Maths::cos(1.7f * t) * 0.5f, Maths::sin(1.3f * t) * Maths::cos(1.5f * t) * 2.0f));
    Matrix4 yRotation = Matrix4::createRotationY(t * 45.0f / 10.0f);
    Matrix4 xRotation = Matrix4::createRotationX(t * 81.0f / 10.0f);

    //Matrix4 yRotation = Matrix4::createRotationY(0);
    //Matrix4 xRotation = Matrix4::createRotationX(0);
    
    Matrix4 translation = basePosition /** move*/;
    Matrix4 rotation = yRotation * xRotation;
    transform = translation * rotation;


    ///// to move & rotate cube
    //Matrix4 yRotation = Matrix4::createRotationY(t * 45.0f / 10.0f);
    //Matrix4 xRotation = Matrix4::createRotationX(t * 81.0f / 10.0f);
    //Matrix4 move = Matrix4::createTranslation(Vector3(Maths::sin(2.1f * t) * 0.5f, Maths::cos(1.7f * t) * 0.5f, Maths::sin(1.3f * t) * Maths::cos(1.5f * t) * 2.0f));

}

void Cube::Render(Shader &shader) 
{
    static const GLfloat bgColor[] = {0.0f, 0.0f, 0.2f, 1.0f};
    glClearBufferfv(GL_COLOR, 0, bgColor);
    
    shader.use();
    shader.setMatrix4("mv_matrix", transform);
    //shader.setMatrix4("proj_matrix", projection);
    
    glDrawArrays(GL_TRIANGLES, 0, 36);
}

void Cube::Clean() 
{
    glDeleteVertexArrays(1, &vao);
}

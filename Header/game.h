// ==========================================================
// STRUCT PLATFORM
// ==========================================================

struct Platform {
    float x, y, z;
    float width, depth;
    bool moving;
    float minY, maxY;
    float dir;
};

// ==========================================================
// STRUCT OBSTACLE
// ==========================================================

struct Obstacle {
    float x, y, z;
    float size;
    bool moveX;
    float minMove;
    float maxMove;
    float dir;
};

// ==========================================================
// STATUS
// ==========================================================

enum GameStatus {
    PLAYING,
    WIN,
    LOSE
};

// ==========================================================
// GLOBAL VARIABLE
// ==========================================================
float posX = 0.0f;
float posY = 1.25f;
float posZ = 0.0f;

float vY = 0.0f;

bool isJumping = false;

bool keyW = false;
bool keyA = false;
bool keyS = false;
bool keyD = false;

float walkAnim = 0.0f;

float characterRotation = 0.0f;

GameStatus gameStatus = PLAYING;

bool isMousePressed = false;  
int lastMouseX = 0;           
int lastMouseY = 0;         

float camAngleX = 0.0f;       
float camAngleY = 18.0f;    
float camRadius = 12.0f;      

// ==========================================================
// PLATFORM
// ==========================================================
Platform stage[] = {
    { 0.0f,  -1.0f,   0.0f, 2.5f, 2.0f, false, 0, 0, 0 },
    { 3.0f,   0.5f,   0.0f, 2.3f, 2.0f, false, 0, 0, 0 },
    { 6.0f,   2.2f,   0.0f, 2.2f, 2.0f, true,  1.5f, 3.0f, 0.025f },
    { 9.0f,   3.8f,   0.0f, 2.3f, 2.0f, true,  3.1f, 4.5f, 0.022f },

    { 9.0f,   5.0f,  -3.0f, 2.2f, 2.0f, false, 0, 0, 0 },
    { 9.0f,   6.5f,  -6.0f, 2.2f, 2.0f, false, 0, 0, 0 },

    { 9.0f,   5.0f,  -9.0f, 2.0f, 2.0f, false, 0, 0, 0 },

    { 9.0f,   7.0f, -12.0f, 2.2f, 2.0f, true,  6.2f, 7.8f, 0.02f },
    { 9.0f,   8.5f, -15.0f, 2.2f, 2.0f, false, 0, 0, 0 },
    { 9.0f,  10.0f, -18.0f, 2.5f, 2.2f, false, 0, 0, 0 }
};

int platformCount = sizeof(stage) / sizeof(stage[0]);

// ==========================================================
// OBSTACLE
// ==========================================================
Obstacle obstacles[] = {

    { 3.0f, 1.3f,  0.0f, 0.35f, true,  2.0f,  4.0f,  0.03f },

    { 9.0f, 5.8f, -3.0f, 0.40f, false, -4.0f, -2.0f, 0.04f },

    { 9.0f, 8.0f,-12.0f, 0.45f, true,  8.2f, 10.0f, 0.05f }
};

int obstacleCount = sizeof(obstacles) / sizeof(obstacles[0]);

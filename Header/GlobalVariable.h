// ==========================================================
// GLOBAL VARIABLE
// ==========================================================
#include "Status.h"
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
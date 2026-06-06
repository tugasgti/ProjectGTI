// ==========================================================
// RESET GAME
// ==========================================================
void resetGame() {
    srand((unsigned int)time(NULL));

    posX = 0.0f;
    posY = 1.25f;
    posZ = 0.0f;
    vY = 0.0f;

    isJumping = false;
    walkAnim = 0.0f;
    gameStatus = PLAYING;

    generatePlatforms();

    glutPostRedisplay();
}

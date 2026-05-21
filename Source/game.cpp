// ==========================================================
// RESET GAME
// ==========================================================
void resetGame() {
    posX = 0.0f;
    posY = 1.25f;
    posZ = 0.0f;
    vY = 0.0f;

    isJumping = false;
    walkAnim = 0.0f;
    gameStatus = PLAYING;

    stage[2].y = 2.2f;
    stage[3].y = 3.8f;
    stage[7].y = 7.0f;

    glutPostRedisplay();
}

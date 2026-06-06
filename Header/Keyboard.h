// ==========================================================
// KEYBOARD
// ==========================================================

void keyboardDown(unsigned char key,int x,int y) {

    if (key == 'a' || key == 'A')
        keyA = true;

    if (key == 'd' || key == 'D')
        keyD = true;

    if (key == 'w' || key == 'W')
        keyW = true;

    if (key == 's' || key == 'S')
        keyS = true;

    if (
        key == 32 &&
        gameStatus == PLAYING &&
        !isJumping
    ) {

        vY = 0.42f;

        isJumping = true;
    }

    if (key == 'r' || key == 'R') {

        resetGame();
    }
}

void keyboardUp(unsigned char key,int x,int y) {

    if (key == 'a' || key == 'A')
        keyA = false;

    if (key == 'd' || key == 'D')
        keyD = false;

    if (key == 'w' || key == 'W')
        keyW = false;

    if (key == 's' || key == 'S')
        keyS = false;
}

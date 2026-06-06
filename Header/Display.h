// ==========================================================
// DISPLAY
// ==========================================================
void display() {
    if (gameStatus == WIN)
        glClearColor(0.62f,0.72f,0.60f,1.0f);
    else if (gameStatus == LOSE)
        glClearColor(0.35f,0.0f,0.0f,1.0f);
    else
        glClearColor(0.45f,0.75f,1.0f,1.0f);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    GLfloat lightPos[] = {0.0f,20.0f,20.0f,1.0f};
    glLightfv(GL_LIGHT0,GL_POSITION,lightPos);
    float camX = posX + camRadius * sin(camAngleX * 3.14159f / 180.0f) * cos(camAngleY * 3.14159f / 180.0f);
    float camY = posY + 3.0f + camRadius * sin(camAngleY * 3.14159f / 180.0f);
    float camZ = posZ + camRadius * cos(camAngleX * 3.14159f / 180.0f) * cos(camAngleY * 3.14159f / 180.0f);

    gluLookAt(
        camX, camY, camZ,   
        posX, posY + 1.0f, posZ,  
        0.0f, 1.0f, 0.0f
    );

    drawBackground();

    for (int i = 0; i < platformCount; i++) {
        glPushMatrix();
        glTranslatef(
            stage[i].x,
            stage[i].y,
            stage[i].z
        );

        drawPlatform3D(
            stage[i].width,
            stage[i].depth
        );

        glPopMatrix();
    }

    // obstacle
    for (int i = 0; i < obstacleCount; i++) {
        glPushMatrix();
        glTranslatef(
            obstacles[i].x,
            obstacles[i].y,
            obstacles[i].z
        );

        drawObstacle(obstacles[i].size);

        glPopMatrix();
    }

    // crown
    Platform last = stage[platformCount - 1];
    glPushMatrix();
    glTranslatef(last.x,last.y + 1.0f,last.z);
    drawCrown();
    glPopMatrix();

    if (gameStatus == PLAYING) {
        drawHuman();
    }

    if (gameStatus == WIN) {
        drawScreenText(
            "YOU WIN",
            "Press 'R' to restart",
            1.0f,
            0.0f,
            0.0f
        );
    }

    if (gameStatus == LOSE) {
        drawScreenText(
            "YOU LOSE",
            "Press 'R' to restart",
            1.0f,
            1.0f,
            1.0f
        );
    }

    glutSwapBuffers();
}

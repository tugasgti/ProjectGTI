// ==========================================================
// TEXT
// ==========================================================
void drawText(float x, float y, const char* text, void* font) {
    glRasterPos2f(x, y);
    while (*text) {
        glutBitmapCharacter(font, *text);
        text++;
    }
}

// ==========================================================
// SCREEN TEXT
// ==========================================================
void drawScreenText(
    const char* title,
    const char* subtitle,
    float r,
    float g,
    float b
) {
    glDisable(GL_LIGHTING);
    glDisable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    gluOrtho2D(-1,1,-1,1);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    glColor3f(r,g,b);

    drawText(
        -0.2f,
        0.1f,
        title,
        GLUT_BITMAP_TIMES_ROMAN_24
    );

    glColor3f(1,1,1);

    drawText(
        -0.25f,
        -0.05f,
        subtitle,
        GLUT_BITMAP_HELVETICA_18
    );

    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
}

// ==========================================================
// BACKGROUND 
// ==========================================================
void drawBackground() {
    glDisable(GL_DEPTH_TEST);
    glDepthMask(GL_FALSE);
    glMatrixMode(GL_PROJECTION);
    glPushMatrix(); 
        glLoadIdentity();
        gluOrtho2D(-1.0, 1.0, -1.0, 1.0); 
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
            glLoadIdentity();
            glDisable(GL_LIGHTING);
            glBegin(GL_QUADS);
                glColor3f(0.55f, 0.85f, 1.0f);
                glVertex2f(-1.0f, -1.0f);
                glVertex2f( 1.0f, -1.0f);
                glColor3f(0.12f, 0.45f, 0.85f);
                glVertex2f( 1.0f,  1.0f);
                glVertex2f(-1.0f,  1.0f);
            glEnd();
            glEnable(GL_LIGHTING);
        glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix(); 
    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_DEPTH_TEST);
    glDepthMask(GL_TRUE);
}

// ==========================================================
// PLATFORM
// ==========================================================
void drawPlatform3D(float width, float depth) {
    glPushMatrix();
    glColor3f(0.55f,0.35f,0.18f);
    glPushMatrix();
    glScalef(width,0.5f,depth);
    glutSolidCube(1.0f);
    glPopMatrix();
    glColor3f(0.2f,0.85f,0.2f);
    glPushMatrix();
    glTranslatef(0.0f,0.28f,0.0f);
    glScalef(width + 0.1f,0.12f,depth + 0.1f);
    glutSolidCube(1.0f);
    glPopMatrix();
    glPopMatrix();
}

// ==========================================================
// CROWN
// ==========================================================
void drawCrown() {
    glDisable(GL_LIGHTING);
    glColor3f(1.0f,0.8f,0.0f);
    glPushMatrix();
    glScalef(0.8f,0.25f,0.8f);
    glutSolidCube(1.0f);
    glPopMatrix();

    for (int i = -1; i <= 1; i++) {
        glPushMatrix();
        glTranslatef(i * 0.28f,0.25f,0.0f);
        glRotatef(-90,1,0,0);
        glutSolidCone(0.18f,0.55f,16,16);
        glPopMatrix();
    }

    glEnable(GL_LIGHTING);
}

// ==========================================================
// DRAW OBSTACLE
// ==========================================================
void drawObstacle(float size) {
    glPushMatrix();
    glColor3f(0.75f, 0.15f, 0.12f);
    glutSolidSphere(size, 20, 20);
    glColor3f(1,1,1);

    for (int i = 0; i < 8; i++) {
        glPushMatrix();
        glRotatef(i * 45.0f, 0,1,0);
        glTranslatef(0,0,size);

        glutSolidCone(
            size * 0.25f,
            size * 0.55f,
            10,
            10
        );

        glPopMatrix();
    }

    glPopMatrix();
}

void drawCylinder(double baseRadius, double topRadius, double height, int slices, int stacks) {
    GLUquadricObj* quadric = gluNewQuadric();
    gluQuadricDrawStyle(quadric, GLU_FILL);
    gluCylinder(quadric, baseRadius, topRadius, height, slices, stacks);
    gluDeleteQuadric(quadric);
}

void drawSphere(double radius, int slices, int stacks) {
    GLUquadricObj* quadric = gluNewQuadric();
    gluQuadricDrawStyle(quadric, GLU_FILL);
    gluSphere(quadric, radius, slices, stacks);
    gluDeleteQuadric(quadric);
}

// ==========================================================
// HUMAN
// ==========================================================
void drawHuman() {
    int slices = 16;
    int stacks = 16;

    float armMove;
    float legMove;

    if (isJumping) {
        armMove = 45.0f;
        legMove = -35.0f;
    }
    else {
        armMove = sin(walkAnim) * 35.0f;
        legMove = sin(walkAnim) * 40.0f;
    }

    glPushMatrix();
        glTranslatef(posX, posY, posZ);
        glRotatef(characterRotation, 0.0f, 1.0f, 0.0f);
        glTranslatef(0.0f, -0.65f, 0.0f);

        // ==========================================
        // 1. BADAN / BAJU GAUN
        // ==========================================
        glColor3f(0.53f, 0.57f, 0.41f); 
        glPushMatrix();
            glRotatef(-90.0f, 1.0f, 0.0f, 0.0f); 
            glTranslatef(0.0f, 0.0f, 0.4f);    
            drawCylinder(0.35, 0.18, 0.7, slices, stacks);
        glPopMatrix();

        // ==========================================
        // KERAH BAJU T
        // ==========================================
        glColor3f(0.53f, 0.57f, 0.41f); 
        glPushMatrix();
            glTranslatef(0.0f, 1.12f, 0.0f);
            glScalef(1.2f, 0.5f, 1.2f);     
            drawSphere(0.16, slices, stacks);
        glPopMatrix();

        glColor3f(0.92f, 0.78f, 0.68f); 
        glPushMatrix();
            glTranslatef(0.0f, 1.10f, 0.0f);
            glRotatef(-90.0f, 1.0f, 0.0f, 0.0f); 
            drawCylinder(0.07, 0.07, 0.15, slices, stacks); 
        glPopMatrix();

        // ==========================================
        // 2. KEPALA, WAJAH & RAMBUT 
        // ==========================================
        glPushMatrix();
            glTranslatef(0.0f, 1.42f, 0.0f); 

            // KEPALA DASAR (Warna Kulit)
            glColor3f(0.92f, 0.78f, 0.68f); 
            glPushMatrix();
                glScalef(0.9f, 1.1f, 0.9f); 
                drawSphere(0.18, slices, stacks);
            glPopMatrix();

            // MATA KIRI (Menghadap -Z depan karakter)
            glColor3f(0.1f, 0.1f, 0.1f);
            glPushMatrix();
                glTranslatef(-0.06f, 0.04f, -0.17f); 
                glScalef(1.0f, 1.0f, 0.2f); 
                drawSphere(0.035, 8, 8);    
            glPopMatrix();

            // MATA KANAN
            glPushMatrix();
                glTranslatef(0.06f, 0.04f, -0.17f);  
                glScalef(1.0f, 1.0f, 0.2f);
                drawSphere(0.035, 8, 8);
            glPopMatrix();

            // HIDUNG 
            glColor3f(0.88f, 0.72f, 0.62f); 
            glPushMatrix();
                glTranslatef(0.0f, -0.01f, -0.18f); 
                glScalef(0.025f, 0.05f, 0.04f); 
                glutSolidCube(1.0f);
            glPopMatrix();

            // MULUT 
            glColor3f(0.65f, 0.35f, 0.35f);
            glPushMatrix();
                glTranslatef(0.0f, -0.07f, -0.175f); 
                glScalef(0.07f, 0.015f, 0.02f); 
                glutSolidCube(1.0f);
            glPopMatrix();

            // TELINGA KIRI
            glColor3f(0.92f, 0.78f, 0.68f);
            glPushMatrix();
                glTranslatef(-0.17f, 0.0f, 0.01f); 
                glScalef(0.4f, 0.7f, 0.5f);
                drawSphere(0.04, 8, 8);
            glPopMatrix();

            // TELINGA KANAN
            glPushMatrix();
                glTranslatef(0.17f, 0.0f, 0.01f);  
                glScalef(0.4f, 0.7f, 0.5f);
                drawSphere(0.04, 8, 8);
            glPopMatrix();

            // RAMBUT (Belakang & Atas di area +Z)
            glColor3f(0.75f, 0.34f, 0.27f); 
            glPushMatrix();
                glTranslatef(0.0f, 0.05f, 0.03f); 
                drawSphere(0.19, slices, stacks);
            glPopMatrix();
            
            // PONI DEPAN / RAMBUT SAMPING KIRI
            glPushMatrix();
                glTranslatef(-0.09f, -0.08f, -0.08f); 
                drawSphere(0.07, slices, stacks);
            glPopMatrix();

            // PONI DEPAN / RAMBUT SAMPING KANAN
            glPushMatrix();
                glTranslatef(0.09f, -0.08f, -0.08f);  
                drawSphere(0.07, slices, stacks);
            glPopMatrix();
        glPopMatrix(); // Selesai blok kepala

        // ==========================================
        // 3. TANGAN KIRI
        // ==========================================
        glPushMatrix();
            glTranslatef(0.18f, 1.02f, 0.0f); 
            glRotatef(armMove, 1.0f, 0.0f, 0.0f); 
            glRotatef(-35.0f, 0.0f, 0.0f, 1.0f); 
            glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
            glColor3f(0.53f, 0.57f, 0.41f);
            drawCylinder(0.08, 0.06, 0.4, slices, stacks);
            glTranslatef(0.0f, 0.0f, 0.4f);
            drawCylinder(0.09, 0.09, 0.05, slices, stacks);
            glColor3f(0.2f, 0.2f, 0.25f);
            glTranslatef(0.0f, 0.0f, 0.05f);
            glPushMatrix();
                glScalef(0.6f, 0.3f, 1.0f);
                drawSphere(0.07, slices, stacks);
            glPopMatrix();
        glPopMatrix();

        // ==========================================
        // 4. TANGAN KANAN
        // ==========================================
        glPushMatrix();
            glTranslatef(-0.18f, 1.02f, 0.0f); 
            glRotatef(-armMove, 1.0f, 0.0f, 0.0f); 
            glRotatef(35.0f, 0.0f, 0.0f, 1.0f); 
            glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);
            glColor3f(0.53f, 0.57f, 0.41f);
            drawCylinder(0.08, 0.06, 0.4, slices, stacks);
            glTranslatef(0.0f, 0.0f, 0.4f);
            drawCylinder(0.09, 0.09, 0.05, slices, stacks);
            glColor3f(0.2f, 0.2f, 0.25f);
            glTranslatef(0.0f, 0.0f, 0.05f);
            glPushMatrix();
                glScalef(0.6f, 0.3f, 1.0f);
                drawSphere(0.07, slices, stacks);
            glPopMatrix();
        glPopMatrix();

        // ==========================================
        // 5. KAKI KIRI & SEPATU BOOT
        // ==========================================
        glPushMatrix();
            glTranslatef(0.12f, 0.4f, 0.0f); 
            glRotatef(legMove, 1.0f, 0.0f, 0.0f); 
            glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
            glColor3f(0.15f, 0.18f, 0.22f);
            drawCylinder(0.07, 0.06, 0.25, slices, stacks);
            glTranslatef(0.0f, 0.0f, 0.25f);
            glColor3f(0.9f, 0.9f, 0.9f);
            drawCylinder(0.09, 0.09, 0.06, slices, stacks);
            glTranslatef(0.0f, 0.0f, 0.06f);
            glColor3f(0.72f, 0.53f, 0.34f);
            drawCylinder(0.08, 0.07, 0.25, slices, stacks);
            glTranslatef(0.0f, -0.05f, 0.25f); 
            glPushMatrix();
                glScalef(1.0f, 1.8f, 0.8f);        
                drawSphere(0.07, slices, stacks);
            glPopMatrix();
        glPopMatrix();

        // ==========================================
        // 6. KAKI KANAN & SEPATU BOOT
        // ==========================================
        glPushMatrix();
            glTranslatef(-0.12f, 0.4f, 0.0f); 
            glRotatef(-legMove, 1.0f, 0.0f, 0.0f); 
            glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
            glColor3f(0.15f, 0.18f, 0.22f);
            drawCylinder(0.07, 0.06, 0.25, slices, stacks);
            glTranslatef(0.0f, 0.0f, 0.25f);
            glColor3f(0.9f, 0.9f, 0.9f);
            drawCylinder(0.09, 0.09, 0.06, slices, stacks);
            glTranslatef(0.0f, 0.0f, 0.06f);
            glColor3f(0.72f, 0.53f, 0.34f);
            drawCylinder(0.08, 0.07, 0.25, slices, stacks);
            glTranslatef(0.0f, -0.05f, 0.25f);
            glPushMatrix();
                glScalef(1.0f, 1.8f, 0.8f);
                drawSphere(0.07, slices, stacks);
            glPopMatrix();
        glPopMatrix();
    glPopMatrix();
}

// ==========================================================
// INIT
// ==========================================================
void init() {
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glShadeModel(GL_SMOOTH);
    GLfloat lightPos[] = {0.0f,20.0f,20.0f,1.0f};
    GLfloat ambient[] = {0.7f,0.7f,0.7f,1.0f};
    GLfloat diffuse[] = {1.0f,1.0f,1.0f,1.0f};
    glLightfv(GL_LIGHT0,GL_POSITION,lightPos);
    glLightfv(GL_LIGHT0,GL_AMBIENT,ambient);
    glLightfv(GL_LIGHT0,GL_DIFFUSE,diffuse);
    glClearColor(0.45f,0.75f,1.0f,1.0f);
}

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

// ==========================================================
// UPDATE
// ==========================================================
void update(int value) {
    if (gameStatus == PLAYING) {

        float speed = 0.08f;

        bool isMoving = false;

        if (keyA) {

            posX -= speed;

            characterRotation = 90.0f;

            isMoving = true;
        }

        if (keyD) {

            posX += speed;

            characterRotation = -90.0f;

            isMoving = true;
        }

        if (keyW) {

            posZ -= speed;

            characterRotation = 0.0f;

            isMoving = true;
        }

        if (keyS) {

            posZ += speed;

            characterRotation = 180.0f;

            isMoving = true;
        }

        if (isMoving)
            walkAnim += 0.2f;
        

        // platform gerak

        for (int i = 0; i < platformCount; i++) {

            if (stage[i].moving) {

                stage[i].y += stage[i].dir;

                if (
                    stage[i].y >= stage[i].maxY ||
                    stage[i].y <= stage[i].minY
                ) {

                    stage[i].dir *= -1.0f;
                }
            }
        }

        // obstacle gerak

        for (int i = 0; i < obstacleCount; i++) {

            if (obstacles[i].moveX) {

                obstacles[i].x += obstacles[i].dir;

                if (
                    obstacles[i].x >= obstacles[i].maxMove ||
                    obstacles[i].x <= obstacles[i].minMove
                ) {

                    obstacles[i].dir *= -1;
                }
            }
            else {

                obstacles[i].z += obstacles[i].dir;

                if (
                    obstacles[i].z >= obstacles[i].maxMove ||
                    obstacles[i].z <= obstacles[i].minMove
                ) {

                    obstacles[i].dir *= -1;
                }
            }
        }

        // gravitasi

        posY += vY;

        vY -= 0.018f;

        // collision platform

        for (int i = 0; i < platformCount; i++) {

            float top = stage[i].y + 0.25f;

            float feet = posY - 1.0f;

            if (vY <= 0) {

                if (
                    feet >= top - 0.18f &&
                    feet <= top + 0.18f
                ) {

                    if (
                        posX >= stage[i].x - stage[i].width / 2.0f &&
                        posX <= stage[i].x + stage[i].width / 2.0f &&

                        posZ >= stage[i].z - stage[i].depth / 2.0f &&
                        posZ <= stage[i].z + stage[i].depth / 2.0f
                    ) {

                        posY = top + 1.0f;

                        vY = 0.0f;

                        isJumping = false;
                    }
                }
            }
        }

        // collision obstacle

        for (int i = 0; i < obstacleCount; i++) {

            float dx = posX - obstacles[i].x;
            float dy = (posY - 0.4f) - obstacles[i].y;
            float dz = posZ - obstacles[i].z;

            float dist = sqrt(dx*dx + dy*dy + dz*dz);

            if (dist < obstacles[i].size + 0.28f) {

                gameStatus = LOSE;
            }
        }

        // win

        Platform last = stage[platformCount - 1];

        if (
            posX >= last.x - last.width / 2.0f &&
            posX <= last.x + last.width / 2.0f &&

            posZ >= last.z - last.depth / 2.0f &&
            posZ <= last.z + last.depth / 2.0f &&

            posY >= last.y + 0.5f
        ) {

            gameStatus = WIN;
        }

        // lose

        if (posY < -8.0f) {

            gameStatus = LOSE;
        }
    }

    glutPostRedisplay();

    glutTimerFunc(16,update,0);
}

// ==========================================================
// RESHAPE
// ==========================================================

void reshape(int w,int h) {

    if (h == 0)
        h = 1;

    glViewport(0,0,w,h);

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    gluPerspective(
        45.0,
        (float)w / h,
        1.0,
        150.0
    );

    glMatrixMode(GL_MODELVIEW);
}

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

// ==========================================================
// MOUSE CONTROLS
// ==========================================================
void mouseClick(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON) {
        if (state == GLUT_DOWN) {
            isMousePressed = true;
            lastMouseX = x;
            lastMouseY = y;
        } else if (state == GLUT_UP) {
            isMousePressed = false;
        }
    }
}

void mouseMotion(int x, int y) {
    if (isMousePressed) {
        int deltaX = x - lastMouseX;
        int deltaY = y - lastMouseY;

        camAngleX += deltaX * 0.3f; 
        camAngleY += deltaY * 0.3f;

        if (camAngleY > 80.0f)  camAngleY = 80.0f;
        if (camAngleY < -10.0f) camAngleY = -10.0f;

        lastMouseX = x;
        lastMouseY = y;

        glutPostRedisplay();
    }
}

// ==========================================================
// MAIN
// ==========================================================

int main(int argc,char** argv) {

    glutInit(&argc,argv);

    glutInitDisplayMode(
        GLUT_DOUBLE |
        GLUT_RGB |
        GLUT_DEPTH
    );

    glutInitWindowSize(1024,768);

    glutCreateWindow("Game Jumping OpenGL 3D");

    resetGame();

    init();

    glutDisplayFunc(display);

    glutReshapeFunc(reshape);

    glutKeyboardFunc(keyboardDown);

    glutKeyboardUpFunc(keyboardUp);
    
    glutMouseFunc(mouseClick);
    glutMotionFunc(mouseMotion);

    glutTimerFunc(0,update,0);

    glutMainLoop();

    return 0;
}
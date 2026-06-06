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

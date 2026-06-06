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

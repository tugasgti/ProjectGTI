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

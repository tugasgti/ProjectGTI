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
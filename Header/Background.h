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

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
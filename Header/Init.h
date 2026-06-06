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

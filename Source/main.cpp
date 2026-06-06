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

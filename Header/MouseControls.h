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

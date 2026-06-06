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

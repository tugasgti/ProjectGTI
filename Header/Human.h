// ==========================================================
// HUMAN
// ==========================================================
void drawHuman() {
    int slices = 16;
    int stacks = 16;

    float armMove;
    float legMove;

    if (isJumping) {
        armMove = 45.0f;
        legMove = -35.0f;
    }
    else {
        armMove = sin(walkAnim) * 35.0f;
        legMove = sin(walkAnim) * 40.0f;
    }

    glPushMatrix();
        glTranslatef(posX, posY, posZ);
        glRotatef(characterRotation, 0.0f, 1.0f, 0.0f);
        glTranslatef(0.0f, -0.65f, 0.0f);

        // ==========================================
        // 1. BADAN / BAJU GAUN
        // ==========================================
        glColor3f(0.53f, 0.57f, 0.41f); 
        glPushMatrix();
            glRotatef(-90.0f, 1.0f, 0.0f, 0.0f); 
            glTranslatef(0.0f, 0.0f, 0.4f);    
            drawCylinder(0.35, 0.18, 0.7, slices, stacks);
        glPopMatrix();

        // ==========================================
        // KERAH BAJU T
        // ==========================================
        glColor3f(0.53f, 0.57f, 0.41f); 
        glPushMatrix();
            glTranslatef(0.0f, 1.12f, 0.0f);
            glScalef(1.2f, 0.5f, 1.2f);     
            drawSphere(0.16, slices, stacks);
        glPopMatrix();

        glColor3f(0.92f, 0.78f, 0.68f); 
        glPushMatrix();
            glTranslatef(0.0f, 1.10f, 0.0f);
            glRotatef(-90.0f, 1.0f, 0.0f, 0.0f); 
            drawCylinder(0.07, 0.07, 0.15, slices, stacks); 
        glPopMatrix();

        // ==========================================
        // 2. KEPALA, WAJAH & RAMBUT 
        // ==========================================
        glPushMatrix();
            glTranslatef(0.0f, 1.42f, 0.0f); 

            // KEPALA DASAR (Warna Kulit)
            glColor3f(0.92f, 0.78f, 0.68f); 
            glPushMatrix();
                glScalef(0.9f, 1.1f, 0.9f); 
                drawSphere(0.18, slices, stacks);
            glPopMatrix();

            // MATA KIRI (Menghadap -Z depan karakter)
            glColor3f(0.1f, 0.1f, 0.1f);
            glPushMatrix();
                glTranslatef(-0.06f, 0.04f, -0.17f); 
                glScalef(1.0f, 1.0f, 0.2f); 
                drawSphere(0.035, 8, 8);    
            glPopMatrix();

            // MATA KANAN
            glPushMatrix();
                glTranslatef(0.06f, 0.04f, -0.17f);  
                glScalef(1.0f, 1.0f, 0.2f);
                drawSphere(0.035, 8, 8);
            glPopMatrix();

            // HIDUNG 
            glColor3f(0.88f, 0.72f, 0.62f); 
            glPushMatrix();
                glTranslatef(0.0f, -0.01f, -0.18f); 
                glScalef(0.025f, 0.05f, 0.04f); 
                glutSolidCube(1.0f);
            glPopMatrix();

            // MULUT 
            glColor3f(0.65f, 0.35f, 0.35f);
            glPushMatrix();
                glTranslatef(0.0f, -0.07f, -0.175f); 
                glScalef(0.07f, 0.015f, 0.02f); 
                glutSolidCube(1.0f);
            glPopMatrix();

            // TELINGA KIRI
            glColor3f(0.92f, 0.78f, 0.68f);
            glPushMatrix();
                glTranslatef(-0.17f, 0.0f, 0.01f); 
                glScalef(0.4f, 0.7f, 0.5f);
                drawSphere(0.04, 8, 8);
            glPopMatrix();

            // TELINGA KANAN
            glPushMatrix();
                glTranslatef(0.17f, 0.0f, 0.01f);  
                glScalef(0.4f, 0.7f, 0.5f);
                drawSphere(0.04, 8, 8);
            glPopMatrix();

            // RAMBUT (Belakang & Atas di area +Z)
            glColor3f(0.75f, 0.34f, 0.27f); 
            glPushMatrix();
                glTranslatef(0.0f, 0.05f, 0.03f); 
                drawSphere(0.19, slices, stacks);
            glPopMatrix();
            
            // PONI DEPAN / RAMBUT SAMPING KIRI
            glPushMatrix();
                glTranslatef(-0.09f, -0.08f, -0.08f); 
                drawSphere(0.07, slices, stacks);
            glPopMatrix();

            // PONI DEPAN / RAMBUT SAMPING KANAN
            glPushMatrix();
                glTranslatef(0.09f, -0.08f, -0.08f);  
                drawSphere(0.07, slices, stacks);
            glPopMatrix();
        glPopMatrix(); // Selesai blok kepala

        // ==========================================
        // 3. TANGAN KIRI
        // ==========================================
        glPushMatrix();
            glTranslatef(0.18f, 1.02f, 0.0f); 
            glRotatef(armMove, 1.0f, 0.0f, 0.0f); 
            glRotatef(-35.0f, 0.0f, 0.0f, 1.0f); 
            glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
            glColor3f(0.53f, 0.57f, 0.41f);
            drawCylinder(0.08, 0.06, 0.4, slices, stacks);
            glTranslatef(0.0f, 0.0f, 0.4f);
            drawCylinder(0.09, 0.09, 0.05, slices, stacks);
            glColor3f(0.2f, 0.2f, 0.25f);
            glTranslatef(0.0f, 0.0f, 0.05f);
            glPushMatrix();
                glScalef(0.6f, 0.3f, 1.0f);
                drawSphere(0.07, slices, stacks);
            glPopMatrix();
        glPopMatrix();

        // ==========================================
        // 4. TANGAN KANAN
        // ==========================================
        glPushMatrix();
            glTranslatef(-0.18f, 1.02f, 0.0f); 
            glRotatef(-armMove, 1.0f, 0.0f, 0.0f); 
            glRotatef(35.0f, 0.0f, 0.0f, 1.0f); 
            glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);
            glColor3f(0.53f, 0.57f, 0.41f);
            drawCylinder(0.08, 0.06, 0.4, slices, stacks);
            glTranslatef(0.0f, 0.0f, 0.4f);
            drawCylinder(0.09, 0.09, 0.05, slices, stacks);
            glColor3f(0.2f, 0.2f, 0.25f);
            glTranslatef(0.0f, 0.0f, 0.05f);
            glPushMatrix();
                glScalef(0.6f, 0.3f, 1.0f);
                drawSphere(0.07, slices, stacks);
            glPopMatrix();
        glPopMatrix();

        // ==========================================
        // 5. KAKI KIRI & SEPATU BOOT
        // ==========================================
        glPushMatrix();
            glTranslatef(0.12f, 0.4f, 0.0f); 
            glRotatef(legMove, 1.0f, 0.0f, 0.0f); 
            glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
            glColor3f(0.15f, 0.18f, 0.22f);
            drawCylinder(0.07, 0.06, 0.25, slices, stacks);
            glTranslatef(0.0f, 0.0f, 0.25f);
            glColor3f(0.9f, 0.9f, 0.9f);
            drawCylinder(0.09, 0.09, 0.06, slices, stacks);
            glTranslatef(0.0f, 0.0f, 0.06f);
            glColor3f(0.72f, 0.53f, 0.34f);
            drawCylinder(0.08, 0.07, 0.25, slices, stacks);
            glTranslatef(0.0f, -0.05f, 0.25f); 
            glPushMatrix();
                glScalef(1.0f, 1.8f, 0.8f);        
                drawSphere(0.07, slices, stacks);
            glPopMatrix();
        glPopMatrix();

        // ==========================================
        // 6. KAKI KANAN & SEPATU BOOT
        // ==========================================
        glPushMatrix();
            glTranslatef(-0.12f, 0.4f, 0.0f); 
            glRotatef(-legMove, 1.0f, 0.0f, 0.0f); 
            glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
            glColor3f(0.15f, 0.18f, 0.22f);
            drawCylinder(0.07, 0.06, 0.25, slices, stacks);
            glTranslatef(0.0f, 0.0f, 0.25f);
            glColor3f(0.9f, 0.9f, 0.9f);
            drawCylinder(0.09, 0.09, 0.06, slices, stacks);
            glTranslatef(0.0f, 0.0f, 0.06f);
            glColor3f(0.72f, 0.53f, 0.34f);
            drawCylinder(0.08, 0.07, 0.25, slices, stacks);
            glTranslatef(0.0f, -0.05f, 0.25f);
            glPushMatrix();
                glScalef(1.0f, 1.8f, 0.8f);
                drawSphere(0.07, slices, stacks);
            glPopMatrix();
        glPopMatrix();
    glPopMatrix();
}

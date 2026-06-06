/ ==========================================================
// GENERATE RANDOM PLATFORMS
// ==========================================================
void generatePlatforms() {
    platformCount = 0;

    // Platform pertama selalu tetap sebagai starting point
    stage[0].x     = 0.0f;
    stage[0].y     = -1.0f;
    stage[0].z     = 0.0f;
    stage[0].width = 2.5f;
    stage[0].depth = 2.0f;
    stage[0].moving = false;
    stage[0].minY  = 0;
    stage[0].maxY  = 0;
    stage[0].dir   = 0;
    platformCount = 1;

    // Generate platform acak sebanyak 8 platform (index 1..8)
    int numRandom = 8;

    // Arah pergantian: campuran sumbu X dan Z
    // Setiap platform melangkah dari platform sebelumnya
    float curX = 0.0f;
    float curY = -1.0f;
    float curZ = 0.0f;

    // Pola arah: bergantian maju (+X) dan belok (-Z)
    // Agar tetap bisa dijangkau, jarak lompat dibatasi
    // maxJumpHeight ~ 0.42^2 / (2*0.018) ~ 4.9 unit, aman pakai max deltaY 1.8
    // maxJumpDist horizontal ~ 3.5 unit aman

    // Arah acak: 0=+X, 1=-X, 2=-Z, 3=+Z
    // Paksa agar setiap beberapa step ada kemajuan agar bisa menang
    // Kita buat rute maju ke -Z (seperti aslinya) dengan sedikit variasi X

    for (int i = 1; i <= numRandom; i++) {
        Platform p;

        // Delta posisi dari platform sebelumnya
        // Agar pasti bisa dijangkau:
        //   horizontal max ~3.2, deltaY max 1.8
        float deltaX = randFloat(-1.5f, 1.5f);
        float deltaY = randFloat(0.8f,  1.8f);
        float deltaZ = randFloat(-3.5f, -2.5f); // selalu maju ke -Z

        curX += deltaX;
        curY += deltaY;
        curZ += deltaZ;

        p.x = curX;
        p.y = curY;
        p.z = curZ;

        // Ukuran platform acak
        p.width = randFloat(1.8f, 2.6f);
        p.depth = randFloat(1.8f, 2.2f);

        // ~40% platform bergerak naik-turun
        if (randFloat(0.0f, 1.0f) < 0.4f) {
            p.moving = true;
            float amp   = randFloat(0.6f, 1.2f);
            p.minY  = p.y - amp;
            p.maxY  = p.y + amp;
            p.dir   = randFloat(0.015f, 0.030f);
        } else {
            p.moving = false;
            p.minY   = 0;
            p.maxY   = 0;
            p.dir    = 0;
        }

        stage[platformCount++] = p;
    }

    // Platform terakhir (finish) selalu sedikit lebih besar & tidak bergerak
    {
        Platform p;
        p.x     = curX + randFloat(-1.0f, 1.0f);
        p.y     = curY + randFloat(1.0f, 1.8f);
        p.z     = curZ + randFloat(-3.5f, -2.5f);
        p.width = 2.5f;
        p.depth = 2.2f;
        p.moving = false;
        p.minY  = 0;
        p.maxY  = 0;
        p.dir   = 0;
        stage[platformCount++] = p;
    }

    // ----------------------------------------------------------
    // Generate obstacle di atas platform acak (skip platform 0
    // dan platform terakhir agar tidak menghalangi start/finish)
    // Pilih 3 platform berbeda sebagai host obstacle
    // ----------------------------------------------------------
    obstacleCount = 0;

    // Kumpulkan index platform yang boleh dapat obstacle (index 1..platformCount-2)
    int candidateCount = platformCount - 2; // bisa 0..numRandom-1 (index 1..8)
    int numObstacles = (candidateCount >= 3) ? 3 : candidateCount;

    // Fisher-Yates shuffle sederhana untuk memilih index tanpa duplikat
    int indices[MAX_PLATFORMS];
    for (int i = 0; i < candidateCount; i++)
        indices[i] = i + 1; // platform index 1 s/d platformCount-2

    for (int i = candidateCount - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int tmp = indices[i]; indices[i] = indices[j]; indices[j] = tmp;
    }

    for (int k = 0; k < numObstacles; k++) {
        int pi = indices[k]; // index platform host
        Platform& p = stage[pi];

        Obstacle o;
        // Posisikan obstacle tepat di atas permukaan platform
        // top platform = p.y + 0.25 (tinggi setengah kubus 0.5)
        // lalu tambah radius obstacle agar tidak terbenam
        float obsSize = randFloat(0.30f, 0.50f);
        o.x    = p.x;
        o.y    = p.y + 0.25f + obsSize + 0.05f;
        o.z    = p.z;
        o.size = obsSize;

        // Obstacle bergerak horizontal (X atau Z) di atas platform
        bool movX = (rand() % 2 == 0);
        o.moveX   = movX;
        float amp = (movX ? p.width : p.depth) * 0.35f; // gerak dalam batas platform
        o.minMove = (movX ? p.x : p.z) - amp;
        o.maxMove = (movX ? p.x : p.z) + amp;
        o.dir     = randFloat(0.025f, 0.055f);

        obstacles[obstacleCount++] = o;
    }
}

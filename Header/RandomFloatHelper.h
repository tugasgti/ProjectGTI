// ==========================================================
// RANDOM FLOAT HELPER
// ==========================================================
float randFloat(float minVal, float maxVal) {
    return minVal + ((float)rand() / (float)RAND_MAX) * (maxVal - minVal);
}
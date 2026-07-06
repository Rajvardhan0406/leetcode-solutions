char* predictPartyVictory(char* senate) {
    int n = strlen(senate);

    int* rQueue = (int*)malloc(n * sizeof(int));
    int* dQueue = (int*)malloc(n * sizeof(int));
    int rFront = 0, rBack = 0, dFront = 0, dBack = 0;

    for (int i = 0; i < n; i++) {
        if (senate[i] == 'R') {
            rQueue[rBack++] = i;
        } else {
            dQueue[dBack++] = i;
        }
    }

    
    while (rFront < rBack && dFront < dBack) {
        int rIdx = rQueue[rFront++];
        int dIdx = dQueue[dFront++];

        if (rIdx < dIdx) {
            rQueue[rBack++] = rIdx + n; 
        } else {
            dQueue[dBack++] = dIdx + n; 
        }
    }

    char* result;
    if (rFront < rBack) {
        result = "Radiant";
    } else {
        result = "Dire";
    }

    free(rQueue);
    free(dQueue);

    return result;
}
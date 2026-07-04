int compress(char* chars, int charsSize) {
    int write = 0;  
    int read  = 0;  
    while (read < charsSize) {
        char current = chars[read];
        int count = 0;
        while (read < charsSize && chars[read] == current) {
            read++;
            count++;
        }
        chars[write++] = current;
        if (count > 1) {
            char buf[12];
            int len = sprintf(buf, "%d", count);
            for (int i = 0; i < len; i++) {
                chars[write++] = buf[i];
            }
        }
    }
    return write;
}
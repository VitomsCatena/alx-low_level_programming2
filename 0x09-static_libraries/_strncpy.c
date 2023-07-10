char *_strncpy(char *dest, const char *src, int n) {
    char *temp = dest;
    while (n && *src) {
        *dest = *src;
        dest++;
        src++;
        n--;
    }
    while (n) {
        *dest = '\0';
        dest++;
        n--;
    }
    return temp;
}


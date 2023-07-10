char *_strncat(char *dest, const char *src, int n) {
    char *temp = dest;
    while (*dest) {
        dest++;
    }
    while (n && *src) {
        *dest = *src;
        dest++;
        src++;
        n--;
    }
    *dest = '\0';
    return temp;
}


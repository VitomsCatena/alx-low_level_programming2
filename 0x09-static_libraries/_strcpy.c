char *_strcpy(char *dest, const char *src) {
    char *temp = dest;
    while ((*dest++ = *src++))
        ;
    return temp;
}


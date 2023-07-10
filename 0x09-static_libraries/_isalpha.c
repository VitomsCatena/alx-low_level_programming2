int _isalpha(int c) {
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
        return 1;  // alphabetic character
    } else {
        return 0;  // not an alphabetic character
    }
}


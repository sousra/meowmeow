#include "decode.h"

void meowDecode(FILE* src, FILE* dest) {
    char c, decodedChar = 0;
    int pos = 0;
    while ((c = fgetc(src)) != EOF) {
        if (isupper(c)) {
            decodedChar |= 1 << (7 - pos);
        }
        ++pos;
        if (pos == 8) {
            fprintf(dest, "%c", decodedChar);
            decodedChar = 0;
            pos = 0;
        }
    }
}

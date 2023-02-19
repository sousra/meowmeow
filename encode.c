#include "encode.h"

void meowEncode(FILE* src, FILE* dest) {
    char c;
    char meowStr[9] = "meowmeow";
    while ((c = fgetc(src)) != EOF) {
        for (int i = 7; i != -1; --i) {
            if (c & (1 << i)) {
                fprintf(dest, "%c", toupper(meowStr[7 - i]));
            } else {
                fprintf(dest, "%c", meowStr[7 - i]);
            }
        }
    }
}

#include <stdio.h>
#include <string.h>
#include "encode.h"
#include "decode.h"

int main(int argc, char** argv) {
    if (argc != 3) {
        printf("Usage: %s SRC_FILE DEST_FILE\n", argv[0]);
        return 0;
    }
    if (strcmp(argv[1], argv[2]) == 0) {
        printf("Source and destinition files cannot be the same one\n");
        return 0;
    }
    FILE* srcFile = fopen(argv[1], "r");
    FILE* destFile = fopen(argv[2], "w");
    if (!srcFile) {
        perror("fopen");
        return -1;
    }

    char* p = argv[0];
    for (size_t i = 0; argv[0][i]; ++i) {
        if (argv[0][i] == '/' || argv[0][i] == '\\') {
            p = &argv[0][i + 1];
        }
    }
    if (strcmp(p, "encode") == 0) {
        meowEncode(srcFile, destFile);
    }
    else if (strcmp(p, "decode") == 0) {
        meowDecode(srcFile, destFile);
    }
    fclose(srcFile);
    fclose(destFile);
    return 0;
}

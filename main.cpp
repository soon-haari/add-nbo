#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <arpa/inet.h>

uint32_t f_ntohl(char *fname) {
    uint32_t buf;
    FILE* fp = fopen(fname, "rb");
    if (fp == NULL) {
        printf("Invalid file name \"%s\".\n", fname);
        exit(1);
    }
    size_t size = fread(&buf, 1, 4, fp);
    fclose(fp);
    
    if (size != 4) {
        printf("File must be 4 bytes long.\n");
        exit(1);
    }

    return ntohl(buf);
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Invalid number of argument.\n");
        exit(1);
    }
    
    uint32_t tmp;
    uint32_t res = 0;
    
    tmp = f_ntohl(argv[1]);
    printf("%d(0x%x)", tmp, tmp);
    res += tmp;
    
    printf(" + ");
    
    tmp = f_ntohl(argv[2]);
    printf("%d(0x%x)", tmp, tmp);
    res += tmp;
    
    printf(" = %d(0x%x)\n", res, res);

    return 0;
}

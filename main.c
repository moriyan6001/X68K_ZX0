#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <iocslib.h>

void ZX0Decompress(unsigned char* src, unsigned char* dst);

// ファイルサイズ取得
long GetFileSize(const char *file)
{
    struct stat statBuf;
    if (stat(file, &statBuf) == 0) return statBuf.st_size;
    return -1L;
}

void main(int argc, char*argv[])
{
    int ssp;
    long fileSize;
    FILE* fp;
    unsigned char* fileData;

    fileSize = GetFileSize(argv[1]);
    fileData = malloc(sizeof(unsigned char) * fileSize);
    fp = fopen(argv[1], "rb");
    fread(fileData, fileSize, 1, fp);
    fclose(fp);    

    CRTMOD(12);
    G_CLR_ON();

    ssp = B_SUPER(0);
    ZX0Decompress(fileData, (unsigned char*)0xc00000);
    B_SUPER(ssp);

    free(fileData);
}

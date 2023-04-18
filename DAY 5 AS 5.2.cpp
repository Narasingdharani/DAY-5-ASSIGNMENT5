#include <stdio.h>

int main() {
    FILE *fp;
    int num;

    fp = fopen("data.bin", "rb");  
    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    while (fread(&num, sizeof(int), 1, fp) == 1) {  
        printf("%d ", num);  
    }

    fclose(fp);  
    return 0;
}

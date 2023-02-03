#include <stdio.h>
#include <math.h>
#include <string.h>

void inDodai(char s[100]) {
    printf("Do dai cua chuoi %d\n", strlen(s));
}

void SoSanh(char s[100], char t[100]) {
    if (strcmp(s, t) == 0) {
        printf("2 chuoi nay bang nhau\n");
    } else {
        printf("2 chuoi nay khac nhau\n");
    }
}

int main() {
    char s[100];
//    scanf("%s", s);
//    fgets(s, 5, stdin);
    gets(s);
    char t[100] = "abcdef";
    // strlen
    inDodai(s);
    SoSanh(s, t);
    char chuoiCopy[100];
    char chuoiTest[100] = "hello";
    strcpy(chuoiCopy, chuoiTest);
    printf("%s\n", chuoiTest);
    // strcmp
//    printf("%s\n", s);
}
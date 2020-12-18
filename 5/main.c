#include "stdio.h"
#include "stdlib.h"

int countspace(char s[]) {
    int i = 0;
    int count = 0;
    while (s[i] != '\0') {
        if (s[i] == ' ') count++;
        i++;
    }
    return count;
}

int countspace2(char s[]) {
    int i = 0;
    int count = 0;
    while (*(s + i) != '\0') {
        if (*(s + i) == ' ') count++;
        i += sizeof(char);
    }
    return count;
}

int strlength(const char* str) {
    int count = 0;
    while (str[count] != '\0') count++;
    return count;
}

char* stringcat(const char* str1, const char* str2) {
    int lenght = 0;
    int length1 = strlength(str1);
    int length2 = strlength(str2);

    char* newStr = malloc((length1 + length2) * sizeof(char));

    int i = 0;
    for (; i < length1; i++) {
        newStr[i] = str1[i];
    }
    for (; (i - length1) < length2; i++) {
        newStr[i] = str2[(i - length1)];
    }
    return newStr;
}

int faculty(int n) {
    if (n == 0)
        return 1;
    else
        return n * faculty(n - 1);
}

double binomialCoefficent(int n, int k) {
    return  (double) faculty(n) / (faculty(k) * faculty(n - k));
}

int main() {
    printf("%lf\n", binomialCoefficent(10,0));
    printf("%lf\n", binomialCoefficent(10,1));
    printf("%lf\n", binomialCoefficent(10,10));
    printf("%lf\n", binomialCoefficent(49,6));
    return 0;
}
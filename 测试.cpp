#include <stdio.h>
#include <ctype.h>
#include <string.h>

int countWords(char* str) {
    int count = 0;
    int isWord = 0; // ����Ƿ����ڱ�������

    for (int i = 0; str[i] != '\0'; i++) {
        if (isalpha(str[i]) || ispunct(str[i])) {
            // �����ǰ�ַ�����ĸ������ţ�����Ϊ��һ�����ʵ�һ����
            isWord = 1;
        } else if (isspace(str[i]) && isWord) {
            // ����ǿո����ʾ��ǰ�Ѿ�������һ������
            count++;
            isWord = 0;
        }
    }

    // ĩβ���⴦��
    if (isWord) {
        count++;
    }

    return count;
}

int main() {
    char str[] = "The price of this orange is 3.5 yuan. There has a space, not 3.5yuan.";
    int numWords = countWords(str);
    printf("Number of words: %d", numWords);
    return 0;
}


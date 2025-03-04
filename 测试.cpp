#include <stdio.h>
#include <ctype.h>
#include <string.h>

int countWords(char* str) {
    int count = 0;
    int isWord = 0; // 标记是否正在遍历单词

    for (int i = 0; str[i] != '\0'; i++) {
        if (isalpha(str[i]) || ispunct(str[i])) {
            // 如果当前字符是字母或标点符号，则认为是一个单词的一部分
            isWord = 1;
        } else if (isspace(str[i]) && isWord) {
            // 如果是空格，则表示当前已经遍历完一个单词
            count++;
            isWord = 0;
        }
    }

    // 末尾特殊处理
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


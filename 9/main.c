#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef char bool;

void make_substr(char* src, char* dest, int from, int length)
{
    memcpy(dest, &src[from], length);
    dest[length] = '\0';
}

/// @brief Find unique substring
/// @param from start search from
/// @param str_length length of str
/// @param str string where to search
/// @return unique substring's length (started from *from*)
int find_unique(int from, int str_length, char* str)
{
    bool is_present[256] = {0,};

    int j;
    for (j = from; !is_present[str[j]]; j++)
        is_present[str[j]] = 1;
    
    return j - from;
}

int main()
{
    char str[256];
    printf("Строка: ");
    scanf("%s", str);

    int length = strlen(str);
    int maxlen = 0;
    int start = 0;

    for (int i = 0; i < length; i++)
    {
        int len = find_unique(i, length, str);
        if (len > maxlen)
        {
            maxlen = len;
            start = i;
        }
    }

    char substr[256];
    make_substr(str, substr, start, maxlen);
    printf("Наибольшая подстрока без повторов:\n%s\n", substr);
    return 0;
}

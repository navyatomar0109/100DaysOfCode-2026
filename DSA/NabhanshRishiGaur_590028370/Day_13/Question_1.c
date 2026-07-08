int cmp(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

char* mostCommonWord(char* paragraph, char** banned, int bannedSize) {
    char *words[1000];
    int cnt = 0;

    int n = strlen(paragraph);
    char temp[20];
    int k = 0;

    for (int i = 0; i <= n; i++) {
        if (isalpha(paragraph[i])) {
            temp[k++] = tolower(paragraph[i]);
        } else {
            if (k) {
                temp[k] = '\0';
                k = 0;

                bool ban = false;
                for (int j = 0; j < bannedSize; j++) {
                    if (!strcmp(temp, banned[j])) {
                        ban = true;
                        break;
                    }
                }

                if (!ban)
                    words[cnt++] = strdup(temp);
            }
        }
    }

    qsort(words, cnt, sizeof(char *), cmp);

    int best = 1, cur = 1;
    char *ans = words[0];

    for (int i = 1; i < cnt; i++) {
        if (!strcmp(words[i], words[i - 1])) {
            cur++;
        } else {
            if (cur > best) {
                best = cur;
                ans = words[i - 1];
            }
            cur = 1;
        }
    }

    if (cur > best)
        ans = words[cnt - 1];

    return ans;
}

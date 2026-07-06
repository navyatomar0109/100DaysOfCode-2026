#include <stdbool.h>
#include <string.h>

bool isIsomorphic(char* s, char* t) {

    if(strlen(s) != strlen(t))
        return false;

    int mapST[256];
    int mapTS[256];

    for(int i = 0; i < 256; i++) {
        mapST[i] = -1;
        mapTS[i] = -1;
    }

    for(int i = 0; s[i] != '\0'; i++) {

        if(mapST[(unsigned char)s[i]] == -1 &&
           mapTS[(unsigned char)t[i]] == -1) {

            mapST[(unsigned char)s[i]] = t[i];
            mapTS[(unsigned char)t[i]] = s[i];
        }

        else if(mapST[(unsigned char)s[i]] != t[i] ||
                mapTS[(unsigned char)t[i]] != s[i]) {

            return false;
        }
    }

    return true;
}

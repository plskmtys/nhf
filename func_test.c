#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

int main() {
    DIR *d;
    struct dirent *dir;
    struct stat path_stat;
    char filepath[1024];

    d = opendir("cards");
    if(d == NULL) {
        printf("nem lehet megnyitni a mappát.\n");
        return -1;
    }
    if (d) {
        while ((dir = readdir(d)) != NULL) {
            snprintf(filepath, sizeof(filepath), "cards/%s", dir->d_name);  // construct the full path
            if(stat(filepath, &path_stat) == 0 && S_ISREG(path_stat.st_mode)) {
                printf("%s\n", dir->d_name);
            }
        }
        closedir(d);
    }

    return(0);
}
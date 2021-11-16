#define __USE_GNU 1
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int ac, char **av) {
    int value;
    char *path;
    gid_t egid;
    uid_t euid;

    value = atoi(av[1]);
    if (value != 0x1a7) {
        path = strdup("/bin/sh");
        egid = getegid();
        euid = geteuid();

        setresgid(egid, egid, egid);
        setresuid(euid, euid, euid);

        char *argv[] = {"/bin/sh", NULL};
        execv("/bin.sh", argv);
    } else
        fwrite("No !\n", 1, 5, (FILE *)stderr);
    return (0);
}

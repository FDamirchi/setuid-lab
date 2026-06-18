#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Run a command as another user.\n");
        fprintf(stderr, "   Example: %s whoami", argv[0]);
        return 1;
    }

    uid_t euid = geteuid(); // effective uid
    uid_t ruid = getuid();  // real uid

    printf("Real UID: %ld\n", (long)ruid);
    printf("Effective UID: %ld\n", (long)euid);
    printf("--------------------\n\n");

    fflush(stdout);

    execvp(argv[1], &argv[1]);
    perror("execvp failed to do the job.");

    return 1;
}

#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>

void printCurrentTime();

int main(int argc, char* argv[]) {
    pid_t parentPID;

// The program processes the command line arguments
//      The arguments indicate which signals to catch
// The program emits a status line that includes its PID to stderr
    fprintf(stderr, "%s: $$ = %d\n", argv[0], parentPID);
// The program registers a handler for each argument                      (see signal(2))

//    signal(SIGINT, handle_sigint); 

// The program pauses itself continually                   (see pause(2))
// The handler registers itself again            (read about unreliable signals)
// The handler emits a line to stdout that indicates 
//      the signal caught, and 
//      the time it was caught                         (see time(2))
    for(int i=1; i<argc; i++) {
        printf("SIG%s caught at ", argv[i]);
        printCurrentTime();
    }
// The program gracefully terminates after 
//  receiving three successive SIGTERM signals       (hint: static int count)

// The program emits a final status message to stderr that indicates
//      the number of signals caught
    fprintf(stderr, "%s: Total signals count = %d\n", argv[0], argc);
}

void printCurrentTime() {
    time_t currentTime;
    currentTime = time(NULL);
    printf("%ld\n", currentTime);
}
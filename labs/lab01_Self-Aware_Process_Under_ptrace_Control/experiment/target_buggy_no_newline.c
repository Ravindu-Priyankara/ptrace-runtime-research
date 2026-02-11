#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    //fork
    pid_t pid = fork();

    //if fork failed
    if(pid < 0){
        perror("fork");
        return 1;
    }

    //watch dog
    if(pid == 0){
        //get parent pid
        pid_t ppid = getppid();
        // array for construct path
        char path[64];
        //array for store /proc/self/status
        char lines[128];
        // variable for debugger detect/detach msg display
        int display = 0;

        //combine the ppid to path
        snprintf(path, sizeof(path), "/proc/%d/status", ppid);

        while(1){
            //open the file {/proc/self/status}
            FILE *parent_status = fopen(path, "r");

            //check if its open or failedd
            if(parent_status){
                while(fgets(lines, sizeof(lines), parent_status)){
                    // get tracerpid line
                    if(strncmp(lines, "TracerPid:", 10) == 0){
                        //check debuger attack or not
                        if(atoi(lines + 10) != 0 && display == 0){
                            printf("I see you, debugger.");
                            display = 1;
                        }else if(atoi(lines + 10) == 0 && display == 1){
                            printf("Debugger detached. Good boy");
                            display = 0;
                        }
                    }
                }
                //close file
                fclose(parent_status);
            }
            usleep(100000); // Check every 0.1 seconds (fast detection)
        }


    }
    // parent process
    printf("Program started normally");
    
    while(1){
        sleep(5);
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/ptrace.h>
#include <sys/wait.h>
#include <unistd.h>

//get maximum pid
long get_max_pid(){
    //get pid
    FILE *f = fopen("/proc/sys/kernel/pid_max", "r");
    if(!f){
        return 32768; // fallback default
    }

    //copy to long variabl
    long max_pid;

    if(fscanf(f, "%ld", &max_pid) != 1){
        fclose(f);
        return 32768; // fallback
    }

    fclose(f);
    return max_pid;

}

int main(int argc, char *argv[]){

    //check argivements
    if(argc != 2){
        printf("Usage: %s <pid>\n", argv[0]);
        return 1;
    }

    char *endptr;
    int base = 10; //we need decimal
    errno = 0;  // before check errno should be zero
    long max_pid = get_max_pid();

    long pid = strtol(argv[1], &endptr, base);

    //handling edge cases
    if(errno != 0 || *endptr != '\0' || pid < 1 || pid > max_pid){
        printf("Invalid PID!");
        return 1;
    }

    //attach
    if(ptrace(PTRACE_ATTACH, pid, NULL, NULL) == -1){ // kernel sends SIGSTOP to target process
        perror("ptrace");
        return 1;
    }

    //waitpid
    waitpid(pid, NULL, 0);  // wait for process stop

    //sleep 10 seconds {helps to catch /proc/{pid/status has TracerPid changes}}
    sleep(10);

    //detach
    ptrace(PTRACE_DETACH, pid, NULL, NULL); //release the process

    return 0;
}
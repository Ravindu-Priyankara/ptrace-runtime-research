#include <stdio.h>
#include <sys/ptrace.h>
#include <stdlib.h>

//get pid
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
        printf("Usage: %s <pid> \n", argv[0]);
        return 1;
    }

    

    return 0;
}
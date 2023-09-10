/*====================================================================================================================================================================================
Name : 29.c
Author : Darshit Jakhaniya
Description :Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO, SCHED_RR).
Date: 6th sept, 2023.
====================================================================================================================================================================================*/
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <unistd.h>
#include <errno.h>

int main() {
    int pid=getpid();

    // Get the current scheduling policy
    int current_policy = sched_getscheduler(0);
    //sched_getscheduler(pid) will give the current scheduling policy
    //on success it will return the policy(non-negative integer)
    if (current_policy == -1) {
        perror("Error getting scheduling policy");
        return 1;
    }

    printf("Current scheduling policy: ");
    switch (current_policy) {
        case SCHED_FIFO:
            printf("SCHED_FIFO\n");
            break;
        case SCHED_RR:
            printf("SCHED_RR\n");
            break;
        default:
            printf("Unknown\n");
            break;
    }

    // Modify the scheduling policy to SCHED_FIFO
    struct sched_param param;
    param.sched_priority = 50; // Set the priority as needed
    
    //sched_setscheduler(pid,policy_name,priority) used to set the scheduling policy
    //on success it will return 0, -1 otherwise
    if (sched_setscheduler(pid, SCHED_FIFO, &param) == -1) {
        perror("Error setting SCHED_FIFO policy");
        return 1;
    }

    printf("Scheduling policy changed to SCHED_FIFO\n");

    int new_policy = sched_getscheduler(getpid());

    if (new_policy == -1) {
        perror("Error getting scheduling policy");
        return 1;
    }

    printf("new scheduling policy: ");
    switch (new_policy) {
        case SCHED_FIFO:
            printf("SCHED_FIFO\n");
            break;
        case SCHED_RR:
            printf("SCHED_RR\n");
            break;
        default:
            printf("Unknown (%d)\n", new_policy);
            break;
    }
  

    return 0;
}

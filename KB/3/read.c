/*
 Narayan Lal Menariya:August 30, 2018
 * */
#include<sys/sem.h>
#include<stdio.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<string.h>
 
 
struct student
{
        int id;
        char name[20];
}stdobj;
 
int main()
{
        int ret;
        char choice;
        char msg[20];
        struct student *ptr;
 
        //declaring key for semaphore
        key_t semKey = 1;
        //creating key for shared memory
        key_t shmKey = 100;
 
        //requesting kernel to return semaphore memory id
        int semid = semget(semKey, 1, IPC_CREAT|0666); //semkey, no.of sem, flg|permission
 
        if(semid == -1)
            perror("semget");
        else
        {
                        struct sembuf x = {0,-1,0}; //semaphore number, decrement operation, IPC_NOWAIT
                        //perform locking operation on
                        ret = semop(semid, &x, 1);
                        if(ret == -1)                                                                                        perror("semop");
                        else                                                                                           {                                                                                                 printf("semaphore locked \n");
 
                        //requesting kernel to allocate shared memory and return shmid
                        int shmid = shmget(shmKey, sizeof(stdobj), IPC_CREAT|0666);
 
                        //attaching to shared memory
                        ptr = (struct student*)shmat(shmid,NULL,0);
 
                        if(ptr)
                        {
                                printf("Attached successfully\n");
                                while(1)
                                {
                                        while((*ptr).id != 0)
                                        {
 
                                                printf("student id : %d\n",(*ptr).id);
                                                printf("student name :%s\n",(*ptr).name);
 
                                                printf("Data read successfully\n");
                                                ptr++;
                                        }
                                }
                                //deattaching from memory
                                shmdt(ptr);
                                printf("deattached successfully\n");
                                //release explicitly
                                semctl(semid,0,SETVAL,1);
                        }
                        else
                                perror("shmat");
                        }
        }
        return 0;
}
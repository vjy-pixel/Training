/*
 Narayan Lal Menariya:August 30,2018
 * */
#include<sys/sem.h>
#include<stdio.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<string.h>
#include "file.h"
 
int counter;
 
 
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
                //ACQUIRING SEMAPHORE:semval = 1 means semaphore is available
                ret = semctl(semid,0, SETVAL, 1); //semid, semaphore number, setvalue = 1
                if(ret == -1)
                        perror("smctl");
                else
                {
                        //creating semaphore structure
                        struct sembuf x = {0,-1,0}; //semaphore number, decrement operation, IPC_NOWAIT:process should release sem explicitly
 
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
                                printf("Do you want to write in shared memory 1. y:yes, 2.n:no\n");
                                while(1)
                                {
                                        scanf("%c",&choice);
                                        if(choice == 'y')
                                        {
                                                //ptr = &stdobj;
                                                printf("enter student id:\n");
                                                scanf("%d",&stdobj.id);
                                                printf("enter student name :\n");
                                                scanf("%s",&stdobj.name);
 
                                                printf("name :%s\n",stdobj.name);
                                                printf("id :%d\n",stdobj.id);
 
                                                (*ptr).id = stdobj.id;
                                                strcpy((*ptr).name, stdobj.name);
 
 
                                                printf("\nData written successfully\n");
                                                ptr++;
                                                printf("write choice y/n :");
                                        }
                                        if(choice == 'n')
                                        {
 
                                                break;
                                        }
 
                                }
 
                                //deattaching from memory
                                shmdt(ptr);
                                printf("deattached successfully\n");
                                //releasing semaphore
                                semctl(semid,0,SETVAL,1);
 
                        }
                        else
                                perror("shmat");
                        }
                }
        }
        return 0;
}
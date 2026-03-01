#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include <fcntl.h>
#include <sys/stat.h>

void takeInput(char *dirAddr)
{
        DIR *ptr=NULL;
        int flag=0;
        char buf[100];
        char readbuf[100];

label:
        ptr=opendir(dirAddr);

        strcpy(readbuf, dirAddr);

        printf("Enter your choice:");
        fgets(buf, 100, stdin);
        buf[strlen(buf)-1]='\0';

        struct dirent *rd;
        if((memcmp(buf, "cd ", 3))==0)
        {
                while((rd=readdir(ptr))!=NULL)
                {
                        if((strcmp(buf+3, rd->d_name))==0)
                        {
                                flag=1;
                                struct stat sb;
                                strcat(readbuf,rd->d_name);
                                stat(readbuf, &sb);

                                if(S_ISDIR(sb.st_mode))
                                        strcat(dirAddr, buf+3);
                                else{
                                        printf("Not a directory\n");
                                        goto label;
                                }
                        }
                }

                if(flag==0)
                {
                        printf("----Invalid directory-----\n");
                        goto label;
                }
        }
        else if((memcmp(buf, "open ", 5))==0)
        {
                while((rd=readdir(ptr))!=NULL)
                {
                        if((strcmp(buf+5, rd->d_name))==0)
                        {
                                flag=1;
                                struct stat sb;
                                strcat(readbuf,rd->d_name);
                                stat(readbuf, &sb);

                                if(S_ISREG(sb.st_mode))
                                {
                                        int fd=open(readbuf, O_RDONLY);
                                        if(fd<0)
                                        {
                                                perror("open");
                                                goto label;
                                        }
                                        char ch;
                                        while((read(fd, &ch, 1))==1){
                                                printf("%c", ch);
                                                fflush(stdout);
                                                usleep(50000);
                                        }

                                }
                                else
                                        printf("Not a regular file\n");

                                goto label;
                        }
                }

                if(flag==0)
                {
                        printf("---Invalid file---\n");
                        goto label;
                }
        }
        else if(strcmp(buf, "back")==0 && strlen(dirAddr)>2)
        {
                for(int i=strlen(dirAddr)-2; i>=0; i--)
                {
                        if(dirAddr[i]!='/')
                                dirAddr[i]='\0';
                        else if(dirAddr[i]=='/'){
                                dirAddr[i]='\0';
                                break;
                        }
                }
        }
        else if(strcmp(buf, "exit")==0 || strcmp(buf, "quit")==0)
                exit(0);
        else if(strcmp(buf, "path")==0)
        {
                printf("PATH:------>%s\n", dirAddr);
                goto label;
        }
        else
        {
                printf("INVALID INPUT\n");
                goto label;
        }
}

int main()
{
        DIR *dir=NULL;
        char *dirAddr = malloc(100*sizeof(char));
        strcpy(dirAddr, "/");


        while(1)
        {
                dir = opendir(dirAddr);
                struct dirent *read;

                while((read=readdir(dir))!=NULL){
                        if(read->d_name[0]!='.'){
                                printf("%s\n", read->d_name);
                                usleep(50000);
                        }
                }

                        takeInput(dirAddr);
                        strcat(dirAddr, "/");
        }
}

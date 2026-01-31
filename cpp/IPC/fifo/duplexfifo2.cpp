#include<iostream>
#include<fcntl.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/stat.h>
#include<cstring>

int main()
{

    const char * fifo1="/tmp/dfifo1";
    const char * fifo2="/tmp/dfifo2";
    mkfifo(fifo1,0666);
    mkfifo(fifo2,0666);

    pid_t id = fork();
    if(id<0)
    {
        perror("fail to create child");
        return 1;

    }
    if(id==0)
    {
        sleep(1);
        int fd=open(fifo2,O_RDONLY);
        if(fd<0)
        {
            perror("fail to open file");
            return 1;
        }
        char buff[100];
        read(fd,buff,sizeof(buff));
        std::cout<<buff<<std::endl;
        close(fd);

    }
    else{
        
        int fd= open(fifo1,O_WRONLY);
        if(fd<0)
        {
            perror("fail to open file");
            return 1;
        }
        const char * atr="i am from KARNATAKA";
        write(fd,atr,strlen(atr)+1);
        close(fd);
        wait(nullptr);
        


    }

    return 0;
}
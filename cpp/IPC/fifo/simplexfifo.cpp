#include<iostream>
#include<fcntl.h>
#include<cstring>
#include<sys/wait.h>
#include<unistd.h>
#include<sys/stat.h>

int main()
{
const char * fifo ="/tmp/myfifo";

mkfifo(fifo,0666);
pid_t pid = fork();
if(pid<0)
{
    perror("fork failed");
    return 1;
}

if(pid==0)
{
    sleep(1);
    int fd=open(fifo,O_RDONLY);
    if(fd<0)
    {
        perror("open file failed");
        return 1;

    }

    char buff[100];
    read(fd,buff,sizeof(buff));

    std::cout<<" result : "<<buff<<std::endl;

    close(fd);

}

else{
    int fd=open(fifo,O_WRONLY);
    if(fd<0)
    {
        perror("failed to open file");
        return 1;
    }
const char * atr="message from write process";
write(fd,atr,strlen(atr)+1);

close(1);
wait(nullptr);


}








    return 0;
}
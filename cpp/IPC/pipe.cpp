#include<iostream>
#include<cstring>
#include<unistd.h>
using namespace std;

int main()
{


    int fd[2];
     char buffer[100];
    if(pipe(fd)==-1)
    {
        cerr<<"pipe failed "<<endl;
        return 1;

    }
    pid_t id=fork();
    if(id<0)
    {
        cerr<<"fork failed"<<endl;
        return 1;

    }

  else  if(id==0)
{
    close(fd[1]);
  //  char buffer[100];
    read(fd[0],buffer,sizeof(buffer));
    cout<<"child process recived "<<buffer<<endl;
    close(fd[0]);
}

else{
    close(fd[0]);
    const char *ptr="hello child i am your father";
    write(fd[1],ptr,strlen(ptr)+1);
    close(fd[1]);

}

return 0;


}
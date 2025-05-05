#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
int main(){
        int fd1,fd2;
        char a[40],b[40];
        mkfifo("np1",0644);
        mkfifo("np2",0644);
        fd1=open("np1",O_WRONLY);
        fd2=open("np2",O_RDONLY);
        if(fork()==0){
                while(1){
                        scanf("%s",a);
                        write(fd1,a,sizeof(a));
                }
        }
        else{
                while(1){
                read(fd2,b,sizeof(b));
                printf("Data received: %s\n",b);
                }
        }
        return 0;
}

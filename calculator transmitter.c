#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
int main(int argc,char *argv[]){
        int fd1,fd2,ans;
        char word[10];
        sprintf(word,"%d %c %d",atoi(argv[1]),argv[2][0],atoi(argv[3]));
        mkfifo("np1",0644);
        mkfifo("np2",0644);
        fd1=open("np1",O_WRONLY);
        fd2=open("np2",O_RDONLY);
        write(fd1,word,sizeof(word));
        read(fd2,&ans,sizeof(ans));
        printf("Answer: %d\n",ans);
        return 0;
}

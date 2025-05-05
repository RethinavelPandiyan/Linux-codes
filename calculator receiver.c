#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
int main(){
        int fd1,fd2,num1,num2,ans;
        char word[10],symbol;
        mkfifo("np1",0644);
        mkfifo("np2",0644);
        fd1=open("np1",O_RDONLY);
        fd2=open("np2",O_WRONLY);
        read(fd1,word,sizeof(word));
        sscanf(word,"%d %c %d",&num1,&symbol,&num2);
        switch(symbol){
                case '+':ans=num1+num2;
                         break;
                case '-':ans=num1-num2;
                         break;
                case 'x':ans=num1*num2;
                         break;
                case '/':ans=num1/num2;
                         break;
                default:printf("Invalid\n");
        }
write(fd2,&ans,sizeof(ans));
        return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
void error_handling(char *message);

int main(int argc, char *argv[]){
    int serv_sock, clnt_sock;
    struct sockaddr_in serv_addr, clnt_addr;
    socklen_t clnt_addr_size = sizeof(clnt_addr_size);

    char meassage[1024] = "hello";

    if(argc != 2){
        printf("Usage : argv[0] <port> ");
        exit(1);
    }

    serv_sock = socket(PF_INET, SOCK_STREAM, 0);
    if(serv_sock == -1)
        error_handling("socket() error");
    
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(atoi(argv[1]));

    if(bind(serv_sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1)
        error_handling("bind() error");
    
    if(listen(serv_sock, 5) == -1)
        error_handling("listen() error");
    
    clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_addr, &clnt_addr_size);
    if(clnt_sock == -1)
        error_handling("accept() error");
    
    write(clnt_sock, meassage, sizeof(meassage));
    while(read(clnt_sock, meassage, 1024)!= -1){
        write(clnt_sock, meassage, strlen(meassage));
    }
    close(clnt_sock);
    close(serv_sock);


    return 0;
}

void error_handling(char *message){
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}
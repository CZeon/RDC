/*Programa feito utilizando base do código da aula 16 da profª Natássya Barlate Floro Da Silva*/


#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<netdb.h>
#include<stdio.h>
#include<stdlib.h>

void error(char *msg){
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[]){
    int sock, length, fromlen, n;
    struct sockaddr_in server;
    struct sockaddr_in from;
    char buf[1024];

    if(argc < 2){
        fprintf(stderr,"ERRO, nenhuma porta fornecida\n");
        exit(0);
    }

    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if(sock < 0){
        error("Abrindo socket");
    }
    length = sizeof(server);
    bzero(&server,length);
    server.sin_family=AF_INET;
    server.sin_addr.s_addr=INADDR_ANY;
    server.sin_port=htons(atoi(argv[1]));
    if(bind(sock,(struct sockaddr*)&server,length)< 0){
        error("Binding");
    }
    fromlen = sizeof(struct sockaddr_in);

    while(1){
        n = recvfrom(sock,buf,1024,0,(struct sockaddr*)&from,&fromlen);
        if(n < 0){
            error("recvfrom");
        }
        write(1,buf,n);
        n = sendto(sock,"Recebi sua mensagem: \n", 17, 0,(struct sockaddr*)&from,fromlen);
        if(n < 0){
            error("sendto");
        }
    }
}

#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<netdb.h>
#include<stdio.h>
#include<time.h>
void error(char *);

void delay(int number_of_seconds){
    int milli_seconds = 1000 * number_of_seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds);
}

int main(int argc, char *argv[]){
    int sock, length, n, n2, flag = 0,cont = 0;
    struct sockaddr_in server, from;
    struct hostent *hp;
    char buffer [256];

    if(argc != 3){
        printf("Erro");
        exit(1);
    }

    sock = socket(AF_INET, SOCK_DGRAM, 0);

    if(sock < 0){
        error("Socket");
    }

    server.sin_family = AF_INET;
    hp = gethostbyname(argv[1]);

    if(hp == 0){
        error("Host desconhecido");
    }

    bcopy((char *)hp->h_addr, (char *)&server.sin_addr,hp->h_length);
    server.sin_port = htons(atoi(argv[2]));
    length=sizeof(struct sockaddr_in);

    printf("Digite sua mensagem: ");

    bzero(buffer, 256);
    fgets(buffer, 255, stdin);
    flag = 1;
    do{
    n = sendto(sock, buffer, strlen(buffer), 0, &server, length);
    if(n < 0){
        printf("Mensagem enviada invalida");
    }
    n2 = recvfrom(sock, buffer, 256, 0, &from, &length); //-2;

    if(n2 < 0){
        flag = 0;
    }else{
        cont = 5;
    }
    if(cont == 4){
        flag = 1;
        printf("Falha ao enviar Mensagem!");
    }

    write(1, "Got an ack: ", 12);
    write(1, buffer, n);
    delay(1000);
    cont++;
    }while(flag == 0);
}

void error(char *msg){
    perror(msg);
    exit(0);
}

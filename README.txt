Para realizar as operações no programa, é necessário o uso de dois terminais abertos, um para o cliente e outro para o servidor.

Após abrir o terminal na pasta do arquivo (simplesmente abra o diretório onde o arquivo está salvo, aperte o botão direito e vá em abrir em um terminal).
utilize o comando: "gcc server_udp.c -o server_udp.out" para compilar o server e, no outro terminal, use o comando "gcc client_udp.c -o client_udp.out"
para compilar o client.

Para executar o servidor, é necessário colocar uma porta para que ele se comunique com o cliente, por exemplo, digite o comando no terminal:

"./server_udp 4547"

Para executar o client, é necessário fazer um procedimento similar, indicando que você está utilizando o localhost, por exemplo:

"./client_udp localhost 4547"
 
 o cliente deve digitar uma mensagem e o server deve imprimir ela, assim q ele recebe, o cliente retorna a informação de que a mensagem foi recebida.
/*
 * network.h
 *
 *  Created on: Oct 28, 2019
 *      Author: chaseglasper
 */

#ifndef NETWORK_H_
#define NETWORK_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <pthread.h>



#define SOCKET_DEFAULT 8765
#define DICT_DEFAULT "dictionary.txt"
#define DICT_BUF 128
#define BUFFER_MAX 5


FILE *DICTIONARY;
FILE *LOG;
int LISTEN_PORT;
int clients[BUFFER_MAX];
char *logs[BUFFER_MAX];

/*Struct for Server*/
typedef struct server{
    int client_count, log_count;
    int l_read_ptr, l_write_ptr;
    int c_read_ptr, c_write_ptr;
    pthread_mutex_t client_mutex, log_mutex;
    pthread_cond_t client_not_empty, client_not_full;
    pthread_cond_t log_not_empty, log_not_full;
}server;


void *worker_thread(void *args);
void *logger_thread(void *args);
int open_listenfd(int port);
void server_init(server *serv);
void insert_client(server *serv, int socket);
int remove_client(server *serv);
void insert_log(server *serv, char *word, int iscorrect);
char *remove_log(server *serv);



#endif /* NETWORK_H_ */

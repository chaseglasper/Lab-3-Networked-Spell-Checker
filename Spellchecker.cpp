//============================================================================
// Name        : Spellchecker.cpp
// Author      : lol
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "network.h"

using namespace std;


int main(int argc, char *argv[]) {
    //default dictionary and socket
    if (argc == 1) {
        if (!(DICTIONARY = fopen(DICT_DEFAULT, "r"))) {
            perror("Dictionary");
            exit(EXIT_FAILURE);
        }
        LISTEN_PORT = SOCKET_DEFAULT;
    }
    else if (argc == 2) {
           char *endptr;

           //if the first argument isn't an int
           if (!(LISTEN_PORT = (int) strtol(argv[1], &endptr, 10))) {
               //assume it's a dictionary
               if (!(DICTIONARY = fopen(argv[1], "r"))) {
                   perror("Unknown dictionary");
                   exit(EXIT_FAILURE);
               }
               LISTEN_PORT = SOCKET_DEFAULT;
           }
       }

       //passed specific dictionary and socket
       else {
           if (!(DICTIONARY = fopen(argv[1], "r"))) {
               perror("Unknown dictionary");
               exit(EXIT_FAILURE);
           }
           char *endptr;

           if (!(LISTEN_PORT = (int) strtol(argv[2], &endptr, 10))) {
               perror("Cannot read socket");
               exit(EXIT_FAILURE);
           }
           //if the port isn't a legal port
           if (LISTEN_PORT < 1024 || LISTEN_PORT > 65535) {
               perror("Port must be between 1025 & 65534)");
               exit(EXIT_FAILURE);
           }
       }
//checks to see if listening socket open
 int listen_socket;
       if ((listen_socket = open_listenfd(LISTEN_PORT)) < 0) {
            perror("Couldn't open listening socket");
            exit(EXIT_FAILURE);
        }





}

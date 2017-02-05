#ifndef __ONENET_H_
#define __ONENET_H_

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


#define uint  unsigned int
#define uchar unsigned char
*/

#include "include.h"

uint32_t HTTP_PostPkt(char *pkt, char *key, char *devid, char *dsid, char *val,char *dsid1, char *val1,char *dsid2, char *val2);
int socket_statr(void);
void socket_close(int socke);


#endif
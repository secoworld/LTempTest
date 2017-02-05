#ifndef __INCLUDE_H_
#define __INCLUDE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <wiringPi.h>
#include <math.h>


#define uint  unsigned int
#define uchar unsigned char

//oled pins
#define SCL 21
#define SDA 22
#define RST 23
#define DC 24
#define CS 25

//Pi3 cpu temp
#define TEMP_PATH "/sys/class/thermal/thermal_zone0/temp"
#define SIZE 32


//onenet api id port 
#define APi  "NPmvBXGPaQz2=3p9sODpKgjLFqA="
#define Id     "4657028"
//IP:183.230.40.33 端口号:80
#define Ip "183.230.40.33"
#define Port "80"


#endif
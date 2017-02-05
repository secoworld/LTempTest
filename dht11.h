#ifndef __DHT11_H_
#define __DHT11_H_

/*
#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#define uint  unsigned int
#define uchar unsigned char
*/

#include "include.h"

void dht11_pin_init(uchar pins);
uint dht11_check(void);
uint dht11_init(void);
uint dht11_read_bit(void);
uint dht11_read_byte(void);
uint dht11_read_data(uint *temp,uint *humi,uint *temp1,uint *humi1);


#endif
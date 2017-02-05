

#include "dht11.h"
unsigned char pin;

#define data_1   digitalWrite(pin, HIGH)
#define data_0   digitalWrite(pin, LOW)

#define  data_in 	 pinMode(pin,INPUT)
#define  data_out    pinMode(pin,OUTPUT)

#define   data    digitalRead(pin)

//返回0代表成功，1代表失败

void dht11_pin_init(uchar pins)
{
	pin=pins;
	pinMode (pin, OUTPUT) ;
}

//0 代表成功，1代表失败
uint dht11_check(void)
{
	uint i=0;
	data_in;
	while(data&&i<100)
	{
		i++;
		delayMicroseconds(1);
	}
	if(i>=100) return 1;
	else i=0;
	
	while(!data&&i<100)
	{
		i++;
		delayMicroseconds(1);
	}
	if(i>=100) return 1;
	return 0;
}

uint dht11_init(void)	//DHT11初始化
{
	data_out;
	data_0;
	delay(20);		//延时ms
	data_1;
	delayMicroseconds(30);		//延时us
	return dht11_check();
}

uint dht11_read_bit(void)
{
	uint i=0;
	while(data&&i<100)
	{
		i++;
		delayMicroseconds(1);
	}
	i=0;
	while(!data&&i<100)
	{
		i++;
		delayMicroseconds(1);
	}
	delayMicroseconds(40);
	if(data) return 1;
	else return 0;
}

uint dht11_read_byte(void)
{
	uint i,dat;
	dat=0;
	for(i=0;i<8;i++)
	{
		dat<<=1;
		dat |= dht11_read_bit();
		
	}
	return dat;
}

uint dht11_read_data(uint *temp,uint *humi,uint *temp1,uint *humi1)
{
	uint buf[5];
	uint i,j=0;
	
	while(dht11_init()==1)
   {
	    //printf("dht11 初始化失败\r\n");
		delay(500);
		j++;
		if(j>=5) return 1;
    }
	//printf("dht11 初始化成功\r\n");
	
	for(i=0;i<5;i++)
	{
		buf[i]=dht11_read_byte();
	}
	if((buf[0]+buf[1]+buf[2]+buf[3])==buf[4])
	{
		*humi=buf[0];
		*temp=buf[2];
		*humi1=buf[1];
		*temp1=buf[3];
		//printf("读取数据成功\r\n");
		//printf("%d,%d\r\n",*humi,*temp);
	}
	else
	{
		//printf("读取数据错误\r\n");
		dht11_read_data(temp,humi,temp1,humi1);
		
	}
	
	return 0;
		
}

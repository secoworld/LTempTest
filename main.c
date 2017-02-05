
#include "dht11.h"
#include "oled.h"
#include "onenet.h"
#include "pitemp.h"



int main(void)
{
	int socke1;
	int len;
	float Pitemp;
	char pitempStr[7];
	char tempStr[5];
	char humiStr[5];
	char HTTP_Buf[400]={0};
	wiringPiSetup();
	uint temp,humi,temp1,humi1;
	socke1=socket_statr();
	
	OLED_Pin_Init();
	dht11_pin_init(7);
	LCD_Init();
	//LCD_CLS();
	OLED_CLS();
	
	LCD_P6x8Str(2,1,"hello world");
	
	Pitemp=read_cpu_temp();		//pi3 cpu  temp
	if(dht11_read_data(&temp,&humi,&temp1,&humi1))
	{
		printf("DHT11 error!!");
		OLED_P6X8Str(20,4,"DHT11 ERROR");
		OLED_Write();
		return 1;
	}
	
	OLED_P6X8Str(20,0,"raspberry pi3");
	OLED_P6X8Str(0,1,"*********************");
	//OLED_Write();
	
	
	sprintf(pitempStr,"%.2f",Pitemp);
	sprintf(tempStr,"%d",temp);
	sprintf(humiStr,"%d",humi);
	
	
	OLED_P6X8Str(2,3,"Pi3 temp:         C");
	OLED_P6X8Str(70,3,pitempStr); 
	OLED_P6X8Str(2,5,"Temp :      C");
	OLED_P6X8Str(50,5,tempStr);
	OLED_P6X8Str(2,6,"Humi :      %RH");
	OLED_P6X8Str(50,6,humiStr);
	
	OLED_Write();
	
	printf("The pi3 CPU temp is %.3f °C\r\n",Pitemp);
	printf("The temp is %d.%d  °C\r\n",temp,temp1);
    printf("The humi is %d.%d  RH\r\n",humi,humi1);
	
	
	len=HTTP_PostPkt(HTTP_Buf,APi,Id,"dht11_temp",tempStr,"dht11_humi",humiStr,"pi3_cpu_temp",pitempStr);
	write(socke1,HTTP_Buf,len);   //write to https
	
	socket_close(socke1);
	return 0;
	
}
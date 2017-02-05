#include "onenet.h"

/*
#define Ip "183.230.40.33"
#define Port "80"
*/

//HTTP报文,pkt为字符串缓存，key为api-key密钥，devid为设备号，dsid为上传数据的名称，val为要上传数据的值
uint32_t HTTP_PostPkt(char *pkt, char *key, char *devid, char *dsid, char *val,char *dsid1, char *val1)
{
	char dataBuf[100] = {0};
	char lenBuf[10] = {0};
	*pkt = 0;

	sprintf(dataBuf, ",;%s,%s;%s,%s", dsid, val,dsid1, val1); //采用分割字符串格式:type = 5
	sprintf(lenBuf, "%d", strlen(dataBuf));

	strcat(pkt, "POST /devices/");
	strcat(pkt, devid);
	strcat(pkt, "/datapoints?type=5 HTTP/1.1\r\n");

	strcat(pkt, "api-key:");
	strcat(pkt, key);
	strcat(pkt, "\r\n");

	strcat(pkt, "Host:api.heclouds.com\r\n");

	strcat(pkt, "Content-Length:");
	strcat(pkt, lenBuf);
	strcat(pkt, "\r\n\r\n");

	strcat(pkt, dataBuf);

	return strlen(pkt);
}


int socket_statr(void)
{
	int socke;
	struct sockaddr_in serv_addr;

	socke=socket(PF_INET,SOCK_STREAM,0);   //创建socket套接字
	if(socke == -1)
	{
		printf("socket error!!");
		exit(1);
	}

	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr=inet_addr(Ip);
	serv_addr.sin_port=htons(atoi(Port));

	if(connect(socke,(struct sockaddr*)&serv_addr,sizeof(serv_addr))== -1)
	{
		printf("error connect!");
		exit(1);
	}
	return socke;
}

void socket_close(int socke)
{
	close(socke); 
}
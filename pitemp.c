#include "pitemp.h"

float read_cpu_temp(void)
{
	FILE *fp;
	float  temp;
	char buf[SIZE];

	fp=fopen(TEMP_PATH,"r");
	if(fp==NULL)
	{
		printf("open error\n");
		return -1;
	}

	if(fread(buf,1,SIZE,fp)>=0)
	{
		//puts("read successful");

		temp=atoi(buf)/1000.0;
		//printf("temp:%d\n",temp);
	}
	else
	{
		//printf("read error\n");
		return -1;
	}


	if(fclose(fp)==-1)
	{
		printf("close error\n");
		return -1;
	}
	return temp;

}



��ݮ�� ʹ��DHT11���������¶ȡ�ʪ�ȣ�ͨ��OLED������ʾ�������ϴ���onenet��ƽ̨���������ߵ���ʾ��

���ӷ�ʽ��
	1.DHT11 
		��Data�ˣ�ͨ��ʹ��dht11_pin_init��ȷ�����Ŷ˿�
			dht11_pin_init(uchar pins);
	
	2.OLED:
		VCC��1    GND��6   SCL:29  SDA:31  RST:33  DC:35  CS:37
		����ݮ�ɵ����ű�ţ�
		������Ҫ�޸����ţ�����include.h���޸ļ��ɡ�

ʹ�û�����
	1.ʹ�õ���wiringPi�����밲װ��wiringPi��
		git clone git://git.drogon.net/wiringPi
		cd wiringPi
		git pull origin
		./build
		
	2.onenet��ƽ̨
		��1������ע��onenet��ƽ̨��http://open.iot.10086.cn/
		��2���½���Ŀ������豸������豸��ID ��API
		��3������inlcude.h �е�APi��Id���滻�����Լ��ļ���
		
		
��ʱ���г���
	1.ʹ��cron��ʱ��������/etc/crontab��������񼴿�
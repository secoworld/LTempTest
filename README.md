
树莓派 使用DHT11测量室内温度、湿度，通过OLED进行显示。并且上传到onenet云平台，进行在线的显示。

1.


2.连接方式：

	1.DHT11 
	
		DHT11的Data端，通过使用dht11_pin_init来确定引脚端口
			dht11_pin_init(uchar pins);
	
	2.OLED:
	
		VCC：1    GND：6   SCL:29  SDA:31  RST:33  DC:35  CS:37
		（树莓派的引脚编号）
		若是想要修改引脚，可在include.h中修改即可。

3.使用环境：

	1.使用的是wiringPi，必须安装好wiringPi。
	
	
		git clone git://git.drogon.net/wiringPi
		cd wiringPi
		git pull origin
		./build
		
4.onenet云平台

		（1）必须注册onenet云平台，http://open.iot.10086.cn/
		（2）新建项目，添加设备，获得设备的ID 和API
		（3）更改inlcude.h 中的APi和Id，替换成你自己的即可
		
		
5.定时运行程序：

	1.使用cron定时启动，在/etc/crontab中添加任务即可

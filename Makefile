LL= -lwiringPi -lpthread
ALL= oled.o dht11.o onenet.o main.c include.h pitemp.o 
test : $(ALL)
	gcc -Wall -o test $(ALL) $(LL)
oled.o : oled.c oled.h include.h
	gcc -c oled.c -o oled.o  $(LL)
dht11.o : dht11.c dht11.h  include.h
	gcc -c dht11.c   -o dht11.o  $(LL)
onenet.o : onenet.c onenet.h include.h
	gcc -c onenet.c  -o onenet.o  $(LL)
pitemp.o : pitemp.c pitemp.h include.h
	gcc -c pitemp.c  -o pitemp.o  $(LL)
	
clean :
	rm -f *.o
	
cleanall:
	rm -f *.o *.c *.h test Makefile

# MakeFile for restChat
# server using C++ Microservice
# sudo mkdir /var/www/html/restChatDB
# sudo chown ubuntu /var/www/html/restChatDB
CC=g++
CFLAGS= -std=c++14 -Wno-deprecated-declarations
CXXFLAGS += -std=c++17
RM= /bin/rm -f

all: restChat PutHTML

chatEntry.o: chatEntry.cpp chatEntry.h
	$(CC) -c $(CFLAGS) chatEntry.cpp

chatDB.o: chatDB.cpp chatDB.h
	$(CC) -c $(CFLAGS) -I/usr/include/cppconn chatDB.cpp



restChat.o: restChat.cpp httplib.h
	$(CC) -c $(CFLAGS) restChat.cpp 

restChat: restChat.o chatDB.o chatEntry.o 
	$(CC) restChat.o chatDB.o chatEntry.o -o restChat -L/usr/local/lib -lmariadbcpp
PutHTML:
	cp restChat.html /var/www/html/restChatDB/
	cp restChat.css /var/www/html/restChatDB/
	cp restChat.js /var/www/html/restChatDB/

	echo "Current contents of your HTML directory: "
	ls -l /var/www/html/restChatDB/

clean:
	rm restChat *.o

# MakeFile for restChat
# server using C++ Microservice
# sudo mkdir /var/www/html/restChatDB
# sudo chown ubuntu /var/www/html/restChatDB

CC= g++

CFLAGS= -std=c++14  -Wno-deprecated-declarations

RM= /bin/rm -f

all: PutHTML restChat

PutHTML:
	cp restChat.html /var/www/html/restChatDB/
	cp restChat.css /var/www/html/restChatDB/
	cp restChat.js /var/www/html/restChatDB/
	
	echo "Current contents of your HTML directory: "
	ls -l /var/www/html/restChatDB/

chatEntry.o: chatEntry.cpp chatEntry.h
	$(CC) -c $(CFLAGS) chatEntry.cpp

chatDB.o: chatDB.cpp chatDB.h
	$(CC) -c $(CFLAGS) -I/usr/include/cppconn chatDB.cpp

chat.o: restChat.cpp chatEntry.h	chatDB.h
	$(CC) -c $(CFLAGS) restChat.cpp

restChat: chat.o chatDB.o chatEntry.o
	$(CC) chat.o chatDB.o chatEntry.o -L/usr/lib -o restChat -L/usr/local/lib -lmariadbcpp


restChat : restChat.cpp httplib.h
	$(CXX) -o restChat $(CXXFLAGS) restChat.cpp $(OPENSSL_SUPPORT) $(ZLIB_SUPPORT) $(BROTLI_SUPPORT) 

clean:
	rm restChat *.o

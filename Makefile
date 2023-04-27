# MakeFile for restChat
# server using C++ Microservice
# sudo mkdir /var/www/html/restChatDB
# sudo chown ubuntu /var/www/html/restChatDB

all: PutHTML restChat

PutHTML:
	cp restChat.html /var/www/html/restChatDB/
	cp restChat.css /var/www/html/restChatDB/
	cp restChat.js /var/www/html/restChatDB/
	
	echo "Current contents of your HTML directory: "
	ls -l /var/www/html/restChatDB/

restChat : restChat.cpp httplib.h
	$(CXX) -o restChat $(CXXFLAGS) restChat.cpp $(OPENSSL_SUPPORT) $(ZLIB_SUPPORT) $(BROTLI_SUPPORT) 

clean:
	rm restChat *.o

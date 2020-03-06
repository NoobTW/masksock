#include <string>
#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

using namespace std;

int main(int argc, char *argv[]) {
	if (argc == 2 && (
		argv[1] == std::string("help") ||
		argv[1] == std::string("-h") ||
		argv[1] == std::string("--help")
	)) {
		cout << "USAGE: nc [SERVER_HOST=127.0.0.1] [PORT=8124]" << endl << endl;
		cout << "EXAMPLE:" << endl;
		cout << "    nc 127.0.0.1" << endl;
		cout << "    nc 140.127.220.2 8124" << endl;
		return 0;
	}

	string IP = "127.0.0.1";
	int PORT = 8124;

	if (argc == 2) {
		IP = string(argv[1]);
	}
	if (argc == 3) {
		IP = string(argv[1]);
		PORT = stoi(string(argv[2]));
	}

	string line;

	int sock = 0, valread; 
	struct sockaddr_in serv_addr; 
	// char buffer[1024] = {0}; 
	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) { 
		printf("\n Socket creation error \n"); 
		return -1; 
	}

	serv_addr.sin_family = AF_INET; 
	serv_addr.sin_port = htons(PORT); 

	if(inet_pton(AF_INET, IP.c_str(), &serv_addr.sin_addr)<=0)  {
	   cout << "Invalid address" << endl;	
		return -1; 
	} 

	if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) { 
		cout << "Connection failed." << endl;
		return -1; 
	}

	cout << "Connected to " << IP << ":" << PORT << endl;
	
	while(getline(cin, line)) {
		// cout << "Line Received: " << line << endl;
		const char* str = line.c_str();
		send(sock, str, strlen(str), 0);
		// valread = read( sock , buffer, 1024); 
		// printf("%s\n",buffer ); 
	}

	return 0; 
}

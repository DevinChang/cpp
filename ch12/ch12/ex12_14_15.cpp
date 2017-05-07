#include <iostream>
#include <memory>
#include <string>
#include <vector>

struct destination {
	std::string ip;
	int port;
	destination(std::string ip_, int port_) : ip(ip_), port(port_){}

};


struct connection {
	std::string ip;
	int port;
	connection(std::string ip_, int port_) : ip(ip_), port(port_){}

};
connection connect(destination *pDest) {
	std::shared_ptr<connection> pConn(new connection(pDest->ip, pDest->port));
	std::cout << "creating connetion(" << pConn.use_count() << ")" << std::endl;
	return *pConn;
}
void disconnect(connection pConn) {
	std::cout << "connection close(" << pConn.ip << ":"
		<< pConn.port << ")" << std::endl;
}

void end_connection(connection *pConn) {
	disconnect(*pConn);
}
void f(destination &d) {
	connection conn = connect(&d);
	//std::shared_ptr<connection> p(&conn, end_connection);
	//ex12_15 use lambda
	std::shared_ptr<connection> p(&conn, [](connection *p) { disconnect(*p); });
	std::cout << "connecting now(" << p.use_count() << ")" << std::endl;
}

int main5() {
	destination dest("127.0.0.1", 80);
	f(dest);
	
	system("pause");
	return 0;
}

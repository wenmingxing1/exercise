#include<iostream>
#include<memory>
#include<string>

using namespace std;

//连接类
struct connection
{
    string ip;
    int port;
    connection(string ip_, int port_) : ip(ip_), port(port_) {}
};

//目的类
struct destination
{
    string ip;
    int port;
    destination(string ip_, int port_) : ip(ip_), port(port_) {}
};

//连接函数
connection connect(destination* pDest)
{
    shared_ptr<connection> pConn(new connection(pDest->ip, pDest->port));
    cout << "creating connection (" << pConn.use_count() << ")" << endl;
    return *pConn;
}

//断开连接
void disconnect(connection pConn)
{
    cout << "connection close(" << pConn.ip << ":" << pConn.port << ")" << endl;
}

//自定义删除器
void end_connection(connection* pConn)
{
    disconnect(*pConn);
}

void f(destination &d)
{
    connection conn = connect(&d);
    shared_ptr<connection> p(&conn, end_connection);
    cout << "connection now(" << p.use_count() << ")" << endl;
    //完成后会自动调用end_connection
}

int main()
{
    destination dest("201.118.176.67", 3316);
    f(dest);
}

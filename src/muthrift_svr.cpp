
/* ====================================================
#   Copyright (C)2019 All rights reserved.
#
#   Author        : anlongfei
#   Email         : anlongfei@meituan.com
#   File Name     : muthrift_svr.cpp
#   Last Modified : 2019-02-01 16:50
#   Describe      :
#
# ====================================================*/

#include <iostream>
#include "muthrift_svr.h"
using namespace std;

muthrift_svr::muthrift_svr(const uint16_t &u16_port) {
    m_tcp_server = boost::make_shared<muduo::net::TcpServer>(&m_event_loop,
                                                             muduo::net::InetAddress(u16_port),
                                                             "test_server"); // TODO
}
bool muthrift_svr::init() {
    m_tcp_server.setConnectionCallback(
                                       std::bind(&EchoServer::OnConn, this, _1));
    m_tcp_server.setMessageCallback(
                                    std::bind(&EchoServer::OnMsg, this, _1, _2, _3));
}
virtual muthrift_svr::~muthrift_svr() {
}
void muthrift_svr::serve() {
    m_event_loop.loop();
}

void muthrift_svr::OnWriteComplete(const muduo::net::TcpConnectionPtr &conn) {
    std::cout << "OnWriteComplete ..." << std::endl;
}
void muthrift_svr::OnConn(const TcpConnectionPtr &conn) {
    std::cout << "OnConn ..." << std::endl;
}
void muthrift_svr::OnMsg(const muduo::net::TcpConnectionPtr &conn,
                         muduo::net::Buffer *buffer,
                         Timestamp receiveTime) {
    std::cout << "OnMsg ..." << std::endl;
}

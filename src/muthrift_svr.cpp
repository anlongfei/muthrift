
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
using namespace std::placeholders;
using std::make_shared;
using std::shared_ptr;

muthrift_svr::muthrift_svr(const uint16_t &u16_port) {
    m_tcp_server = make_shared<muduo::net::TcpServer>(&m_event_loop,
                                                      muduo::net::InetAddress(u16_port),
                                                      "test_server"); // TODO
}
bool muthrift_svr::init() {
    m_tcp_server->setConnectionCallback(
                                       std::bind(&muthrift_svr::OnConn, this, _1));
    m_tcp_server->setMessageCallback(
                                    std::bind(&muthrift_svr::OnMsg, this, _1, _2, _3));
    m_tcp_server->start();
}

void muthrift_svr::serve() {
    m_event_loop.loop();
}

muthrift_svr::~muthrift_svr() {
}

void muthrift_svr::OnWriteComplete(const muduo::net::TcpConnectionPtr &conn) {
    std::cout << "OnWriteComplete ..." << std::endl;
}
void muthrift_svr::OnConn(const muduo::net::TcpConnectionPtr &conn) {
    std::cout << "OnConn ..." << std::endl;
}
void muthrift_svr::OnMsg(const muduo::net::TcpConnectionPtr &conn,
                         muduo::net::Buffer *buffer,
                         muduo::Timestamp receiveTime) {
    std::cout << "OnMsg ..." << std::endl;
}

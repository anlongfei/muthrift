
/* ====================================================
#   Copyright (C)2019 All rights reserved.
#
#   Author        : anlongfei
#   Email         : anlongfei@meituan.com
#   File Name     : muthrift_svr.h
#   Last Modified : 2019-01-31 14:32
#   Describe      :
#
# ====================================================*/

#ifndef  _MUTHRIFT_SVR_H
#define  _MUTHRIFT_SVR_H

//#include <thrift/Thrift.h>
//#include <thrift/server/TServer.h>

//class muthrift_svr : public TServer {
class muthrift_svr {
    public:
        muthrift_svr(const uint16_t &u16_port);
        bool init();
        virtual ~muthrift_svr();
        void serve();
        void OnWriteComplete(const muduo::net::TcpConnectionPtr &conn);
        void OnConn(const TcpConnectionPtr &conn);
        void CthriftSvr::OnMsg(const muduo::net::TcpConnectionPtr &conn,
                               muduo::net::Buffer *buffer,
                               Timestamp receiveTime);
    private:
        std::shared_ptr<muduo::net::TcpServer> m_tcp_server;
        muduo::net::EventLoop m_event_loop;  //guarantee init before server_ !!
};

#endif // _MUTHRIFT_SVR_H



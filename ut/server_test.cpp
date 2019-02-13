
/* ====================================================
#   Copyright (C)2019 All rights reserved.
#
#   Author        : anlongfei
#   Email         : anlongfei@meituan.com
#   File Name     : server_test.cpp
#   Last Modified : 2019-02-01 16:53
#   Describe      :
#
# ====================================================*/

#include <iostream>
#include "muthrift_svr.h"
using namespace std;

int main() {
    muthrift_svr server(8090);
    server.init();
    server.serve();
    return 0;
}




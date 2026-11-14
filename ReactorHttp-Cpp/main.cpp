#include <cstdio>
#include "Buffer.h"
#include "Channel.h"
#include "EpollDispatcher.h"
#include "EventLoop.h"
#include "HttpRequest.h"
#include "HttpResponse.h"
#include "Log.h"
#include "PollDispatcher.h"
#include "SelectDispatcher.h"
#include "TcpConnection.h"
#include "TcpServer.h"
#include "ThreadPool.h"
#include "WorkerThread.h"

int main()
{
    LOG("ReactorHttp-Cpp skeleton");
    std::printf("%s\n", Buffer().name().c_str());
    std::printf("%s\n", Channel().name().c_str());
    std::printf("%s\n", EventLoop().name().c_str());
    std::printf("%s\n", HttpRequest().name().c_str());
    std::printf("%s\n", HttpResponse().name().c_str());
    std::printf("%s\n", TcpConnection().name().c_str());
    std::printf("%s\n", TcpServer().name().c_str());
    std::printf("%s\n", ThreadPool().name().c_str());
    std::printf("%s\n", WorkerThread().name().c_str());
    std::printf("%s\n", EpollDispatcher().name().c_str());
    std::printf("%s\n", PollDispatcher().name().c_str());
    std::printf("%s\n", SelectDispatcher().name().c_str());
    return 0;
}

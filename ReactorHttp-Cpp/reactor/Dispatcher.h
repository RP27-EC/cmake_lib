#pragma once
#include <string>

// IO 多路复用的基类，Epoll/Poll/Select 三个子类继承它
class Dispatcher
{
public:
    virtual ~Dispatcher() = default;
    virtual std::string name() const;
};

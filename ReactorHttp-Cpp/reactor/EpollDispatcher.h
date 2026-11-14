#pragma once
#include "Dispatcher.h"

class EpollDispatcher : public Dispatcher
{
public:
    std::string name() const override;
};

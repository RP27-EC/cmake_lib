#pragma once
#include "Dispatcher.h"

class PollDispatcher : public Dispatcher
{
public:
    std::string name() const override;
};

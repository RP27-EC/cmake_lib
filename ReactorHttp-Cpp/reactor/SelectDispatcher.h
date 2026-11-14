#pragma once
#include "Dispatcher.h"

class SelectDispatcher : public Dispatcher
{
public:
    std::string name() const override;
};

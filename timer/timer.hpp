#ifndef TIMER_HPP
#define TIMER_HPP

#include <bits/c++config.h>
#include <cstdint>
#include "hardware/timer.h"
#include "hardware_abstraction/timer/i_timer.hpp"

namespace hardware_layer
{
class Timer : public ITimer
{
   public:
    explicit Timer();
    ~Timer() = default;

    std::uint64_t get() override;
    void setAlarm(std::uint64_t alarm_value) override;
};

}  // namespace hardware_layer

#endif
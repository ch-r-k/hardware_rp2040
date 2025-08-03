#include "timer.hpp"

#include "hardware/structs/timer.h"
#include "hardware/timer.h"

namespace hardware_layer
{
Timer::Timer() { timer_hw->dbgpause = 0x00; }

std::uint64_t Timer::get() { return timer_time_us_64(timer_hw); }

void Timer::setAlarm(std::uint64_t alarm_value)
{
    uint64_t target = alarm_value;  // 3s
    timer_hw->alarm[0] = (uint32_t)target;
}

}  // namespace hardware_layer

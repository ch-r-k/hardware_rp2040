#include "timer.hpp"

#include "hardware/structs/timer.h"
#include "hardware/timer.h"

namespace hardware_layer
{
Timer::Timer() { timer_hw->dbgpause = 0x00; }

std::uint64_t Timer::get() { return timer_time_us_64(timer_hw); }

void Timer::setAlarm(std::uint32_t alarm_value)
{
    timer_hw->alarm[0] = alarm_value;
    timer_hw->inte = 1;
}

void Timer::clearInterrupt() { timer_hw->intr = 0; }

void Timer::notifyInterruptAcknowledge()
{
    hw_clear_bits(&timer_hw->intr, 1u << 0);
    timer_hw->intr = 0;
    clearInterrupt();
}

}  // namespace hardware_layer

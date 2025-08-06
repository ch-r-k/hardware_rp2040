#ifndef TIMER_HPP
#define TIMER_HPP

#include <bits/c++config.h>
#include <cstdint>
#include "hardware/timer.h"
#include "hardware_abstraction/interrupt_dispatcher/icb_interrupt_ack.hpp"
#include "hardware_abstraction/timer/i_timer.hpp"

namespace hardware_layer
{
class Timer : public ITimer, public IcbIntAcknowledge
{
   public:
    explicit Timer();
    ~Timer() = default;

    std::uint64_t get() override;
    void setAlarm(std::uint32_t alarm_value) override;

   private:
    void clearInterrupt();
    void notifyInterruptAcknowledge() override;
};

}  // namespace hardware_layer

#endif
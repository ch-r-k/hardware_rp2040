#include "interrupt_dispatcher.hpp"
#include <assert.h>
#include <bits/c++config.h>
#include <algorithm>
#include <cstdint>
#include <iterator>
#include "hardware/irq.h"
#include "hardware_abstraction/interrupt_dispatcher/icb_interrupt_ack.hpp"
#include "hardware_abstraction/interrupt_dispatcher/icb_interrupt_disp.hpp"
#include "hardware_rp2040/interrupt_dispatcher/nvic_types.hpp"

namespace hardware_layer
{
// IcbIntDispatcher* IntDispatcher::callbackObject[static_cast<std::size_t>(
//     IntVectorNumber::SIZE)];

// icbInterruptAcknowledge* cSTM32F7xxNVIC_Dispatcher::mptrAcknowledgeObject
//     [InterruptVectorNumberAmount];

std::array<IcbIntDispatcher*, static_cast<std::size_t>(IntVectorNumber::SIZE)>
    IntDispatcher::callbackObjectArray = {nullptr};

std::array<IcbIntAcknowledge*, static_cast<std::size_t>(IntVectorNumber::SIZE)>
    IntDispatcher::acknowledgeObjectArray = {nullptr};

void IntDispatcher::init(void)
{
    callbackObjectArray.fill(nullptr);
    acknowledgeObjectArray.fill(nullptr);
}

void IntDispatcher::registerIntAcknowledge(
    IcbIntAcknowledge* const int_ack_object,
    const IntVectorNumber int_vec_number)
{
    assert(int_ack_object != nullptr);
    acknowledgeObjectArray[static_cast<std::size_t>(int_vec_number)] =
        int_ack_object;
}

void IntDispatcher::registerIntCallback(IcbIntDispatcher* const int_call_object,
                                        const IntVectorNumber int_vec_number)
{
    assert(int_call_object != nullptr);
    callbackObjectArray[static_cast<std::size_t>(int_vec_number)] =
        int_call_object;
}

void IntDispatcher::unregisterIntAcknowledge(
    const IntVectorNumber int_vec_number)
{
    acknowledgeObjectArray[static_cast<std::size_t>(int_vec_number)] = nullptr;
}

void IntDispatcher::unregisterIntCallback(const IntVectorNumber int_vec_number)
{
    callbackObjectArray[static_cast<std::size_t>(int_vec_number)] = nullptr;
}

void IntDispatcher::TIMER_IRQ_0_Handler(void)
{
    const std::size_t int_vect_number{
        static_cast<std::size_t>(IntVectorNumber::TIMER_IRQ_0)};

    if (acknowledgeObjectArray[int_vect_number] != nullptr)
    {
        acknowledgeObjectArray[int_vect_number]->notifyInterruptAcknowledge();
    }

    if (callbackObjectArray[int_vect_number] != nullptr)
    {
        // call interrupt service
        callbackObjectArray[int_vect_number]->notifyInterruptService();
    }
}

void IntDispatcher::enable(const IntVectorNumber int_vec_number)
{
    irq_set_enabled(static_cast<size_t>(int_vec_number), true);
}

void IntDispatcher::disable(const IntVectorNumber int_vec_number)
{
    irq_set_enabled(static_cast<size_t>(int_vec_number), false);
}

}  // namespace hardware_layer

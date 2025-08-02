#include "interrupt_dispatcher.hpp"
#include <assert.h>
#include <bits/c++config.h>
#include <cstdint>
#include <iterator>
#include "hardware_abstraction/interrupt_dispatcher/icb_interrupt_ack.hpp"
#include "hardware_abstraction/interrupt_dispatcher/icb_interrupt_disp.hpp"
#include "hardware_rp2040/interrupt_dispatcher/nvic_types.hpp"

namespace hardware_layer
{
// IcbIntDispatcher* IntDispatcher::callbackObject[static_cast<std::size_t>(
//     IntVectorNumber::SIZE)];

// icbInterruptAcknowledge* cSTM32F7xxNVIC_Dispatcher::mptrAcknowledgeObject
//     [InterruptVectorNumberAmount];

void IntDispatcher::init(void)
{
    std::uint32_t locLoopCounter = 0;

    for (auto element : callbackObject)
    {
        element = nullptr;
    }

    for (auto element : acknowledgeObject)
    {
        element = nullptr;
    }
}

void IntDispatcher::registerIntAcknowledge(
    IcbIntAcknowledge* const int_ack_object,
    const IntVectorNumber int_vec_number)
{
    assert(int_ack_object != nullptr);
    acknowledgeObject[static_cast<std::size_t>(int_vec_number)] =
        int_ack_object;
}

void IntDispatcher::registerIntCallback(IcbIntDispatcher* const int_call_object,
                                        const IntVectorNumber int_vec_number)
{
    assert(int_call_object != nullptr);
    callbackObject[static_cast<std::size_t>(int_vec_number)] = int_call_object;
}

void IntDispatcher::unregisterIntAcknowledge(
    const IntVectorNumber int_vec_number)
{
    acknowledgeObject[static_cast<std::size_t>(int_vec_number)] = nullptr;
}

void IntDispatcher::unregisterIntCallback(const IntVectorNumber int_vec_number)
{
    callbackObject[static_cast<std::size_t>(int_vec_number)] = nullptr;
}

void IntDispatcher::TIMER_IRQ_0_Handler(void)
{
    const std::size_t int_vect_number{
        static_cast<std::size_t>(IntVectorNumber::TIMER_IRQ_0)};

    if (acknowledgeObject[int_vect_number] != nullptr)
    {
        acknowledgeObject[int_vect_number]->notifyInterruptAcknowledge();
    }

    if (callbackObject[int_vect_number] != nullptr)
    {
        // call interrupt service
        callbackObject[int_vect_number]->notifyInterruptService();
    }
}

}  // namespace hardware_layer

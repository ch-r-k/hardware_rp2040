#ifndef INTERRUPT_DISP
#define INTERRUPT_DISP
#include <bits/c++config.h>
#include <array>
#include "hardware_abstraction/interrupt_dispatcher/icb_interrupt_disp.hpp"
#include "hardware_abstraction/interrupt_dispatcher/icb_interrupt_ack.hpp"
#include "nvic_types.hpp"

namespace hardware_layer
{
class IntDispatcher : public IcbIntDispatcher, public IcbIntAcknowledge
{
   public:
    void notifyInterruptService(void) override;
    void notifyInterruptAcknowledge(void) override;

   public:
    static void init(void);

    static void registerIntCallback(IcbIntDispatcher* const int_call_object,
                                    const IntVectorNumber int_vec_number);
    static void unregisterIntCallback(const IntVectorNumber int_vec_number);

    static void registerIntAcknowledge(IcbIntAcknowledge* const int_call_object,
                                       const IntVectorNumber int_vec_number);
    static void unregisterIntAcknowledge(const IntVectorNumber int_vec_number);

    // NOLINTBEGIN
    static void TIMER_IRQ_0_Handler(void);
    static void TIMER_IRQ_1_Handler(void);
    static void TIMER_IRQ_2_Handler(void);
    static void TIMER_IRQ_3_Handler(void);
    static void PWM_IRQ_WRAP_Handler(void);
    static void USBCTRL_IRQ_Handler(void);
    static void XIP_IRQ_Handler(void);
    static void PIO0_IRQ_0_Handler(void);
    static void PIO0_IRQ_1_Handler(void);
    static void PIO1_IRQ_0_Handler(void);
    static void PIO1_IRQ_1_Handler(void);
    static void DMA_IRQ_0_Handler(void);
    static void DMA_IRQ_1_Handler(void);
    static void IO_IRQ_BANK0_Handler(void);
    static void IO_IRQ_QSPI_Handler(void);
    static void SIO_IRQ_PROC0_Handler(void);
    static void SIO_IRQ_PROC1_Handler(void);
    static void CLOCKS_IRQ_Handler(void);
    static void SPI0_IRQ_Handler(void);
    static void SPI1_IRQ_Handler(void);
    static void UART0_IRQ_Handler(void);
    static void UART1_IRQ_Handler(void);
    static void ADC_IRQ_FIFO_Handler(void);
    static void I2C0_IRQ_Handler(void);
    static void I2C1_IRQ_Handler(void);
    static void RTC_IRQ_Handler(void);
    // NOLINTEND

   private:
    static std::array<IcbIntDispatcher*,
                      static_cast<std::size_t>(IntVectorNumber::SIZE)>
        callbackObject;

    static std::array<IcbIntAcknowledge*,
                      static_cast<std::size_t>(IntVectorNumber::SIZE)>
        acknowledgeObject;
};

}  // namespace hardware_layer

#endif
#include "interrupt_dispatcher.hpp"

namespace hardware_layer
{
extern "C"
{
    void isr_irq0() { IntDispatcher::TIMER_IRQ_0_Handler(); }
    // void isr_irq1() { IntDispatcher::TIMER_IRQ_1_Handler(); }
    // void isr_irq2() { IntDispatcher::TIMER_IRQ_2_Handler(); }
    // void isr_irq3() { IntDispatcher::TIMER_IRQ_3_Handler(); }
    // void isr_irq4() { IntDispatcher::PWM_IRQ_WRAP_Handler(); }
    // void isr_irq5() { IntDispatcher::USBCTRL_IRQ_Handler(); }
    // void isr_irq6() { IntDispatcher::XIP_IRQ_Handler(); }
    // void isr_irq7() { IntDispatcher::PIO0_IRQ_0_Handler(); }
    // void isr_irq8() { IntDispatcher::PIO0_IRQ_1_Handler(); }
    // void isr_irq9() { IntDispatcher::PIO1_IRQ_0_Handler(); }
    // void isr_irq10() { IntDispatcher::PIO1_IRQ_1_Handler(); }
    // void isr_irq11() { IntDispatcher::DMA_IRQ_0_Handler(); }
    // void isr_irq12() { IntDispatcher::DMA_IRQ_1_Handler(); }
    // void isr_irq13() { IntDispatcher::IO_IRQ_BANK0_Handler(); }
    // void isr_irq14() { IntDispatcher::IO_IRQ_QSPI_Handler(); }
    // void isr_irq15() { IntDispatcher::SIO_IRQ_PROC0_Handler(); }
    // void isr_irq16() { IntDispatcher::SIO_IRQ_PROC1_Handler(); }
    // void isr_irq17() { IntDispatcher::CLOCKS_IRQ_Handler(); }
    // void isr_irq18() { IntDispatcher::SPI0_IRQ_Handler(); }
    // void isr_irq19() { IntDispatcher::SPI1_IRQ_Handler(); }
    // void isr_irq20() { IntDispatcher::UART0_IRQ_Handler(); }
    // void isr_irq21() { IntDispatcher::UART1_IRQ_Handler(); }
    // void isr_irq22() { IntDispatcher::ADC_IRQ_FIFO_Handler(); }
    // void isr_irq23() { IntDispatcher::I2C0_IRQ_Handler(); }
    // void isr_irq24() { IntDispatcher::I2C1_IRQ_Handler(); }
    // void isr_irq25() { IntDispatcher::RTC_IRQ_Handler(); }

}  // extern "C"

}  // namespace hardware_layer
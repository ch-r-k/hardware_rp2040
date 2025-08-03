#include "interrupt_dispatcher.hpp"

namespace hardware_layer
{
extern "C"
{
    void isr_timer_0() { IntDispatcher::TIMER_IRQ_0_Handler(); }
    void isr_timer_1() { IntDispatcher::TIMER_IRQ_1_Handler(); }
    void isr_timer_2() { IntDispatcher::TIMER_IRQ_2_Handler(); }
    void isr_timer_3() { IntDispatcher::TIMER_IRQ_3_Handler(); }

    void isr_pwm_wrap() { IntDispatcher::PWM_IRQ_WRAP_Handler(); }

    void isr_usbctrl() { IntDispatcher::USBCTRL_IRQ_Handler(); }
    void isr_xip() { IntDispatcher::XIP_IRQ_Handler(); }

    void isr_pio0_0() { IntDispatcher::PIO0_IRQ_0_Handler(); }
    void isr_pio0_1() { IntDispatcher::PIO0_IRQ_1_Handler(); }
    void isr_pio1_0() { IntDispatcher::PIO1_IRQ_0_Handler(); }
    void isr_pio1_1() { IntDispatcher::PIO1_IRQ_1_Handler(); }

    void isr_dma_0() { IntDispatcher::DMA_IRQ_0_Handler(); }
    void isr_dma_1() { IntDispatcher::DMA_IRQ_1_Handler(); }

    void isr_io_irq_bank0() { IntDispatcher::IO_IRQ_BANK0_Handler(); }
    void isr_io_irq_qspi() { IntDispatcher::IO_IRQ_QSPI_Handler(); }

    void isr_sio_proc0() { IntDispatcher::SIO_IRQ_PROC0_Handler(); }
    void isr_sio_proc1() { IntDispatcher::SIO_IRQ_PROC1_Handler(); }

    void isr_clocks() { IntDispatcher::CLOCKS_IRQ_Handler(); }

    void isr_spi0() { IntDispatcher::SPI0_IRQ_Handler(); }
    void isr_spi1() { IntDispatcher::SPI1_IRQ_Handler(); }

    void isr_uart0() { IntDispatcher::UART0_IRQ_Handler(); }
    void isr_uart1() { IntDispatcher::UART1_IRQ_Handler(); }

    void isr_adc_fifo() { IntDispatcher::ADC_IRQ_FIFO_Handler(); }

    void isr_i2c0() { IntDispatcher::I2C0_IRQ_Handler(); }
    void isr_i2c1() { IntDispatcher::I2C1_IRQ_Handler(); }

    void isr_rtc() { IntDispatcher::RTC_IRQ_Handler(); }

}  // extern "C"

}  // namespace hardware_layer
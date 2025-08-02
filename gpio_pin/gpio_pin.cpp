#include "gpio_pin.hpp"
#include <cstdint>
#include "common.hpp"

namespace hardware_layer
{
GpioPin::GpioPin(Port initPort, uint8_t initPin, Mode initMode, Pull initPull,
                 Speed initSpeed, Function initFunction)
{
    configure(initPort, initPin, initMode, initPull, initSpeed, initFunction);
}

void GpioPin::configure(Port initPort, uint8_t initPin, Mode initMode,
                        Pull initPull, Speed initSpeed, Function initFunction)
{
    UNUSED(initPort);
    UNUSED(initSpeed);

    pin = initPin;
    mode = initMode;
    pull = initPull;
    function = initFunction;

    gpio_set_dir(static_cast<uint8_t>(pin), static_cast<uint8_t>(initMode));

    switch (initPull)
    {
        case Pull::NONE:
            gpio_set_pulls(static_cast<uint8_t>(initPin), false, false);
            break;
        case Pull::UP:
            gpio_set_pulls(static_cast<uint8_t>(initPin), true, false);
            break;

        case Pull::DOWN:
            gpio_set_pulls(static_cast<uint8_t>(initPin), false, true);
            break;
    }

    gpio_set_function(static_cast<uint8_t>(initPin),
                      static_cast<gpio_function_t>(initFunction));
}

void GpioPin::set() { gpio_put(static_cast<uint8_t>(pin), 1); }

void GpioPin::reset() { gpio_put(static_cast<uint8_t>(pin), 0); }

bool GpioPin::get() { return gpio_get(static_cast<uint8_t>(pin)); }

}  // namespace hardware_layer
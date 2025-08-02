set(ARCH_FLAGS 
    -mthumb
    -mcpu=cortex-m0plus
)

set(FEATURE_FLAGS
    -ffunction-sections
    -fdata-sections
    -fno-exceptions
)

set(DEVICE_DEFINES
    PICO_RP2040
)

add_compile_definitions(${DEVICE_DEFINES})

set(ASM_FLAGS_LIST "${ARCH_FLAGS}")
set(COMPILE_FLAGS_LIST "${ARCH_FLAGS} ${FEATURE_FLAGS}")
set(EXE_LINKER_FLAGS_LIST
    ${ARCH_FLAGS}
    -Wl,--print-memory-usage
    -Wl,-Map,${PROJECT}.map
    -Wl,--gc-sections
    -Xlinker
)

list(JOIN ASM_FLAGS_LIST " " ASM_FLAGS)
list(JOIN COMPILE_FLAGS_LIST " " COMPILE_FLAGS)
list(JOIN EXE_LINKER_FLAGS_LIST " " EXE_LINKER_FLAGS)

string(APPEND CMAKE_ASM_FLAGS " ${ASM_FLAGS}")
string(APPEND CMAKE_C_FLAGS " ${COMPILE_FLAGS}")
string(APPEND CMAKE_CXX_FLAGS " ${COMPILE_FLAGS} -fno-rtti")
string(APPEND CMAKE_EXE_LINKER_FLAGS " ${EXE_LINKER_FLAGS}")
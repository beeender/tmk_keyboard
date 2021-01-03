#include "os/os.h"

uint16_t timer_read(void)
{
    return os_cputime_get32() & 0xffff;
}

uint32_t timer_read32(void)
{
    return os_cputime_get32();
}

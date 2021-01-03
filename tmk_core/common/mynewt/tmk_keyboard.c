#include "os/os.h"
#include "os/os_callout.h"
#include "hal/hal_system.h"
#include "hal/hal_watchdog.h"
#include "assert.h"

#include "matrix.h"
#include "keyboard.h"

#define KEYBOARD_STACK_SIZE OS_STACK_ALIGN(256)
#define KEYBOARD_TASK_PRIO (150)

extern void driver_init(void);

static struct os_callout callout;

static void
keyboard_handler(struct os_event *ev)
{
    keyboard_task();
    hal_watchdog_tickle();
    os_callout_reset(&callout, 100);
}

void
tmk_keyboard_init()
{
    //os_stack_t *keyboard_stack;

    matrix_setup();
    matrix_init();
    driver_init();

    os_callout_init(&callout, os_eventq_dflt_get(),
                    keyboard_handler, NULL);
    os_callout_reset(&callout, 100);
}

void
bootloader_jump()
{
    os_reboot(HAL_RESET_REQUESTED);
}

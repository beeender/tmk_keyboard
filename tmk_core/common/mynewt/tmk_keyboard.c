#include "os/os.h"
#include "hal/hal_system.h"
#include "hal/hal_watchdog.h"
#include "assert.h"

#include "matrix.h"
#include "keyboard.h"

#define KEYBOARD_STACK_SIZE OS_STACK_ALIGN(256)
#define KEYBOARD_TASK_PRIO (150)

extern void driver_init(void);

static struct os_task tmk_keyboard_task;
static void keyboard_task_handler(void *arg);

void tmk_keyboard_init()
{
    os_stack_t *keyboard_stack;

    matrix_setup();
    matrix_init();
    driver_init();

    keyboard_stack = malloc(sizeof(os_stack_t) * KEYBOARD_STACK_SIZE);
    assert(keyboard_stack);

    os_task_init(&tmk_keyboard_task, "keyboard", keyboard_task_handler, NULL,
            KEYBOARD_TASK_PRIO, OS_WAIT_FOREVER, keyboard_stack,
            KEYBOARD_STACK_SIZE);
}

void
keyboard_task_handler(void *arg)
{
    while (1) {
        keyboard_task();
        hal_watchdog_tickle();
    }
}

void
bootloader_jump()
{
    os_reboot(HAL_RESET_REQUESTED);
}

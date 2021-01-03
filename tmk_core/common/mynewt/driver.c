#include "host.h"
#include "report.h"
#include "tusb.h"

static uint8_t keyboard_leds(void);
static void send_keyboard(report_keyboard_t *);
static void send_mouse(report_mouse_t *);
static void send_system(uint16_t);
static void send_consumer(uint16_t);

static host_driver_t driver = {
    .keyboard_leds = keyboard_leds,
    .send_keyboard = send_keyboard,
    .send_mouse = send_mouse,
    .send_system = send_system,
    .send_consumer = send_consumer
};

static uint8_t
keyboard_leds(void)
{
    return 0;
}

extern int hid_send_keyboard_report(const void* report, size_t report_size);

static void
send_keyboard(report_keyboard_t *report)
{
    //tud_hid_report(0, report, sizeof(report_keyboard_t));
    hid_send_keyboard_report(report, sizeof(report_keyboard_t));
}

static void
send_mouse(report_mouse_t *report)
{
}

static void
send_system(uint16_t data)
{
}

static void
send_consumer(uint16_t data)
{
}

void
driver_init(void){
    host_set_driver(&driver);
}

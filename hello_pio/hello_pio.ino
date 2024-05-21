#include <hardware/pio.h>

// Our assembled program:
#include "hello.pio.h"

PIO pio = pio0;
uint offset;
uint sm;

void setup() {
  offset = pio_add_program(pio, &hello_program);
  sm = pio_claim_unused_sm(pio, true);
  hello_program_init(pio, sm, offset, PICO_DEFAULT_LED_PIN);
}

void loop() {
  // put your main code here, to run repeatedly:
  pio_sm_put_blocking(pio, sm, 1);
  sleep_ms(5000);
  pio_sm_put_blocking(pio, sm, 0);
  sleep_ms(5000);
}
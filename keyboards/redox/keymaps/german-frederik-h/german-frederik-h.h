#pragma once

#include "quantum.h"
#include "process_keycode/process_tap_dance.h"

typedef struct {
  bool is_press_action;
  int state;
} tap;

enum {
  HOLD = 1,
  SINGLE_TAP = 2,
  DOUBLE_TAP = 3,
  TRIPLE_TAP = 4,
  QUAD_TAP = 5
};


enum {
  SPL_O = 0,
  SPL_C = 1,
  SOME_OTHER_DANCE
};

/* int cur_dance (qk_tap_dance_state_t *state); */
/* void spl_o_finished (qk_tap_dance_state_t *state, void *user_data); */
/* void spl_o_reset (qk_tap_dance_state_t *state, void *user_data); */

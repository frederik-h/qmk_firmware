#include "quantum.h"
#include "action.h"
#include "process_keycode/process_tap_dance.h"
#include "keymap_german.h"
#include "ext-space-cadet.h"

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

int cur_dance (qk_tap_dance_state_t *state) {
  if(state->pressed)
    return HOLD;
  
  if (state->count == 1)
    return SINGLE_TAP;

  if (state->count == 2)
    return DOUBLE_TAP;

  if (state->count == 3)
    return TRIPLE_TAP;

  if (state->count == 4)
    return QUAD_TAP;

   return -1;
}

static int sc_o_tap_state = 0;
static int sc_c_tap_state = 0;


void sc_o_finished (qk_tap_dance_state_t *state, void *user_data) {
  sc_o_tap_state = cur_dance(state);
  switch (sc_o_tap_state) {
  case SINGLE_TAP:
    register_mods(MOD_BIT(KC_LSFT));
    register_code(KC_8); // (
    break;
  case DOUBLE_TAP:
    unregister_code(KC_8);
    register_mods(MOD_BIT(KC_RALT));
    register_code(KC_7); // {
    break;
  case TRIPLE_TAP:
    unregister_code(KC_7);
    register_mods(MOD_BIT(KC_RALT));
    register_code(KC_8); // [
    break;
  case QUAD_TAP:
    unregister_code(KC_8);
    unregister_mods(MOD_BIT(KC_RALT));
    register_code(KC_NUBS); // <
    break;
  case HOLD:
    register_mods(MOD_BIT(KC_LSFT));
  }
}

void sc_o_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (sc_o_tap_state) {
  case SINGLE_TAP:
    unregister_code(KC_8);
    unregister_mods(MOD_BIT(KC_LSFT));
    break;
  case DOUBLE_TAP:
    unregister_code(KC_7); // {
    unregister_mods(MOD_BIT(KC_RALT));
    break;
  case TRIPLE_TAP:
    unregister_code(KC_8); // [
    unregister_mods(MOD_BIT(KC_RALT));
    break;
  case QUAD_TAP:
    unregister_code(KC_NUBS); // <
    break;
  case HOLD:
    unregister_mods(MOD_BIT(KC_LSFT));
    break;
  }
  sc_o_tap_state = 0;
}


void sc_c_finished (qk_tap_dance_state_t *state, void *user_data) {
  sc_c_tap_state = cur_dance(state);
  switch (sc_c_tap_state) {
  case SINGLE_TAP:
    register_mods(MOD_BIT(KC_LSFT));
    register_code(KC_9); // )
    break;
  case DOUBLE_TAP:
    unregister_code(KC_9);
    register_mods(MOD_BIT(KC_RALT));
    register_code(KC_0); // }
    break;
  case TRIPLE_TAP:
    unregister_code(KC_0);
    register_mods(MOD_BIT(KC_RALT));
    register_code(KC_9); // ]
    break;
  case QUAD_TAP:
    unregister_code(KC_9);
    unregister_mods(MOD_BIT(KC_RALT));
    register_mods(MOD_BIT(KC_LSFT));
    register_code(KC_NUBS); // <
    break;
  case HOLD:
    register_mods(MOD_BIT(KC_LSFT));
  }
}

void sc_c_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (sc_c_tap_state) {
  case SINGLE_TAP:
    unregister_code(KC_9); // )
    unregister_mods(MOD_BIT(KC_LSFT));
    break;
  case DOUBLE_TAP:
    unregister_code(KC_0); // }
    unregister_mods(MOD_BIT(KC_RALT));
    break;
  case TRIPLE_TAP:
    unregister_code(KC_9); // ]
    unregister_mods(MOD_BIT(KC_RALT));
    break;
  case QUAD_TAP:
    unregister_code(KC_NUBS); // >
    unregister_mods(MOD_BIT(KC_RALT));
    unregister_mods(MOD_BIT(KC_LSFT));
    break;
  case HOLD:
    unregister_mods(MOD_BIT(KC_LSFT));
    break;
  }
  sc_c_tap_state = 0;
}


qk_tap_dance_action_t tap_dance_actions[] = {
  [SC_O] = ACTION_TAP_DANCE_FN_ADVANCED(NULL,sc_o_finished, sc_o_reset),
  [SC_C] = ACTION_TAP_DANCE_FN_ADVANCED(NULL,sc_c_finished, sc_c_reset),
};

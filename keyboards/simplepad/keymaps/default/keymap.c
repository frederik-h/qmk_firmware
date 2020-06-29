#include QMK_KEYBOARD_H
#include "keymap_german.h"

#define LAYER_DEFAULT 0

/* A layer for using a debugger. The keys are set up
   for Emacs GUD (cf. function process_recorder_user) .*/
#define LAYER_DEBUGGER 1

enum debugger_keycodes {
    DBG_BREAK = SAFE_RANGE,
    DBG_BREAK_DEL = SAFE_RANGE + 1,
    DBG_NEXT = SAFE_RANGE + 2,
    DBG_STEP = SAFE_RANGE + 3,
    DBG_CONT = SAFE_RANGE + 4,
    DBG_STACK_DOWN = SAFE_RANGE + 5,
    DBG_STACK_UP = SAFE_RANGE + 6,
    DBG_FIN = SAFE_RANGE + 7
};

enum tapdance_keycodes {
    TD_SLEEP,
    TD_RESET
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [LAYER_DEFAULT] = LAYOUT(
	TO(LAYER_DEBUGGER), TD(TD_SLEEP), TD(TD_RESET),
	KC_MY_COMPUTER, KC_MAIL, KC_CALCULATOR,
	KC_MEDIA_PREV_TRACK, KC_MEDIA_PLAY_PAUSE, KC_MEDIA_NEXT_TRACK,
	KC_AUDIO_MUTE),

    [LAYER_DEBUGGER] = LAYOUT(
	TO(LAYER_DEFAULT), DBG_BREAK, DBG_BREAK_DEL,
	DBG_CONT, DBG_STEP, DBG_NEXT,
	DBG_CONT, DBG_STEP, DBG_NEX,
	DBG_FIN)

};

qk_tap_dance_action_t tap_dance_actions[] = {
    /* Require two presses to avoid unintentional activation.  */
    [TD_SLEEP] = ACTION_TAP_DANCE_DOUBLE(KC_NO, KC_SYSTEM_SLEEP),
    /* FIXME RESET does not work with tap dance!? */
    [TD_RESET] = ACTION_TAP_DANCE_DOUBLE(KC_NO, RESET)
};

void encoder_update_user(uint8_t index, bool clockwise) {
  if (layer_state_is(LAYER_DEFAULT)) {
    if (clockwise)
      tap_code(KC_AUDIO_VOL_UP);
    else
      tap_code(KC_AUDIO_VOL_DOWN);
  }
  else if (layer_state_is(LAYER_DEBUGGER)) {
    /* We cannot use SEND_STRING which does not send the
       correct key codes for a German keyboard layout.
       tap_code16 is necessary because DE_LESS uses modifier. */
    if (clockwise) {
      tap_code16(C(DE_X));
      tap_code16(C(DE_A));
      tap_code16(DE_LESS);
    } else {
      tap_code16(C(DE_X));
      tap_code16(C(DE_A));
      tap_code16(DE_MORE);
    }
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case DBG_BREAK:
    if (record->event.pressed)
      SEND_STRING(SS_LCTL("xab"));
    break;
  case DBG_BREAK_DEL:
    if (record->event.pressed)
      SEND_STRING(SS_LCTL("xad"));
    break;
  case DBG_NEXT:
    if (record->event.pressed)
      SEND_STRING(SS_LCTL("xan"));
    break;
  case DBG_STEP:
    if (record->event.pressed)
      SEND_STRING(SS_LCTL("xas"));
    break;
  case DBG_CONT:
    if (record->event.pressed)
      SEND_STRING(SS_LCTL("xar"));
    break;
  case DBG_FIN:
    if (record->event.pressed)
      tap_code16(C(DE_C));
    tap_code16(C(DE_F));
    break;

  }
  return true;
};

#define LED0 B0
#define LED1 D5

/* Toggle LEDs on layer change. */
layer_state_t layer_state_set_user(layer_state_t state) {
  int layer = get_highest_layer(state);

  if (layer == LAYER_DEBUGGER)
    writePin(LED0, 0);
  else if (layer == LAYER_DEFAULT)
    writePin(LED0, 1);

  return state;
}

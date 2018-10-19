#include QMK_KEYBOARD_H
#include "keymap_german.h"
#include "ext-space-cadet.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _SYMB 1
#define _NAV 2

#define DEBUG 1


enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  SYMB,
  NAV
};

// Fillers to make layering more clear
#define KC_ KC_TRNS
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,---------------------------------------------------.            ,----------------------------------------------------.
 * |^/Lyr2|   1  |   2  |   3  |   4   |   5   | Lyr1  |            | Lyr1  |   6   |   7    |   8  |   9  |   0  |--Lyr2|
 * |------+------+------+------+-------+-------+-------|            |-------+-------+--------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R   |   T   |  ESC  |            |   /   |   Y   |   U    |   I  |   O  |   P  |   =  |
 * |------+------+------+------+-------+-------+-------|            |-------+-------+--------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F   |   G   | PgUp  |            | End   |   H   |   J    |   K  |   L  |   Ö  |   Ä  |
 * |------+------+------+------+-------+-------+-------|            |-------+-------+--------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V   |   B   | PgDn  |            | Home  |   N   |   M    |   ,  |   .  |   -  |Shift |
 * |------+------+------+------+-------+-------+-------|            |-------+-------+--------+------+------+------+------|
 * |  Gui |   <  |   #  |  GUI |Alt/Bck|Ctl/Spc|Sft/Ent|            |Sft/Ent|Ctl/Spc|Alt/Del | Left | Down |  Up  | Right|
 * `---------------------------------------------------'            `----------------------------------------------------'
 */
  [_QWERTY] = LAYOUT(
  //,----+----+----+----+----+----+----.                                                         ,----+----+----+----+----+----+----.
     LT(_NAV, DE_CIRC) , DE_1  , DE_2  , DE_3  , DE_4  , DE_5  ,MO(_SYMB),                           MO(_SYMB), DE_6  , DE_7  , DE_8  , DE_9  , DE_0  ,LT(_NAV, DE_SS),
  //|----+----+----+----+----+----+----|                                                         |----+----+----+----+----+----+----|
     KC_ESC , DE_Q  , DE_W  , DE_E  , DE_R  , DE_T  , KC_ESC,                                       DE_SLSH, DE_Z  , DE_U  , DE_I  , DE_O  , DE_P  , DE_UE,
  //|----+----+----+----+----+----+----|                                                         |----+----+----+----+----+----+----|
     KC_TAB , DE_A  , DE_S  , DE_D  , DE_F  , DE_G  , LT(_NAV, KC_PGDN),                         LT(_NAV, KC_HOME) , DE_H  , DE_J  , DE_K  , DE_L  , DE_OE , DE_AE,
  //|----+----+----+----+----+----+----|                                                         |----+----+----+----+----+----+----|
     TD(SC_O),  DE_Y  , DE_X  , DE_C  , DE_V  , DE_B  ,LT(_SYMB, KC_PGUP),                         LT(_SYMB, KC_END) , DE_N  , DE_M  , DE_COMM, DE_DOT , DE_MINS , TD(SC_C),
  //|----+----+----+----+----+----+----|                                                         |----+----+----+----+----+----+----|
     KC_LGUI , DE_LESS , DE_HASH , LGUI_T(DE_PLUS), LALT_T(KC_BSPC), KC_SPC , LCTL_T(KC_ENT) ,     RCTL_T(KC_ENT) , KC_SPC, ALGR_T(KC_DEL) , KC_LEFT, KC_DOWN, KC_UP , KC_RGHT
  //`----+----+----+----+----+----+----'                                                         `----+----+----+----+----+----+----'
  ),

/* Symbols
 * ,------------------------------------------------.      ,------------------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |      |      |      |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+-----+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      |   !  |   @  |   {  |   }  |   |  |      |      |      |      |   1  |   2  |   3  |      | F12  |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      |   #  |   $  |   [  |   ]  |   ~  |      |      |      |      |   4  |   5  |   6  |      |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * | Shift|   %  |   ^  |   (  |   )  |   ´  |      |      |      |      |   7  |   8  |   9  |      |Shift |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      |      |      | Alt  | Ctrl |      |      |      |      |      |   0  |   0  |   .  |      |      |
 * `------------------------------------------------'      `------------------------------------------------'
 */

  [_SYMB] = LAYOUT(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,                             _______, KC_F6,    KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    _______, DE_EXLM, DE_AT ,  DE_LCBR, DE_RCBR, DE_PIPE, _______,                             _______, XXXXXXX,  DE_1, DE_2, DE_3, XXXXXXX, KC_F12,
    _______, DE_HASH, DE_DLR , DE_LBRC, DE_RBRC, DE_TILD,  _______,                            _______, XXXXXXX,  DE_4, DE_5, DE_6, XXXXXXX, XXXXXXX,
    _______, DE_PERC, DE_CIRC, DE_LPRN, DE_RPRN, DE_ACUT, _______,                             _______, XXXXXXX,  DE_7, DE_8, DE_9, XXXXXXX, _______,
    _______, _______, _______, KC_LALT, KC_LCTL, _______, _______,                             _______, _______,  _______, DE_0, KC_PDOT, XXXXXXX, XXXXXXX
  ),

/* Navigation
 * ,------------------------------------------------.      ,------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      |      |MOUS_U|      |WHEL_U|      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      |MOUS_L|MOUS_D|MOUS_R|WHEL_D|      |      |      |      | LEFT | DOWN |  UP  |RIGHT |      |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      |      |      |      |MOUS_1|MOUS_2|      |      |      |      |      | Home | PgDn | PgUp | End  |
 * `------------------------------------------------'      `------------------------------------------------'
 */
  [_NAV] = LAYOUT(
    _______, _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______, _______,
    XXXXXXX, XXXXXXX, KC_MS_U, XXXXXXX, KC_WH_U, XXXXXXX, _______,                            _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END, XXXXXXX, XXXXXXX,
    XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, XXXXXXX, _______,                            _______, KC_LEFT, KC_DOWN, KC_UP  , KC_RIGHT,XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,                            _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BTN1, KC_BTN2, _______,                            _______, _______, XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP, KC_END
  )
};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}


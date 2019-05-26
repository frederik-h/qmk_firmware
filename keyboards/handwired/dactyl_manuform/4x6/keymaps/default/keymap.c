/* A standard layout for the Dactyl Manuform 4x6 Keyboard */

#include QMK_KEYBOARD_H
#include "4x6.h"
#include "keymap_german.h"
extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _SYMB 1
#define _NAV 2
#define _MOUSE 3
#define _NUM 4

#define LAG(kc) LALT(LGUI(kc))
#define LCG(kc) LCTL(LGUI(kc))
#define LTM(kc) LT(_MOUSE, kc)
#define LTN(kc) LT(_NUM, kc)
#define TTSPEC OSL(_SPECIAL)

#define ALT_ENT LALT_T(KC_ENT)
#define NAV_BSPC LT(_NAV, KC_BSPC)
#define SYMB_SPC LT(_SYMB, KC_SPC)
#define CTL_ENT LCTL_T(KC_ENT)
#define SFT_SPC MT(MOD_RSFT, KC_SPC)
#define MOUS_TAB LT(_MOUSE, KC_TAB)
#define NUM_TAB LT(_NUM, KC_TAB)

#define _______ KC_TRNS



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  
  [_QWERTY] = LAYOUT_4x6(
     MOUS_TAB , DE_Q  , DE_W  , DE_E  , DE_R  , DE_T ,                         DE_Z  , DE_U  , DE_I    ,  DE_O  , DE_P    , KC_MINS,
     MOUS_TAB, DE_A  , DE_S  , DE_D  , DE_F  , DE_G ,                        DE_H  , DE_J  , DE_K    ,  DE_L  , KC_ESC  , MO(_SYMB),
     KC_LSFT, DE_Y  , DE_X  , DE_C  , DE_V  , DE_B ,                         DE_N  , DE_M  , DE_COMM , DE_DOT , DE_MINS , MOD_RSFT,
                      KC_LBRC,KC_RBRC,                                                       KC_PLUS, KC_EQL,
                                      NAV_BSPC, ALT_ENT,                     SFT_SPC, SYMB_SPC, 
                                        NUM_TAB,KC_HOME,                    CTL_ENT,  KC_DEL,
                                          KC_BSPC, KC_GRV,               KC_LGUI, KC_LALT
			 ),  
     [_SYMB] = LAYOUT_4x6(
     _______,DE_AT  , DE_DQOT, DE_LCBR, DE_RCBR, DE_QUOT,                    DE_EXLM, DE_QST , DE_SLSH, DE_BSLS, XXXXXXX ,KC_PLUS,
     _______,DE_CIRC, DE_DLR , DE_LPRN, DE_RPRN, DE_TILD,                    DE_LESS, DE_EQL , DE_PLUS, DE_ASTR, XXXXXXX ,KC_PIPE,
     _______,DE_HASH, DE_PERC, DE_LBRC, DE_RBRC, DE_ACUT,                    DE_MORE, DE_AMPR, DE_PIPE, _______, _______ ,KC_UNDS,
                      _______,_______,                                                         _______,_______,
                                        _______,_______,                     _______,_______,
                                          _______,_______,                _______,_______,
                                            _______,_______,           _______,_______

  ),
  [_NUM] = LAYOUT_4x6(
     _______,_______, _______, _______, _______, _______,                    DE_7   ,  DE_8   , DE_9   , _______, DE_LESS, DE_MORE,
     _______,_______, _______, _______, _______, _______,                    DE_4   ,  DE_5   , DE_6   , DE_PLUS, DE_ASTR, XXXXXXX,
     _______,_______, _______, _______, _______, _______,                    DE_1   ,  DE_2   , DE_3   , DE_0   , _______, _______,
                      _______, _______,                                                         _______,_______,
                                        _______,_______,                     _______,_______,
                                          _______,_______,                _______,_______,
                                            _______,_______,           _______,_______

  ),
     

     
  [_NAV] = LAYOUT_4x6(
       RESET  , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5     ,               KC_HOME, KC_PGDN, KC_PGUP, KC_END  , XXXXXXX, KC_PSCR,
       _______, KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10    ,               KC_LEFT, KC_DOWN, KC_UP  , KC_RIGHT, LGUI(KC_UP), _______,
       _______, _______, _______, _______, KC_F11 , KC_F12    ,               LCG(KC_LEFT), LAG(KC_LEFT), LAG(KC_RGHT), LCG(KC_RGHT), LGUI(KC_DOWN), _______,
                                               _______,_______,            KC_EQL ,_______,
                                               _______,_______,            _______,_______,
                                               _______,_______,            _______,_______,
                                               _______,_______,            _______,_______
  ),

  [_MOUSE] = LAYOUT_4x6(
       _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,                _______, KC_WH_D, KC_WH_U, _______, _______, _______,
       _______, KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 ,                KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, _______,
       _______, _______, _______, _______, KC_F11 , KC_F12 ,                _______, _______, _______,_______ , _______, _______,
 
                                               _______,_______,                               KC_BTN3,KC_BTN2,
                                               _______,_______,                      KC_BTN3,KC_BTN2,
                                               _______,_______,                   _______,_______,
                                               _______,_______,                 _______,_______
  )

};



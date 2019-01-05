#include QMK_KEYBOARD_H
#include "action_layer.h"
#include "action_util.h"
#include "debug.h"
#include "eeconfig.h"
#include "version.h"
#include "wait.h"

enum custom_keycodes {
    M_CENTR = SAFE_RANGE,
    M_RIGHT,
    M_LEFT,
    M_BIGER,
    M_SMLER,
    M_FULSC,
    M_REG1,
    M_REG2,
    M_GCOMM,
    M_GSEMI,
};

enum {
    TD_QUOT,
};

#define ESC_CTL LCTL_T(KC_ESC)
#define ENT_CTL LCTL_T(KC_ENT)
#define MIN_GUI LGUI_T(KC_MINS)
#define EQL_GUI RGUI_T(KC_EQL)
#define KC_TDQT TD(TD_QUOT)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [0] = LAYOUT_ergodox(
               KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    M_REG1,
               KC_TAB , KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    M_GSEMI,
               ESC_CTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,
               KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LALT,
               OSL(1) , M_LEFT , M_CENTR, M_FULSC, M_RIGHT,
                                 KC_PGDN, KC_PGUP,
                                          KC_INS,
                        KC_ENT , MIN_GUI, KC_DEL,                    
               M_REG2,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS,
               M_GCOMM, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
                        KC_H,    KC_J,    KC_K,    KC_L   , KC_SCLN, ENT_CTL,
               KC_RALT, KC_N,    KC_M,    KC_COMM, KC_DOT , KC_SLSH, KC_RSFT,
                                 KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, OSL(1) ,
                                          KC_HOME, KC_END ,
                                          TG(2),
                                          KC_PSCR, EQL_GUI , KC_SPC),

  [2] = LAYOUT_ergodox(
               _______, _______, _______, _______, _______, _______, KC_UNDS,
               _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_LCBR,
               _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
               _______, _______, _______, _______, KC_F11,  KC_F12,  _______,
               _______, _______, _______, _______, _______,
                                 _______, _______,
                                          _______,
                        _______, _______, _______,
               KC_PLUS, _______, _______, _______, _______, _______,  _______,
               KC_RCBR, _______, _______, _______, _______, _______, _______,
                        _______, _______, _______, _______, KC_DQUO, _______,
               _______, _______, _______, _______, _______, _______, _______,
               _______, _______, _______, _______, _______,
                                          _______, _______,
                                          _______,
                                          _______, _______, _______),

  [1] = LAYOUT_ergodox(
               _______, _______, _______, _______, _______, _______, _______,
               _______, _______, _______, _______, _______, _______, _______,
               _______, KC_QUOT, KC_LBRC, KC_LCBR, KC_LPRN, _______,
               _______, _______, _______, _______, _______, _______, _______,
               _______, _______, _______, _______, _______,
                                 _______, _______,
                                          _______,
                        _______, _______, _______,
               _______, _______, _______, _______, _______, _______, _______,
               _______, _______, _______, _______, _______, _______, _______,
                        _______, KC_RPRN, KC_RCBR, KC_RBRC, KC_DQUO, _______,
               _______, _______, _______, _______, _______, _______, _______,
               _______, _______, _______, _______, _______,
                                          _______, _______,
                                          _______,
                                          _______, _______, _______),
};

const uint16_t PROGMEM fn_actions[] = {
  [1] = ACTION_LAYER_TAP_TOGGLE(1)
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_QUOT] = ACTION_TAP_DANCE_DOUBLE(KC_QUOTE, KC_DQUO),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
  switch(keycode) {
    // case CTL_FN_LAYER:
    // if (record->event.pressed) {
    //    layer_invert(1);
    //    register_mods(MOD_BIT(KC_LCTL));
    //    return MACRO_NONE;
    // } else {
    //    layer_invert(1);
    //    unregister_mods(MOD_BIT(KC_LCTL));
    //    return MACRO_NONE; 
    //}
    case M_CENTR:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT(SS_LGUI(SS_TAP(X_C))));
        return false;   
      } 
      break;
    case M_RIGHT:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT(SS_LGUI(SS_TAP(X_RIGHT))));
        return false;
      } 
      break;
    case M_LEFT:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT(SS_LGUI(SS_TAP(X_LEFT))));
        return false;
      } 
      break;
    case M_BIGER:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT(SS_LCTRL(SS_LSFT(SS_TAP(X_RIGHT)))));
        return false;
      } 
      break;
    case M_SMLER:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT(SS_LCTRL(SS_LSFT(SS_TAP(X_LEFT)))));
        return false;
      } 
      break;
    case M_FULSC:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL(SS_LGUI(SS_TAP(X_F))));
        return false;
      } 
      break;
    case M_REG1:
      if (record->event.pressed) {
        SEND_STRING("\"b");
        return false;
      } 
      break;
    case M_REG2:
      if (record->event.pressed) {
        SEND_STRING("\"*");
        return false;
      } 
      break;
    case M_GCOMM:
      if (record->event.pressed) {
        SEND_STRING("g,");
        return false;
      } 
      break;
    case M_GSEMI:
      if (record->event.pressed) {
        SEND_STRING("g;");
        return false;
        // this is a test
        //
      } 
      break;
  }
  return true;
};

void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        case 3:
            ergodox_right_led_3_on();
            break;
        case 4:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            break;
        case 5:
            ergodox_right_led_1_on();
            ergodox_right_led_3_on();
            break;
        case 6:
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
        case 7:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
        default:
            break;
    }

};

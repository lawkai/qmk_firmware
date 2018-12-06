#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD,
  LAYER_ESC,
};

enum custom_macro {
    DEFAULT_MACRO=0,
    CTL_FN_LAYER,
    ALT_FN_LAYER,
    LESS_THAN_EQUAL,
    GREATER_THAN_EQUAL,
    LEFT_ARROW,
    RIGHT_ARROW,
    NOT_EQUAL,
    EQUAL_EQUAL,
};

#define ESC_GUI LGUI_T(KC_ESC)
#define ESC_CTL LCTL_T(KC_ESC)
#define KC_CTL1 LM(1, KC_LCTL)
#define KC_ALT1 LM(1, KC_LALT)
#define KC_ALT1 LM(1, KC_LALT)
#define KC_GUI1 LM(1, KC_LGUI)
#define KC_QUT1 LT(1, KC_QUOT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [0] = LAYOUT_ergodox(
               KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_MINS,
               KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_UP,
               ESC_GUI, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,
               KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LEFT,
               KC_LCTL, KC_CTL1, KC_GUI1, KC_ALT1, KC_LALT,
                                 KC_PGDN, KC_PGUP,
                                          KC_INS,
                        KC_SPC, KC_ENT, MO(1),                    
               KC_EQL,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS,
               KC_DOWN, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
                        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUT1,
               KC_RGHT, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                                 KC_RALT, KC_ALT1, KC_GUI1, KC_CTL1,  KC_RCTL,
                                          KC_HOME, KC_END,
                                          KC_DEL,
                                          MO(1),   KC_ENT, KC_SPC),

  [1] = LAYOUT_ergodox(
               _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,
               _______, _______, _______, _______, _______, _______, _______,
               _______, _______, _______, _______, _______, _______,
               _______, _______, _______, _______, _______, _______, _______,
               _______, _______, _______, _______, _______,
                                 _______, _______,
                                          _______,
                        _______, _______, _______,
               KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,
               _______, _______, _______, KC_PSCR, KC_LBRC, KC_RBRC, _______,
                        _______, _______, _______, _______, _______, _______,
               _______, _______, _______, _______, _______, _______, _______,
               _______, _______, _______, _______, _______,
                                          _______, _______,
                                          _______,
                                          _______, _______, _______),
};

const uint16_t PROGMEM fn_actions[] = {
  [1] = ACTION_LAYER_TAP_TOGGLE(1)
};

// leaving this in place for compatibilty with old keymaps cloned and re-compiled.
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
      switch(id) {
        case CTL_FN_LAYER:
        if (record->event.pressed) {
            layer_invert(1);
            register_mods(MOD_BIT(KC_LCTL));
            return MACRO_NONE;
        } else {
            layer_invert(1);
            unregister_mods(MOD_BIT(KC_LCTL));
            return MACRO_NONE; 
        }
        case ALT_FN_LAYER:
        if (record->event.pressed) {
            layer_invert(1);
            register_mods(MOD_BIT(KC_LALT));
            return MACRO_NONE;
        } else {
            layer_invert(1);
            unregister_mods(MOD_BIT(KC_LALT));
            return MACRO_NONE; 
        }
        case LESS_THAN_EQUAL:
        if (record->event.pressed) {
            SEND_STRING("<=");
            return false;
        }
        case GREATER_THAN_EQUAL:
        if (record->event.pressed) {
            SEND_STRING(">=");
            return false;
        }
        case LEFT_ARROW:
        if (record->event.pressed) {
            SEND_STRING("<-");
            return false;
        }
        case RIGHT_ARROW:
        if (record->event.pressed) {
            SEND_STRING("->");
            return false;
        }
        case NOT_EQUAL:
        if (record->event.pressed) {
            SEND_STRING("!=");
            return false;
        }
        case EQUAL_EQUAL:
        if (record->event.pressed) {
            SEND_STRING("==");
            return false;
        }
      }
    return MACRO_NONE;
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

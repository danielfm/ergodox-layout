#include QMK_KEYBOARD_H
#include "version.h"

#define BASE 0 // basic layer
#define SYMB 1 // symbols layer
#define NAV  2 // media layer

enum custom_keycodes {
  RGB_SLD = SAFE_RANGE,
  EPRM,
  HSV_LBLUE,
  HSV_LGREEN,
  HSV_LWHITE
};

// Tap Dance declarations
enum {
  TD_LCP = 0,
  TD_RCP,
  TD_PUH,
  TD_PDE,
  TD_MPN
};

qk_tap_dance_action_t tap_dance_actions[] = {
  // Tap once for [, twice for (
  [TD_LCP] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_LPRN),

  // Tap once for PgUp, twice for Home
  [TD_RCP] = ACTION_TAP_DANCE_DOUBLE(KC_RBRC, KC_RPRN),

  // Tap once for PgUp, twice for Home
  [TD_PUH] = ACTION_TAP_DANCE_DOUBLE(KC_PGUP, KC_HOME),

  // Tap once for PgDn, twice for End
  [TD_PDE] = ACTION_TAP_DANCE_DOUBLE(KC_PGDN, KC_END),

  // Tap once for Media next, twice for Media prev
  [TD_MPN] = ACTION_TAP_DANCE_DOUBLE(KC_MNXT, KC_MPRV)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   Esc  |   1  |   2  |   3  |   4  |   5  |   =  |           |  =   |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   Tab  |   Q  |   W  |   E  |   R  |   T  | [{ ( |           | ]} ) |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  Bksp  |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  | ;/L2 |   '"   |
 * |--------+------+------+------+------+------|  |   |           |  _   |------+------+------+------+------+--------|
 * |  MO L1 |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | MO L1  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | LGUI | Left | Down |  '"  |  `~  |                                       |   [  |   ]  |  Up  | Right| LGUI |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |  Del |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |LCtrl | Shift|------|       |------|Enter/|Space/|
 *                                 |      |      |  Alt |       | Alt  |Shift |LCtrl |
 *                                 `--------------------'       `--------------------'
 */
[BASE] = LAYOUT_ergodox(
        // left hand
        KC_ESC,   KC_1,    KC_2,    KC_3,    KC_4,   KC_5, KC_EQL,
        KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,   KC_T, TD(TD_LCP),
        KC_BSPC,  KC_A,    KC_S,    KC_D,    KC_F,   KC_G,
        MO(SYMB), KC_Z,    KC_X,    KC_C,    KC_V,   KC_B, KC_PIPE,
        KC_LGUI,  KC_LEFT, KC_DOWN, KC_QUOT, KC_GRV,
                                                  KC_DELT, KC_TRNS,
                                                           KC_TRNS,
                             OSM(MOD_LCTL), OSM(MOD_LSFT), OSM(MOD_LALT),
        // right hand
        KC_EQL,     KC_6, KC_7,    KC_8,    KC_9,    KC_0,             KC_MINS,
        TD(TD_RCP), KC_Y, KC_U,    KC_I,    KC_O,    KC_P,             KC_BSLS,
                    KC_H, KC_J,    KC_K,    KC_L,    LT(NAV, KC_SCLN), KC_QUOT,
        KC_UNDS,    KC_N, KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          MO(SYMB),
                          KC_LBRC, KC_RBRC, KC_UP,   KC_RGHT,          KC_LGUI,
        KC_TRNS, KC_LEAD,
        KC_TRNS,
        OSM(MOD_LALT), LSFT_T(KC_ENTER), LCTL_T(KC_SPC)
    ),

/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |         |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |   !  |   @  |   {  |   }  |   |  |      |           |      |      |   7  |   8  |   9  |   *  |   F12  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   #  |   $  |   (  |   )  |   `  |------|           |------|      |   4  |   5  |   6  |   +  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                       |      |    . |   0  |   =  |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |Animat| Blue |       |Toggle|Solid |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |Bright|Bright| Green|       | Sat+ |Hue-  |Hue+  |
 *                                 |ness- |ness+ |------|       |------|      |      |
 *                                 |      |      | White|       | Sat- |      |      |
 *                                 `--------------------'       `--------------------'
 */

[SYMB] = LAYOUT_ergodox(
  // left hand
  KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TRNS,
  KC_TRNS, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE, KC_TRNS,
  KC_TRNS, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,
  KC_LGUI, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                               RGB_MOD, HSV_LBLUE,
                                                        HSV_LGREEN,
                                      RGB_VAD, RGB_VAI, HSV_LWHITE,
  // right hand
  KC_TRNS, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  KC_TRNS, KC_TRNS, KC_7,    KC_8,    KC_9,    KC_ASTR, KC_F12,
           KC_TRNS, KC_4,    KC_5,    KC_6,    KC_PLUS, KC_TRNS,
  KC_TRNS, KC_AMPR, KC_1,    KC_2,    KC_3,    KC_BSLS, KC_TRNS,
                    KC_TRNS, KC_DOT,  KC_0,    KC_EQL,  KC_TRNS,
  RGB_TOG, RGB_SLD,
  RGB_SAI,
  RGB_SAD, RGB_HUD, RGB_HUI
),

/* Keymap 2: Navigation and media keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |  Up  |      |      | PgUp |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------| Home |           |      |------+------+------+------+------+--------|
 * |        |      | Left | Down | Right|      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------| PgDn |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |  End |           |      |      | Mute | VolDn| VolUp|      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------| Prev | Play |
 *                                 |      |      |      |       |      | Next |      |
 *                                 `--------------------'       `--------------------'
 */
[NAV] = LAYOUT_ergodox(
       // left hand
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_UP,   KC_TRNS,  KC_TRNS, TD(TD_PUH),
       KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_RIGHT, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, TD(TD_PDE),
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                    KC_TRNS,  KC_TRNS,
                                                              KC_TRNS,
                                            KC_TRNS, KC_TRNS, KC_TRNS,
       // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_MUTE, KC_VOLD, KC_VOLU, KC_TRNS, KC_TRNS,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, TD(TD_MPN), KC_MPLY
),
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
  uint8_t layer = biton32(layer_state);
  uint8_t mods = get_mods();
  uint8_t oneshot_mods = get_oneshot_mods();

  if (layer == SYMB) {
    ergodox_right_led_1_set(LED_BRIGHTNESS_HI);
    ergodox_right_led_1_on();
  } else if (mods & MOD_MASK_SHIFT) {
    ergodox_right_led_1_set(LED_BRIGHTNESS_HI);
    ergodox_right_led_1_on();
  } else if (oneshot_mods & MOD_MASK_SHIFT) {
    ergodox_right_led_1_set(LED_BRIGHTNESS_LO);
    ergodox_right_led_1_on();
  } else {
    ergodox_right_led_1_off();
  }

  if (layer == NAV) {
    ergodox_right_led_2_set(LED_BRIGHTNESS_HI);
    ergodox_right_led_2_on();
  } else if (mods & MOD_MASK_ALT) {
    ergodox_right_led_2_set(LED_BRIGHTNESS_HI);
    ergodox_right_led_2_on();
  } else if (oneshot_mods & MOD_MASK_ALT) {
    ergodox_right_led_2_set(LED_BRIGHTNESS_LO);
    ergodox_right_led_2_on();
  } else {
    ergodox_right_led_2_off();
  }

  if (mods & MOD_MASK_CTRL) {
    ergodox_right_led_3_set(LED_BRIGHTNESS_HI);
    ergodox_right_led_3_on();
  } else if (oneshot_mods & MOD_MASK_CTRL) {
    ergodox_right_led_3_set(LED_BRIGHTNESS_LO);
    ergodox_right_led_3_on();
  } else {
    ergodox_right_led_3_off();
  }
}

// Implement custom keycodes.
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case EPRM:
        eeconfig_init();
        return false;

      case RGB_SLD:
        rgblight_mode(1);
        return false;

      case HSV_LBLUE:
        rgblight_mode(1);
        rgblight_sethsv(172, 255, 255);
        return false;

      case HSV_LWHITE:
        rgblight_mode(1);
        rgblight_sethsv(0, 0, 255);
        return false;
    }
  }
  return true;
}

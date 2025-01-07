/*
 * Jul.2024@qwasium
 *
 * Template was created qmk CLI: qmk new-keymap -kb ergodox_ez -km qwasium
 * Template is in: qmk_firmware/keyboards/ergodox_ez/keymaps/default/keymap.c
 * Put this source code in: qmk_firmware/keyboards/ergodox_ez/keymaps/qwasium/keymap.c
 *
 * Compile with qmk CLI: qmk compile -kb ergodox_ez/base -km qwasium
 *
 * Key assignment is based on my custom CSTC40 keymap.
 */

#include QMK_KEYBOARD_H
#include "version.h"

enum layers {
    LAYER_BASE, // LAYER 0: default layer
    LAYER_SYMB, // LAYER 1: symbols
    LAYER_NUM,  // LAYER 2: numbers and navigation
    LAYER_MOUS, // LAYER 3: mouse and less used keys
};

// Must come before keymaps array and process_record_user()
enum custom_keycodes {
    VRSN = SAFE_RANGE,
    MACRO_SWTCH_KB,  // MACRO 0: switch keyboard with super+space and set to kana if changed to Japanese Keyboard
    MACRO_WORD_FRWD, // MACRO 1: move one word forward (vim keybind style)
    MACRO_WORD_BACK, // MACRO 2: move one word backward (vim keybind style)
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* [0] LAYER_BASE: Basic layer ------------------------------------------------------------------------------------- *
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   F1   |  F2  |  F3  |  F4  |  F5  |  F6  | MENU |           | NumLk|  F7  |  F8  |  F9  |  F10 |  F11 |  F12   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Esc    |   Q  |   W  |   E  |   R  |   T  |  M0  |           |  M0  |   Y  |   U  |   I  |   O  |   P  |  BkSp  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Tab    |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |  Enter |
 * |--------+------+------+------+------+------| BkSp |           | Del  |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |LCtrl | LGUI | LAlt | MO(2)| MO(1)|                                       | MO(1)| MO(2)| RAlt | LGUI |  RCtrl |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Play |BritUp|       | VolUp| Mute |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |BritDn|       | VolDn|      |      |
 *                                 | Space| MO(2)|------|       |------|MO(2) |Space |
 *                                 |      |      | MO(3)|       | MO(3)|      |      |
 *                                 `--------------------'       `--------------------'
 */
[LAYER_BASE] = LAYOUT_ergodox_pretty(
  // left hand                                                             right hand
  KC_F1,   KC_F2,   KC_F3,   KC_F4, KC_F5,  KC_F6,   KC_APP,               KC_NUM,         KC_F7,   KC_F8, KC_F9,   KC_F10,  KC_F11,  KC_F12,
  KC_ESC,  KC_Q,    KC_W,    KC_E,  KC_R,   KC_T,    MACRO_SWTCH_KB,       MACRO_SWTCH_KB, KC_Y,    KC_U,  KC_I,    KC_O,    KC_P,    KC_BSPC,
  KC_TAB,  MT(MOD_LCTL, KC_A), MT(MOD_LGUI, KC_S), MT(MOD_LALT, KC_D), MT(MOD_LSFT, KC_F),   KC_G, KC_H,    MT(MOD_LSFT, KC_J), MT(MOD_LALT, KC_K), MT(MOD_LGUI, KC_L), MT(MOD_LCTL, KC_SCLN), KC_ENT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,  KC_V,   KC_B,    KC_BSPC,              KC_DEL,         KC_N,    KC_M,  KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT,
  KC_LCTL, KC_LGUI, KC_LALT, MO(2), MO(1),                                                 MO(1),   MO(2), KC_RALT, KC_LGUI, KC_RCTL,
                                            KC_MPLY, KC_BRIU,              KC_VOLU,        KC_MUTE,
                                                     KC_BRID,              KC_VOLD,
                                    KC_SPC, MO(2),   MO(3),                MO(3),          MO(2),  KC_SPC
), // LAYER_BASE end ----------------------------------------------------------------------------------------------- *

/* [1] LAYER_SYMB: Symbol Layer ------------------------------------------------------------------------------------ *
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   F1   |  F2  |  F3  |  F4  |  F5  |  F6  | MENU |           | NumLk|  F7  |  F8  |  F9  |  F10 |  F11 |  F12   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Esc    |   !  |   @  |   #  |   $  |   %  |  M0  |           |  M0  |   ^  |   &  |   *  |   (  |   )  |  BkSp  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Tab    |   _  |   |  |   <  |   >  |  M0  |------|           |------|  Del |   {  |   }  |   [  |   ]  |  Enter |
 * |--------+------+------+------+------+------| BkSp |           | Del  |------+------+------+------+------+--------|
 * | LShift |   =  |   \  | 英数  | かな | M1  |      |           |      |  na  |   `  |   ~  |   "  |   '  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |LCtrl | LGUI | LAlt | MO(2)| MO(1)|                                       | MO(1)| MO(2)| RAlt | LGUI |  RCtrl |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Play |BritUp|       | VolUp| Mute |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |BritDn|       | VolDn|      |      |
 *                                 | Space| MO(2)|------|       |------|MO(2) |Space |
 *                                 |      |      | MO(3)|       | MO(3)|      |      |
 *                                 `--------------------'       `--------------------'
 */
[LAYER_SYMB] = LAYOUT_ergodox_pretty(
  // left hand                                                                                               right hand
  KC_F1,   KC_F2,         KC_F3,         KC_F4,         KC_F5,        KC_F6,           KC_APP,               KC_NUM,         KC_F7,      KC_F8,         KC_F9,         KC_F10,        KC_F11,     KC_F12,
  KC_ESC,  LSFT(KC_1),    LSFT(KC_2),    LSFT(KC_3),    LSFT(KC_4),   LSFT(KC_5),      MACRO_SWTCH_KB,       MACRO_SWTCH_KB, LSFT(KC_6), LSFT(KC_7),    LSFT(KC_8),    LSFT(KC_9),    LSFT(KC_0), KC_BSPC,
  KC_TAB,  LSFT(KC_MINS), LSFT(KC_BSLS), LSFT(KC_COMM), LSFT(KC_DOT), MACRO_SWTCH_KB,                                        KC_DEL,     LSFT(KC_LBRC), LSFT(KC_RBRC), KC_LBRC,       KC_RBRC,    KC_ENT,
  KC_LSFT, KC_EQL,        KC_BSLS,       KC_LNG2,       KC_INT2,      MACRO_WORD_BACK, KC_BSPC,              KC_DEL,         KC_NO,      KC_GRV,        LSFT(KC_GRV),  LSFT(KC_QUOT), KC_QUOT,    KC_RSFT,
  KC_LCTL, KC_LGUI,       KC_LALT,       MO(2),         MO(1),                                                                           MO(1),         MO(2),         KC_RALT,       KC_LGUI,    KC_RCTL,
                                                                      KC_MPLY,         KC_BRIU,              KC_VOLU,        KC_MUTE,
                                                                                       KC_BRID,              KC_VOLD,
                                                        KC_SPC,       MO(2),           MO(3),                MO(3),          MO(2),      KC_SPC
), // LAYER_SYMB end ----------------------------------------------------------------------------------------------- *

/* [2] LAYER_NUM: Number and Navigation Layer ---------------------------------------------------------------------- *
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   F1   |  F2  |  F3  |  F4  |  F5  |  F6  | MENU |           | NumLk|  F7  |  F8  |  F9  |  F10 |  F11 |  F12   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Esc    |  na  |  M2  |  na  | End  |  na  |  M0  |           |  M0  | Home | PgDn | PgUp |  na  |   -  |  BkSp  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Tab    |   1  |   2  |   3  |   4  |   5  |------|           |------| Left | Down |  Up  | Right|   +  |  Enter |
 * |--------+------+------+------+------+------| BkSp |           | Del  |------+------+------+------+------+--------|
 * | LShift |   6  |   7  |   8  |   9  |   0  |      |           |      |  na  |  na  |   ,  |   .  |   /  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |LCtrl | LGUI | LAlt | MO(2)| MO(1)|                                       | MO(1)| MO(2)| RAlt | LGUI |  RCtrl |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Play |BritUp|       | VolUp| Mute |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |BritDn|       | VolDn|      |      |
 *                                 | Space| MO(2)|------|       |------|MO(2) |Space |
 *                                 |      |      | MO(3)|       | MO(3)|      |      |
 *                                 `--------------------'       `--------------------'
 */
[LAYER_NUM] = LAYOUT_ergodox_pretty(
  // left hand                                                                     right hand
  KC_F1,   KC_F2,   KC_F3,           KC_F4, KC_F5,  KC_F6,   KC_APP,               KC_NUM,         KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  KC_ESC,  KC_NO,   MACRO_WORD_FRWD, KC_NO, KC_END, KC_NO,   MACRO_SWTCH_KB,       MACRO_SWTCH_KB, KC_HOME, KC_PGDN, KC_PGUP, KC_NO,   KC_MINS, KC_BSPC,
  KC_TAB,  KC_1,    KC_2,            KC_3,  KC_4,   KC_5,                                          KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_PLUS, KC_ENT,
  KC_LSFT, KC_6,    KC_7,            KC_8,  KC_9,   KC_0,    KC_BSPC,              KC_DEL,         KC_NO,   KC_NO,   KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT,
  KC_LCTL, KC_LGUI, KC_LALT,         MO(2), MO(1),                                                          MO(1),   MO(2),   KC_RALT, KC_LGUI, KC_RCTL,
                                                    KC_MPLY, KC_BRIU,              KC_VOLU,        KC_MUTE,
                                                             KC_BRID,              KC_VOLD,
                                            KC_SPC, MO(2),   MO(3),                MO(3),          MO(2),   KC_SPC
), // LAYER_NUM end ------------------------------------------------------------------------------------------------ *

/* [3] LAYER_MOUS: Mouse and Less Used Keys Layer ------------------------------------------------------------------ *
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   F1   |  F2  |  F3  |  F4  |  F5  |  F6  | MENU |           | NumLk|  F7  |  F8  |  F9  |  F10 |  F11 |  F12   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Esc    |  na  |  na  |  na  |  na  |  na  |Browse|           | Copy |LWheel|UWheel|DWheel|RWheel|  na  |  BkSp  |
 * |--------+------+------+------+------+------| Fwrd |           |      |------+------+------+------+------+--------|
 * | Tab    |  na  |PrtScr|ScrLk |Pause |  na  |------|           |------|LMouse|DMouse|UMouse|RMouse|  na  |  Enter |
 * |--------+------+------+------+------+------|Browse|           | Paste|------+------+------+------+------+--------|
 * | LShift |  na  |  na  |  na  |  na  |  na  | Back |           |      |  na  |  na  |  na  |  na  |  na  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |LCtrl | LGUI | LAlt | MO(2)| MO(1)|                                       | MO(1)| MO(2)| RAlt | LGUI |  RCtrl |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |LClick|RClick|       |LClick|RClick|
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |  na  |       |  na  |      |      |
 *                                 | Space| MO(2)|------|       |------|MO(2) |Space |
 *                                 |      |      | MO(3)|       | MO(3)|      |      |
 *                                 `--------------------'       `--------------------'
 */
[LAYER_MOUS] = LAYOUT_ergodox_pretty(
  // left hand                                                              right hand
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6, KC_APP,               KC_NUM,  KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11, KC_F12,
  KC_ESC,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_WFWD,              KC_COPY, KC_WH_L, KC_WH_U, KC_WH_D, KC_WH_R, KC_NO,  KC_BSPC,
  KC_TAB,  KC_NO,   KC_PSCR, KC_SCRL, KC_PAUS, KC_NO,                                KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_NO,  KC_ENT,
  KC_LSFT, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_WBAK,              KC_PSTE, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_RSFT,
  KC_LCTL, KC_LGUI, KC_LALT, MO(2),   MO(1),                                                  MO(1),   MO(2),   KC_RALT, KC_LGUI, KC_RCTL,
                                             KC_BTN1, KC_BTN2,              KC_BTN1, KC_BTN2,
                                                      KC_NO,                KC_NO,
                                      KC_SPC,  MO(2), MO(3),                MO(3),   MO(2),   KC_SPC
) // LAYER_MOUS end ------------------------------------------------------------------------------------------------ *
};
// clang-format on


// Runs whenever a key is pressed or released.
// Define macro (see: qmk_firmware/docs/feature_macros.md)
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) { // When keycode is pressed
        switch (keycode) {

            // Defined in default keymap
            case VRSN:
                SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
                return false;

            // MACRO 0
            // Switch keyboard with super+space and then set to kana
            // Tapping kana is affected in JP Keyboard input, ignored in other languages
            case MACRO_SWTCH_KB:
                SEND_STRING(SS_DOWN(X_LGUI) SS_DOWN(X_SPC) SS_UP(X_LGUI) SS_UP(X_SPC) SS_TAP(X_INT2) SS_TAP(X_INT2));
                break;

            // MACRO 1
            // Move one word forward (vim keybind style)
            // In macos, it will act as END key
            case MACRO_WORD_FRWD:
                SEND_STRING(SS_DOWN(X_LCTL) SS_DOWN(X_RCTL) SS_TAP(X_RGHT) SS_UP(X_LCTL) SS_UP(X_RCTL));
                break;

            // MACRO 2
            // Move one word backward (vim keybind style)
            // In macos, it will act as HOME key
            case MACRO_WORD_BACK:
                SEND_STRING(SS_DOWN(X_LCTL) SS_DOWN(X_RCTL) SS_TAP(X_LEFT) SS_UP(X_LCTL) SS_UP(X_RCTL));
                break;
        }
    }
    return true;
}

// Runs just one time when the keyboard initializes.
void keyboard_post_init_user(void) {
    // qmk_firmware/keyboards/ergodox_ez/ergodox_ez.c
    ergodox_blink_all_leds();
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
};

// Switch indicator LED
// Runs constantly in the background, in a loop.
bool led_update_user(led_t led_state) { // qmk_firmware/quantum/led.h

    // LED 1 (top): Num Lock
    if (led_state.num_lock) {
        ergodox_right_led_1_on();
    } else {
        ergodox_right_led_1_off();
    }

    // LED 2 (middle): Caps Lock
    if (led_state.caps_lock) {
        ergodox_right_led_2_on();
    } else {
        ergodox_right_led_2_off();
    }

    // LED 3 (bottom): Scroll Lock
    if (led_state.scroll_lock) {
        ergodox_right_led_3_on();
    } else {
        ergodox_right_led_3_off();
    }

    return false; // false: led_set_kb() will be overridden by this function
}

// // Runs whenever there is a layer state change.
// layer_state_t layer_state_set_user(layer_state_t state) {
//     return state;
// };

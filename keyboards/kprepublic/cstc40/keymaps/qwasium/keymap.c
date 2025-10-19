/* Copyright 2023
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Oct.2025@qwasium
 * qmk_firmware/keyboards/kprepublic/cstc40/keymaps/qwasium/keymap.c
 *
 * to compile:
 * qmk compile -kb kprepublic/cstc40/rev2 -km qwasium
 *
 * to compile and flash:
 * make kprepublic/cstc40/rev2:qwasium:flash
 *
 */

#include QMK_KEYBOARD_H


enum layers {
    LAYER_BASE, // LAYER 0: default layer
    LAYER_SYMB, // LAYER 1: symbols
    LAYER_NUM,  // LAYER 2: numbers and navigation
    LAYER_MOUS, // LAYER 3: mouse and less used keys
};

// Must come before keymaps array and process_record_user()
enum custom_keycodes {
    // VRSN = SAFE_RANGE,
    MACRO_SWTCH_KB,  // MACRO 0: switch keyboard with super+space and set to kana if changed to Japanese Keyboard
    MACRO_WORD_FRWD, // MACRO 1: move one word forward (vim keybind style)
    MACRO_WORD_BACK, // MACRO 2: move one word backward (vim keybind style)
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |RShift|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | LCtrl| LGUI | LAlt | MO(2)| MO(1)|    Space    |MO(1) |MO(2) | RAlt | RGUI |RCtrl |
 * `-----------------------------------------------------------------------------------'
 */
[LAYER_BASE] = LAYOUT_planck_mit(
    KC_ESC,  KC_Q,               KC_W,               KC_E,               KC_R,               KC_T, KC_Y, KC_U,               KC_I,               KC_O,               KC_P,                  KC_BSPC,
    KC_TAB,  MT(MOD_LCTL, KC_A), MT(MOD_LGUI, KC_S), MT(MOD_LALT, KC_D), MT(MOD_LSFT, KC_F), KC_G, KC_H, MT(MOD_LSFT, KC_J), MT(MOD_LALT, KC_K), MT(MOD_LGUI, KC_L), MT(MOD_LCTL, KC_SCLN), KC_ENT,
    KC_LSFT, KC_Z,               KC_X,               KC_C,               KC_V,               KC_B, KC_N, KC_M,               KC_COMM,            KC_DOT,             KC_SLSH,               KC_RSFT,
    KC_LCTL, KC_LGUI,            KC_LALT,            MO(2),              MO(1),                KC_SPC,   MO(1),              MO(2),              KC_RALT,            KC_LGUI,               KC_RCTL
),

/* Symbols
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |  _   |  |   |  <   |  >   | M(0) |  Del |   {  |   }  |   [  |   ]  |EnTer |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |LShift|  =   |  \   | 英数 | かな | M(1) |      |   `` |   ~  |   ,  |   .  |RShift|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | LCtrl| LGUI | LAlt | MO(2)| MO(1)|    Space    |MO(1) |MO(2) | RAlt | RGUI |RCtrl |
 * `-----------------------------------------------------------------------------------'
 */
[LAYER_SYMB] = LAYOUT_planck_mit(
    KC_ESC,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,         KC_CIRC, KC_AMPR, KC_ASTR,     KC_LPRN,        KC_RPRN, KC_BSPC,
    KC_TAB,  MT(MOD_LCTL, LSFT(KC_MINS)),
                      MT(MOD_LGUI, LSFT(KC_BSLS)),
                               MT(MOD_LALT, LSFT(KC_COMM)),
                                        MT(MOD_LSFT, LSFT(KC_DOT)),
                                                 MACRO_SWTCH_KB,  KC_DEL,  MT(MOD_LSFT, LSFT(KC_LBRC)),
                                                                                    MT(MOD_LALT, LSFT(KC_RBRC)),
                                                                                                  MT(MOD_LGUI, KC_LBRC),
                                                                                                                 MT(MOD_LCTL, KC_RBRC),
                                                                                                                          KC_ENT,
    KC_LSFT, KC_EQL,  KC_BSLS, KC_LNG2, KC_INT2, MACRO_WORD_BACK, KC_NO,   KC_GRV,  LSFT(KC_GRV), LSFT(KC_QUOT), KC_QUOT, KC_RSFT,
    KC_LCTL, KC_LGUI, KC_LALT, MO(2),   MO(1),             KC_SPC,         MO(1),   MO(2),        KC_RALT,       KC_LGUI, KC_RCTL
),

/* Number/Arrows
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |      | M(2) |      | End  |      | Home |      |      |      |   -  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  1   |  2   |  3   |  4   |  5   | Left | Down |  Up  | Right|   +  |  Esc |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |LShift|  6   |  7   |  8   |  9   |  0   |      |      |   ,  |   .  |   /  |RShift|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | LCtrl| LGUI | LAlt | MO(2)| MO(1)|    Space    |MO(1) |MO(2) | RAlt | RGUI |RCtrl |
 * `-----------------------------------------------------------------------------------'
 */
[LAYER_NUM] = LAYOUT_planck_mit(
    KC_ESC,  KC_NO,              MACRO_WORD_FRWD,    KC_NO,              KC_END,             KC_NO, KC_HOME, KC_NO,                 KC_NO,               KC_NO,                 KC_MINS,               KC_BSPC,
    KC_TAB,  MT(MOD_LCTL, KC_1), MT(MOD_LGUI, KC_2), MT(MOD_LALT, KC_3), MT(MOD_LSFT, KC_4), KC_5,  KC_LEFT, MT(MOD_LSFT, KC_DOWN), MT(MOD_LALT, KC_UP), MT(MOD_LGUI, KC_RGHT), MT(MOD_LCTL, KC_PPLS), KC_ENT,
    KC_LSFT, KC_6,               KC_7,               KC_8,               KC_9,               KC_0,  KC_NO,   KC_NO,                 KC_COMM,             KC_DOT,                KC_SLSH,               KC_RSFT,
    KC_LCTL, KC_LGUI,            KC_LALT,            MO(2),              MO(1),                KC_SPC,       MO(1),                 MO(2),               KC_RALT,               KC_LGUI,               KC_RCTL
),

/* Mouse/Function
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |      |PrtScr|LClick|RClick|      |LMouse|DMouse|UMouse|Rmouse|      | Enter|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |LShift|      |      |      |      |      |LWheel|DWheel|UWheel|RWheel|      |RShift|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | LCtrl| LGUI | LAlt | MO(2)| MO(1)|    Space    |MO(1) |MO(2) | RAlt | RGUI |RCtrl |
 * `-----------------------------------------------------------------------------------'
 */
[LAYER_MOUS] = LAYOUT_planck_mit(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
    KC_TAB,  KC_NO,   KC_PSCR, MS_BTN1, MS_BTN2, KC_NO, MS_LEFT, MS_DOWN, MS_UP,   MS_RGHT, KC_NO,   KC_ENT,
    KC_LSFT, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, MS_WHLL, MS_WHLU, MS_WHLD, MS_WHLR, KC_NO,   KC_RSFT,
    KC_LCTL, KC_LGUI, KC_LALT, MO(2),   MO(1),      KC_SPC,      MO(1),   MO(2),   KC_RALT, KC_LGUI, KC_RCTL
)

};


// Runs whenever a key is pressed or released.
// Define macro (see: qmk_firmware/docs/feature_macros.md)
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) { // When keycode is pressed
        switch (keycode) {

            // // Defined in default keymap
            // case VRSN:
            //     SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
            //     return false;

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

// MO(3)
const uint16_t PROGMEM mo3_combo[] = {MO(1), MO(2), COMBO_END};
combo_t key_combos[] = {
    COMBO(mo3_combo, MO(3))
};


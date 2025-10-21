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
    MACRO_SWTCH_KB,  // MACRO 0: switch keyboard with super+space and set to kana if changed to Japanese Keyboard
    MACRO_WORD_FRWD, // MACRO 1: move one word forward (vim keybind style)
    MACRO_WORD_BACK, // MACRO 2: move one word backward (vim keybind style)
};

// Tap dance; sinde MT(mod, LSFT(kc)) is not supported.
enum {
    CTL_UNDR, // CTL_T( _ )
    GUI_PIPE, // GUI_T( | )
    ALT_LESS, // ALT_T( < )
    SFT_MORE, // SFT_T( > )
    SFT_LCUR, // SFT_T( { )
    ALT_RCUR, // ALT_T( } )
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
    KC_ESC,  KC_Q,        KC_W,        KC_E,        KC_R,        KC_T, KC_Y, KC_U,        KC_I,        KC_O,        KC_P,           KC_BSPC,
    KC_TAB,  CTL_T(KC_A), GUI_T(KC_S), ALT_T(KC_D), SFT_T(KC_F), KC_G, KC_H, SFT_T(KC_J), ALT_T(KC_K), GUI_T(KC_L), CTL_T(KC_SCLN), KC_ENT,
    KC_LSFT, KC_Z,        KC_X,        KC_C,        KC_V,        KC_B, KC_N, KC_M,        KC_COMM,     KC_DOT,      KC_SLSH,        KC_RSFT,
    KC_LCTL, KC_LGUI,     KC_LALT,     MO(2),       MO(1),         KC_SPC,   MO(1),       MO(2),       KC_RALT,     KC_LGUI,        KC_RCTL
),

/* Symbols
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |  _   |  |   |  <   |  >   | M(0) |  Del |   {  |   }  |   [  |   ]  |EnTer |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |LShift|  =   |  \   | 英数 | かな | M(1) |      |   `` |   ~  |   "  |   '  |RShift|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | LCtrl| LGUI | LAlt | MO(2)| MO(1)|    Space    |MO(1) |MO(2) | RAlt | RGUI |RCtrl |
 * `-----------------------------------------------------------------------------------'
 */
[LAYER_SYMB] = LAYOUT_planck_mit(
    KC_ESC,  KC_EXLM,      KC_AT,        KC_HASH,      KC_DLR,       KC_PERC,         KC_CIRC, KC_AMPR,      KC_ASTR,      KC_LPRN,        KC_RPRN,        KC_BSPC,
    KC_TAB,  TD(CTL_UNDR), TD(GUI_PIPE), TD(ALT_LESS), TD(SFT_MORE), MACRO_SWTCH_KB,  KC_DEL,  TD(SFT_LCUR), TD(ALT_RCUR), GUI_T(KC_LBRC), CTL_T(KC_RBRC), KC_ENT,
    KC_LSFT, KC_EQL,       KC_BSLS,      KC_LNG2,      KC_INT2,      MACRO_WORD_BACK, KC_NO,   KC_GRV,       S(KC_GRV),    S(KC_QUOT),     KC_QUOT,        KC_RSFT,
    KC_LCTL, KC_LGUI,      KC_LALT,      MO(2),        MO(1),                KC_SPC,           MO(1),        MO(2),        KC_RALT,        KC_LGUI,        KC_RCTL
),

/* Number/Arrows
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |      | M(2) |      | End  |      | Home |      |      |      |   -  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |CapsLk|  1   |  2   |  3   |  4   |  5   | Left | Down |  Up  | Right|   +  |  Esc |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |LShift|  6   |  7   |  8   |  9   |  0   |      |      |   ,  |   .  |   /  |RShift|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | LCtrl| LGUI | LAlt | MO(2)| MO(1)|    Space    |MO(1) |MO(2) | RAlt | RGUI |RCtrl |
 * `-----------------------------------------------------------------------------------'
 */
[LAYER_NUM] = LAYOUT_planck_mit(
    KC_ESC,  KC_NO,       MACRO_WORD_FRWD, KC_NO,       KC_END,      KC_NO, KC_HOME, KC_NO,          KC_NO,        KC_NO,          KC_MINS,        KC_BSPC,
    KC_CAPS, CTL_T(KC_1), GUI_T(KC_2),     ALT_T(KC_3), SFT_T(KC_4), KC_5,  KC_LEFT, SFT_T(KC_DOWN), ALT_T(KC_UP), GUI_T(KC_RGHT), CTL_T(KC_PPLS), KC_ENT,
    KC_LSFT, KC_6,        KC_7,            KC_8,        KC_9,        KC_0,  KC_NO,   KC_NO,          KC_COMM,      KC_DOT,         KC_SLSH,        KC_RSFT,
    KC_LCTL, KC_LGUI,     KC_LALT,         MO(2),       MO(1),          KC_SPC,      MO(1),          MO(2),        KC_RALT,        KC_LGUI,        KC_RCTL
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

// MO(3)
const uint16_t PROGMEM mo3_combo[] = {MO(1), MO(2), COMBO_END};
combo_t key_combos[] = {
    COMBO(mo3_combo, MO(3))
};

// Tap Dance definitions
typedef struct {
    uint16_t tap;
    uint16_t hold;
    uint16_t held;
} tap_dance_tap_hold_t;

void tap_dance_tap_hold_finished(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (state->pressed) {
        if (state->count == 1
#ifndef PERMISSIVE_HOLD
            && !state->interrupted
#endif
        ) {
            register_code16(tap_hold->hold);
            tap_hold->held = tap_hold->hold;
        } else {
            register_code16(tap_hold->tap);
            tap_hold->held = tap_hold->tap;
        }
    }
}

void tap_dance_tap_hold_reset(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (tap_hold->held) {
        unregister_code16(tap_hold->held);
        tap_hold->held = 0;
    }
}

#define ACTION_TAP_DANCE_TAP_HOLD(tap, hold)                                        \
    {                                                                               \
        .fn        = {NULL, tap_dance_tap_hold_finished, tap_dance_tap_hold_reset}, \
        .user_data = (void *)&((tap_dance_tap_hold_t){tap, hold, 0}),               \
    }

tap_dance_action_t tap_dance_actions[] = {
    [CTL_UNDR] = ACTION_TAP_DANCE_TAP_HOLD(S(KC_MINS), KC_LCTL),
    [GUI_PIPE] = ACTION_TAP_DANCE_TAP_HOLD(S(KC_BSLS), KC_LGUI),
    [ALT_LESS] = ACTION_TAP_DANCE_TAP_HOLD(S(KC_COMM), KC_LALT),
    [SFT_MORE] = ACTION_TAP_DANCE_TAP_HOLD(S(KC_DOT), KC_LSFT),
    [SFT_LCUR] = ACTION_TAP_DANCE_TAP_HOLD(S(KC_LBRC), KC_LSFT),
    [ALT_RCUR] = ACTION_TAP_DANCE_TAP_HOLD(S(KC_RBRC), KC_LALT),
};

// Runs whenever a key is pressed or released.
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    tap_dance_action_t *action;

    switch (keycode) {

        // TAP DANCE
        // list all tap dance keycodes with tap-hold configurations
        case TD(CTL_UNDR):
        case TD(GUI_PIPE):
        case TD(ALT_LESS):
        case TD(SFT_MORE):
        case TD(SFT_LCUR):
        case TD(ALT_RCUR):
            action = &tap_dance_actions[QK_TAP_DANCE_GET_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
            return true;

        // MACRO 0
        // Switch keyboard with super+space and then set to kana
        // Tapping kana is affected in JP Keyboard input, ignored in other languages
        case MACRO_SWTCH_KB:
            if (record->event.pressed) { // When keycode is pressed
                SEND_STRING(SS_DOWN(X_LGUI) SS_DOWN(X_SPC) SS_UP(X_LGUI) SS_UP(X_SPC) SS_TAP(X_INT2) SS_TAP(X_INT2));
                break;
            }

        // MACRO 1
        // Move one word forward (vim keybind style)
        // In macos, it will act as END key
        case MACRO_WORD_FRWD:
            if (record->event.pressed) { // When keycode is pressed
                SEND_STRING(SS_DOWN(X_LCTL) SS_DOWN(X_RCTL) SS_TAP(X_RGHT) SS_UP(X_LCTL) SS_UP(X_RCTL));
                break;
            }

        // MACRO 2
        // Move one word backward (vim keybind style)
        // In macos, it will act as HOME key
        case MACRO_WORD_BACK:
            if (record->event.pressed) { // When keycode is pressed
                SEND_STRING(SS_DOWN(X_LCTL) SS_DOWN(X_RCTL) SS_TAP(X_LEFT) SS_UP(X_LCTL) SS_UP(X_RCTL));
                break;
            }
    }
    return true;
}

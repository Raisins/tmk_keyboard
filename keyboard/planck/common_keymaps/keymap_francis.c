// https://github.com/shanecelis/tmk_keyboard/blob/master/keyboard/planck/keymap_shane.c

#include "keymap_common.h"
#include "action_layer.h"
#include "action.h"
#include "action_util.h"

/*
  Francis's Planck Layout
  TODO: Write post about this.
  http://www.keyboard-layout-editor.com/#/layouts/954e7a13360e1c9e101b64be2c6107e2
*/
const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = KEYMAP( /* Base */
    TAB,     Q,     W,     E,    R,      T,     Y,    U,      I,    O,     P,       BSPC,
    ESC,     A,     S,     D,    F,      G,     H,    J,      K,    L,     SCLN,    QUOT,
    LSFT,    Z,     X,     C,    V,      B,     N,    M,      COMM, DOT,   SLSH,    FN5,
    LCTL,    LCTL,  LALT,  LGUI, FN2,      SPC,       FN1,    LEFT, DOWN,  UP,      RGHT),
  [1] = KEYMAP( /* Raise/FN1 */
    GRV,     1,     2,     3,     4,     5,     6,     7,     8,     9,     0,      EQL,
    ESC,     TRNS,  TRNS,  TRNS,  TRNS,  TRNS,  TRNS,  TRNS,  TRNS,  LBRC,  RBRC,   BSLS,
    LSFT,    F1,    F2,    F3,    F4,    F5,    F6,    F7,    F8,    F9,    F10,    FN5,
    MUTE,    TRNS,  TRNS,  TRNS,  FN3,      SPC,       FN1,   NO,    PGUP,  PGDN,   MRWD),
  [2] = KEYMAP( /* Lower/FN2 */
    GRV,     1,     2,     3,     4,     5,     6,     P7,    P8,    P9,   0,       MINS,
    ESC,     TRNS,  TRNS,  TRNS,  TRNS,  TRNS,  TRNS,  P4,    P5,    P6,   NO,      EQL,
    LSFT,    TRNS,  TRNS,  TRNS,  TRNS,  TRNS,  TRNS,  P1,    P2,    P3,   NO,      FN5,
    MPLY,    TRNS,  TRNS,  MUTE,  FN2,      SPC,       FN3,   P0,    VOLD, VOLU,    MFFD),
  [3] = KEYMAP( /*  lower + raise */  //buggy sometimes, Seeems to get stuck, just hit both raise and lower
    FN7,     LBRC,  NO,    NO,     NO,   NO,    NO,    NO,    NO,    NO,   RBRC,   FN8,
    NO,      F1,    F2,    F3,     F4,   F5,    F6,    F7,    F8,    F9,   F10,    NO,
    LSFT,    NO,    NO,    NO,     NO,   NO,    NO,    8,     9,    LBRC,  RBRC,     FN5,
    MPLY,    NO,    NO,    MUTE,   TRNS,     SPC,      TRNS,   MFFD,  VOLD, VOLU,   MPLY)
};

// Media keys dont work on mac https://github.com/tmk/tmk_keyboard/issues/195
// TODO watch that ticket

enum macro_id {
    M_Q0,
    M_Q1,
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    keyevent_t event = record->event;
    switch (id) {
        case M_Q0: //Command + Shift Brackets aka Change tabs, LEFT
            return event.pressed ?
                MACRO( I(1), D(LGUI), D(LSFT), T(LBRC), U(LGUI), U(LSFT), END ) :
                MACRO_NONE;
        case M_Q1: //Command + Shift Brackets aka Change tabs, RIGHT
            return event.pressed ?
                MACRO( I(1), D(LGUI), D(LSFT), T(RBRC), U(LGUI), U(LSFT), END ) :
                MACRO_NONE;
    }
    return MACRO_NONE;
}


const uint16_t PROGMEM fn_actions[] = {
  [1] = ACTION_LAYER_MOMENTARY(1),  // Raise to Fn1 overlay
  [2] = ACTION_LAYER_MOMENTARY(2),  // Lower to Fn overlay
  [3] = ACTION_LAYER_MOMENTARY(3),  // to Fn overlay

  [5] = ACTION_MODS_TAP_KEY(MOD_RSFT, KC_ENT), // FN5 hold for enter, tap for shift

  [7] = ACTION_MACRO(M_Q0), //Command + Shift Brackets aka Change tabs, LEFT
  [8] = ACTION_MACRO(M_Q1), //Command + Shift Brackets aka Change tabs, RIGHT

  [11] = ACTION_MODS_KEY(MOD_LSFT, KC_1),
  [12] = ACTION_MODS_KEY(MOD_LSFT, KC_2),
  [13] = ACTION_MODS_KEY(MOD_LSFT, KC_3),
  [14] = ACTION_MODS_KEY(MOD_LSFT, KC_4),
  [15] = ACTION_MODS_KEY(MOD_LSFT, KC_5),
  [16] = ACTION_MODS_KEY(MOD_LSFT, KC_6),
  [17] = ACTION_MODS_KEY(MOD_LSFT, KC_7),
  [18] = ACTION_MODS_KEY(MOD_LSFT, KC_8),
  [19] = ACTION_MODS_KEY(MOD_LSFT, KC_9),
  [20] = ACTION_MODS_KEY(MOD_LSFT, KC_0),
  [21] = ACTION_MODS_KEY(MOD_LSFT, KC_MINS),
  [22] = ACTION_MODS_KEY(MOD_LSFT, KC_EQL),
  [23] = ACTION_MODS_KEY(MOD_LSFT, KC_GRV),
  [24] = ACTION_MODS_KEY(MOD_LSFT, KC_LBRC),
  [25] = ACTION_MODS_KEY(MOD_LSFT, KC_RBRC),
  [26] = ACTION_MODS_KEY(MOD_LSFT, KC_BSLS),
};



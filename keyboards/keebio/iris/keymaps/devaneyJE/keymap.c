// Copyright 2023 Danny Nguyen (@nooges)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum combos {
  ALT_L,
  ALT_R,
  CTRL_L,
  CTRL_R,
  LU_HOME,
  UY_END,
  TC_ENTER,
  IO_ENTER,
  YSEMI_BSPC,
  QW_TAB,
  AR_ESC,
  ZX_CAPS
};

const uint16_t PROGMEM alt_l_combo[] = {KC_N, KC_E, COMBO_END};
const uint16_t PROGMEM alt_r_combo[] = {KC_E, KC_I, COMBO_END};
const uint16_t PROGMEM ctrl_l_combo[] = {KC_H, KC_COMM, COMBO_END};
const uint16_t PROGMEM ctrl_r_combo[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM home_combo[] = {KC_L, KC_U, COMBO_END};
const uint16_t PROGMEM end_combo[] = {KC_U, KC_Y, COMBO_END};
const uint16_t PROGMEM tc_enter_combo[] = {KC_BSPC, KC_SPC, COMBO_END};
const uint16_t PROGMEM enter_combo[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM bspc_combo[] = {KC_Y, KC_SCLN, COMBO_END};
const uint16_t PROGMEM tab_combo[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM esc_combo[] = {KC_A, KC_R, COMBO_END};
const uint16_t PROGMEM caps_combo[] = {KC_Z, KC_X, COMBO_END};

combo_t key_combos[] = {
  [ALT_L] = COMBO(alt_l_combo, LALT(KC_LEFT)),
  [ALT_R] = COMBO(alt_r_combo, LALT(KC_RGHT)),
  [CTRL_L] = COMBO(ctrl_l_combo, LCTL(KC_LEFT)),
  [CTRL_R] = COMBO(ctrl_r_combo, LCTL(KC_RGHT)),
  [LU_HOME] = COMBO(home_combo, KC_HOME),
  [UY_END] = COMBO(end_combo, KC_END),
  [TC_ENTER] = COMBO(tc_enter_combo, KC_ENT),
  [IO_ENTER] = COMBO(enter_combo, KC_ENT),
  [YSEMI_BSPC] = COMBO(bspc_combo, KC_BSPC),
  [QW_TAB] = COMBO(tab_combo, KC_TAB),
  [AR_ESC] = COMBO(esc_combo, KC_ESC),
  [ZX_CAPS] = COMBO(caps_combo, CW_TOGG),
};

//enum custom_keycodes {
//  CDH = SAFE_RANGE,
//  LOWER,
//  RAISE,
//  ADJUST,
//};

//#define _CDH 0
//#define _NAV 1
//#define _SYMNUM 2
//#define _FUNC 3

enum layer_names {
    _CDH, // 0 | Original | Home for encoders
    _NAV, // 1 | vi nav
    _SYMNUM, // 2 | combined
    _FUNC // 3 | Original | TapDance x2, hold to activate
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_CDH] = LAYOUT(
//┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
 KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
 KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                               KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,    KC_DEL,
//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
 KC_ESC, LGUI_T(KC_A),    MT(MOD_LALT, KC_R),    MT(MOD_LSFT, KC_S),    MT(MOD_LCTL, KC_T),    KC_G,                               KC_M,    MT(MOD_RCTL, KC_N),    MT(MOD_RSFT, KC_E),    MT(MOD_RALT, KC_I),    LGUI_T(KC_O), KC_QUOT,
//├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
 KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_HOME,          KC_END,  KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
//└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                KC_LGUI, LT(3,KC_DEL),   LT(1,KC_BSPC),                    LT(2,KC_SPC),  KC_ENT,   KC_RALT
                            // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
),

[_NAV] = LAYOUT(
//┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
 KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,                              KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,  KC_TRNS,
//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
 KC_TRNS, KC_TAB,    KC_MS_BTN1,    KC_MS_UP,    KC_MS_BTN2,   KC_HOME,                            KC_PGDN,    KC_PGUP,    KC_END,    KC_NO, KC_NO, KC_NO,
//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
 KC_TRNS, LGUI_T(KC_ESC), LALT_T(KC_MS_LEFT),   LSFT_T(KC_MS_DOWN),  LCTL_T(KC_MS_RIGHT),  KC_END,                            KC_H,  RCTL_T(KC_J), RSFT_T(KC_K), LALT_T(KC_L),   LGUI_T(KC_NO), KC_NO,
//├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
 KC_TRNS, KC_LSFT,    KC_MS_ACCEL0,      KC_INS,  KC_MS_ACCEL2,     KC_PSCR, KC_TRNS,          KC_TRNS, KC_LEFT,       KC_DOWN,    KC_UP,    KC_RGHT,    KC_NO, KC_NO,
//└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS
                            // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
),

[_SYMNUM] = LAYOUT(
//┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
 KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,                              KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,  KC_TRNS,
//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
 KC_TRNS, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
 KC_TRNS, LGUI_T(KC_1),  LALT_T(KC_2),   LSFT_T(KC_3),  LCTL_T(KC_4),  KC_5,                               KC_6,  RCTL_T(KC_7), RSFT_T(KC_8), LALT_T(KC_9),   LGUI_T(KC_0),     KC_NO,
//├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
 KC_TRNS, KC_LSFT, KC_LBRC, KC_RBRC,  KC_LCBR, KC_RCBR, KC_TRNS,          KC_TRNS, KC_GRV, KC_EQL,   KC_QUOT,   KC_MINS,   KC_BSLS, KC_NO,
//└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                KC_TRNS, KC_TRNS, KC_TRNS,                    KC_TRNS,  KC_TRNS, KC_TRNS
                            // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
),

[_FUNC] = LAYOUT(
//┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
 KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                              KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,
//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
 RGB_TOG, KC_NO, KC_NO,   KC_NO, KC_NO,  KC_NO,                            KC_NO, KC_F7, KC_F8, KC_F9, KC_F11, KC_NO,
//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
 RGB_MOD, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                            KC_NO,  KC_F4, KC_F5, KC_F6, KC_F12, KC_NO,
//├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
 QK_BOOT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS,          KC_TRNS, KC_F10, KC_F1,  KC_F2, KC_F3, KC_F13, KC_NO,
//└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS
                            // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
)
};

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//   switch (keycode) {
//     case CDH:
//       if (record->event.pressed) {
//         set_single_persistent_default_layer(_CDH);
//       }
//       return false;
//       break;
//     case LOWER:
//       if (record->event.pressed) {
//         layer_on(_LOWER);
//         update_tri_layer(_LOWER, _RAISE, _ADJUST);
//       } else {
//         layer_off(_LOWER);
//         update_tri_layer(_LOWER, _RAISE, _ADJUST);
//       }
//       return false;
//       break;
//     case RAISE:
//       if (record->event.pressed) {
//         layer_on(_RAISE);
//         update_tri_layer(_LOWER, _RAISE, _ADJUST);
//       } else {
//         layer_off(_RAISE);
//         update_tri_layer(_LOWER, _RAISE, _ADJUST);
//       }
//       return false;
//       break;
//     case ADJUST:
//       if (record->event.pressed) {
//         layer_on(_ADJUST);
//       } else {
//         layer_off(_ADJUST);
//       }
//       return false;
//       break;
//   }
//   return true;
// }

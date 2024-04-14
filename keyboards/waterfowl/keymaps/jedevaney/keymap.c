/* Copyright 2022  CyanDuck
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

// Define and configure combos
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

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _CDH, // 0 | Original | Home for encoders
    _NAV, // 1 | vi nav
    _SYMNUM, // 2 | combined
    _FUNC // 3 | Original | TapDance x2, hold to activate
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Colemak-DH
 *
 * ,----------------------------------.                      ,----------------------------------.
 * |   Q  |   W  |   F  |   P  |   B  |                      |   J  |   L  |   U  |   Y  |   ;  |
 * |------+------+------+------+------|                      |------+------+------+------+------|
 * |   A  |R,LALT|S,SHFT|T,CTRL| G,OS |                      | M,OS |N,CTRL|E,SHFT|I,RALT|   O  |
 * |------+------+------+------+------|  ,-----.    ,-----.  |------+------+------+------+------|
 * |Z,SHFT|   X  |C,COPY|   D  |V,PSTE|  | VOL |    | Page|  |   K  |   H  |   ,  |   .  |/,SHFT|
 * `----------------------------------'  `-----'    `-----'  `----------------------------------'
 *          ,------.  ,------------------------.    ,--------------------.   ,-----.
 *          |C+L/R |  | DEL,L3 |  BS,L1  |     |    |     | SPC,L2 | REP |   | L/R |
 *          `------'  `------------------------'    `--------------------'   `-----'
 */
[_CDH] = LAYOUT(
  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,         KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,
  LGUI_T(KC_A),    MT(MOD_LALT, KC_R),    MT(MOD_LSFT, KC_S),    MT(MOD_LCTL, KC_T),    KC_G,         KC_M,    MT(MOD_RCTL, KC_N),    MT(MOD_RSFT, KC_E),    MT(MOD_RALT, KC_I),    LGUI_T(KC_O),
  KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,         KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH,
  KC_NO, KC_NO, LT(3,KC_DEL), LT(1,KC_BSPC), KC_NO,         KC_NO, LT(2,KC_SPC), KC_ENT, QK_REP, KC_NO
),

/* NAV
 *
 * ,----------------------------------.                      ,----------------------------------.
 * |  TAB | BTN1 | M UP | BTN2 | Home |                      | Home |PgDown| PgUp |  End |      |
 * |------+------+------+------+------|                      |------+------+------+------+------|
 * |  ESC |M Left|M Down|M Rght| End  |                      |   H  |   J  |   K  |   L  |      |
 * |------+------+------+------+------|  ,-----.    ,-----.  |------+------+------+------+------|
 * | SHIFT| ACC0 |  INS | ACC2 |PRTSCR|  |C+d/u|    | n/N |  | Left | Down |  Up  | Right|      |
 * `----------------------------------'  `-----'    `-----'  `----------------------------------'
 *          ,-----.   ,--------------------.            ,--------------------.   ,-------.
 *          |     |   |     |       |      |            |       |    |       |   |       |
 *          `-----'   `--------------------'            `--------------------'   `-------'
 */
[_NAV] = LAYOUT(
//[_NAVNUM] = LAYOUT( // removed for line above
  KC_TAB,    KC_MS_BTN1,    KC_MS_UP,    KC_MS_BTN2,   KC_HOME,    KC_HOME,    KC_PGDN,    KC_PGUP,    KC_END,    KC_NO,
  LGUI_T(KC_ESC),  LALT_T(KC_MS_LEFT),   LSFT_T(KC_MS_DOWN),  LCTL_T(KC_MS_RIGHT),  KC_END,                 KC_H,  RCTL_T(KC_J), RSFT_T(KC_K), LALT_T(KC_L),   LGUI_T(KC_NO),
  KC_LSFT,    KC_MS_ACCEL0,      KC_INS,  KC_MS_ACCEL2,     KC_PSCR,    KC_LEFT,       KC_DOWN,    KC_UP,    KC_RGHT,    KC_NO,
  KC_TRNS ,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),

/* SYM
 *
 * ,----------------------------------.                      ,----------------------------------.
 * |   !  |   @  |   #  |   $  |   %  |                      |   ^  |   &  |   *  |   (  |   )  |
 * |------+------+------+------+------|                      |------+------+------+------+------|
 * |   1  |   2  |   3  |   4  |   5  |                      |   6  |   7  |   8  |   9  |   0  |
 * |------+------+------+------+------|  ,-----.    ,-----.  |------+------+------+------+------|
 * |LSHIFT|  [{  |  ]}  |   {  |   }  |  |     |    |     |  |  ~`  |   =+ |  '"  |  -_  |  \|  |
 * `----------------------------------'  `-----'    `-----'  `----------------------------------'
 *          ,-----.   ,--------------------.            ,--------------------.   ,-----.
 *          |     |   |     |       |      |            |       |    |       |   |     |
 *          `-----'   `--------------------'            `--------------------'   `-----'
 */
[_SYMNUM] = LAYOUT(
//[_SYM] = LAYOUT( // removed line for above
  KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC,          KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
  LGUI_T(KC_1),  LALT_T(KC_2),   LSFT_T(KC_3),  LCTL_T(KC_4),  KC_5,                 KC_6,  RCTL_T(KC_7), RSFT_T(KC_8), LALT_T(KC_9),   LGUI_T(KC_0),
  KC_LSFT, KC_LBRC, KC_RBRC,  KC_LCBR, KC_RCBR,      KC_GRV, KC_EQL,   KC_QUOT,   KC_MINS,   KC_BSLS,
  KC_TRNS ,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),

/* FUNC
 *
 * ,----------------------------------.                      ,----------------------------------.
 * |      |      |      |      |      |                      |      |  F7  |  F8  |  F9  |  F11 |
 * |------+------+------+------+------|                      |------+------+------+------+------|
 * |      |      |      |      |      |                      |      |  F4  |  F5  |  F6  |  F12 |
 * |------+------+------+------+------|  ,-----.    ,-----.  |------+------+------+------+------|
 * | Reset|      |      |      |      |  |     |    |     |  |  F10 |  F1  |  F2  |  F3  |  F13 |
 * `----------------------------------'  `-----'    `-----'  `----------------------------------'
 *          ,-----.   ,--------------------.            ,--------------------.   ,-----.
 *          |     |   |     |       |      |            |       |    |       |   |     |
 *          `-----'   `--------------------'            `--------------------'   `-----'
 */
[_FUNC] =  LAYOUT(
  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,        KC_NO,   KC_F7,   KC_F8,   KC_F9,   KC_F11,
  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,        KC_NO,   KC_F4,   KC_F5,   KC_F6,   KC_F12,
  QK_BOOT, KC_NO,   KC_NO,   KC_NO,   KC_NO,        KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_F13,
  KC_TRNS ,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),
};

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

// Define and configure macros
enum combos {
  ALT_L,
  ALT_R,
  CTRL_L,
  CTRL_R,
  TC_ENTER,
  IO_ENTER,
  QW_ESC,
  AR_CAPS
};

const uint16_t PROGMEM alt_l_combo[] = {KC_M, KC_N, COMBO_END};
const uint16_t PROGMEM alt_r_combo[] = {KC_E, KC_I, COMBO_END};
const uint16_t PROGMEM ctrl_l_combo[] = {KC_K, KC_H, COMBO_END};
const uint16_t PROGMEM ctrl_r_combo[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM tc_enter_combo[] = {KC_BSPC, KC_SPC, COMBO_END};
const uint16_t PROGMEM enter_combo[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM esc_combo[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM caps_combo[] = {KC_A, KC_R, COMBO_END};

combo_t key_combos[] = {
  [ALT_L] = COMBO(alt_l_combo, LALT(KC_LEFT)),
  [ALT_R] = COMBO(alt_r_combo, LALT(KC_RIGHT)),
  [CTRL_L] = COMBO(ctrl_l_combo, LCTL(KC_LEFT)),
  [CTRL_R] = COMBO(ctrl_r_combo, LCTL(KC_RIGHT)),
  [TC_ENTER] = COMBO(tc_enter_combo, KC_ENT),
  [IO_ENTER] = COMBO(esc_combo, KC_ENT),
  [QW_ESC] = COMBO(esc_combo, KC_ESC),
  [AR_CAPS] = COMBO(esc_combo, CW_TOGG),
};

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _COLEMAKDH, // 0 | Original | Home for encoders
    _NAVNUM, //Original, split for vi nav
    // _NAV // 1 | vi nav
    _SYM, // Original, change to SYMNUM
    // _SYMNUM // 2 | combined
    _FUNC, // 3 | Original | TapDance x2, hold to activate
    _GAME // 4 | Original, remove?
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
 *          |C+L/R |  | DEL,L3 | BS,L1,RET |RET|    |  | SPC,RET | BS,L2 |   | L/R |
 *          `------'  `------------------------'    `--------------------'   `-----'
 */
[_COLEMAKDH] = LAYOUT(
  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,         KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,
  KC_A,    MT(MOD_LALT, KC_R),    MT(MOD_LSFT, KC_S),    MT(MOD_LCTL, KC_T),    LGUI_T(KC_G),         LGUI_T(KC_M),    MT(MOD_RCTL, KC_N),    MT(MOD_RSFT, KC_E),    MT(MOD_RALT, KC_I),    KC_O,
  LSFT_T(KC_Z),    KC_X,    KC_C,    KC_D,    KC_V,         KC_K,    KC_H,    KC_COMM, KC_DOT,  RSFT_T(KC_SLSH),
  KC_1, LT(3,KC_DEL), LT(1,KC_BSPC), KC_ENT, KC_2,         KC_3, KC_NO, KC_SPC, LT(2,KC_ENT), KC_4
),

/* NAV
 *
 * ,----------------------------------.                      ,----------------------------------.
 * |  ESC | PgUp |  UP  | PgDn | TO(4)|                      |   /  |   7  |   8  |   9  |   -  |
 * |  ESC | PgUp |  UP  | PgDn | TO(4)|                      |      |  INS |      |      |      |
 * |------+------+------+------+------|                      |------+------+------+------+------|
 * | Home | Left | Down | Right| End  |                      |   =  |   4  |   5  |   6  |   +  |
 * |  TAB | Left | Down | Right| End  |                      | Left | Down |  Up  | Right|      |
 * |------+------+------+------+------|  ,-----.    ,-----.  |------+------+------+------+------|
 * |      |      |  INS | TO(2)|      |  |  2  |    |  3  |  |   0  |   1  |   2  |   3  |   *  |
 * | SHIFT|      |  INS |      |PRTSCR|  |C+d/u|    | n/N |  | Home |PgDown| PgUp |  End |      |
 * `----------------------------------'  `-----'    `-----'  `----------------------------------'
 *          ,-----.   ,--------------------.            ,--------------------.   ,-------. 
 *          |  1  |   | DEL | SPACE | MO(3)|            | TO(0) | BS | ENTER |   |Alt+L/R|
 *          `-----'   `--------------------'            `--------------------'   `-------'
 */
//[_NAV] = LAYOUT(
[_NAVNUM] = LAYOUT( // remove for line above
  KC_ESC,    KC_PGUP,    KC_UP,    KC_PGDN,   TO(4),    KC_SLSH,    KC_7,    KC_8,    KC_9,    KC_MINS,
  KC_HOME,   KC_LEFT,    KC_DOWN,  KC_RGHT,   KC_END,  KC_EQL,     KC_4,    KC_5,    KC_6,    KC_PLUS,
  KC_NO,    KC_NO,      KC_INS,   TO(2),     KC_NO,    KC_0,       KC_1,    KC_2,    KC_3,    KC_ASTR,
  KC_1, LT(3,KC_DEL), LT(1,KC_SPC), KC_ESC, KC_2,         KC_3, TO(0), KC_BSPC, LT(2,KC_ENT), KC_4
),

/* SYM
 *
 * ,----------------------------------.                      ,----------------------------------.
 * |   1  |   2  |   3  |   4  |   5  |                      |   6  |   7  |   8  |   9  |   0  |
 * |------+------+------+------+------|                      |------+------+------+------+------|
 * |   !  |   @  |   #  |   $  |   %  |                      |   ^  |   &  |   *  |   (  |   )  |
 * |------+------+------+------+------|  ,-----.    ,-----.  |------+------+------+------+------|
 * |   [  |   ]  |   {  |   }  |  ~`  |  |     |    |     |  |   _  |   -  |   '  |   "  |  \|  |
 * `----------------------------------'  `-----'    `-----'  `----------------------------------'
 *          ,-----.   ,--------------------.            ,--------------------.   ,-----. 
 *          |     |   |     |       |      |            |       |    |       |   |     |
 *          `-----'   `--------------------'            `--------------------'   `-----'
 */
//[_SYMNUM] = LAYOUT(
[_SYM] = LAYOUT( // remove line for above
  KC_PERC, S(KC_QUOT),   KC_LBRC, KC_RBRC,  KC_NUBS,     RALT(KC_GRV), S(KC_GRV), KC_CIRC, KC_NO,   KC_NO,
  KC_NONUS_HASH, KC_EXLM, KC_LPRN, KC_RPRN, S(KC_NUBS),      KC_UNDS, KC_QUOT, S(KC_2), S(KC_NUHS), KC_GRV,
  KC_DLR, S(KC_3),  KC_LCBR, KC_RCBR, KC_AMPR,      TO(1), KC_NO,   KC_NO,   KC_NO,   KC_NO,
  KC_1, LT(3,KC_DEL), LT(1,KC_SPC), KC_TAB, KC_2,         KC_3, TO(0), KC_BSPC, LT(2,KC_ENT), KC_4
),

/* FUNC
 *
 * ,----------------------------------.                      ,----------------------------------.
 * |      |      |      |      |      |                      |      |  F7  |  F8  |  F9  |  F11 |
 * |------+------+------+------+------|                      |------+------+------+------+------|
 * |      |      |      |      |      |                      |      |  F4  |  F5  |  F6  |  F12 |
 * |------+------+------+------+------|  ,-----.    ,-----.  |------+------+------+------+------|
 * | Reset|      |      |      |      |  |  2  |    |  3  |  |  F10 |  F1  |  F2  |  F3  |  F13 |
 * `----------------------------------'  `-----'    `-----'  `----------------------------------'
 *          ,-----.   ,--------------------.            ,--------------------.   ,-----. 
 *          |  1  |   | DEL | SPACE | TAB  |            | TO(0) | BS | ENTER |   |  4  |
 *          `-----'   `--------------------'            `--------------------'   `-----'
 */
[_FUNC] =  LAYOUT(
  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,        KC_NO,   KC_F7,   KC_F8,   KC_F9,   KC_F11,
  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,        KC_NO,   KC_F4,   KC_F5,   KC_F6,   KC_F12,
  QK_BOOT, KC_NO,   KC_NO,   KC_NO,   KC_NO,        KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_F13,
  KC_1, LT(3,KC_DEL), LT(1,KC_SPC), KC_TAB, KC_2,         KC_3, TO(0), KC_BSPC, LT(2,KC_ENT), KC_4
),
};

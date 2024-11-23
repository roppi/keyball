/*
Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#include "quantum.h"

// ======================================================================
// Keymap
// ======================================================================
// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_universal(
// Default (Alphabet) Key Layer
// +----------+----------+----------+----------+----------+----------+                                  +----------+----------+----------+----------+----------+----------+
    KC_ESC    ,KC_Q      ,KC_W      ,KC_E      ,KC_R      ,KC_T      ,                                   KC_Y      ,KC_U      ,KC_I      ,KC_O      ,KC_P      ,KC_DEL    ,
// +----------+----------+----------+----------+----------+----------+                                  +----------+----------+----------+----------+----------+----------+
    KC_TAB    ,KC_A      ,KC_S      ,KC_D      ,KC_F      ,KC_G      ,                                   KC_H      ,KC_J      ,KC_K      ,KC_L      ,KC_SCLN   ,S(KC_7)   ,
// +----------+----------+----------+----------+----------+----------+                                  +----------+----------+----------+----------+----------+----------+
    KC_LSFT   ,KC_Z      ,KC_X      ,KC_C      ,KC_V      ,KC_B      ,                                   KC_N      ,KC_M      ,KC_COMM   ,KC_DOT    ,KC_SLSH   ,KC_INT1   ,
// +----------+----------+----------+------+---+------+---+------+---+------+                    +------+---+------+---+------+----------+----------+----------+----------+
               KC_LALT   ,KC_LGUI   , LCTL_T(KC_LNG2),LT(1,KC_SPC),LT(3,KC_LNG1),                 KC_BSPC ,LT(2,KC_ENT),       _______   ,_______   ,KC_PSCR
//            +----------+----------+      +----------+----------+----------+                    +----------+----------+                            +----------+
  ),

  [1] = LAYOUT_universal(
// Signs & Function Key Layer
// +----------+----------+----------+----------+----------+----------+                                  +----------+----------+----------+----------+----------+----------+
    _______   ,KC_F1     ,KC_F2     ,KC_F3     ,KC_F4     ,S(KC_8)   ,                                   S(KC_9)   ,S(KC_1)   ,S(KC_6)   ,KC_LBRC   ,S(KC_4)   ,_______   ,
// +----------+----------+----------+----------+----------+----------+                                  +----------+----------+----------+----------+----------+----------+
    _______   ,KC_F5     ,KC_F6     ,KC_F7     ,KC_F8     ,S(KC_RBRC),                                   S(KC_NUHS),KC_MINS   ,S(KC_EQL) ,S(KC_3)   ,KC_QUOT   ,S(KC_2)   ,
// +----------+----------+----------+----------+----------+----------+                                  +----------+----------+----------+----------+----------+----------+
    _______   ,KC_F9     ,KC_F10    ,KC_F11    ,KC_F12    ,KC_RBRC   ,                                   KC_NUHS   ,S(KC_INT1),KC_EQL    ,S(KC_LBRC),S(KC_SLSH),S(KC_INT3),
// +----------+----------+----------+------+---+------+---+------+---+------+                    +------+---+------+---+------+----------+----------+----------+----------+
               _______   ,_______   ,       _______   ,_______   ,_______   ,                     _______   ,_______   ,       _______   ,_______   ,_______
//            +----------+----------+      +----------+----------+----------+                    +----------+----------+                            +----------+
  ),

  [2] = LAYOUT_universal(
// NumPad & Mouse Layer
// +----------+----------+----------+----------+----------+----------+                                  +----------+----------+----------+----------+----------+----------+
    _______  ,KC_KP_EQUAL,KC_KP_7   ,KC_KP_8   ,KC_KP_9   ,KC_KP_MINUS,                                  AML_TO    ,AML_I50   ,AML_D50   ,CPI_I100  ,CPI_D100  ,SSNP_VRT  ,
// +----------+----------+----------+----------+----------+----------+                                  +----------+----------+----------+----------+----------+----------+
    _______   ,KC_KP_PLUS,KC_KP_4   ,KC_KP_5   ,KC_KP_6   ,KC_KP_ASTERISK,                               KC_PGUP   ,KC_BTN1   ,KC_BTN3   ,KC_BTN2   ,SCRL_MO   ,SSNP_HOR  ,
// +----------+----------+----------+----------+----------+----------+                                  +----------+----------+----------+----------+----------+----------+
    _______   ,KC_KP_0   ,KC_KP_1   ,KC_KP_2   ,KC_KP_3   ,KC_KP_SLASH,                                  KC_PGDN   ,KC_LEFT   ,KC_DOWN   ,KC_UP     ,KC_RGHT   ,SSNP_FRE  ,
// +----------+----------+----------+------+---+------+---+------+---+------+                    +------+---+------+---+------+----------+----------+----------+----------+
               KC_KP_DOT ,_______   ,       _______   ,_______   ,_______   ,                     _______   ,_______   ,       _______   ,_______   ,_______
//            +----------+----------+      +----------+----------+----------+                    +----------+----------+                            +----------+
  ),

  [3] = LAYOUT_universal(
// +----------+----------+----------+----------+----------+----------+                                  +----------+----------+----------+----------+----------+----------+
    RGB_TOG   ,AML_TO    ,AML_I50   ,AML_D50   ,_______   ,_______   ,                                   RGB_M_P   ,RGB_M_B   ,RGB_M_R   ,RGB_M_SW  ,RGB_M_SN  ,RGB_M_K   ,
// +----------+----------+----------+----------+----------+----------+                                  +----------+----------+----------+----------+----------+----------+
    RGB_MOD   ,RGB_HUI   ,RGB_SAI   ,RGB_VAI   ,_______   ,SCRL_DVI  ,                                   RGB_M_X   ,RGB_M_G   ,RGB_M_T   ,RGB_M_TW  ,_______   ,_______   ,
// +----------+----------+----------+----------+----------+----------+                                  +----------+----------+----------+----------+----------+----------+
    RGB_RMOD  ,RGB_HUD   ,RGB_SAD   ,RGB_VAD   ,_______   ,SCRL_DVD  ,                                   CPI_D1K   ,CPI_D100  ,CPI_I100  ,CPI_I1K   ,_______   ,KBC_SAVE  ,
// +----------+----------+----------+------+---+------+---+------+---+------+                    +------+---+------+---+------+----------+----------+----------+----------+
               QK_BOOT   ,KBC_RST   ,       _______   ,_______   ,_______   ,                     _______   ,_______   ,       _______   ,_______   ,QK_BOOT
//            +----------+----------+      +----------+----------+----------+                    +----------+----------+                            +----------+
  ),
};
// clang-format on


// ======================================================================
// Functions
// ======================================================================

layer_state_t layer_state_set_user(layer_state_t state) {
  // Auto enable scroll mode when the highest layer is 3
  keyball_set_scroll_mode(get_highest_layer(state) == 3);
  return state;
}

#ifdef OLED_ENABLE
# include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
  keyball_oled_render_keyinfo();
  keyball_oled_render_ballinfo();
  keyball_oled_render_layerinfo();
}
#endif

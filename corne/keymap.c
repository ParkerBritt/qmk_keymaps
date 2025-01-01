/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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
#include "render.h"

// home row mods
#define GUI_A LALT_T(KC_A)
#define ALT_S LALT_T(KC_S)
#define SFT_D LALT_T(KC_D)
#define CTL_F LALT_T(KC_F)

enum layers {
    _BASE,
    _LOWER,
    _RAISE,
    _ADJUST,
    _GAMING,
    _HOUDINI,
    _SWITCHER
};

// ----- oled -------
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}


static void render_icon(void) {
    switch (get_highest_layer(layer_state)) {
        case _BASE:
			render_kitty_anim();
            break;
        case _LOWER:
            render_lower();
            break;
        case _RAISE:
            render_raise();
            break;
        case _GAMING:
            render_gaming();
            break;
        case _ADJUST:
            render_switcher();
            break;
        case _HOUDINI:
            render_houdini();
            break;
        case _SWITCHER:
            render_switcher();
            break;
        default:
            oled_write_P(PSTR("Undefined"), false);
    }
}

static void render_layer_status(void) {
    switch (get_highest_layer(layer_state)) {
        case _BASE:
            oled_write_P(PSTR("Layer-----base"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Layer-----lower"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Layer-----raise"), false);
            break;
        case _GAMING:
            oled_write_P(PSTR("Layer-----game"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Layer-----adjst"), false);
            break;
        case _HOUDINI:
            oled_write_P(PSTR("Layer-----hdini"), false);
            break;
        case _SWITCHER:
            oled_write_P(PSTR("Layer-----switcher"), false);
            break;
        default:
            oled_write_P(PSTR("Undefined"), false);
    }
}

// #ifdef OLED_DRIVER_ENABLE
bool oled_task_user(void) {
     // if (is_keyboard_master()) {
        oled_clear();
        oled_set_cursor(0,5);
        render_icon();
        oled_set_cursor(0,0);
        render_layer_status();
    // }
    // else{
    //     oled_set_cursor(0,4);
    //     render_kitty_anim();
    //     render_layer_status();
    // }



    // render_icon();
    return false;
}


bool shutdown_user(bool jump_to_bootloader) {
    oled_render_boot(jump_to_bootloader);
    return false;
}
// ----------------
// #endif


// TODO: add houdini layer (F2, delete)
// TODO: add function keys
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = { // default
    [_BASE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,   KC_ESC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,   GUI_A,   ALT_S,   SFT_D,    CTL_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ENT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   MO(_LOWER),  KC_SPC,    KC_BSPC,   MO(_RAISE), KC_RALT
                                      //`--------------------------'  `--------------------------'

  ),

    [_LOWER] = LAYOUT_split_3x6_3( // lower
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LCBR, KC_RCBR, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       KC_EQL, KC_UNDS, KC_BSLS, KC_LPRN, KC_RPRN, KC_TILD,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_PLUS, KC_MINS, KC_PIPE, KC_LBRC, KC_RBRC,  KC_GRV,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,  KC_DELETE,   MO(_ADJUST), KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

    [_RAISE] = LAYOUT_split_3x6_3( // raise
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,KC_MEDIA_PLAY_PAUSE,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   MO(_ADJUST),  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

    [_ADJUST] = LAYOUT_split_3x6_3( // adjust
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
  TG(_GAMING),TG(_HOUDINI), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX,KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RM_TOGG, RM_HUEU, RM_SATU, RM_VALU, XXXXXXX, KC_HOME,                       KC_END, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RM_NEXT, RM_HUED, RM_SATD, RM_VALD, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),
   [_GAMING] = LAYOUT_split_3x6_3( // gaming
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,   KC_ESC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ENT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,  TG(_GAMING),  KC_SPC,    KC_BSPC,MO(_ADJUST), KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),
  [_HOUDINI] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_Y,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,   KC_ESC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,   GUI_A,   ALT_S,   SFT_D,    CTL_F,   KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ENT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   TG(_HOUDINI),  KC_SPC,    KC_BSPC,MO(_SWITCHER), KC_RALT
                                      //`--------------------------'  `--------------------------'

  ),
  [_SWITCHER] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     TO(_GAMING),TO(_HOUDINI),KC_W, KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,   KC_ESC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,   GUI_A,   ALT_S,   SFT_D,    CTL_F,   KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ENT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   TG(_HOUDINI),  KC_SPC,    KC_BSPC,MO(_ADJUST), KC_RALT
                                      //`--------------------------'  `--------------------------'

  ),
};


#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [1] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [2] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [3] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
};
#endif

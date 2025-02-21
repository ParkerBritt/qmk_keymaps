#include QMK_KEYBOARD_H

// Home row mods
#define GUI_A LALT_T(KC_A)
#define ALT_S LALT_T(KC_S)
#define SFT_D LALT_T(KC_D)
#define CTL_F LALT_T(KC_F)

enum layers {
    _BASE,
    _LOWER,
    _RAISE,
    _ADJUST,
};



// KEYMAPS
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
         KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,   KC_ESC,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LCTL,   KC_A,   KC_S,   KC_D,   CTL_F,   KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LSFT,   KC_Z,    KC_X,    KC_C,    KC_V,   KC_B, XXXXXXX,             XXXXXXX,   KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ENT,
    //|--------------------------+--------------------------|                    |--------------------------+--------------------------|
                            KC_LALT, KC_LGUI, MO(_LOWER),KC_SPC,           KC_BSPC, MO(_RAISE), KC_RALT, KC_RALT
    ),

    [_LOWER] = LAYOUT(
         KC_ENT, KC_6, KC_7, KC_8, KC_9, KC_0,               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
         KC_ESC, KC_EXLM,   KC_AT,  KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LCBR, KC_RCBR, KC_BSPC,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_EQL,  KC_UNDS, KC_BSLS, KC_LPRN, KC_RPRN, KC_TILD,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,_______,_______,                      KC_PLUS, KC_MINS, KC_PIPE, KC_LBRC, KC_RBRC,  KC_GRV,
    //|--------------------------+--------------------------|                    |--------------------------+--------------------------|
                                          _______,  KC_LGUI, _______, KC_SPC,  KC_DELETE, MO(_ADJUST), KC_RALT, _______
    ),

    [_RAISE] = LAYOUT(
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
         KC_TAB,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MPLY,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_LEFT, KC_DOWN,  KC_UP, KC_RIGHT, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,_______,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //|--------------------------+--------------------------|                    |--------------------------+--------------------------|
                                         _______,   KC_LGUI, MO(_ADJUST), KC_SPC, KC_ENT, _______, KC_RALT, _______
    ),

    [_ADJUST] = LAYOUT(
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,               QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, KC_MPRV, KC_MNXT,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_HOME,                      KC_END, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,  _______,                   _______,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
    //|--------------------------+--------------------------|                    |--------------------------+--------------------------|
                                          _______,  KC_LGUI, _______, KC_SPC, KC_ENT, _______, KC_RALT, _______
    )
};


#include QMK_KEYBOARD_H

#define BASE 0
#define SYMB 1
#define ARRW 2
#define NUMB 3

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT(
        KC_Q, KC_W, KC_E, LALT_T(KC_R), KC_T,                                                       KC_Y, LALT_T(KC_U), KC_I, KC_O, KC_P,
        LSFT_T(KC_A), LCTL_T(KC_S), RALT_T(KC_D), LGUI_T(KC_F), KC_G,                               KC_H, RGUI_T(KC_J), RALT_T(KC_K), RCTL_T(KC_L), RSFT_T(KC_SCLN),
        KC_Z, KC_X, KC_C, KC_V, KC_B,                                                               KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,
        TO(SYMB), KC_SPC,                                                                           KC_BSPC, TO(ARRW)),
    [SYMB] = LAYOUT(
        KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC,                                                   KC_ASTR, KC_SCLN, KC_UNDS, KC_CIRC, KC_AMPR,
        KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, KC_COLN,                                                KC_LCBR, KC_LBRC, KC_LPRN, KC_GRV, KC_TILD,
        KC_PIPE, KC_BSLS, KC_PLUS, KC_EQL, KC_MINS,                                                 KC_RCBR, KC_RBRC, KC_RPRN, KC_TILD, KC_LABK,
        TO(NUMB), TO(BASE),                                                                         TO(BASE), TO(NUMB)),
    [ARRW] = LAYOUT(
        LGUI(KC_1), LGUI(KC_2), LGUI(KC_3), LGUI(KC_4), _______,                                    LCTL(KC_B), LALT(KC_1), LALT(KC_2), LALT(KC_3), LALT(KC_4),
        KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, KC_TAB,                                                 KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, CW_TOGG,
        _______, _______, _______, _______, _______,                                                KC_HOME, KC_PGDN, KC_PGUP, KC_END, _______,
        TO(NUMB), TO(BASE),                                                                         TO(BASE), TO(NUMB)),
    [NUMB] = LAYOUT(
        KC_1, KC_2, KC_3, KC_4, KC_5,                                                               KC_6, KC_7, KC_8, KC_9, KC_0,
        KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, _______,                                                _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT,
        _______, _______, _______, _______, _______,                                                _______, _______, KC_COMM, KC_DOT, KC_SLSH,
        TO(BASE), TO(BASE),                                                                          TO(BASE), TO(BASE)),
};

enum combos {
    RT_ESC,
    FG_ENT,
    HJ_TAB,
    YU_UP,
    NM_DOWN,
    JK_RIGHT,
};

const uint16_t PROGMEM rt_combo[] = {LALT_T(KC_R), KC_T, COMBO_END};
const uint16_t PROGMEM fg_combo[] = {LGUI_T(KC_F), KC_G, COMBO_END};
const uint16_t PROGMEM hj_combo[] = {KC_H, RGUI_T(KC_J), COMBO_END};
const uint16_t PROGMEM yu_combo[] = {KC_Y, LALT_T(KC_U), COMBO_END};
const uint16_t PROGMEM nm_combo[] = {KC_N, KC_M, COMBO_END};
const uint16_t PROGMEM jk_combo[] = {RGUI_T(KC_J), RALT_T(KC_K), COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    [RT_ESC] = COMBO(rt_combo, KC_ESC),
    [FG_ENT] = COMBO(hj_combo, KC_ENT),
    [HJ_TAB] = COMBO(fg_combo, KC_TAB),
    [YU_UP] = COMBO(yu_combo, KC_UP),
    [NM_DOWN] = COMBO(nm_combo, KC_DOWN),
    [JK_RIGHT] = COMBO(jk_combo, KC_RIGHT),
};

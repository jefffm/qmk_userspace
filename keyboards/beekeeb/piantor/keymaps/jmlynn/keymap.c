#include "keymap_steno.h"

#include QMK_KEYBOARD_H

enum layers {
    DEF,
    SYM,
    NAV,
    NUM,
    STENO,
};

// layers
#define LA_SYM MO(SYM)
#define LA_NAV MO(NAV)

// oneshot mods
#define OS_LSFT OSM(MOD_LSFT)
#define OS_LALT OSM(MOD_LALT)
#define OS_LCTL OSM(MOD_LCTL)
#define OS_LGUI OSM(MOD_LGUI)
#define OS_RSFT OSM(MOD_RSFT)
#define OS_RALT OSM(MOD_RALT)
#define OS_RCTL OSM(MOD_RCTL)
#define OS_RGUI OSM(MOD_RGUI)

// misc
#define SSHOT SGUI(KC_S)
#define UNDO C(KC_Z)
#define REDO C(S(KC_Z))
#define CUT C(KC_X)
#define COPY C(KC_C)
#define PASTE C(KC_V)
#define TAB_CLS C(KC_W)
#define TAB_NEW C(KC_T)
#define TAB_PREV C(S(KC_TAB))
#define TAB_NEXT C(KC_TAB)
#define BACK KC_WBAK
#define FWD KC_WFWD

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [DEF] = LAYOUT_split_3x6_3(
        XXXXXXX, KC_QUOT,    KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L, TO(STENO),
        XXXXXXX,   KC_A,       KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S, XXXXXXX,
        XXXXXXX,   KC_SCLN,    KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z, XXXXXXX,
                                   KC_SPC, KC_BSPC, LA_NAV, LA_SYM, KC_SPC, XXXXXXX
    ),

    [SYM] = LAYOUT_split_3x6_3(
        _______, KC_ESC,  KC_LBRC, KC_LCBR, KC_LPRN, KC_TILD, KC_CIRC, KC_RPRN,  KC_RCBR, KC_RBRC, KC_GRV,  _______,
        _______, KC_MINS, KC_ASTR, KC_EQL,  KC_UNDS, KC_DLR,  KC_HASH, OS_RSFT, OS_RCTL, OS_RALT,  OS_RGUI, _______,
        _______, KC_PLUS, KC_PIPE, KC_AT,   KC_SLSH, KC_PERC, XXXXXXX, KC_BSLS,  KC_AMPR, KC_QUES, KC_EXLM, _______,
                                   _______, KC_ESC, _______, _______, _______, _______
    ),

    [NAV] = LAYOUT_split_3x6_3(
        _______, REDO,    SSHOT,    COPY,     PASTE,    CUT,     KC_TAB,  KC_HOME, KC_UP,   KC_END,  KC_DEL,  _______,
        _______, OS_LGUI, OS_LALT,  OS_LCTL,  OS_LSFT,  XXXXXXX, CW_TOGG, KC_LEFT, KC_DOWN, KC_RGHT, KC_BSPC, _______,
        _______, UNDO,    TAB_NEW,  TAB_PREV, TAB_NEXT, TAB_CLS, XXXXXXX, KC_PGDN, KC_PGUP, BACK,    FWD,     _______,
                                   _______, _______, _______, _______, KC_ENT, _______

    ),

    [NUM] = LAYOUT_split_3x6_3(
        _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
        _______, OS_LGUI, OS_LALT, OS_LCTL, OS_LSFT, KC_F11,  KC_F12,  OS_RSFT, OS_RCTL, OS_RALT, OS_RGUI, _______,
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
                                   _______, KC_ESC, _______, _______, KC_ENT, _______
    ),

    [STENO] = LAYOUT_split_3x6_3(
        STN_FN,  STN_S1,  STN_TL,  STN_PL,  STN_HL,  STN_ST1,       STN_ST3, STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR,
        STN_PWR, STN_S2,  STN_KL,  STN_WL,  STN_RL,  STN_ST2,       STN_ST4, STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR,
        TO(DEF), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                   STN_A,   STN_O,   STN_N1,        STN_N7,  STN_E,   STN_U
    )
};
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, SYM, NAV, NUM);
}

void matrix_init_user(void) {
    steno_set_mode(STENO_MODE_GEMINI); // or STENO_MODE_BOLT
}

#pragma once

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

enum custom_keycodes { KC_HACKPIPE = SAFE_RANGE };

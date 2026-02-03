#include QMK_KEYBOARD_H

enum layers {
    DEF,
    SYM,
    NAV,
    NUM,
    SYS,
    TMUX,
    GAME,
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

// Combos
enum combo_events {
    CMB_LBKT,   // [ - left bracket
    CMB_LBRC,   // { - left brace
    CMB_LPRN,   // ( - left paren
    CMB_RPRN,   // ) - right paren
    CMB_RBRC,   // } - right brace
    CMB_RBKT,   // ] - right bracket
    CMB_LSFT,   // oneshot left shift
    CMB_RSFT,   // oneshot right shift
    CMB_CW,     // caps word
    CMB_CAPS,   // caps lock
    CMB_ESC,    // escape
    CMB_ENT,    // enter
    CMB_SYS,    // SYS layer
};

const uint16_t PROGMEM combo_lbkt[] = {KC_COMM, KC_O, COMBO_END};
const uint16_t PROGMEM combo_lbrc[] = {KC_DOT, KC_E, COMBO_END};
const uint16_t PROGMEM combo_lprn[] = {KC_P, KC_U, COMBO_END};
const uint16_t PROGMEM combo_rprn[] = {KC_G, KC_H, COMBO_END};
const uint16_t PROGMEM combo_rbrc[] = {KC_C, KC_T, COMBO_END};
const uint16_t PROGMEM combo_rbkt[] = {KC_R, KC_N, COMBO_END};
const uint16_t PROGMEM combo_lsft[] = {KC_DOT, KC_P, COMBO_END};
const uint16_t PROGMEM combo_rsft[] = {KC_G, KC_C, COMBO_END};
const uint16_t PROGMEM combo_cw[]   = {KC_QUOT, KC_L, COMBO_END};
const uint16_t PROGMEM combo_caps[] = {KC_SCLN, KC_Z, COMBO_END};
const uint16_t PROGMEM combo_esc[]  = {KC_O, KC_E, KC_U, COMBO_END};
const uint16_t PROGMEM combo_ent[]  = {KC_H, KC_T, KC_N, COMBO_END};
const uint16_t PROGMEM combo_sys[]  = {KC_BSPC, LA_SYM, COMBO_END};

combo_t key_combos[] = {
    [CMB_LBKT] = COMBO(combo_lbkt, KC_LBRC),
    [CMB_LBRC] = COMBO(combo_lbrc, KC_LCBR),
    [CMB_LPRN] = COMBO(combo_lprn, KC_LPRN),
    [CMB_RPRN] = COMBO(combo_rprn, KC_RPRN),
    [CMB_RBRC] = COMBO(combo_rbrc, KC_RCBR),
    [CMB_RBKT] = COMBO(combo_rbkt, KC_RBRC),
    [CMB_LSFT] = COMBO(combo_lsft, OS_LSFT),
    [CMB_RSFT] = COMBO(combo_rsft, OS_RSFT),
    [CMB_CW]   = COMBO(combo_cw, CW_TOGG),
    [CMB_CAPS] = COMBO(combo_caps, KC_CAPS),
    [CMB_ESC]  = COMBO(combo_esc, KC_ESC),
    [CMB_ENT]  = COMBO(combo_ent, KC_ENT),
    [CMB_SYS]  = COMBO(combo_sys, MO(SYS)),
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [DEF] = LAYOUT_split_3x5_3(
  //┌────────┬────────┬────────┬────────┬────────┐  ┌────────┬────────┬────────┬────────┬────────┐
     KC_QUOT ,KC_COMM , KC_DOT , KC_P   , KC_Y   ,    KC_F   , KC_G   , KC_C   , KC_R   , KC_L   ,
  //├────────┼────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┼────────┤
     KC_A    , KC_O   , KC_E   , KC_U   , KC_I   ,    KC_D   , KC_H   , KC_T   , KC_N   , KC_S   ,
  //├────────┼────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┼────────┤
     KC_SCLN , KC_Q   , KC_J   , KC_K   , KC_X   ,    KC_B   , KC_M   , KC_W   , KC_V   , KC_Z   ,
  //└────────┴────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┴────────┘
                        KC_BSPC, LA_NAV , XXXXXXX,    XXXXXXX, LA_SYM , KC_SPC
  //                  └────────┴────────┴────────┘  └────────┴────────┴────────┘
    ),

    [SYM] = LAYOUT_split_3x5_3(
  //┌────────┬────────┬────────┬────────┬────────┐  ┌────────┬────────┬────────┬────────┬────────┐
     KC_ESC  ,KC_LBRC ,KC_LCBR ,KC_LPRN ,KC_TILD ,   KC_CIRC ,KC_RPRN ,KC_RCBR ,KC_RBRC ,KC_GRV  ,
  //├────────┼────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┼────────┤
     KC_MINS ,KC_ASTR ,KC_EQL  ,KC_UNDS ,KC_DLR  ,   KC_HASH ,OS_RSFT ,OS_RCTL ,OS_RALT ,OS_RGUI ,
  //├────────┼────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┼────────┤
     KC_PLUS ,KC_PIPE , KC_AT  , KC_SLSH, KC_PERC,   KC_HACKPIPE ,KC_BSLS ,KC_AMPR ,KC_QUES ,KC_EXLM ,
  //└────────┴────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┴────────┘
                        _______, _______, _______,    _______, _______, _______
  //                  └────────┴────────┴────────┘  └────────┴────────┴────────┘
    ),

    [NAV] = LAYOUT_split_3x5_3(
  //┌────────┬────────┬────────┬────────┬────────┐  ┌────────┬────────┬────────┬────────┬────────┐
     REDO    , SSHOT  , COPY   , PASTE  , CUT    ,   KC_TAB  ,KC_HOME , KC_UP  , KC_END , KC_DEL ,
  //├────────┼────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┼────────┤
     OS_LGUI ,OS_LALT ,OS_LCTL ,OS_LSFT , XXXXXXX,   CW_TOGG ,KC_LEFT ,KC_DOWN ,KC_RGHT ,KC_BSPC ,
  //├────────┼────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┼────────┤
     UNDO    , TAB_NEW,TAB_PREV,TAB_NEXT,TAB_CLS ,   XXXXXXX ,KC_PGDN ,KC_PGUP , BACK   , FWD    ,
  //└────────┴────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┴────────┘
                        _______, _______, _______,    _______,KC_ENT  , _______
  //                  └────────┴────────┴────────┘  └────────┴────────┴────────┘
    ),

    [NUM] = LAYOUT_split_3x5_3(
  //┌────────┬────────┬────────┬────────┬────────┐  ┌────────┬────────┬────────┬────────┬────────┐
     KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,   KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,
  //├────────┼────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┼────────┤
     KC_LGUI ,KC_LALT ,KC_LCTL ,KC_LSFT ,KC_F11  ,   KC_F12  ,OS_RSFT ,OS_RCTL ,OS_RALT ,OS_RGUI,
  //├────────┼────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┼────────┤
     KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,   KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10,
  //└────────┴────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┴────────┘
                       _______ , _______, _______,   _______ , _______, _______
  //                  └────────┴────────┴────────┘  └────────┴────────┴────────┘
    ),
};
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, SYM, NAV, NUM);
}

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case KC_HACKPIPE:
            if (record->event.pressed) {
                SEND_STRING("|>");
            }
            return false;
    }

    return true;
}

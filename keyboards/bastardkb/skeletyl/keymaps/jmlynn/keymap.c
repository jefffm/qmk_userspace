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

// misc - macOS mode
#define SSHOT C(SGUI(KC_4))   // Ctrl+Cmd+Shift+4 (selection to clipboard)
#define LOCK LCTL(LGUI(KC_Q)) // Ctrl+Cmd+Q (lock screen)
#define GLOBE KC_LNG2         // Globe/Fn key (mapped to KC_LNG2, may need adjustment)
#define UNDO G(KC_Z)
#define CUT G(KC_X)
#define COPY G(KC_C)
#define PASTE G(KC_V)
#define TAB_CLS G(KC_W)
#define TAB_NEW G(KC_T)
#define TAB_PREV G(S(KC_TAB))
#define TAB_NEXT G(KC_TAB)
#define BACK G(KC_LBRC)
#define FWD G(KC_RBRC)

enum custom_keycodes {
    KC_HACKPIPE = SAFE_RANGE,
    KC_EMOJI,
    // TMUX macros (prefix: Ctrl+B)
    TM_WNEW,   // new window
    TM_WPREV,  // previous window
    TM_WNEXT,  // next window
    TM_WLAST,  // last window
    TM_WKILL,  // kill window
    TM_WRNAM,  // rename window
    TM_W1,     // select window 1
    TM_W2,     // select window 2
    TM_W3,     // select window 3
    TM_W4,     // select window 4
    TM_W5,     // select window 5
    TM_SPLTH,  // split horizontal
    TM_SPLTV,  // split vertical
    TM_PNEXT,  // next pane
    TM_PPREV,  // previous pane
    TM_PKILL,  // kill pane
    TM_PZOOM,  // zoom pane
    TM_SNEW,   // new session
    TM_SDET,   // detach session
    TM_SRNAM,  // rename session
    TM_SNEXT,  // next session
    TM_SPREV,  // previous session
    TM_SCROL,  // scroll/copy mode
    TM_CMD,    // command prompt
};

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
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_TILD ,   KC_CIRC ,XXXXXXX ,KC_EMOJI,TO(TMUX),KC_GRV  ,
  //├────────┼────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┼────────┤
     KC_MINS ,KC_ASTR ,KC_EQL  ,KC_UNDS ,KC_DLR  ,   KC_HASH ,OS_RSFT ,OS_RGUI ,OS_RALT ,OS_RCTL ,
  //├────────┼────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┼────────┤
     KC_PLUS ,KC_PIPE , KC_AT  ,KC_SLSH ,KC_PERC ,   KC_HACKPIPE,KC_BSLS,KC_AMPR,KC_QUES ,KC_EXLM ,
  //└────────┴────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┴────────┘
                        _______, _______, _______,    _______, _______, _______
  //                  └────────┴────────┴────────┘  └────────┴────────┴────────┘
    ),

    [NAV] = LAYOUT_split_3x5_3(
  //┌────────┬────────┬────────┬────────┬────────┐  ┌────────┬────────┬────────┬────────┬────────┐
     XXXXXXX ,XXXXXXX ,XXXXXXX , SSHOT  , GLOBE  ,   KC_TAB  ,KC_HOME , KC_UP  , KC_END ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┼────────┤
     OS_LCTL ,OS_LALT ,OS_LGUI ,OS_LSFT ,KC_BSPC ,   KC_DEL  ,KC_LEFT ,KC_DOWN ,KC_RGHT ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┼────────┤
     UNDO    , CUT    , COPY   , PASTE  ,XXXXXXX ,   XXXXXXX ,KC_PGDN ,XXXXXXX ,KC_PGUP , LOCK   ,
  //└────────┴────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┴────────┘
                        _______, _______, _______,    _______, _______, _______
  //                  └────────┴────────┴────────┘  └────────┴────────┴────────┘
    ),

    [NUM] = LAYOUT_split_3x5_3(
  //┌────────┬────────┬────────┬────────┬────────┐  ┌────────┬────────┬────────┬────────┬────────┐
     KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,   KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,
  //├────────┼────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┼────────┤
     OS_LCTL ,OS_LALT ,OS_LGUI ,OS_LSFT ,KC_F6   ,   KC_F7   ,OS_RSFT ,OS_RGUI ,OS_RALT ,OS_RCTL ,
  //├────────┼────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┼────────┤
     KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,   KC_F8   ,KC_F9   ,KC_F10  ,KC_F11  ,KC_F12  ,
  //└────────┴────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┴────────┘
                       _______ , _______, _______,   _______ , _______, _______
  //                  └────────┴────────┴────────┘  └────────┴────────┴────────┘
    ),

    [SYS] = LAYOUT_split_3x5_3(
  //┌────────┬────────┬────────┬────────┬────────┐  ┌────────┬────────┬────────┬────────┬────────┐
     QK_BOOT ,TG(GAME),XXXXXXX ,XXXXXXX ,XXXXXXX ,   XXXXXXX ,KC_MPRV ,KC_MPLY ,KC_MNXT ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┼────────┤
     KC_LCTL ,KC_LALT ,KC_LGUI ,KC_LSFT ,XXXXXXX ,   XXXXXXX ,KC_VOLD ,KC_MUTE ,KC_VOLU ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,   XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //└────────┴────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┴────────┘
                        _______, _______, _______,    _______, _______, _______
  //                  └────────┴────────┴────────┘  └────────┴────────┴────────┘
    ),

    [TMUX] = LAYOUT_split_3x5_3(
  //┌────────┬────────┬────────┬────────┬────────┐  ┌────────┬────────┬────────┬────────┬────────┐
     TM_W1   ,TM_W2   ,TM_W3   ,TM_W4   ,TM_W5   ,   TM_WNEW ,TM_WPREV,TM_WNEXT,TM_WLAST,TO(DEF) ,
  //├────────┼────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┼────────┤
     TM_SNEW ,TM_SRNAM,TM_SPREV,TM_SNEXT,TM_SDET ,   TM_SPLTH,TM_PPREV,TM_PNEXT,TM_PZOOM,TM_PKILL,
  //├────────┼────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┼────────┤
     TM_CMD  ,TM_WRNAM,TM_SCROL,XXXXXXX ,XXXXXXX ,   TM_SPLTV,XXXXXXX ,XXXXXXX ,TM_WKILL,XXXXXXX ,
  //└────────┴────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┴────────┘
                        _______, _______, _______,    _______, _______, _______
  //                  └────────┴────────┴────────┘  └────────┴────────┴────────┘
    ),

    [GAME] = LAYOUT_split_3x5_3(
  //┌────────┬────────┬────────┬────────┬────────┐  ┌────────┬────────┬────────┬────────┬────────┐
     KC_TAB  , KC_1   , KC_2   , KC_3   , KC_4   ,    KC_5   , KC_6   , KC_7   , KC_8   ,TG(GAME),
  //├────────┼────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┼────────┤
     KC_LSFT , KC_A   , KC_W   , KC_D   , KC_E   ,    KC_R   , KC_F   , KC_G   , KC_T   , KC_Y   ,
  //├────────┼────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┼────────┤
     KC_LCTL , KC_Z   , KC_S   , KC_X   , KC_C   ,    KC_V   , KC_B   , KC_N   , KC_M   , KC_ESC ,
  //└────────┴────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┴────────┘
                        KC_Q   , KC_SPC , KC_LALT,    KC_ENT , KC_BSPC, KC_DEL
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
                SEND_STRING("|> ");
            }
            return false;
        case KC_EMOJI:
            if (record->event.pressed) {
                tap_code16(LCTL(LGUI(KC_SPC)));
            }
            return false;

        // TMUX macros - all send Ctrl+B prefix then command key
        case TM_WNEW:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("b") "c");
            }
            return false;
        case TM_WPREV:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("b") "p");
            }
            return false;
        case TM_WNEXT:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("b") "n");
            }
            return false;
        case TM_WLAST:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("b") "l");
            }
            return false;
        case TM_WKILL:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("b") "&");
            }
            return false;
        case TM_WRNAM:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("b") ",");
            }
            return false;
        case TM_W1:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("b") "1");
            }
            return false;
        case TM_W2:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("b") "2");
            }
            return false;
        case TM_W3:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("b") "3");
            }
            return false;
        case TM_W4:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("b") "4");
            }
            return false;
        case TM_W5:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("b") "5");
            }
            return false;
        case TM_SPLTH:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("b") "\"");
            }
            return false;
        case TM_SPLTV:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("b") "%");
            }
            return false;
        case TM_PNEXT:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("b") "o");
            }
            return false;
        case TM_PPREV:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("b") ";");
            }
            return false;
        case TM_PKILL:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("b") "x");
            }
            return false;
        case TM_PZOOM:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("b") "z");
            }
            return false;
        case TM_SNEW:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("b") ":new-session" SS_TAP(X_ENT));
            }
            return false;
        case TM_SDET:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("b") "d");
            }
            return false;
        case TM_SRNAM:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("b") "$");
            }
            return false;
        case TM_SNEXT:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("b") ")");
            }
            return false;
        case TM_SPREV:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("b") "(");
            }
            return false;
        case TM_SCROL:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("b") "[");
            }
            return false;
        case TM_CMD:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("b") ":");
            }
            return false;
    }

    return true;
}

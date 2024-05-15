// https://stevep99.github.io/seniply/
// https://github.com/callum-oakley/qmk_firmware/tree/master/users/callum
// https://www.reddit.com/r/ErgoMechKeyboards/comments/weipet/my_homerow_mods_alternative/
#include QMK_KEYBOARD_H
#include <moonlander.h>
#include <version.h>
#define MOON_LED_LEVEL LED_LEVEL
#undef TAPPING_TOGGLE
#define TAPPING_TOGGLE 1
#define LCG(kc) (QK_LCTL | QK_LGUI | (kc))

#define _BASE 0
#define _NUM 1
#define _FN 2
#define _NAV 3
#define _MOUSE 4
#define _MEDIA 5

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  ST_MACRO_0,
  ST_MACRO_1,
  ST_MACRO_2,
  ST_MACRO_3,
  ST_MACRO_4,
  PLOOPY_BOOT,
//   MX_BSPC,
//   MX_TAB,
//   MX_SPACE,
//   MX_ENTER,
};

typedef struct {
    uint16_t tap;
    uint16_t hold;
    uint16_t held;
} tap_dance_tap_hold_t;
tap_dance_action_t *action;

enum tap_dance_codes {
  DANCE_0,
  DANCE_1,
  DANCE_2,
};
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_moonlander(
//|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|       |-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|
    KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,                 KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT, 
//|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|       |-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|
    KC_Q,                   KC_W,                   KC_E,                   KC_R,                   KC_T,                   KC_TRANSPARENT,         KC_TRANSPARENT,                 KC_TRANSPARENT,         KC_TRANSPARENT,         KC_Y,                   KC_U,                   KC_I,                   KC_O,                   KC_P,           
//|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|       |-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|
    KC_A,                   KC_S,                   KC_D,                   KC_F,                   KC_G,                   KC_TRANSPARENT,         KC_TRANSPARENT,                 KC_TRANSPARENT,         KC_TRANSPARENT,         KC_H,                   KC_J,                   KC_K,                   KC_L,                   KC_SCLN,
//|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|                                                       |-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|
    KC_Z,                   KC_X,                   KC_C,                   KC_V,                   KC_B,                   KC_TRANSPARENT,                                                                 KC_TRANSPARENT,         KC_N,                   KC_M,                   KC_COMMA,               KC_DOT,                 KC_SLASH,       
//|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|-------RED KEY---------|                                                       |---RED KEY-------------|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|
    KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,         LT(_FN,KC_BSPC),        LT(1,KC_TAB),           TD(DANCE_0),                                                                    KC_TRANSPARENT,         LT(_NAV,KC_SPACE),         MEH_T(KC_ENTER),        KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT, 
//|--THUMB 1--------------|---THUMB 2-------------|---THUMB 3-------------|                                                                                                                                                                                                       |---THUMB 3-------------|---------THUMB 2-------|-----THUMB 1-----------|
    KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,                                                                                                                                                                                                                 KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT
  ),
  [_NUM] = LAYOUT_moonlander (
//|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|       |-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|
    KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,                 KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT, 
//|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|       |-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|
    KC_NO,                  KC_GRAVE,               KC_LPRN,                KC_RPRN,                KC_NO,                  KC_TRANSPARENT,         KC_TRANSPARENT,                 KC_TRANSPARENT,         KC_TRANSPARENT,         KC_NO,                  KC_7,                   KC_8,                   KC_9,                   KC_EQUAL,       
//|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|       |-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|
    OSM(MOD_LALT),          OSM(MOD_LGUI),          OSM(MOD_LCTL),          OSM(MOD_LSFT),          KC_NO,                  KC_TRANSPARENT,         KC_TRANSPARENT,                 KC_TRANSPARENT,         KC_TRANSPARENT,         KC_BSLS,                KC_4,                   KC_5,                   KC_6,                   KC_QUOTE,
//|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|                                                       |-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|
    KC_NO,                  KC_NO,                  KC_LBRC,                KC_RBRC,                KC_NO,                  KC_TRANSPARENT,                                                                 KC_TRANSPARENT,         KC_NO,                  KC_1,                   KC_2,                   KC_3,                   KC_MINUS,         
//|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|-------RED KEY---------|                                                       |---RED KEY-------------|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|
    KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,                                                                 KC_TRANSPARENT,         KC_TRANSPARENT,                 KC_0,                   KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT, 
//|--THUMB 1--------------|---THUMB 2-------------|---THUMB 3-------------|                                                                                                                                                                                                       |---THUMB 3-------------|---------THUMB 2-------|-----THUMB 1-----------|
    KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,                                                                                                                                                                                                                 KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT
  ),  
  [_FN] = LAYOUT_moonlander(
//|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|       |-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|
    KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,                 KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT, 
//|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|       |-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|
    KC_NO,                  KC_TILDE,               KC_LT,                  KC_GT,                  KC_NO,                  KC_TRANSPARENT,         KC_TRANSPARENT,                 KC_TRANSPARENT,         KC_TRANSPARENT,         KC_NO,                  KC_F9,                  KC_F10,                 KC_F11,                 KC_F12,          
//|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|       |-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|
    OSM(MOD_LALT),          OSM(MOD_LGUI),          OSM(MOD_LCTL),          OSM(MOD_LSFT),          KC_NO,                  KC_TRANSPARENT,         KC_TRANSPARENT,                 KC_TRANSPARENT,         KC_TRANSPARENT,         KC_NO,                  KC_F5,                  KC_F6,                  KC_F7,                  KC_F8,          
//|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|                                                       |-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|
    KC_NO,                  KC_NO,                  KC_LCBR,                KC_RCBR,                KC_NO,                  KC_TRANSPARENT,                                                                 KC_TRANSPARENT,         KC_NO,                  KC_F1,                  KC_F2,                  KC_F3,                  KC_F4,          
//|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|-------RED KEY---------|                                                       |---RED KEY-------------|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|
    KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,                                                                 KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT, 
//|--THUMB 1--------------|---THUMB 2-------------|---THUMB 3-------------|                                                                                                                                                                                                       |---THUMB 3-------------|---------THUMB 2-------|-----THUMB 1-----------|
    KC_TRANSPARENT,         KC_TRANSPARENT,         KC_NO,                                                                                                                                                                                                                          KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT
  ),
  [_NAV] = LAYOUT_moonlander(
//|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|       |-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|
    KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,                 KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT, 
//|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|       |-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|
    KC_NO,                  KC_BSPC,                KC_UP,                  KC_DELETE,              KC_NO,                  KC_TRANSPARENT,         KC_TRANSPARENT,                 KC_TRANSPARENT,         KC_TRANSPARENT,         KC_NO,                  KC_PAGE_UP,             KC_PAGE_UP,             KC_NO,                  KC_NO,          
//|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|       |-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|
    KC_HOME,                KC_LEFT,                KC_DOWN,                KC_RIGHT,               KC_END,                 KC_TRANSPARENT,         KC_TRANSPARENT,                 KC_TRANSPARENT,         KC_TRANSPARENT,         KC_NO,                  OSM(MOD_LSFT),          OSM(MOD_LCTL),          OSM(MOD_LGUI),          OSM(MOD_LALT),
//|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|                                                       |-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|
    KC_NO,                  KC_NO,                  KC_ESC,                 KC_INSERT,              KC_NO,                  KC_TRANSPARENT,                                                                 KC_TRANSPARENT,         KC_NO,                  KC_PAGE_DOWN,           KC_PAGE_DOWN,           KC_NO,                  KC_NO,          
//|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|-------RED KEY---------|                                                       |---RED KEY-------------|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|
    KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,                                                                 KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT, 
//|--THUMB 1--------------|---THUMB 2-------------|---THUMB 3-------------|                                                                                                                                                                                                       |---THUMB 3-------------|---------THUMB 2-------|-----THUMB 1-----------|
    KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,                                                                                                                                                                                                                 KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT
  ),
  [_MOUSE] = LAYOUT_moonlander(
//|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|       |-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|
    KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,                 KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT, 
//|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|       |-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|
    OSM(MOD_LSFT),          LCG(KC_LEFT),           ST_MACRO_4,             LCG(KC_RIGHT),          KC_NO,                  KC_TRANSPARENT,         KC_TRANSPARENT,                 KC_TRANSPARENT,         KC_TRANSPARENT,         KC_NO,                  KC_MS_WH_LEFT,          KC_MS_WH_DOWN,          KC_MS_WH_UP,            KC_MS_WH_RIGHT,          
//|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|       |-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|
    KC_LEFT_SHIFT,          KC_MS_BTN3,             KC_MS_BTN2,             KC_MS_BTN1,             KC_NO,                  KC_TRANSPARENT,         KC_TRANSPARENT,                 KC_TRANSPARENT,         KC_TRANSPARENT,         KC_NO,                  KC_MS_LEFT,             KC_MS_DOWN,             KC_MS_UP,               KC_MS_RIGHT,          
//|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|                                                       |-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|
    OSM(MOD_LCTL),          LCTL(KC_X),             LCTL(KC_C),             LCTL(KC_V),             KC_NO,                  KC_TRANSPARENT,                                                                 KC_TRANSPARENT,         KC_NO,                  KC_NO,                  KC_NO,                  KC_NO,                  KC_NO,          
//|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|-------RED KEY---------|                                                       |---RED KEY-------------|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|
    KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,         KC_SCRL,                KC_SCRL,                KC_PSCR,                                                                        KC_NO,                  KC_SCRL,                KC_SCRL,                KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT, 
//|--THUMB 1--------------|---THUMB 2-------------|---THUMB 3-------------|                                                                                                                                                                                                       |---THUMB 3-------------|---------THUMB 2-------|-----THUMB 1-----------|
    KC_SCRL,                KC_TRANSPARENT,         KC_TRANSPARENT,                                                                                                                                                                                                                 KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT
  ),
  [_MEDIA] = LAYOUT_moonlander(
//|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|       |-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|
    KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,                 KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT, 
//|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|       |-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|
    QK_BOOT,                KC_NO,                  TD(DANCE_1),            KC_AUDIO_VOL_UP,        KC_NO,                  KC_TRANSPARENT,         KC_TRANSPARENT,                 KC_TRANSPARENT,         KC_TRANSPARENT,         KC_NO,                  KC_BRIGHTNESS_UP,       KC_NO,                  KC_NO,                  KC_NO,          
//|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|       |-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|
    KC_NO,                  KC_NO,                  KC_MEDIA_PLAY_PAUSE,    KC_AUDIO_MUTE,          KC_NO,                  KC_TRANSPARENT,         KC_TRANSPARENT,                 KC_TRANSPARENT,         KC_TRANSPARENT,         KC_NO,                  KC_NO,                  KC_NO,                  KC_NO,                  KC_NO,          
//|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|                                                       |-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|
    PLOOPY_BOOT,            KC_NO,                  TD(DANCE_2),            KC_AUDIO_VOL_DOWN,      KC_NO,                  KC_TRANSPARENT,                                                                 KC_TRANSPARENT,         KC_NO,                  KC_BRIGHTNESS_DOWN,     KC_NO,                  KC_NO,                  KC_NO,          
//|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|-------RED KEY---------|                                                       |---RED KEY-------------|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|
    KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,         KC_NO,                  KC_NO,                  KC_NO,                                                                          KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT, 
//|--THUMB 1--------------|---THUMB 2-------------|---THUMB 3-------------|                                                                                                                                                                                                       |---THUMB 3-------------|---------THUMB 2-------|-----THUMB 1-----------|
    KC_TRANSPARENT,         KC_TRANSPARENT,         KC_NO,                                                                                                                                                                                                                 KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT
  ),
};
const uint16_t PROGMEM combo0[] = { KC_F, KC_J, COMBO_END};
const uint16_t PROGMEM combo1[] = { KC_W, KC_Q, COMBO_END};
const uint16_t PROGMEM combo2[] = { LT(_NAV,KC_SPACE), MEH_T(KC_ENTER), COMBO_END};
const uint16_t PROGMEM combo3[] = { LT(_NUM,KC_TAB), LT(_FN,KC_BSPC), COMBO_END};
const uint16_t PROGMEM combo4[] = { LT(_NUM,KC_TAB), LT(_NAV,KC_SPACE), COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo0, KC_CAPS),
    COMBO(combo1, KC_ESCAPE),
    COMBO(combo2, TT(_MEDIA)),
    COMBO(combo3, TT(_MOUSE)),
    COMBO(combo4, QK_LEADER),
};

// bool led_update_user(led_t state) {
//     if (state.scroll_lock == 1) {
//         layer_on(_MOUSE);
//     } else {
//         layer_off(_MOUSE);
//     }
//     return true;
// }

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        default:
            return TAPPING_TERM;
    }
}

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [_BASE] = { {0,0,0}, {194,255,255}, {157,255,255}, {194,255,255}, {0,0,0}, {0,0,0}, {194,255,255}, {157,255,255}, {194,255,255}, {0,0,0}, {0,0,0}, {194,255,255}, {157,255,255}, {194,255,255}, {0,0,0}, {0,0,0}, {194,255,255}, {157,255,255}, {194,255,255}, {194,255,255}, {0,0,0}, {194,255,255}, {194,255,255}, {194,255,255}, {194,255,255}, {0,0,0}, {194,255,255}, {194,255,255}, {194,255,255}, {0,0,0}, {194,255,255}, {194,255,255}, {194,255,255}, {194,255,255}, {157,255,255}, {194,255,255}, {0,0,0}, {194,255,255}, {157,255,255}, {194,255,255}, {0,0,0}, {0,0,0}, {194,255,255}, {157,255,255}, {194,255,255}, {0,0,0}, {0,0,0}, {194,255,255}, {157,255,255}, {194,255,255}, {0,0,0}, {0,0,0}, {194,255,255}, {157,255,255}, {194,255,255}, {194,255,255}, {0,0,0}, {194,255,255}, {194,255,255}, {194,255,255}, {194,255,255}, {0,0,0}, {194,255,255}, {194,255,255}, {194,255,255}, {0,0,0}, {194,255,255}, {194,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [_NUM] = { {0,0,0}, {142,255,255}, {142,255,255}, {142,255,255}, {0,0,0}, {0,0,0}, {219,255,255}, {219,255,255}, {219,255,255}, {0,0,0}, {0,0,0}, {219,255,255}, {219,255,255}, {219,255,255}, {0,0,0}, {0,0,0}, {219,255,255}, {219,255,255}, {219,255,255}, {142,255,255}, {0,0,0}, {142,255,255}, {142,255,255}, {142,255,255}, {142,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {142,255,255}, {142,255,255}, {142,255,255}, {142,255,255}, {0,0,0}, {219,255,255}, {219,255,255}, {219,255,255}, {0,0,0}, {0,0,0}, {154,255,255}, {154,255,255}, {154,255,255}, {0,0,0}, {0,0,0}, {154,255,255}, {154,255,255}, {154,255,255}, {0,0,0}, {0,0,0}, {154,255,255}, {154,255,255}, {0,0,0}, {142,255,255}, {0,0,0}, {219,255,255}, {219,255,255}, {219,255,255}, {142,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [_FN] = { {0,0,0}, {142,255,255}, {142,255,255}, {142,255,255}, {0,0,0}, {0,0,0}, {219,255,255}, {219,255,255}, {219,255,255}, {0,0,0}, {0,0,0}, {219,255,255}, {219,255,255}, {219,255,255}, {0,0,0}, {0,0,0}, {219,255,255}, {219,255,255}, {219,255,255}, {142,255,255}, {0,0,0}, {142,255,255}, {142,255,255}, {142,255,255}, {142,255,255}, {194,255,255}, {0,0,0}, {194,255,255}, {194,255,255}, {0,0,0}, {194,255,255}, {194,255,255}, {142,255,255}, {142,255,255}, {142,255,255}, {142,255,255}, {0,0,0}, {219,255,255}, {219,255,255}, {219,255,255}, {0,0,0}, {0,0,0}, {154,255,255}, {154,255,255}, {154,255,255}, {0,0,0}, {0,0,0}, {154,255,255}, {154,255,255}, {154,255,255}, {0,0,0}, {0,0,0}, {154,255,255}, {154,255,255}, {0,0,0}, {142,255,255}, {0,0,0}, {219,255,255}, {219,255,255}, {219,255,255}, {142,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [_NAV] = { {0,0,0}, {142,255,255}, {142,255,255}, {142,255,255}, {0,0,0}, {0,0,0}, {219,255,255}, {219,255,255}, {219,255,255}, {0,0,0}, {0,0,0}, {219,255,255}, {219,255,255}, {219,255,255}, {0,0,0}, {0,0,0}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {0,0,0}, {142,255,255}, {142,255,255}, {142,255,255}, {219,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {0,0,0}, {219,255,255}, {219,255,255}, {219,255,255}, {0,0,0}, {0,0,0}, {154,255,255}, {154,255,255}, {154,255,255}, {0,0,0}, {0,0,0}, {154,255,255}, {154,255,255}, {154,255,255}, {0,0,0}, {0,0,0}, {154,255,255}, {154,255,255}, {154,255,255}, {154,255,255}, {0,0,0}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [_MOUSE] = { {0,0,0}, {75,155,120}, {75,155,120}, {75,155,120}, {0,0,0}, {0,0,0}, {226,58,245}, {226,58,245}, {226,58,245}, {0,0,0}, {0,0,0}, {226,58,245}, {226,58,245}, {226,58,245}, {0,0,0}, {0,0,0}, {226,58,245}, {226,58,245}, {226,58,245}, {75,155,120}, {0,0,0}, {75,155,120}, {75,155,120}, {75,155,120}, {75,155,120}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {75,155,120}, {75,155,120}, {75,155,120}, {75,155,120}, {0,0,0}, {75,155,120}, {75,155,120}, {75,155,120}, {0,0,0}, {0,0,0}, {226,58,245}, {226,58,245}, {226,58,245}, {0,0,0}, {0,0,0}, {226,58,245}, {226,58,245}, {226,58,245}, {0,0,0}, {0,0,0}, {226,58,245}, {226,58,245}, {226,58,245}, {75,155,120}, {0,0,0}, {75,155,120}, {75,155,120}, {75,155,120}, {226,58,245}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [_MEDIA] = { {0,0,0}, {0,0,0}, {0,245,245}, {0,245,245}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {152,255,255}, {152,255,255}, {152,255,255}, {0,0,0}, {0,0,0}, {74,255,255}, {74,255,255}, {74,255,255}, {14,229,244}, {0,0,0}, {14,229,244}, {14,229,244}, {14,229,244}, {14,229,244}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {14,229,244}, {14,229,244}, {14,229,244}, {14,229,244}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {43,255,255}, {0,0,0}, {43,255,255}, {14,229,244}, {0,0,0}, {14,229,244}, {14,229,244}, {14,229,244}, {14,229,244}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );   
    }
  }
}

bool rgb_matrix_indicators_user(void) {
  if (rawhid_state.rgb_control) {
      return false;
  }
  if (keyboard_config.disable_layer_led) { return false; }
  switch (biton32(layer_state)) {
    case _BASE:
      set_layer_color(_BASE);
      break;
    case _NUM:
      set_layer_color(_NUM);
      break;
    case _FN:
      set_layer_color(_FN);
      break;
    case _NAV:
      set_layer_color(_NAV);
      break;
    case _MOUSE:
      set_layer_color(_MOUSE);
      break;
    case _MEDIA:
      set_layer_color(_MEDIA);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
  return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ST_MACRO_0:
    if (record->event.pressed) {
      SEND_STRING("--\nAndre Dessert\nCyberSecurity Systems Engineer\nCorsica Technologies");
    }
    break;
    case ST_MACRO_1:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_MINUS) SS_DELAY(50) SS_TAP(X_SPACE) SS_DELAY(50) SS_TAP(X_LBRC) SS_DELAY(50) SS_TAP(X_SPACE) SS_DELAY(50) SS_TAP(X_RBRC));
    }
    break;
    case ST_MACRO_2:
    if (record->event.pressed) {
      SEND_STRING("末");
    }
    break;
    case ST_MACRO_3:
    if (record->event.pressed) {
      SEND_STRING("");
    }
    break;
    case ST_MACRO_4:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_NUM) SS_TAP(X_NUM));
    }
    break;
    case PLOOPY_BOOT:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_NUM) SS_TAP(X_NUM) SS_TAP(X_SCRL) SS_TAP(X_SCRL));
    }
    break;
    // case MX_BSPC:
    // if (record->event.pressed) {
    //   SENDSTRING(SS_TAP(X_SCRL) SS_TAP(X_BSPC));
    // }
    // break;
    // case MX_TAB:
    // if (record->event.pressed) {
    //   SENDSTRING(SS_TAP(X_SCRL) SS_TAP(X_TAB));
    // }
    // break;
    // case MX_SPACE:
    // if (record->event.pressed) {
    //   SENDSTRING(SS_TAP(X_SCRL) SS_TAP(X_SPACE));
    // }
    // break;
    // case MX_ENTER:
    // if (record->event.pressed) {
    //   SENDSTRING(SS_TAP(X_SCRL) SS_TAP(X_ENTER));
    // }
    // break;

    case TD(DANCE_0):
    case TD(DANCE_1):
    case TD(DANCE_2):
        action = &tap_dance_actions[TD_INDEX(keycode)];
        if (!record->event.pressed && action->state.count && !action->state.finished) {
            tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
            tap_code16(tap_hold->tap);
        }
        break;
    case RGB_SLD:
        if (rawhid_state.rgb_control) {
            return false;
        }
        if (record->event.pressed) {
            rgblight_mode(1);
        }
        return false;
  }
  return true;
}

void leader_start_user(void) {
    // Do something when the leader key is pressed
}

void leader_end_user(void) {
    if (leader_sequence_one_key(KC_F)) {
        // Leader, f => Types the below string
        SEND_STRING("QMK is awesome.");
    } else if (leader_sequence_two_keys(KC_D, KC_D)) {
        // Leader, d, d => Ctrl+A, Ctrl+C
        SEND_STRING(SS_LCTL("a") SS_LCTL("c"));
    } else if (leader_sequence_two_keys(KC_W, KC_R)) {
        // Leader, w, ; => Display Right
        tap_code16(LCG(KC_RIGHT));
    } else if (leader_sequence_two_keys(KC_W, KC_L)) {
        // Leader, w, j => Display Left
        tap_code16(LCG(KC_LEFT));
    } else if (leader_sequence_two_keys(KC_A, KC_S)) {
        // Leader, a, s => GUI+S
        tap_code16(LGUI(KC_S));
    }
}

void tap_dance_tap_hold_finished(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (state->pressed) {
        if (state->count == 1
#ifndef PERMISSIVE_HOLD
            && !state->interrupted
#endif
        ) {
            register_code16(tap_hold->hold);
            tap_hold->held = tap_hold->hold;
        } else {
            register_code16(tap_hold->tap);
            tap_hold->held = tap_hold->tap;
        }
    }
}

void tap_dance_tap_hold_reset(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (tap_hold->held) {
        unregister_code16(tap_hold->held);
        tap_hold->held = 0;
    }
}

#define ACTION_TAP_DANCE_TAP_HOLD(tap, hold) \
    { .fn = {NULL, tap_dance_tap_hold_finished, tap_dance_tap_hold_reset}, .user_data = (void *)&((tap_dance_tap_hold_t){tap, hold, 0}), }


tap_dance_action_t tap_dance_actions[] = {
        [DANCE_0] = ACTION_TAP_DANCE_TAP_HOLD(LCTL(LSFT(KC_M)), KC_SPACE),
        [DANCE_1] = ACTION_TAP_DANCE_TAP_HOLD(KC_MEDIA_NEXT_TRACK, KC_MEDIA_FAST_FORWARD),
        [DANCE_2] = ACTION_TAP_DANCE_TAP_HOLD(KC_MEDIA_PREV_TRACK, KC_MEDIA_REWIND),
};
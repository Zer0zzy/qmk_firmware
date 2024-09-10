#undef TAPPING_TERM
#define TAPPING_TERM 170

#define COMBO_TERM 60

#define USB_SUSPEND_WAKEUP_DELAY 0

#define CAPS_LOCK_STATUS
#define RAW_USAGE_PAGE 0xFF60
#define RAW_USAGE_ID 0x61
#define COMBO_COUNT 5

#define NO_AUTO_SHIFT_ALPHA
#define AUTO_SHIFT_TIMEOUT 150

#define LEADER_NO_TIMEOUT
#define LEADER_PER_KEY_TIMING
#define LEADER_TIMEOUT 250

#define TAPPING_TERM_PER_KEY

// Everything below here is to reduce firmware size
#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE
// no oneshots
#define NO_ACTION_ONESHOT
#define NO_MUSIC_MODE

#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

// Limits device to 8 layers
#define LAYER_STATE_8BIT

// #undef RGBLIGHT_ANIMATIONS
// #undef RGBLIGHT_EFFECT_BREATHING
// #undef RGBLIGHT_EFFECT_RAINBOW_MOOD
// #undef RGBLIGHT_EFFECT_RAINBOW_SWIRL
// #undef RGBLIGHT_EFFECT_SNAKE
// #undef RGBLIGHT_EFFECT_KNIGHT
// #undef RGBLIGHT_EFFECT_CHRISTMAS
// #undef RGBLIGHT_EFFECT_STATIC_GRADIENT
// #undef RGBLIGHT_EFFECT_RGB_TEST
// #undef RGBLIGHT_EFFECT_ALTERNATING
// #undef RGBLIGHT_EFFECT_TWINKLE
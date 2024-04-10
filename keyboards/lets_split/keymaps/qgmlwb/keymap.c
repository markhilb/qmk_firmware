#include <stdint.h>
#include QMK_KEYBOARD_H
#include "keymap_norwegian.h"

// clang-format off

enum layer_names {
    _QGMLWB_NO,
    _QGMLWB_EN,
    _LOWER_NO,
    _LOWER_EN,
    _RAISE_NO,
    _RAISE_EN,
    _ADJUST
};

#define LOWER_NO  MO(_LOWER_NO)
#define LOWER_EN  MO(_LOWER_EN)
#define RAISE_NO  MO(_RAISE_NO)
#define RAISE_EN  MO(_RAISE_EN)
#define ADJUST    MO(_ADJUST)

enum custom_keymaps {
    PASSWORD = SAFE_RANGE,
    PASSWORD2,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qgmlwb
 * ,-----------------------------------------|-----------------------------------------.
 * | Tab  |   Q  |   G  |   M  |   L  |   W  |   B  |   Y  |   U  |   V  |  '"  | Bksp |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Esc  |   D  |   S  |   T  |   N  |   R  |   I  |   A  |   E  |   O  |   H  | Enter|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |   \  |   Z  |   X  |   C  |   F  |   J  |   K  |   P  |  ,;  |  .:  |  -_  |   |  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Ctrl |      |  GUI |  Alt | Lower| Shift| Space| Raise| Left | Down |  Up  | Right|
 * `-----------------------------------------|-----------------------------------------'
 */
// Norwegian
[_QGMLWB_NO] = LAYOUT_ortho_4x12(
   KC_TAB,        KC_Q,    KC_G,          KC_M,          KC_L,          KC_W,   KC_B,          KC_Y,          KC_U,    KC_V,    NO_QUOT, KC_BSPC,
   KC_ESC,        KC_D,    KC_S,          KC_T,          KC_N,          KC_R,   KC_I,          KC_A,          KC_E,    KC_O,    KC_H,    KC_ENT,
   NO_BSLS,       KC_Z,    KC_X,          KC_C,          KC_F,          KC_J,   KC_K,          KC_P,          NO_COMM, NO_DOT,  NO_MINS, NO_PIPE,
   OSM(MOD_LCTL), _______, OSM(MOD_LGUI), OSM(MOD_LALT), OSL(LOWER_NO), OSM(MOD_LSFT), KC_SPC, OSL(RAISE_NO), KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),
// English
[_QGMLWB_EN] = LAYOUT_ortho_4x12(
   KC_TAB,        KC_Q,    KC_G,          KC_M,          KC_L,          KC_W,   KC_B,          KC_Y,          KC_U,    KC_V,    KC_QUOT, KC_BSPC,
   KC_ESC,        KC_D,    KC_S,          KC_T,          KC_N,          KC_R,   KC_I,          KC_A,          KC_E,    KC_O,    KC_H,    KC_ENT,
   KC_BSLS,       KC_Z,    KC_X,          KC_C,          KC_F,          KC_J,   KC_K,          KC_P,          KC_COMM, KC_DOT,  KC_MINS, KC_PIPE,
   OSM(MOD_LCTL), _______, OSM(MOD_LGUI), OSM(MOD_LALT), OSL(LOWER_EN), OSM(MOD_LSFT), KC_SPC, OSL(RAISE_EN), KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Lower
 * ,-----------------------------------------|-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |  Del |   =  |   *  |   +  |   /  |   !  |   ?  |   <  |   >  |   %  |   &  |   ~  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Mute | Caps |  æ   |  ø   |  å   | Ins  | Home | End  |   ;  |   :  |PrtScr|      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Ctrl |      |      |      |      | Shift|      |Adjust| Next | Bri- | Bri+ | Play |
 * `-----------------------------------------|-----------------------------------------'
 */
// Norwegian
[_LOWER_NO] = LAYOUT_ortho_4x12(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  KC_DEL,  NO_EQL,  NO_ASTR, NO_PLUS, NO_SLSH, KC_EXLM, NO_QUES, NO_LABK, NO_RABK, KC_PERC, NO_AMPR, NO_TILD,
  KC_MUTE, KC_CAPS, NO_AE,   NO_OSTR, NO_ARNG, KC_INS,  KC_HOME, KC_END,  NO_SCLN, NO_COLN, KC_PSCR, _______,
  KC_LCTL, _______, _______, _______, _______, KC_LSFT, _______, ADJUST,  KC_MNXT, KC_BRID, KC_BRIU, KC_MPLY
),
// English
[_LOWER_EN] = LAYOUT_ortho_4x12(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  KC_DEL,  KC_EQL,  KC_ASTR, KC_PLUS, KC_SLSH, KC_EXLM, KC_QUES, KC_LT,   KC_GT,   KC_PERC, KC_AMPR, KC_TILD,
  KC_MUTE, KC_CAPS, _______, _______, _______, KC_INS,  KC_HOME, KC_END,  KC_SCLN, KC_COLN, KC_PSCR, _______,
  KC_LCTL, _______, _______, _______, _______, KC_LSFT, _______, ADJUST,  KC_MNXT, KC_BRID, KC_BRIU, KC_MPLY
),

/* Raise
 * ,-----------------------------------------|-----------------------------------------.
 * |      |   9  |   7  |   5  |   3  |   1  |   0  |   2  |   4  |   6  |   8  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | C+Del|   ^  |  [   |  {   |   (  |   #  |   @  |   )  |   }  |   ]  |   $  |   `  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |   Æ  |   Ø  |   Å  |      | PgDn | PgUp |   ;  |   :  |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Ctrl |      |      |      |Adjust| Shift|      |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------|-----------------------------------------'
 */
// Norwegian
[_RAISE_NO] = LAYOUT_ortho_4x12(
  _______,      KC_9,    KC_7,    KC_5,    KC_3,    KC_1,    KC_0,    KC_2,    KC_4,    KC_6,    KC_8,    _______,
  LCTL(KC_DEL), NO_CIRC, NO_LBRC, NO_LCBR, NO_LPRN, KC_HASH, NO_AT,   NO_RPRN, NO_RCBR, NO_RBRC, NO_DLR,  NO_GRV,
  _______,      _______, KC_DQUO, KC_COLN, KC_LCBR, _______, KC_PGDN, KC_PGUP, NO_SCLN, NO_COLN, _______, _______,
  KC_LCTL,      _______, _______, _______, ADJUST,  KC_LSFT, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),
// English
[_RAISE_EN] = LAYOUT_ortho_4x12(
  _______,      KC_9,    KC_7,    KC_5,    KC_3,    KC_1,    KC_0,    KC_2,    KC_4,    KC_6,    KC_8,    _______,
  LCTL(KC_DEL), KC_CIRC, KC_LBRC, KC_LCBR, KC_LPRN, KC_HASH, KC_AT,   KC_RPRN, KC_RCBR, KC_RBRC, KC_DLR,  KC_GRV,
  _______,      _______, _______, _______, _______, _______, KC_PGDN, KC_PGUP, KC_SCLN, KC_COLN, _______, _______,
  KC_LCTL,      _______, _______, _______, ADJUST,  KC_LSFT, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------|-----------------------------------------------.
 * |      | Reset|      |      |      |      |      |      |      |      |         |         |
 * |------+------+------+------+------+------|------+------+------+------+---------+---------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|PSSWRD|      |      |Qgmlwb en|Qgmlwb no|
 * |------+------+------+------+------+------|------+------+------+------+---------+---------|
 * |      |      |      |      |      |      |      |      |      |      |         |         |
 * |------+------+------+------+------+------|------+------+------+------+---------+---------|
 * |      |      |      |      |      |      |      |      |      |      |         |         |
 * `-----------------------------------------|-----------------------------------------------'
 */
[_ADJUST] =  LAYOUT_ortho_4x12(
  _______, QK_BOOT, _______, _______, _______, _______, _______, _______,  _______,   _______, _______,        _______,
  _______, _______, _______, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, PASSWORD, PASSWORD2, _______, DF(_QGMLWB_EN), DF(_QGMLWB_NO),
  _______, _______, _______, _______, _______, _______, _______, _______,  _______,   _______, _______,        _______,
  _______, _______, _______, _______, _______, _______, _______, _______,  _______,   _______, _______,        _______
)

};

// clang-format on

const key_override_t shift_period_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_DOT, KC_COLN, 1 << _QGMLWB_EN);
const key_override_t shift_comma_override  = ko_make_with_layers(MOD_MASK_SHIFT, KC_COMM, KC_SCLN, 1 << _QGMLWB_EN);

const key_override_t shift_quote_override     = ko_make_with_layers(MOD_MASK_SHIFT, NO_QUOT, NO_DQUO, 1 << _QGMLWB_NO);
const key_override_t shift_backslash_override = ko_make_with_layers(MOD_MASK_SHIFT, NO_BSLS, NO_PIPE, 1 << _QGMLWB_NO);

const key_override_t *key_overrides[] = {
    &shift_period_override, &shift_comma_override, &shift_quote_override, &shift_backslash_override, NULL,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case PASSWORD:
                if (layer_state_cmp(default_layer_state, _QGMLWB_NO)) {
                    SEND_STRING("********");
                } else {
                    SEND_STRING("********");
                }
                break;
            case PASSWORD2:
                if (layer_state_cmp(default_layer_state, _QGMLWB_NO)) {
                    SEND_STRING("********");
                } else {
                    SEND_STRING("********");
                }
                break;
        }
    }

    return true;
}

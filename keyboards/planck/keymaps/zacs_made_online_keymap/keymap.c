#include QMK_KEYBOARD_H
#include "config.h"

// Helpful defines
#define _______ KC_TRNS

enum custom_keycodes {
    MY_CUSTOM_MACRO = SAFE_RANGE,
};
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch(keycode) {
            case MY_CUSTOM_MACRO:
                SEND_STRING(SS_LCTRL("s")SS_LALT(SS_TAP(X_TAB))"y"SS_TAP(X_ENTER)SS_LALT(SS_TAP(X_TAB)));
                return false;
        }
    }
    return true;
};



  /*
   * THIS IS MY DEFAULT BLANK KEY LAYER. COPY AND FILL IN WHEN CREATING A NEW
   * LAYER.
   *
+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+
|         |         |         |         |         |         |         |         |         |         |         |         |
+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+
|         |         |         |         |         |         |         |         |         |         |         |         |
+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+
|         |         |         |         |         |         |         |         |         |         |         |         |
+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+
|         |         |         |         |         |         |         |         |         |         |         |         |
+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+
   *
   *
  [NUMBER] = KEYMAP(
      KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,          KC_NO,          KC_NO,        KC_NO,          KC_NO,        KC_NO,
      KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,          KC_NO,          KC_NO,        KC_NO,          KC_NO,        KC_NO,
      KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,          KC_NO,          KC_NO,        KC_NO,          KC_NO,        KC_NO,
      KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,          KC_NO,          KC_NO,        KC_NO,          KC_NO,        KC_NO
      ),
   */





const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // Default normal
  /*
+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+
|   Tab   |    q    |    w    |    e    |    r    |    t    |    y    |    u    |    i    |    o    |    p    | Bckspce |
+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+
|   Esc   |    a    |    s    |    d    |    f    |    g    |    h    |    j    |    k    |    l    |    ;    |    '    |
+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+
|  Shift  |    z    |    x    |    c    |    v    |    b    |    n    |    m    |    ,    |    .    |    /    |Shift/Ent|
+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+
| Layer 3 | Layer 6 |   GUI   |   Alt   | Layer 4 |   Ctrl  |  Space  | Layer 5 |   Alt   |         |         |  DMenu  |
+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+

   */
	[0] = KEYMAP(
      KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,           KC_Y,         KC_U,                 KC_I,         KC_O,           KC_P,         KC_BSPC,
      KC_ESC,   KC_A,     KC_S,     KC_D,     KC_F,     KC_G,           KC_H,         KC_J,                 KC_K,         KC_L,           KC_SCLN,      KC_QUOT,
      KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,           KC_N,         KC_M,                 KC_COMM,      KC_DOT,         KC_SLSH,      RSFT_T(KC_ENT),
      MO(3),    MO(6),    KC_LGUI,  KC_LALT,  MO(4),    KC_LCTL,        KC_SPC,       MO(5),                KC_RALT,      _______,        _______,      LALT(KC_D)
      ),

// Gaming layer
  /*
+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+
|   Tab   |    q    |    w    |    e    |    r    |    t    |    y    |    u    |    i    |    o    |    p    | Bckspce |
+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+
|   Esc   |    a    |    s    |    d    |    f    |    g    |    h    |    j    |    k    |    l    |    ;    |    '    |
+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+
|  Shift  |    z    |    x    |    c    |    v    |    b    |    n    |    m    |    ,    |    .    |    /    |Shift/Ent|
+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+
| Layer 3 | Layer 6 |   GUI   |   Alt   | Layer 4 |  Space  |  Space  | Layer 5 |   Ctrl  |   Mute  |  Vol -  |  Vol +  |
+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+

   */
	[1] = KEYMAP(
      KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,           KC_Y,         KC_U,               KC_I,         KC_O,           KC_P,         KC_BSPC,
      KC_ESC,   KC_A,     KC_S,     KC_D,     KC_F,     KC_G,           KC_H,         KC_J,               KC_K,         KC_L,           KC_SCLN,      KC_QUOT,
      KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,           KC_N,         KC_M,               KC_COMM,      KC_DOT,         KC_SLSH,      RSFT_T(KC_ENT),
      MO(3),    MO(6),    KC_LGUI,  KC_LALT,  MO(4),    KC_SPC,         KC_SPC,       MO(5),              KC_LCTL,      KC_MUTE,        KC_VOLD,      KC_VOLU
      ),

// Dvorak layer
  /*
+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+
|   Tab   |    '    |    ,    |    .    |    p    |    y    |    f    |    g    |    c    |    r    |    l    | Bckspce |
+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+
|   Esc   |    a    |    o    |    e    |    u    |    i    |    d    |    h    |    t    |    n    |    s    |    /    |
+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+
|  Shift  |    ;    |    q    |    j    |    k    |    x    |    b    |    m    |    w    |    v    |    z    |  Enter  |
+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+
| Layer 3 | Layer 6 |   GUI   |   Alt   | Layer 4 |   Ctrl  |  Space  | Layer 5 |         |   Mute  |  Vol -  |  Vol +  |
+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+

   */
	[2] = KEYMAP(
      KC_TAB,   KC_QUOT,  KC_COMM,  KC_DOT,   KC_P,     KC_Y,           KC_F,         KC_G,               KC_C,         KC_R,           KC_L,         KC_BSPC,
      KC_ESC,   KC_A,     KC_O,     KC_E,     KC_U,     KC_I,           KC_D,         KC_H,               KC_T,         KC_N,           KC_S,         KC_SLSH,
      KC_LSFT,  KC_SCLN,  KC_Q,     KC_J,     KC_K,     KC_X,           KC_B,         KC_M,               KC_W,         KC_V,           KC_Z,         RSFT_T(KC_ENT),
      MO(3),    MO(6),    KC_LGUI,  KC_LALT,  MO(4),    KC_SPC,         KC_SPC,       MO(5),              KC_RALT,      KC_MUTE,        KC_VOLD,      KC_VOLU
      ),

// F-key, numpad layer
  /*
+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+
|   Tab   |   F1    |   F2    |   F3    |   F4    |         |    /    |    7    |    8    |    9    |    -   | Backspce |
+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+
|   Esc   |   F5    |   F6    |   F7    |   F8    |         |    *    |    4    |    5    |    6    |    +    |   Del   |
+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+
|  Shift  |   F9    |   F10   |   F11   |   F12   |         |         |    1    |    2    |    3    |         |  Enter  |
+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+
|   vvv   | Layer 6 |   GUI   |   Alt   | Layer 4 |   Ctrl  |  Space  | Layer 5 |    0    |    .    |    ,    | Num Lock|
+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+

   */
	[3] = KEYMAP(
      KC_TAB,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_NO,          KC_PSLS,      KC_P7,              KC_P8,        KC_P9,          KC_PMNS,      KC_BSPC,
      KC_ESC,   KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_NO,          KC_PAST,      KC_P4,              KC_P5,        KC_P6,          KC_PPLS,      KC_DEL,
      KC_LSFT,  KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_TRNS,        KC_NO,        KC_P1,              KC_P2,        KC_P3,          KC_NO,        KC_ENT,
      KC_TRNS,  MO(6),    KC_LGUI,  KC_LALT,  MO(4),    KC_LCTL,        KC_SPC,       MO(5),              KC_P0,        KC_PDOT,        KC_PCMM,      KC_NLCK
      ),

// Numbers, common coding symbols
  /*
+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+
|    `    |    1    |    2    |    3    |    4    |    5    |    6    |    7    |    8    |    9    |    0    | Bckspce |
+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+
|   Esc   |    {    |    }    |   Home  |   End   |         |         |    -    |    =    |    _    |    +    |   Del   |
+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+
|  Shift  |    [    |    ]    |    (    |    )    |         |         |    |    |    ,    |    .    |    /    |  Enter  |
+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+
| Layer 3 | Layer 6 |   GUI   |   Alt   |   vvv   |   Ctrl  |  Space  | Layer 5 |Caps Lock|Wind Left|Windo Max|Win Right|
+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+

   */
	[4] = KEYMAP(
      KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,           KC_6,         KC_7,               KC_8,         KC_9,           KC_0,         KC_BSPC,
      KC_ESC,   KC_LCBR,  KC_RCBR,  KC_HOME,  KC_END,   KC_NO,          KC_NO,        KC_MINS,            KC_EQL,       LSFT(KC_MINS),  LSFT(KC_EQL), KC_DEL,
      KC_LSFT,  KC_LBRC,  KC_RBRC,  KC_LPRN,  KC_RPRN,  KC_NO,          KC_NO,        KC_PIPE,            KC_COMM,      KC_DOT,         KC_BSLS,      KC_ENT,
      TO(3),    MO(6),    KC_LGUI,  KC_LALT,  KC_TRNS,  KC_LCTL,        KC_SPC,       MO(5),      KC_CAPS, LCTL(LGUI(KC_LEFT)), LCTL(LGUI(KC_UP)), LCTL(LGUI(KC_RIGHT))
      ),

// Num-row symbols, arrow keys, browsing shortcuts
  /*
+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+
|    ~    |    !    |    @    |    #    |    $    | Vimclip | New Term|    %    |    ^    |    &    |    *    | Bckspce |
+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+
|   Esc   |   Ws1   |   Ws2   |   Ws3   |   Ws4   |         |   Left  |   Down  |    Up   |  Right  | New Tab |   Del   |
+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+
|  Shift  |Move->Ws1|Move->Ws2|Move->Ws3|Move->Ws4|         | Go Back | Prev Tab| Next Tab| Go Forw |Close Tab|  Enter  |
+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+
| Layer 3 | Layer 6 |   GUI   |   Alt   | Layer 4 |   Ctrl  |  Space  |   vvv   |   Menu  |   Prev  |  Pause  |   Next  |
+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+

   */
	[5] = KEYMAP(
      KC_TILD,  KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   LCA(KC_V),    LCA(KC_T),      KC_PERC,            KC_CIRC,      KC_AMPR,        KC_ASTR,      KC_BSPC,
      KC_ESC,   LALT(KC_1),LALT(KC_2),LALT(KC_3),LALT(KC_4),KC_NO,    KC_LEFT,        KC_DOWN,            KC_UP,        KC_RGHT,        LCTL(KC_T),   KC_DEL,
      KC_LSFT,  LALT(S(KC_1)),LALT(S(KC_2)),LALT(S(KC_3)),LALT(S(KC_4)),KC_NO,    LALT(KC_LEFT),  LSFT(LCTL(KC_TAB)), LCTL(KC_TAB), LALT(KC_RGHT),  LCTL(KC_W),   KC_ENT,
      MO(3),    MO(6),    KC_LGUI,  KC_LALT,  TO(4),    KC_LCTL,      KC_SPC,         KC_TRNS,            LSFT(KC_F10), KC_MPRV,        KC_MPLY,      KC_MNXT
      ),

// Default-layer switching (includes numpad-layer lock), sound options
  /*
+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+
|         |Default:Q|Default:D|         |         |         |         |         |         |Music Tog|         |Beeps Tog|
+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+
|         |Default:G|Default:#|         |         |         |         |         |         |Mus Types|         | Pitch + |
+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+
|         |         |         |         |         |         |         |         |         |         |         | Pitch - |
+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+
|         |   vvv   |         |         |         |         |Boot Mode|         |         |         |         |         |
+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+

   */
	[6] = KEYMAP(
      KC_NO,    DF(0),    DF(2),    KC_NO,    KC_NO,    KC_NO,        KC_NO,          KC_NO,              KC_NO,        MU_TOG,         KC_NO,        CK_TOGG,
      KC_NO,    DF(1),    DF(3),    KC_NO,    KC_NO,    KC_NO,        KC_NO,          KC_NO,              KC_NO,        MU_MOD,         KC_NO,        CK_UP,
      KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,        KC_NO,          KC_NO,              KC_NO,        KC_NO,          KC_NO,        CK_DOWN,
      KC_NO,    KC_TRNS,  KC_NO,    KC_NO,    KC_NO,    KC_NO,        RESET,          KC_NO,              KC_NO,        KC_NO,          KC_NO,        KC_NO
      )
};

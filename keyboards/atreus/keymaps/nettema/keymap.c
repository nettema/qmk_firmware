// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QW  0  //Qwerty layer
#define _RS  1  //RAISE
#define _LW  2  //LOWER
#define _GM  3  //Gaming
#define _RU  4  //Russian
#define _CFG 5  //Russian


// Layers combo
#define RS_CTL      LT(_RS, KC_LCTL)
#define RS_DEL      LT(_RS, KC_DEL)
#define RS_ENT      LT(_RS, KC_ENT)
#define RS_ESC      LT(_RS, KC_ESC)
#define RS_SPC      LT(_RS, KC_SPC)
#define RS_TAB      LT(_RS, KC_TAB)
#define RS_BSPC     LT(_RS, KC_BSPC)

#define LW_DEL      LT(_LW, KC_DEL)
#define LW_ENT      LT(_LW, KC_ENT)
#define LW_ESC      LT(_LW, KC_ESC)
#define LW_SPC      LT(_LW, KC_SPC)
#define LW_TAB      LT(_LW, KC_TAB)
#define LW_BSPC     LT(_LW, KC_BSPC)
#define LW_PRTSCN   LT(_LW, KC_PSCR)

#define RU_SPC      LT(_RU, KC_SPC)
#define RU_TAB      LT(_RU, KC_TAB)
// Mods combo
#define SH_DEL      SFT_T(KC_DEL)
#define SH_ENT      SFT_T(KC_ENT)
#define SH_SPC      SFT_T(KC_SPC)
#define SH_BSPC     RSFT_T(KC_BSPC)
#define CTL_SPC     CTL_T(KC_SPC)
#define ALT_BSPC    ALGR_T(KC_BSPC)

// Bluetooth buttons
// #define BTAUTO   OUT_AUTO
// #define BTON     OUT_BT
// #define BTOFF    OUT_USB
#define BTAUTO   RGB_M_R
#define BTON     RGB_M_B
#define BTOFF    RGB_M_G

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /*
   *  q       w     e       r          t              ||            y        u       i     o    p
   *  a       s     d       f          g              ||            h        j       k     l    ;
   *  z       x     c       v          b              ||            n        m       ,     .    [
   * ctrl   super  alt   esc`(lw)   space(sh) del(rs) || ent(rs) bksp(sh)  tab(lw)   /     ]    '
   */
  [_QW] = LAYOUT( /* QwertyRU */
    KC_Q,     KC_W,    KC_E,    KC_R,   KC_T,                    KC_Y,    KC_U,   KC_I,    KC_O,    KC_P ,
    KC_A,     KC_S,    KC_D,    KC_F,   KC_G,                    KC_H,    KC_J,   KC_K,    KC_L,    KC_SCLN ,
    KC_Z,     KC_X,    KC_C,    KC_V,   KC_B,                    KC_N,    KC_M,   KC_COMM, KC_DOT,  KC_LBRC ,
    KC_LCTL,  KC_LGUI, KC_LALT, RS_ESC, SH_SPC, LW_DEL, LW_ENT,  SH_BSPC, RS_TAB, KC_SLSH, KC_RBRC, KC_QUOT
    ),
  /*
   *  !       @      up     {    }          ||           -     7     8     9    *
   *  #     left    down  right  $          ||           _     4     5     6    +
   *  [       ]      (      )    &          ||           `     1     2     3    \
   * ctrl   super   alt     fn  spc del(lw) || ent(lw)  bksp   fn    .     0     =
   */
  [_RS] = LAYOUT( /* [> RAISE <] */
    KC_EXLM, KC_AT,   KC_UP,   KC_LCBR, KC_RCBR,                   KC_MINS, KC_7,    KC_8,   KC_9, KC_ASTR ,
    KC_HASH, KC_LEFT, KC_DOWN, KC_RGHT, KC_DLR,                    KC_UNDS, KC_4,    KC_5,   KC_6, KC_PLUS ,
    KC_LBRC, KC_RBRC, KC_LPRN, KC_RPRN, KC_AMPR,                   KC_GRV,  KC_1,    KC_2,   KC_3, KC_BSLS ,
    KC_LCTL, KC_LGUI, KC_LALT, KC_TRNS, SH_SPC,   LW_DEL, LW_ENT,  SH_BSPC, KC_TRNS, KC_DOT, KC_0, KC_EQL
    ),
  /*
   *  insert  home    up      end     pgup        ||       |         F7     F8    F9     F10
   *   del    left   down    right    pgdn        ||       "         F4     F5    F6     F11
   *   rgb+   HUE+   pause   prtsc    reset       ||      rgbOn      F1     F2    F3     F12
   *   ctrl  super    alt   esc(rs)  space(sh) fn || fn  bksp(sh)  tab(rs) prtsc Config Gaming
   */
  [_LW] = LAYOUT( /* [> LOWER <] */
    KC_INS,  KC_HOME, KC_UP,   KC_END,  KC_PGUP,                   KC_PIPE, KC_F7,   KC_F8,   KC_F9,    KC_F10  ,
    KC_DEL,  KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,                   KC_DQT,  KC_F4,   KC_F5,   KC_F6,    KC_F11  ,
    RGB_MOD, RGB_HUD, KC_PAUS, KC_PSCR, RESET,                     RGB_TOG, KC_F1,   KC_F2,   KC_F3,    KC_F12  ,
    KC_LCTL, KC_LGUI, KC_LALT, RS_ESC, SH_SPC,  KC_TRNS, KC_TRNS,  SH_BSPC, RS_TAB,  KC_PSCR, TG(_CFG), TO(_GM)
    ),
  /*
   *  esc`  q  w  e   r             ||              y      u    i    o     p
   *  tab   a  s  d   f             ||              h      j    k    l     ;
   * shift  z  x  c   v             ||              n      m    ,    .     /
   *  CTL   1  2  3 space space(rs) || enter(rs) bksp(sh) del  `~   QWER  RUS
   */
  [_GM] = LAYOUT( /* Gaming */
    KC_GESC, KC_Q, KC_W, KC_E, KC_R,                   KC_Y,    KC_U,    KC_I,    KC_O,    KC_P    ,
    KC_TAB,  KC_A, KC_S, KC_D, KC_F,                   KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN ,
    KC_LSFT, KC_Z, KC_X, KC_C, KC_V,                   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH ,
    KC_LCTL, KC_1, KC_2, KC_3, KC_SPC, RS_SPC, RS_ENT, SH_BSPC, LW_DEL,  KC_GRV,  TO(_QW), TG(_RU)
    ),
  /*
   *  Й       Ц     У       К          Е              ||            Н        Г       Ш     Щ    З
   *  Ф       Ы     В       А          П              ||            Р        О       Л     Д    Ж
   *  Я       Ч     С       М          И              ||            Т        Ь       Б     Ю    Х
   * ctrl   super  alt   esc`(lw)   space(sh) del(rs) || ent(rs) bksp(sh)  tab(lw)   /     Э    tg(ru)
   */
  [_RU] = LAYOUT( /* QwertyRU */
   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P ,
   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN ,
   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_LBRC ,
   KC_LCTL, KC_LGUI, KC_LALT, RS_ESC,  SH_SPC,  LW_DEL,  LW_ENT,  SH_BSPC, RS_TAB,  KC_SLSH, KC_QUOT, TG(_RU)
   ),
  /*
   * BT_Auto  RGB_On  Bright+   HUE+     SAT+           ||         SCRL_Up      LMB       M_Up       RMB       MMB
   * BT_Off   RGB-    Bright-   RGB+     SAT-           ||         SCRL_Down   M_Left    M_Down    M_Right     MB4
   * BT_On    volup     NO       NO      reset          ||         Accel_0    SCRL_Left  Accel_1  SCRL_Right   MB5
   * Mute     voldn     NO     esc(rs)  spc(sh) del(lw) || ent(lw) space(sh)   tab(rs)    QWER      Config    Gaming
   */
  [_CFG] = LAYOUT( /* Media layout */
    BTAUTO,  RGB_TOG,   RGB_VAI,  RGB_HUI,  RGB_SAI,                   KC_WH_U,      KC_BTN1,   KC_MS_U,      KC_BTN2,    KC_BTN3  ,
    BTOFF,   RGB_RMOD,  RGB_VAD,  RGB_MOD,  RGB_SAD,                   KC_WH_D,      KC_MS_L,   KC_MS_D,      KC_MS_R,    KC_BTN4  ,
    BTON,    KC_VOLU,   KC_NO,    KC_NO,    RESET,                     KC_MS_ACCEL0, KC_WH_L,   KC_MS_ACCEL1, KC_WH_R,    KC_BTN5  ,
    KC_MUTE, KC_VOLD,   KC_NO,    RS_ESC,   SH_SPC,   LW_DEL, LW_ENT,  SH_BSPC,      RS_TAB,    TO(_QW),      TG(_CFG),   TO(_GM)  ),
};

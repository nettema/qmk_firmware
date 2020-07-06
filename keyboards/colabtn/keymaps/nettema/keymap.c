// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QW   0  //Qwerty layer
// #define _GM   1  //Gaming
// #define _RU   2  //Russian
// #define _RS   3  //RAISE
// #define _LW   4  //LOWER
// #define _CFG  5  //Config
// #define _GMSP 6  //Gaming and soundpad


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

//Tap Dance Declarations
#define GUI_LNG  TD(TD_GUI_GUISPC)
enum {
  TD_GUI_GUISPC = 0,
  U_F13,  I_F14,    O_F15,    P_F16,
  J_F17,  K_F18,    L_F19,    SC_F20,
  M_F21,  COM_F22,  DOT_F23,  SH_F24
};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for Esc, twice for Caps Lock
  [TD_GUI_GUISPC]  = ACTION_TAP_DANCE_DOUBLE(KC_LGUI, G(KC_SPC))
  ,[U_F13]  = ACTION_TAP_DANCE_DOUBLE(KC_U, KC_F13)
  ,[I_F14]  = ACTION_TAP_DANCE_DOUBLE(KC_I, KC_F14)
  ,[O_F15]  = ACTION_TAP_DANCE_DOUBLE(KC_O, KC_F15)
  ,[P_F16]  = ACTION_TAP_DANCE_DOUBLE(KC_P, KC_F16)
  ,[J_F17]  = ACTION_TAP_DANCE_DOUBLE(KC_J, KC_F17)
  ,[K_F18]  = ACTION_TAP_DANCE_DOUBLE(KC_K, KC_F18)
  ,[L_F19]  = ACTION_TAP_DANCE_DOUBLE(KC_L, KC_F19)
  ,[SC_F20]  = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_F20)
  ,[M_F21]  = ACTION_TAP_DANCE_DOUBLE(KC_M, KC_F21)
  ,[COM_F22]  = ACTION_TAP_DANCE_DOUBLE(KC_COMM, KC_F22)
  ,[DOT_F23]  = ACTION_TAP_DANCE_DOUBLE(KC_DOT, KC_F23)
  ,[SH_F24]  = ACTION_TAP_DANCE_DOUBLE(KC_SLSH, KC_F24)
// Other declarations would go here, separated by commas, if you have them
};

/* Macros definition */
enum custom_keycodes {
  QMKBEST = SAFE_RANGE,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QMKBEST:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING("\n"SS_DELAY(70)"gg ez\n");
      } else {
        // when keycode QMKBEST is released
      }
      break;

  }
  return true;
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /*
   *  q       w     e       r          t              ||            y        u       i     o    p
   *  a       s     d       f          g              ||            h        j       k     l    ;
   *  z       x     c       v          b              ||            n        m       ,     .    [
   * ctrl   super  alt   esc`(lw)   space(sh) del(rs) || ent(rs) bksp(sh)  tab(lw)   /     ]    '
   */
  [_QW] = LAYOUT( /* QwertyRU */
    QMKBEST
    ),
};

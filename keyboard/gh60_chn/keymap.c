#include "keymap_common.h"

enum fn_id {
	FN_DEFAULT_LAYER,
	FN_NAV_LAYER,
	FN_NAV_LAYER_DUP,
	FN_MOUSE_LAYER,
};

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	// keymap 0 - baseline
    [FN_DEFAULT_LAYER] = KEYMAP_ANSI(
        ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSPC, \
        TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSLS, \
        FN0, A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,     ENT,  \
        LSFT,Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,          RSFT, \
        LCTL,LGUI,LALT,          SPC,                     RALT,FN2, FN1, RCTL),

	// layer 1: nav/fn
    [FN_NAV_LAYER] = KEYMAP_ANSI(
        GRV, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, DEL , \
        TRNS,HOME,UP,  END, PGUP,TRNS,TRNS,TRNS,HOME,UP,  END, PGUP,TRNS,INS,  \
        TRNS,LEFT,DOWN,RGHT,PGDN,TRNS,TRNS,TRNS,LEFT,DOWN,RGHT,PGDN,     TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,          TRNS, \
        TRNS,TRNS,TRNS,             TRNS,                 TRNS,TRNS,TRNS,TRNS),

	// layer 1a: nav/fn duplicate.
	//           I want two keys to do the same thing.. but doing this using
	//           two keys with the same Fn keycodes doesn't work all that well.
	//           Release events always un-enable that layer so if you mash both
	//           keys and release one, you leave that layer even though you're
	//           pressing and holding the remaining key.
	//
	//           Of course, this makes for some interesting layer enable options
    [FN_NAV_LAYER_DUP] = KEYMAP_ANSI(
        GRV, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, DEL , \
        TRNS,HOME,UP,  END, PGUP,TRNS,TRNS,TRNS,HOME,UP,  END, PGUP,TRNS,INS,  \
        TRNS,LEFT,DOWN,RGHT,PGDN,TRNS,TRNS,TRNS,LEFT,DOWN,RGHT,PGDN,     TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,          TRNS, \
        TRNS,TRNS,TRNS,             TRNS,                 TRNS,TRNS,TRNS,TRNS),

	// layer 3: mouse keys
	//          totally experimental, not sure this is effective, but it's handy
	//          also, currently the dumping area for the random things I don't
	//          know where to put - RGUI for example
    [FN_MOUSE_LAYER] =  KEYMAP_ANSI(
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, \
        TRNS,WH_U,MS_U,WH_D,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, \
        TRNS,MS_L,MS_D,MS_R,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,          TRNS, \
        BTN2, APP,TRNS,             BTN1,                 TRNS,TRNS,RGUI,TRNS),

	/*
	// transparent layer. start here!
    [FN_TRNS_LAYER] =  KEYMAP_ANSI(
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,          TRNS, \
        TRNS,TRNS,TRNS,             TRNS,                 TRNS,TRNS,TRNS,TRNS),

	*/
};

const action_t PROGMEM fn_actions[] = {
	 [0] = ACTION_LAYER_MOMENTARY(FN_NAV_LAYER),
	 [1] = ACTION_LAYER_MOMENTARY(FN_NAV_LAYER_DUP),
	 [2] = ACTION_LAYER_MOMENTARY(FN_MOUSE_LAYER),
	 // [3] = ACTION_LAYER_MODS(FN_FANCY_LAYER, MOD_LSFT),
};




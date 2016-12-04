#include "keymap_common.h"
#include "action_util.h"
// keymap.h is for keycode-to-action functrion
#include "keymap.h"

enum fn_id {
	FN_DEFAULT_LAYER,
	FN_NAV_LAYER,
	FN_NAV_LAYER_DUP,
	FN_MOUSE_LAYER,
    FN_TEMP,
};

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	// keymap 0 - baseline
    [FN_DEFAULT_LAYER] = KEYMAP_ANSI(
        ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSPC, \
        TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSLS, \
        FN0, A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,     ENT,  \
        LSFT,Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,          RSFT, \
        LCTL,LGUI,LALT,          SPC,                     RALT,FN2, FN1, RCTL),   // 

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
        FN10,FN11,FN12,FN13,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,BOOTLOADER, \
        TRNS,WH_U,MS_U,WH_D,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, \
        TRNS,MS_L,MS_D,MS_R,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,          TRNS, \
        BTN2, APP,TRNS,             BTN1,                 TRNS,TRNS,RGUI,TRNS),


    [FN_TEMP] =  KEYMAP_ANSI(
        TRNS,FN3, FN4, FN5,FN6,FN7,FN8,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,BOOTLOADER, \
        TRNS,WH_U,MS_U,WH_D,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, \
        TRNS,MS_L,MS_D,MS_R,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,          TRNS, \
        BTN2, APP,TRNS,             BTN1,                 TRNS,FN2, RGUI,TRNS),             // on entering this layer, you can't jump to FN1/FN0 without a release


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
	 [2] = ACTION_LAYER_MOMENTARY(FN_TEMP),
     [3] = ACTION_FUNCTION(0),
     [4] = ACTION_MACRO(0),
     [5] = ACTION_MACRO(1),
     [6] = ACTION_MACRO(2),
     [7] = ACTION_MACRO(3),
     [8] = ACTION_MACRO(4),          
	 // [3] = ACTION_LAYER_MODS(FN_FANCY_LAYER, MOD_LSFT),
	 // [10] = ACTION_MACRO(1),
};

/* Tap to enter
hold to permalock
backspace to exit layer */


/*
 * Macro definition
 */
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    switch (id) {
        case 0:
            return (record->event.pressed ?
                    MACRO( I(0), T(H), T(E), T(L), T(L), W(255), T(O), END ) :
                    MACRO_NONE );

                    // keyevent_t->event.pressed
                    // keyevent_t->event.key      gives you back a key_t object which is cols/rows
                    //                            KEYMAP()
                    // keymaps[FN_DEFAULT_LAYER][0,1]
                    // for TMK, how do you convert the keycode in a keyevent into a key on the layer?
                    // /* translates key to keycode */
                    // uint8_t keymap_key_to_keycode(uint8_t layer, keypos_t key);
                    // keymap_get_keycode
                    // keycode_to_action -is this all i really need done? 
        case 1:
            return (record->event.pressed ?
                    MACRO( T(F), D(Z), T(O), END ) :
                    MACRO_NONE  );
        case 2:
            return (record->event.pressed ? 
                    MACRO( D(LSHIFT), D(D), END ) :
                    MACRO_NONE );

        case 3:
            return (record->event.pressed ? 
                    MACRO( U(D), U(LSHIFT), END ) :
                    MACRO( D(LSHIFT), D(D), END ) );
    }
    return MACRO_NONE;
}



/*
 * user defined ((action)) function
 */
void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    switch (id) {
        case 0:
            add_weak_mods(MOD_BIT(KC_LSHIFT));
            send_keyboard_report();
            register_code(KC_9);
            unregister_code(KC_9);
            del_weak_mods(MOD_BIT(KC_LSHIFT));
            break;
        case 1:
          // this below kinda works, but the event.key row/col needs translation
          // need to work out where that translation layer is
            register_code(keymaps[FN_DEFAULT_LAYER][record->event.key.row][record->event.key.col]);
            unregister_code(keymaps[FN_DEFAULT_LAYER][record->event.key.row][record->event.key.col]);
            register_code(KC_7);
            unregister_code(KC_7);
            break;
    }
}
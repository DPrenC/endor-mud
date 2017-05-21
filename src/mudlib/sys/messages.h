#ifndef __MESSAGES_H__
#define __MESSAGES_H__

#define MSG_SEE     "See"
#define MSG_HEAR    "Hear"
#define MSG_FEEL    "Feel"

#define MSG_TELL    "Tell"

#define MSG_COMBAT  "Combat"

/*
#define MSG_MOVE   "Move"   // Ahora este es un MSG_SEE
#define MSG_DAMAGE "Damage"
#define MSG_ENEMY  "Enemy"
#define MSG_DIE    "Die"
#define MSG_STUN   "Stun"
*/

// --- MSG_SEE ---

#define SEE_CAN     1
#define SEE_CANT    2

// --- MSG_HEAR ---

#define HEAR_CAN    1
#define HEAR_CANT   2
/*
#define HEAR_TYPE       1
#define HEAR_TEXT       2
#define HEAR_NO_TEXT    3

#define HEAR_SAY      "say"
#define HEAR_TELL     "tell"
#define HEAR_SHOUT    "shout"
#define HEAR_PSHOUT   "pshout"
#define HEAR_WSHOUT   "wshout"
#define HEAR_HSHOUT   "hshout"
#define HEAR_WHISPER  "whisper"
#define HEAR_CONVERSE "converse"
#define HEAR_ECHOTO   "echoto"
#define HEAR_ECHO     "echo"
#define HEAR_PECHO    "pecho"
#define HEAR_WECHO    "wecho"
#define HEAR_ECHOALL  "echoall"
*/

// --- MSG_FEEL ---

#define FEEL_CAN    1
#define FEEL_CANT   2 // Y yo q se por q, inconsciente!?

// --- MSG_TELL ---

#define TELL_CAN    1
#define TELL_CANT   2 // Quiza ignorado?

// --- MSG_COMBAT ---
//verb, with, what, how
#define COMBAT_TYPE   1
#define COMBAT_ATK    2
#define COMBAT_DEF    3
#define COMBAT_VERB   4
#define COMBAT_WITH   5
#define COMBAT_DAM    6
#define COMBAT_WHAT   7
#define COMBAT_HOW    8

#define COMBAT_TYPE_MELEE   1   // (1<<0)
#define COMBAT_TYPE_THROW   2   // (1<<2)
#define COMBAT_TYPE_SPELL   4   // (1<<3)

// Valores en positivo son hit, en negativo miss.

/*
#define COMBAT_RANGED_HIT  2
#define COMBAT_SPELL_HIT   3

#define COMBAT_MELEE_MISS  -COMBAT_MELEE_HIT
#define COMBAT_RANGED_MISS -COMBAT_RANGED_HIT
#define COMBAT_SPELL_MISS  -COMBAT_SPELL_HIT
*/
/*
// --- MSG_MISS ---

#define MISS_ATK    1
#define MISS_DEF    2
#define MISS_VERB   3
#define MISS_MSG    4

// --- MSG_HIT ---

#define HIT_ATK    1
#define HIT_DEF    2
#define HIT_VERB   3
#define HIT_MSG    4
*/

// --- MSG_MOVE ---

#define MOVE_ORIG   1
#define MOVE_DEST   2
#define MOVE_METHOD 3
#define MOVE_EXTRA  4

/*
// --- MSG_DIE ---

#define DIE_CORPSE 1

// --- MSG_DAMAGE ---

#define DAMAGE_CAUSE  1
#define DAMAGE_AMOUNT 2

// --- MSG_ENEMY

#define ENEMY_ENEMY   1
#define ENEMY_ACTION  2

// --- MSG_STUN ---

#define STUN_CAUSE  1
#define STUN_ROUNDS 2
*/

#endif // __MESSAGES_H__

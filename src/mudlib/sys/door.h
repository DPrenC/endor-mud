/*
	SIMAURIA [/sys/door.h]
	*/

#ifndef _DOOR_
#define _DOOR_

// propiedades
#define P_DOOR_STATE                 "DoorState"
#define P_DOOR_LOCK_STATE            "DoorLockState"
#define P_DOOR_CLOSE_TIME            "DoorCloseTime"
#define P_DOOR_OPEN_MSG              "DoorOpenMsg"
#define P_DOOR_CLOSE_MSG             "DoorCloseMsg"
#define P_DOOR_NOLEAVE_MSG           "DoorNoleaveMsg"
#define P_DOOR_CANT_OPEN_MSG         "DoorCantOpenMsg"
#define P_DOOR_UNLOCK_MSG            "DoorUnlockMsg"
#define P_DOOR_LOCK_MSG              "DoorLockMsg"
#define P_DOOR_CANT_UNLOCK_MSG       "DoorCantUnlockMsg"
#define P_DOOR_CANT_LOCK_MSG         "DoorCantLockMsg"
#define P_DOOR_KNOCK_MSG             "DoorKnockMsg"
#define P_DOOR_KEY                   "DoorKey"
#define P_DOOR_DEFAULT_IN_RESET       "DoorDefaultInReset"
#define P_DOOR_TRANSPARENCY           "DoorTransparency"
#define P_DOOR_TRANSPARENCY_MSG       "DoorTransparencyMsg"
#define P_DOOR_CHANGE_STATE_FUNCTION  "DoorChangeStateFunction"
#define P_DOOR_CHANGE_LOCK_FUNCTION   "DoorChangeLockFunction"
#define P_DOOR_OPEN_SOUND             "DoorOpenSound"
#define P_DOOR_CLOSE_SOUND            "DoorCloseSound"
#define P_DOOR_LOCK_SOUND             "DoorLockSound"
#define P_DOOR_UNLOCK_SOUND           "DoorUnlockSound"
#define P_DOOR_HIT_SOUND              "DoorHitSound"
#define P_DOOR_KNOCK_SOUND            "DoorKnockSound"


// flags de estado
#define DOOR_OPENED            1
#define DOOR_CLOSED            0
#define DOOR_LOCKED            1
#define DOOR_UNLOCKED          0


// path del objeto puerta
#define DOOR_PATH     "/std/door"


// tipos de mensaje
#define DOOR_MSG_PLAYER    0
#define DOOR_MSG_ROOM      1
#define DOOR_MSG_DEST      2
#define DOOR_MSG_SEE       0
#define DOOR_MSG_HEAR      1


#endif
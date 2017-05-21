#ifndef __NPC_H__
#define __NPC_H__

#include <living.h>
#include <moving.h>


//-----------------------------------------------------------------------
// Modes for Drop()

#define PUTGET_SILENT      1   // Issue no messages
#define PUTGET_FULL    (1<<1)  // Return full result field.
#define PUTGET_REALLY  (1<<2)  // Handle wielded equipment as well.

// Data fields of the full result of Drop() and co

/* [Nyh] Antiguo
#define PUTGET_OK        0  // Objects being dropped.
#define PUTGET_NODROP    1  // Objects which have NO_DROP defined.
#define PUTGET_NOMOVE    2  // Objects which don't move at all.
#define PUTGET_NOLEAVE   3  // Objects which couldn't leave their place.
#define PUTGET_TOOHEAVY  4  // Objects which were too heavy for destination
#define PUTGET_TOOMANY	 5  // demasiados objetos
#define PUTGET_TOOBIG    6  // Objects which were too heavy for destination
#define PUTGET_COUNT     7  // Number of full result fields
*/
/* [Nyh] Nuevo, haciendo referencia al moving.h:
Uso el -1 porque en el moving el resultado de ME_OK vale 1, y el putget
necesita que PUTGET_OK valga 0.
*/
#define PUTGET_NOMOVE         (ME_NO_MOVE         - 1) /* general == default if move() is not defined */
#define PUTGET_OK             (ME_OK              - 1) /* as already is now */
#define PUTGET_DESTRUCTEDSELF (ME_DESTRUCTED_SELF - 1) /* object was destructed while moving */
#define PUTGET_NOLEAVE        (ME_NO_LEAVE        - 1) /* was not allowed to leave current env */
#define PUTGET_NOENTER        (ME_NO_ENTER        - 1) /* was denied entering for unknown reason */
#define PUTGET_TOOHEAVY       (ME_TOO_HEAVY       - 1) /* dest cannot carry us */
#define PUTGET_CAUGHTERR      (ME_CAUGHT_ERR      - 1) /* Caught error on move_object() */
#define PUTGET_NODROP         (ME_NO_DROP         - 1) /* object does not want to be dropped */
#define PUTGET_NOGET          (ME_NO_GET          - 1) /* object does not want to be picked up */
#define PUTGET_NOGIVE         (ME_NO_GIVE         - 1) /* object does not want to be given away */
#define PUTGET_TOOMANY        (ME_TOO_MANY        - 1) /* demasiados objetos */
#define PUTGET_TOOBIG         (ME_TOO_BIG         - 1) /* demasiado grande */
#define PUTGET_COUNT          12

// Data fields of the full result of EquipLayoff()

#define EQUIP_OK        0  // Objects being dropped.
#define EQUIP_NOEQUIP   1  // Objects which are of the wrong type.
#define EQUIP_FAIL      2  // Objects which failed to response.

#define EQUIP_COUNT     3  // Number of full result fields

//-----------------------------------------------------------------------
// Modes for the sensing functions.

#define SENSE_MOVE       1  // LookRoom(): called from move().
#define SENSE_IMPL       1  // Sense(): implode result.
#define SENSE_SILENT    (1<<1) // Issue no messages
#define SENSE_EXAMINATE (1<<2) // Add exa info.
//-----------------------------------------------------------------------
// Modes for Inventory()

#define INV_FLAT   1  // List just the top inventory.
#define INV_LONG   2  // Don't fold items of matching description.
#define INV_NARROW 4  // Format the strings for 38 char linesize

#endif // __NPC_H__

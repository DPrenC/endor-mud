#ifndef _EQUIPMENT_H_
#define _EQUIPMENT_H_ 1

// Usage modes of the equipment.

#define EQM_NONE  0
#define EQM_WEAR  1
#define EQM_WIELD 2
#define EQM_BOTH  3

// Binary flag values for the (Un)Equip() functions.

#define EWF_NONE    0
#define EWF_WEAPON  1
#define EWF_SILENT  2

// Fields in the Equipdata array.

#define EQD_DO    0
#define EQD_UNDO  1
#define EQD_ADJ   2

// Default Equipdata array

#define DEFAULT_WIELDDATA ({ ({ "blandir", "empuñar", "empunyar" }) \
                           , ({ "envainar", "desempuñar", "desempunyar" }) \
                           , "empuñad" })
#define DEFAULT_WEARDATA ({ ({ "ponerse", "equipar", "vestir" }) \
                         , ({ "quitarse", "desequipar", "desvestir" }) \
                         , "puest" })
#define DEFAULT_EQUIPDATA ({ ({ "equipar" }) \
                           , ({ "desequipar" }) \
                           , "equipad" })

// Return values of Equip(), Unequip()

#define EQ_OK       0
#define EQ_MUTUAL   1
#define EQ_ALREADY  2
#define EQ_FORBID   3
#define EQ_NOHANDS  4
#define EQ_SMALL    5
#define EQ_LARGE    6
#define EQ_ERROR    7

#endif

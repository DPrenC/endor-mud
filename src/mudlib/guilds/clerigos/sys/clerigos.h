/**
 * SIMAURIA '/guilds/clerigos/sys/clerigos.h'
 */

#ifndef __CLERIGOS_H__
#define __CLERIGOS_H__

/* ############## GREMIO DE CONJURADORES ############## */

#define GCLERIGOS           PPATH "clerigos/"
#define OBJETO(x)           GCLERIGOS "obj/"+x
#define CLERIGO_SAVE(x)     GUILDLOGPATH "clerigos/"+x
#define LOG(x,y)            write_file(GUILDLOGPATH "clerigos/" + x, y)

/* ############## FUNCIONES MAS USADAS ############## */

#define OWNER         QueryObjectOwner()
#define TGENDER       this_player()->QueryGender()

/* ############## COLORES ############## */

#define CNEGRITA       "[1m"
#define CSUBR          "[4m"
#define CPARP          "[5m"
#define CINVERS        "[6m"
#define CNORMAL        "[0m"
#define CNEGRO         "[30m"
#define CROJO          "[31m"
#define CVERDE         "[32m"
#define CAMARILLO      "[33m"
#define CAZUL          "[34m"
#define CVIOLETA       "[35m"
#define CCIAN          "[36m"
#define CBLANCO        "[37m"
#define CCNORMAL       "[39m"

#endif

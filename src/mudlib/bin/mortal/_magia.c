/* SIMAURIA '/bin/mortal/_magia.c'
   ===============================
   [k] Khelben@simauria
   [w] Woo@simauria

            [t] Creación de este archivo.
   07-04-99 [w] Cambio del bin de wizs al de jugadores.
*/

#include "/secure/daemons.h"
#include <magicd.h>

int main(string str) {
    seteuid(getuid());
    return MAGICD->main(TP,str);
}

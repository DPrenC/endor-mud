/******************************************/
// Comando para crear archivos
/******************************************/
#include "/SECURE/config.h"
//#include "/secure/wizlevels.h"
//#include <stdrooms.h>
int main() {
    seteuid(getuid());
write("Comenzando con el comando crear para la creaci�n de rooms.\n");

//log_file("creacion.c", "Segunda creaci�n.\n");
write_file("/d/pais-bree/creacion3.c", "Tercera creaci�n.\n");

write("Supuestamente ha escrito algo en el dominio de Bree.\n");
return 1;
}
/******************************************/
// Comando para crear archivos
/******************************************/
#include "/SECURE/config.h"
//#include "/secure/wizlevels.h"
//#include <stdrooms.h>
int main() {
    seteuid(getuid());
write("Comenzando con el comando crear para la creación de rooms.\n");

//log_file("creacion.c", "Segunda creación.\n");
write_file("/d/pais-bree/creacion3.c", "Tercera creación.\n");

write("Supuestamente ha escrito algo en el dominio de Bree.\n");
return 1;
}
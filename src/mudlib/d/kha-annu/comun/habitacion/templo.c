/*****************************************************************************/
/*   Fichero: templo.c                                                       */
/*   Creado por: [I] Izet@Simauria, 18 Dic 1997                              */
/*   Ultima modificacion: 18 Dic 1997.                                       */
/*   Descripcion: Este es el templo donde resucitaran los creyentes en       */
/*                Kolhiak y en Hatkzi, dioses bueno y malo respectivamente   */
/*                (no hay Dios neutral en este templo).                      */
/*****************************************************************************/

#include "./path.h"
inherit KHA_ROOM;

create() {

   ::create();
    SetIntShort("el Templo Sagrado de Kha-annu");
    SetIntLong(
"Te encuentras en el Templo Sagrado de Kha-annu. Este es un lugar silencioso "
"y lleno de paz. Frente a ti, hacia el norte, ves el altar del templo lleno "
"Kholiak es el Dios de la Tierra, al que veneran los enanos bondadosos y "
"Hatkzi es el Dios del Agua venerado por los Enanos Oscuros y algunos enanos "
"de los barrancos. En el altar logras reconocer unas escrituras que quiza "
"puedas leer.\n");

    SetIndoors(1);
     AddReadMsg( ({"escrituras","escritura","altar"}),
"Si tu alma se ha separado de tu carne podras rezar en este templo para "
"reencarnarte en el cuerpo que antes poseias. Usa 'rezar a <dios>' si deseas "
"resucitar.\n");

     SetIntBright(70);
     AddDetail("altar",
"Es un gran altar tallado hecho de piedra. El trabajo realizado en los "
"detalles del altar es magnifico digno de un gran artista.\n"
"Logras reconocer unas escrituras en su parte posterior.\n");
     AddDetail( ({"escritura","escrituras"}),
"Son unas escrituras en el altar, podrias leerlas sin ningun problema.\n");
     AddDetail( ({"ofrenda","ofrendas"}),
"Ves dos tipos de ofrendas junto al altar. Unas son ofrendas de todo tipo "
"de vegetales y frutas, las otras son todas animales muertos, ratas, "
"gallinas e incluso puedes ver la cabeza decapitada de una vaca.\n");
     AddExit("salir",CIUDAD+"kilok7");
}

init() {
    add_action("Rezos","rezar");
    add_action("Rezos","rezar a");
    add_action("NoMatar","matar");
}

NoMatar() {
     write("Una misteriosa fuerza te impide matar a nadie en un lugar "
           "sagrado.\n");
     say(capitalize(getuid(TP))+" intenta levantar su arma, pero "
         "una fuerza misteriosa le impide matar a nadie aqui.\n");
     return 1;
}

Rezos(string str) {
return 1;
}


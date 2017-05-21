/*****************************************************************************************
 ARCHIVO:       bosque32.c
 AUTOR:         Ztico
 FECHA:         16-03-2005
 DESCRIPCIÓN:   Bosque Central de Faeria.
 COMENTARIOS:   17-03-2005 Añadir un unicornio, que aparezca sólo si eres de alineamiento
                           bueno, en el caso de que haya más de un player de alineamiento
                           malo no aparecerá, y si el player "amigo" está sólo y se lo
                           carga, será enemigo para siempre del bosque.
*****************************************************************************************/

#include "./path.h"

inherit HAB_VALMAR("hab_bosque.c");

create()
{
    if(::create()) return 1;

    SetIntShort("la orilla de un río");
    SetIntLong("En esta zona la vegetación abre paso al caudaloso río Ellidan, el cual "
        "nace de un lago situado en las montañas Cileryd, y separa el bosque en el "
        "que te encuentras del de las Dríadas. El lugar es ideal si necesitas aliviar "
        "tu fatiga, y si tienes paciencia quizás puedas contemplar a alguna criatura "
        "extraña que se acerque a saciar su sed.\n");    
    SetIndoors(0);
    AddExit("sur", HAB_BOSQUE_CENTRAL("bosque27.c"));
    AddExit("este", HAB_BOSQUE_CENTRAL("bosque33.c"));
    
    AddItem(PNJ_VALMAR("unicornio_zolnor.c"), REFRESH_DESTRUCT, 1);
}

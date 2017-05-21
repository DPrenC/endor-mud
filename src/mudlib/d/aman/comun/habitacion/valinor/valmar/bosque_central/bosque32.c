/*****************************************************************************************
 ARCHIVO:       bosque32.c
 AUTOR:         Ztico
 FECHA:         16-03-2005
 DESCRIPCI�N:   Bosque Central de Faeria.
 COMENTARIOS:   17-03-2005 A�adir un unicornio, que aparezca s�lo si eres de alineamiento
                           bueno, en el caso de que haya m�s de un player de alineamiento
                           malo no aparecer�, y si el player "amigo" est� s�lo y se lo
                           carga, ser� enemigo para siempre del bosque.
*****************************************************************************************/

#include "./path.h"

inherit HAB_VALMAR("hab_bosque.c");

create()
{
    if(::create()) return 1;

    SetIntShort("la orilla de un r�o");
    SetIntLong("En esta zona la vegetaci�n abre paso al caudaloso r�o Ellidan, el cual "
        "nace de un lago situado en las monta�as Cileryd, y separa el bosque en el "
        "que te encuentras del de las Dr�adas. El lugar es ideal si necesitas aliviar "
        "tu fatiga, y si tienes paciencia quiz�s puedas contemplar a alguna criatura "
        "extra�a que se acerque a saciar su sed.\n");    
    SetIndoors(0);
    AddExit("sur", HAB_BOSQUE_CENTRAL("bosque27.c"));
    AddExit("este", HAB_BOSQUE_CENTRAL("bosque33.c"));
    
    AddItem(PNJ_VALMAR("unicornio_zolnor.c"), REFRESH_DESTRUCT, 1);
}

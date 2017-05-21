/****************************************************************************
Fichero: Thualin_07.c
Autor: Riberales
Creaci�n: 02/10/2005
Descripci�n: Un tramo de la calle Thualin, donde se dejan las armas y
armaduras usadas.
****************************************************************************/

#include <moving.h>
#include "./path.h"
inherit HAB_THUALIN_ANNUFAM("thualin_base");
int ir_oeste();
int ir_sur();



public void create()
{
    ::create();

    SetIntShort("un porche en la calle Thualin");
    SetIntLong(W("Has llegado a un punto en la calle Thualin donde hay un "
                 "techado que cubre parte de la misma. Al oeste puedes ver "
                 "una puerta cerrada con un cartel. Al sur se encuentra otra "
                 "puerta en la pared trasera de la herrer�a, y al este "
                 "contin�a la calle Thualin.\n"));


    AddLuzAntorchas();
    AddSuelo();
    AddDetail(({"techado","techo","arriba","porche"}),
              W("Es un techo met�lico que cubre esta parte de la calle. Est� "
                "enganchado al sur con la pared de la herrer�a, al norte con "
                "la del Centro y al oeste con un peque�o cuarto.\n"));


    AddDetail("cartel",
            W("Es un cartel al lado de la puerta que da acceso al local del "
              "oeste. Ser�a bueno que lo leyeras.\n"));


    AddDetail(({"local","oeste","almacen","almac�n","cuarto"}),
              W("Es la fachada de una especie de almac�n. Al lado de la "
                "puerta hay un cartel.\n"));


    AddReadMsg("cartel",
            W("Almac�n de reciclaje.\n\nAqu� podr�s depositar las armas y "
              "armaduras que ya no sean de utilidad y la herrer�a las fundir� "
              "para nuevas armas y protecciones. Gracias de antemano por las "
              "aportaciones.\n"));


    AddDetail("puerta","Es una puerta normal y corriente.\n");


    AddExit("este",HAB_THUALIN_ANNUFAM("thualin_06"));
    AddExit("oeste",SF(ir_oeste));
    AddExit("sur",SF(ir_sur));
}

int ir_sur()
{
    return notify_fail("La puerta no se puede abrir por aqu�.\n",
           NOTIFY_NOT_VALID);
}


int ir_oeste()
{
    return notify_fail("la puerta est� cerrada con llave.\n",
           NOTIFY_NOT_VALID);
}


void coger_arma(object arma)
{
    string mensaje;
    if (!arma || !present(arma)) return;
    tell_room(TO,W("Se abre la puerta del almac�n y un corpulento enano sale "
                   "de �l. Al instante se agacha y recoge " +
                   (arma->QueryShort() || "algo") + " del suelo.\n"));
    if (TP && present(TP))
    // el player est� conectado y adem�s, est� a�n en la habitaci�n.
    {
        write(W("El enano te sonr�e mientras te dice: '�Gracias " +
                CAP(TNAME) + "! menos mal que a�n queda gente que nos trae "
                "material para reutilizar...'\n"));
        say(W("El enano sonr�e a " + CAP(TNAME) + " y le agradece la "
              "aportaci�n.\n"),TP);
    }

    tell_room(TO,W("El enano vuelve a entrar en el almac�n y cierra la "
                   "puerta tras de s�.\n"));
    arma->remove();
}

public void notify_enter(mixed from, int method, mixed extra)
{
    object cosa = PO;
    ::notify_enter(from, method, extra);
    if (method == M_DROP && (   cosa->QueryWeaponType()
                             || cosa->QueryArmourType()
                             || cosa->QueryWeaponSpecial()))
    {
        call_out("coger_arma",1,cosa);
    }
}

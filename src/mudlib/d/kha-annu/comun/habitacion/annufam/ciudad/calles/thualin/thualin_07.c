/****************************************************************************
Fichero: Thualin_07.c
Autor: Riberales
Creación: 02/10/2005
Descripción: Un tramo de la calle Thualin, donde se dejan las armas y
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
                 "puerta en la pared trasera de la herrería, y al este "
                 "continúa la calle Thualin.\n"));


    AddLuzAntorchas();
    AddSuelo();
    AddDetail(({"techado","techo","arriba","porche"}),
              W("Es un techo metálico que cubre esta parte de la calle. Está "
                "enganchado al sur con la pared de la herrería, al norte con "
                "la del Centro y al oeste con un pequeño cuarto.\n"));


    AddDetail("cartel",
            W("Es un cartel al lado de la puerta que da acceso al local del "
              "oeste. Sería bueno que lo leyeras.\n"));


    AddDetail(({"local","oeste","almacen","almacén","cuarto"}),
              W("Es la fachada de una especie de almacén. Al lado de la "
                "puerta hay un cartel.\n"));


    AddReadMsg("cartel",
            W("Almacén de reciclaje.\n\nAquí podrás depositar las armas y "
              "armaduras que ya no sean de utilidad y la herrería las fundirá "
              "para nuevas armas y protecciones. Gracias de antemano por las "
              "aportaciones.\n"));


    AddDetail("puerta","Es una puerta normal y corriente.\n");


    AddExit("este",HAB_THUALIN_ANNUFAM("thualin_06"));
    AddExit("oeste",SF(ir_oeste));
    AddExit("sur",SF(ir_sur));
}

int ir_sur()
{
    return notify_fail("La puerta no se puede abrir por aquí.\n",
           NOTIFY_NOT_VALID);
}


int ir_oeste()
{
    return notify_fail("la puerta está cerrada con llave.\n",
           NOTIFY_NOT_VALID);
}


void coger_arma(object arma)
{
    string mensaje;
    if (!arma || !present(arma)) return;
    tell_room(TO,W("Se abre la puerta del almacén y un corpulento enano sale "
                   "de él. Al instante se agacha y recoge " +
                   (arma->QueryShort() || "algo") + " del suelo.\n"));
    if (TP && present(TP))
    // el player está conectado y además, está aún en la habitación.
    {
        write(W("El enano te sonríe mientras te dice: '¡Gracias " +
                CAP(TNAME) + "! menos mal que aún queda gente que nos trae "
                "material para reutilizar...'\n"));
        say(W("El enano sonríe a " + CAP(TNAME) + " y le agradece la "
              "aportación.\n"),TP);
    }

    tell_room(TO,W("El enano vuelve a entrar en el almacén y cierra la "
                   "puerta tras de sí.\n"));
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

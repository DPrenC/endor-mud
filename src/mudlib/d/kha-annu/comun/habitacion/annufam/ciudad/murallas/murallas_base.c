/****************************************************************************
Fichero: murallas_base.c
Autor: Chichindril
Creaci�n: 7/10/2005
Descripci�n: base, En lo alto de las murallas, en Annufam.
[t] 22/02/2009: Arreglo el SetIntShor, combin�ncolo con SetPreIntShort par evitar cosas como "En en las murallas..." o "En por las murallas..."
****************************************************************************/

#include "./path.h"


inherit BASE_CIUDAD_ANNUFAM;
string descripcion_corta();
string descripcion_larga();
string dire1, dire2;

public string SetDirec1(string str)
{
    return dire1 = str;
}

public string SetDirec2(string str)
{
    return dire2 = str;
}


public void create()
{
    ::create();

    descripcion_corta();

    descripcion_larga();


    AddDetail("suelo",
            W("Es todo de piedra, sin ning�n ornamento.\n"));


    AddDetail(({"pared","paredes","muro"}),
              W("Es un muro de roca pulida, y con algo m�s de un metro de "
                "altura, para proteger a los enanos y que a la vez puedan atacar.\n"));



    AddDetail(({"abajo","hacia abajo"}),
              W("Te asomas al peque�o muro y mirando abajo observas el foso "
                "que rodea la ciudad. Al momento empieza a entrarte un ataque "
                "de v�rtigo insoportable y te alejas del borde de la "
                "muralla.\n"));



    SetIndoors(0);
    SetIntSmell("Aqu� el aire es un poco m�s puro.\n");
    //AddItem(HAB_CIUDAD_ANNUFAM("guardia_muralla"),REFRESH_DESTRUCTrandom(4));
}



string descripcion_corta()
{
    string long;
    switch(random(8))
    {
        case 0:
            long = "las murallas de Annufam";
            break;
        case 1:
            long = "las murallas de Annufam";
            break;
        case 2:
            long = "las murallas de Annufam";
            break;
        case 3:
			SetPreIntShort("por");
            long = "las murallas de Annufam";
            break;
        case 4:
			SetPreIntShort("paseando por");
            long = "las murallas de Annufam";
            break;
        case 5:
            long = "las murallas de la ciudad de Annufam";
            break;
        case 6:
			SetPreIntShort("por");
            long = "las murallas de la ciudad de Annufam";
            break;
        case 7:
            long = "las murallas de la ciudad de Annufam";
            break;
    }
    SetIntShort(long);

	return long;
}


string descripcion_larga()
{
    string long;
    switch(random(7))
    {
        case 0:
            long="Te encuentras sobre las murallas de la ciudad enana de "
                 "Annufam. Aqu� es donde se encuentran los vig�as, los "
                 "arqueros, y alguna patrulla, para alertar a la ciudad en "
                 "caso de intento de invasi�n.\n";
            break;
        case 1:
            long="Caminas por las murallas de la ciudad-cuartel enana de "
                 "Annufam. A menudo observas enanos mirando hacia lo que "
                 "parece el infinito, en busca de cualquier indicio de "
                 "movimiento orco. La muralla sigue hacia el "+ dire1 +" y "
                 "hacia el "+ dire2 + ".\n";
            break;
        case 2:
            long="Sigues caminando sobre las murallas de Annufam. Un peque�o "
                 "muro de algo m�s de un metro te salva de los "
                 "aproximadamente diez que te separan de tierra firme, por no "
                 "contar el foso. La muralla sigue de "+ dire1 +" a "+ dire2+
                 ".\n";
            break;
        case 3:
            long="Paseas sobre la parte m�s elevada de la ciudad de Annufam, "
                 "sus murallas. Desde aqu� divisas gran parte del dominio "
                 "enano, y algunas laderas m�s all�. A�n as�, no crees que "
                 "este sitio sea un mirador, aunque en parte, los enanos que "
                 "est�n aqu� pasan todo el d�a haciendo eso, mirar por si hay "
                 "alguna irregularidad.\n";
            break;
        case 4:
            long="Est�s sobre las murallas de Annufam, ciudad-cuartel creada "
                 "para el adiestramiento del ej�rcito enano. Por aqu� "
                 "observas diferentes enanos con diversas funciones, todas "
                 "ellas para preservar a Annufam y a Kha-annu de los ataques "
                 "enemigos.\n";
            break;
        case 5:
            long="Caminas por las murallas enanas de Annufam. Notas el calor "
                 "que desprende el suelo, al estar todo el d�a bajo la "
                 "influencia solar. Aqu� los enanos que les toca hacer "
                 "guardia durante el d�a tienen que pasarlo bastante mal. La "
                 "muralla contin�a al "+ dire1 +" y al "+ dire2 +".\n";
            break;
        case 6:
            long="Te encuentras en la muralla que rodea la ciudad de Annufam, "
                 "creada por el rey Belthain con el fin de instruir a los "
                 "enanos en el arte de la guerra, y que estuviesen preparados "
                 "para alg�n posible ataque. Las mismas discurren al "+ dire1+
                 " y al "+ dire2 +".\n";
              break;

    }
    SetIntLong(W(long));

	return long;
}


public void notify_enter(mixed from, int method, mixed extra)
{
    ::notify_enter(from,method,extra);
    object soldado;

    if ((soldado = present("soldado_murallas")) && living(soldado) &&
        member(RAZASENEMIGAS,PO->QueryRace()) >= 0)
    {
        tell_object(PO, "Eh, t�, "+ PO->QueryRace()+ ", qu� haces aqu�?\n");
        tell_room(TO,"El guardia se enfrenta con "+ PO->QueryRealName()+ ".\n",
                  ({PO}));
        soldado->Kill(PO);
    }
}

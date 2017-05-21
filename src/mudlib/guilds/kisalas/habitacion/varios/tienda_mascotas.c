/*=======================================================================*
 |                  <<   Gremio de las Kisalas   >>                      |
 *=======================================================================*
 | [w] Woo@simauria                                                      |
 | [a] Avengelyne@simauria                                               |
 |                                                                       |
 | 05-03-99 [w] Esta será la tienda en donde las amazonas podrán comprar |
 |              sus mascotas.                                            |
 | 09-03-99 [w] Ahora hace que la amazona llame a su mascota.            |
 | 23-03-99 [w] Cambiado el present del brazalete.                       |
 | 24-03-99 [w] El cartel ahora lee los valores del mapping directamente.|
 *=======================================================================*/

#include "./path.h"
#include <guild.h>
#include <properties.h>
#include <door.h>
#include <sounds.h>
#include <scheduler.h>
#include <keeper.h>
#define MITHRIL        MONEY_DEMON->QueryCoinValue("mithril")
#define MC_ARTICLE     0
#define MC_VALUE       1
#define MC_GENDER      2
#define MC_DESCRIPTION 3
inherit SCHEDULER_ROOM;
inherit KEEPER;


mapping mascotas;
string *nombres_masc;
string *nombres_fem;
void CargarTienda();
int DarMascota(string mascota);

public string ListarMascotas()
{
    string lista;
    mixed indices;
    int num_ind,i;

    if (!mascotas || !num_ind=sizeof(mascotas))
    {
        say(KeeperName(K_CAP) + " le dice algo a " + CAP(TNAME) + ".\n");
        return KeeperName(K_CAP) + " te dice: No mires el cartel, ahora no "
                          "tengo ninguna mascota.\n";
    }

    indices=m_indices(mascotas);
    // si el player es ciego, no se le muestra la lista esa con dibujitos.
    lista=(!TP->QueryTiflo() ? read_file(AM_VARIOS("mascotas.txt")) :
                               "Lista de mascotas: \n");

    for (i=num_ind;i--;)
        lista += "      "+STR->ladjust(mascotas[indices[i],3],33,".")+
                 STR->radjust(""+mascotas[indices[i],1]+"",4,".")+" monedas de Mithril\n";

    return lista+"\n";
}

create()
{
    "*"::create();
    SetIntShort("la tienda de mascotas");
    SetIntLong("Te encuentras en la tienda de adopción de mascotas para las "
               "Kisalas. Aquí podrás adoptar un animal por un módico precio "
               "que puedes ver en el cartel colgado de la puerta. Hacia el "
               "Sur, ves la única salida de la tienda, que te lleva a uno de "
               "los pasillos del gremio.\n");
    SetIntNoise("No escuchas nada, aparte del silencio.\n");
    SetIntSmell("Percibes el inconfundible olor de la magia.\n");
    SetLocate("el gremio de las Kisalas");
    SetIndoors (1);
    SetIntBright(45);
    AddDetail (({"espirales","luz","espiral"}),"Ves unas espirales fosforescentes, que dan "
        "luminosidad al lugar.\nLas espirales son uno de los sistemas mas antiguos empleados por los "
        "elfos para iluminar las habitaciones. Están hechas con algún derivado del fósforo, "
        "aunque hay quien asegura que lo que en verdad las ilumina es la presencia de algún "
        "tipo de magia.\n");
    AddDetail (({"sello","simbolo","símbolo","sellos","simbolos","símbolos"}),"Ves el símbolo de "
        "las Kisalas, consiste en una S y una K entrelazadas situadas en el centro de una "
        "espiral.\n");
    AddDetail("cartel",SF(ListarMascotas));
    AddReadMsg("cartel",SF(ListarMascotas));
    SetKeeper(AM_PNJ("reisi"));
    CargarTienda();
    SetCloseTime(S_CLOSED_AT_NIGHT);
    SetLastDest(AM_PASILLO("pasillo1"));
    SetNotifyExits(({"sur"}));
    AddExit("sur", AM_PASILLO("pasillo1"));
    AddDoor("sur", "la puerta del pasillo",
        "Es la puerta que da al pasillo. Está hecha de madera con un panel de cristal en la "
            "parte superior.\n",
        ({"puerta","puerta del pasillo","puerta sur"}),GENERO_FEMENINO,
        ([P_DOOR_CLOSE_SOUND: SND_SUCESOS("abrir_puerta_campanillas"),
        P_DOOR_OPEN_SOUND: SND_SUCESOS("abrir_puerta_campanillas"),
        P_DOOR_TRANSPARENCY:1,P_DOOR_CLOSE_TIME:S_CLOSED_AT_NIGHT]));
    AddRoomCmd("adoptar","cmd_adoptar");
}

// Nombre y valor en monedas de mithril.
void CargarTienda() // [Nyh] Void para evitar el warning del no return
{
  mascotas=([
            "halcon":     "un";   20;GENERO_MASCULINO;"Un precioso halcón",
            "cocodrilo":  "un";   25;GENERO_MASCULINO;"Un peligroso cocodrilo",
            "tigre":      "un";   22;GENERO_MASCULINO;"Un feroz tigre",
            "panda":      "un";   23;GENERO_MASCULINO;"Un bonito panda"
          ]);
  nombres_masc=({"kiur","fergo","ditty","monga","reidal","pomo","botaw",
                "sighu","ornao"});
  nombres_fem=({"duga","elsa","ivia","ingra"});
}

private string NombreMascota(string mascota)
{
    if (mascotas[mascota,MC_GENDER] == GENERO_FEMENINO)
    {
        return nombres_fem[random(sizeof(nombres_fem))];
    }
    return nombres_masc[random(sizeof(nombres_masc))];
}

int DarMascota(string mascota)
{
    object animal,brazalete;
    int result;

    if (!brazalete=present("brazalete del gremio de kisalas",TP))
    {
        return notify_fail(KeeperName(K_CAP) + " te dice: No tienes el "
                           "brazalete que te identifica como miembro del gremio.\n");
    }
    if (brazalete->QueryObjectOwner()!=TP)
    {
        return notify_fail(KeeperName(K_CAP) + " te dice: ¿A quien le has "
                           "robado el brazalete?\n");
    }
    if (brazalete->QueryMascotaNombre() && brazalete->QueryMascotaNombre() != "")
    {
        return notify_fail(KeeperName(K_CAP) + " te dice: No se permiten tener "
                           "dos mascotas a la vez.\n");
    }
    if (!result = Pay(TP, (mascotas[mascota, MC_VALUE]* MITHRIL), "por la adopción de una "
        "mascota"))
    {
        return notify_fail(KeeperName(K_CAP) + " te dice: Lo siento " +
                           CAP(TNAME) + ", pero no tienes los " +
                           mascotas[mascota, MC_VALUE] + " mithriles que "
                           "cuesta adoptar " + mascotas[mascota, MC_ARTICLE] +
                           mascota + ".\n");
    }
    if (!animal=clone_object(MASCOTA))
    {
        return notify_fail(KeeperName(K_CAP) + " te dice: Hay un problema con "
                           "la mascota. Por favor, contacta con un wizard y "
                           "explícale lo que pasa.\n");
    }

    animal->SetStandard(NombreMascota(mascota),mascota,1,mascotas[mascota,2]);
    animal->SetXP(0);
    brazalete->SetMascotaNombre(animal->QueryName());
    brazalete->SetMascotaSexo(animal->QueryGender());
    brazalete->SetMascotaRaza(animal->QueryRace());
    brazalete->SetMascotaHP(animal->QueryHP());
    brazalete->SetMascotaSP(animal->QuerySP());
    brazalete->SetMascotaXP(0);
    brazalete->SetMascotaSed(animal->QueryDrink());
    brazalete->SetMascotaHambre(animal->QueryFood());
    brazalete->SetMascotaAlcohol(animal->QueryAlcohol());
    brazalete->SetMascotaNombre(animal->QueryName());
    brazalete->SetMascotaNivel(1);
    brazalete->SetMascotaEdad(0);
    brazalete->SetMascotaModo(0);
    animal->remove();
    brazalete->LlamarMascota(1);
    return 1;
}

public int cmd_adoptar(string str)
{
    // si el player no puede ser atendido...
    if (CantAttend(K_NOTIFY)) return 0;
    if (TP->QueryGuild()!=GC_KISALAS)
    {
        return notify_fail(KeeperName(K_CAP) + " te dice: No eres una "
                           "kisala.. vete de aquí.\n");
    }

    if (!str)
    {
        return notify_fail(KeeperName(K_CAP) + " te dice: ¿Qué animal quieres "
                           "adoptar?\n");
  }
    if(str=="halcón") str="halcon";
    if (!member(mascotas,str))
    {
        return notify_fail(KeeperName(K_CAP) + " te dice: No vendemos ese "
                           "tipo de animal aquí.\n");
   }
    return DarMascota(str);
}


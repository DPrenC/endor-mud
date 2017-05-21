/*
DESCRIPCION : herboristeria de Messur
FICHERO     : /d/akallab/comun/habitacion/akallab/zarkam/tienda/herboristeria.c
MODIFICACION: 16-11-98 [Angor@Simauria] Creacion
              28-10-99 [Angor@Simauria] quest
              10-02-00 [Angor@Simauria] wrap
*/
#include "./path.h"
#include AK_MACRO
#include <properties.h>
#include <materials.h>
#include <door.h>
#include <sounds.h>
#include <scheduler.h>
#include <wizlevels.h>
inherit SHOP;

create()
{
    ::create();
    SetIntShort("la herborister�a de Messur");
    SetIntLong("Un denso olor a hierbas, especialmente a incienso, inunda el ambiente en esta "
        "herborister�a. Este peque�o local est� lleno de estanter�as en las que observas "
        "innumerables frascos y cajas con todo tipo de hierbas, hojas o tub�rculos. Bajo una "
        "peque�a chimenea al fondo de la habitaci�n, una marmita cuece a fuego lento.\n");
    AddDetail(({"estanter�as","estanterias"}),"La herborister�a est� repleta de estanter�as. "
        "En ellas puedes ver innumerables frascos de cristal y cajas que contienen todo tipo de "
        "hierbas. Crees reconocer algunas de ellas pero de otras muchas no tienes idea de "
        "d�nde han venido o qu� efectos pueden provocar. Observas tambi�n algunos peque�os "
        "frascos con pociones ya preparadas por Messur.\n");
    AddDetail(({"cajas"}),"Messur emplea algunas peque�as cajas para guardar ciertos "
        "componentes ya secos como hojas o cortezas de �rbol.\n");
    AddDetail(({"frascos"}),"Las estanter�as est�n llenas de ellos. En estos recipientes de "
        "cristal es donde Messur suele guardar hierbas, hojas y otros muchos de los "
        "componentes que se venden aqu� en la herborister�a. Tiene unos frascos mas peque�os "
        "con pociones ya preparadas y listas para vender. Te llama la atenci�n que en ninguno "
        "de los frascos hay etiqueta alguna.\n");
    AddDetail(({"marmita"}),"La marmita es una especie de peque�o caldero de metal colgado "
        "sobre el fuego en la chimenea en la que prepara Messur sus pociones. En este momento "
        "se est� cociendo algo en ella a fuego lento.\n");
    AddDetail(({"chimenea"}),"Al fondo de la habitaci�n hay una peque�a chimenea donde Messur "
        "prepara algunas de sus pociones.\n");
    SetIntNoise("Oyes el hervor de la marmita.\n");
    SetIntSmell("Hay un denso olor a hierbas, especialmente a incienso.\n");
    SetLocate("ciudad de Zarkam");
    SetIndoors(1);
    SetIntBright(50);
    CanSell(1);     //El cliente si puede vender a la tienda
    CanAppraise(0); //No se valoran objetos
    CanIdentify(0); //No se identifican objetos
    RemoveDustbin();
    SetShopkeeper(PNJ_Z_CIUDAD("darkam"));
    SetLastDest(Z_CIUDAD("calle_14"));
    SetNotifyExits("norte");
    SetInformCloseMsg("Messur dice: Vale, Darkam, cierra esos botes, ya es hora de cerrar.\n");
    SetThrowOutMsg("Messur mira a su alrededor y dice: Est� bien, v�monos. Y con un gesto de "
        "impaciencia, te invita a salir.\n");
    SetNotifyCloseMsg("Messur sale de la herborister�a repasando entre dientes las cuentas del "
        "d�a, y se aleja hacia la plaza. A los pocos segundos, sale Darkam, cierra la puerta, "
        "y saludando con un gesto de la mano, se va calle abajo.\n");
    SetNotifyOpenMsg("Messur llega examinando atentamente un pu�ado de hierbas que sabe Dios "
        "d�nde ha conseguido. Junto a �l viene Darkam, con las llaves tintineando en la garra, "
        "abre la puerta y ambos entran en la herborister�a.\n");
    AddExit("norte",Z_CIUDAD("calle_14"));
    AddDoor("norte","la puerta de la herborister�a",
        "Es una gruesa puerta de madera labrada, fuerte y resistente.\n",
        ({"puerta","puerta de herboristeria","puerta de herborister�a",
            "puerta de la herboristeria","puerta de la herborister�a"}),GENDER_FEMALE,
        ([P_MATERIAL:M_MADERA, P_DOOR_OPEN_SOUND:SND_SUCESOS("abrir_puerta_campanillas"),
            P_DOOR_CLOSE_SOUND:SND_SUCESOS("abrir_puerta_campanillas"),
            P_DOOR_CANT_OPEN_MSG:({({"Intentas abrir la puerta, y al no poder, la miras y ves "
                "un cartel:\n'Cerrado toda la noche.'\n","Tratas de abrir la puerta en "
                "la oscuridad, pero no logras encontrar la manija.\n"}),({"@nombre@ trata de "
                "entrar en la herborister�a, pero se da cuenta de que cierra durante la noche.\n",
                "Oyes a alguien removerse, jurando en la oscuridad.\n"}),
                "Parece que alguien trata de abrir la puerta.\n"}),
                P_DOOR_CLOSE_TIME : S_CLOSED_AT_NIGHT]));
    AddArticle(HERBS("hierba_saciante"), REFRESH_REMOVE, 1);
    AddArticle(HERBS("hierba_magica"), REFRESH_REMOVE, 1);
    AddArticle(HERBS("hierba_curativa"), REFRESH_REMOVE, 1);
    AddArticle(HERBS("hierba_narcotica"), REFRESH_REMOVE, 1);
    AddArticle(HERBS("hierba_intoxicante"), REFRESH_REMOVE, 1);
    AddArticle(HERBS("seta_saciante"), REFRESH_REMOVE, 1);
    AddArticle(HERBS("seta_magica"), REFRESH_REMOVE, 1);
    AddArticle(HERBS("seta_curativa"), REFRESH_REMOVE, 1);
    AddArticle(HERBS("seta_narcotica"), REFRESH_REMOVE, 1);
    AddArticle(HERBS("seta_intoxicante"), REFRESH_REMOVE, 1);
    AddRoomCmd("coger", "coger_cmd");
    AddItem(QUEST+"amuleto/messur",REFRESH_DESTRUCT,1);
}

init()
{
    ::init();
    if (IS_LEARNER(TP) && TP->QueryInvis()) return;
    SkSay("Hola "+NOMBRE+", bienvenid"+AO+" a mi tienda.\n");
}

int coger_cmd(string str){
 if ((!str)||((str!="frascos")&&(str!="cajas"))) return 0;
 write(
  "Te lo piensas un momento y decides que mejor sera no coger nada, no vaya a ser "
   "desconociendo los productos que hay aqui te lleves un veneno en lugar de una "
   "medicina.\n");
 return 1;
}

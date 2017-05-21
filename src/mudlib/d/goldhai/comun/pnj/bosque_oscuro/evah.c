/*=============================================================*
 |            << GOLDHAI.Crowy [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 08-10-98                |
 |               Ultima Modificacion.. 02-05-00                |
 |                                     19-02-02 [k] Karu       |
 |          [k]  Añado questions para el quest del sobrino     |
 |               de Leyma                                      |
 |                                                             |
 *=============================================================*/

#include "./path.h"
#include <living.h>
#include <money.h>
#include <properties.h>
inherit NPC;
int regeneracion;
#define price 700000

string preguntar_pluma()
{
    if (MONEY_LIB->QuerySomeonesValue(TP)<price)
    {
        return "Evah la curandera te dice: No tienes suficiente dinero. Esa "
      	       "información es bastante especial y deberás pagarme "+
    	       MONEY_DEMON->QueryValueString(price)+".\n";
    }
    return MONEY_LIB->PayValueString(TP, price, 0, "por la información") +
           "Evah parece ponerse en trance... Poco después despierta, te mira "
    	   "y dice: Vaya, que fastidio, no he podido ver las plumas. Parece "
    	   "que algo me lo impide. Realmente son objetos mágicos. Bueno, "
    	   "al menos he podido ver varios de sus lugares de anidamiento. "
    	   "Así que necesitas tres, ¿no? Pues veamos.\n"
    	   "Uno de ellos está en un bosque, hacia el este. Un bosque "
 	       "bonito, muy bonito, digno de un elfo. Quizás esté en "
 	       "Tiinkdhil, aunque también es posible que esté en Atbalnin. Nunca "
 	       "he viajado hasta allí.\n"
 	       "Otra parece estar cerca, seguramente aquí mismo, en Goldhai, en "
 	       "un lugar azotado por el viento, quizás en un precipicio.\n"
 	       "De la tercera pluma no he podido ver prácticamente nada, todo "
 	       "estaba oscuro y era maloliente. Es curioso, me ha parecido ver "
 	       "una montaña de huesos junto a niños de alguna especie "
 	       "desagradable y apestosa, posiblemente de orcos o de trolls. Estos "
 	       "agradables seres suelen vivir en Akallab, así que allí debe "
    	   "estar la tercera.\n"
    	   "No, no me des las gracias, y ahora déjame, estoy fatigada.\n";

}

create()
{
    ::create();
    SetStandard("Evah", "gnomo", 20, GENERO_FEMENINO);
    AddId(({"evah","Evah","curandera","Evah la curandera","evah la curandera", "gnoma"}));
    SetShort("Evah, la curandera");
    SetLong("Evah es una pequeña gnomo vestida de forma bastante estrafalaria.\n");
    regeneracion = 3;
    SetAlign(200);
    AddQuestion(({"pluma", "plumas", "pluma de wyvelt", "plumas de wyvelt"}),
             SF(preguntar_pluma),1);
    AddQuestion(({"ingrediente","ingredientes","lista", "cura", "receta", "papilla",
        "remedio"}),
	    "La curandera te dice: veamos a ver que se me ocurre para curar a ese niño...\n"
	    "Lo necesario para hacer una papilla que cure a ese niño podría ser: \n "
	    "Un frasco lleno de agua medicinal, un caldero con propiedades, un lenguarón y musgo.\n",1);
    AddQuestion(({"frasco","frascos","agua","frasco de agua","frascos de agua"}),
	    "La curandera dice: Has de conseguir agua del río Darmaii, ya que su agua es "
	    "calmante.\n",1);
    AddQuestion(({"caldero","calderos"}), "La curandera dice: Tienes que conseguir "
        "un caldero con propiedades especiales, puedes conseguir uno en el sagrado"
        " templo que custodia Arandil.\n",1);
    AddQuestion(({"bichito","bicho","lenguaron","lenguarón"}),
	    "La curandera dice: Es una especie de ardilla, y muy escurridizo. Te tendrás "
	    "que hacer con algún tipo de trampa si quieres atrapar uno.\n",1);
    AddQuestion(({"trampa","trampas","cuerda"}),
	    "La curandera dice: Para poder atrapar al lenguarón tendrás que hacerte con un "
	    "cable o algo similar que usen los cazadores para esas actividades.\n",1);
    AddQuestion(({"especias","especia","musgo","musgos"}),
	    "La curandera dice: En las copas de los árboles de Kenton suelen hallarse buenas "
	    "especias COMO LAS QUE PRECISAS.\n",1);
    AddQuestion(({"cocinar","comida", "cocinero"}),
	    "La curandera dice: puedes ir a buscar a un tal Nattan, es un buen cocinero, "
	    "creo que estaba trabajando por Marhalt.\n",1);
    AddQuestion(({"Nattan","nattan"}),
        "La curandera dice: busca, busca, no te lo voy a decir yo todo.\n",1);
}

private status existe_jugador(string jugador) {
    return find_savefile(jugador)||find_object(lower_case(jugador));
}

private int IsGuardian(object mon) { return (mon->QueryGuardian())?1:0;}

public varargs int DoDamage (int dmg, int type, int gentle, mixed xtras) { // Si le atacan busca a los guardias para que le defiendan.
    int i;
    object *guardias,proteccion;

    guardias = filter(deep_inventory(environment(TO)),SF(IsGuardian));

    if(sizeof(guardias))
    for(i=0;i<sizeof(guardias);i++)
    guardias[i]->Kill(TP || PO);

    return ::DoDamage( dmg,  type,  gentle,  xtras);
}

public varargs void Die(mixed silent) {
    if (regeneracion == 0) return ::Die(silent);

    say("Evah saca una pequeña pócima y se la traga...\n\
    Ves un extraño brillo que aparece en sus pupilas, de pronto las heridas,\n\
    poco a poco, comienzan a cicatrizarse y a cerrarse ante tus ojos.\n");
    SetHP(QueryMaxHP());
    regeneracion--;
}

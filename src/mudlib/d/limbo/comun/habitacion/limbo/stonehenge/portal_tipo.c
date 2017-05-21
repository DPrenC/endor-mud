/*
DESCRIPCION  : Portal 'tipo' para una raza en Stonehenge.
10/11/2004 kastwey@simauria: Cambiado el M_SILENT por M_SPECIAL para que no se pueda seguir al player
*/

#include "./path.h"
#include <wizlevels.h>
#include <moving.h>
#include <messages.h>


#define NEWBIELEVEL 4      //cambio del home del newbie
#define AO TP->QueryGenderEndString()


inherit ROOM;

public string destino;     //path destino del teletransporte del portal
public string raza;        //nombre de la raza del portal
public string newbiehome;  //path del home del newbie por defecto
public string muro;        //interior o exterior

int portal()
{
    string msg_wizard;
    if (query_wiz_level(TP))
    {
        msg_wizard = "Acercas tu mano hacia el portal y tratas de cruzarlo. Una luz "
                     "cegadora te envuelve y oyes una profunda voz en tu cabeza: 'Dada tu "
                     "condición de wizard, se te permite usar el portal sin "
                     "importar cual sea tu raza'. Cuando recuperas la visión, te das "
                     "cuenta de que te encuentras en otro lugar.\n";
    }

    else if (TP->QueryRace()!=raza)
    {
        write("Avanzas hacia el portal, pero cuando estás a punto de cruzarlo, pierdes "
              "por un momento la visión y un doloroso escalofrío recorre tu cuerpo. Oyes "
              "una voz grave en el interior de tu cabeza que te dice que este no es el "
              "portal de los de tu raza. Cuando recuperas la visión te das cuenta "
              "de que aún estás frente al portal. No has podido cruzarlo.\n");
    tell_room(TO, ({MSG_SEE, TNAME + " trata de atravesar el portal, pero es "
                                        "detenid"+ AO +" por una fuerza invisible. Por un "
                                        "breve instante su cuerpo se agita victima de "
                                        "extrañas convulsiones, para luego volver a la "
                                        "normalidad.\n"}),({TP}));
    return 1;
    }

    TP->move(destino, M_SPECIAL, ({"se acerca al portal. En el momento en "
                                   "el que cruza bajo el arco del mismo, desaparece de "
                                   "repente. Te frotas los ojos para asegurarte de "
                                   "que lo que acabas de ver es cierto",
                                   "aparece de repente, surgid"+AO+" de la nada",
                                   msg_wizard || "Avanzas hacia el portal y cuando estás a punto de "
                                   "cruzarlo te deslumbra un gran resplandor. Poco a poco "
                                   "vas recuperando la visión y te das cuenta de que "
                                   "todo a cambiado a tu alrededor. Parece como si hubieses "
                                   "sido teletransportad"+AO+ " a algún otro lugar distinto "
                                   "de la isla Limbo. Piensas que probablemente ahora estés "
                                   "en algún lugar del territorio en el que habitan los de "
                                   "tu raza"}));



    if (   !query_wiz_level(TP) && TP->QueryLevel() >= NEWBIELEVEL
        && TP->QueryHome() == newbiehome)
    {
        write("Los dioses de Simauria han decidido que ya tienes suficiente experiencia, por "
              "lo que tu periodo de aprendizaje en la isla Limbo ha acabado. Pese a que "
              "puedes volver a esta isla cuando quieras, se te ha cambiado el lugar en el "
              "que apareces por defecto en el mud (home), a la habitacion que "
              "queda al otro lado de este portal, que se encuentra en el territorio de los de "
              "tu raza.\n");
        TP->SetHome(destino);
    }
    return 1;
}


create() {
  ::create();
  if (!raza) raza="()";
  if (!muro) muro="()";

  SetIntShort("el portal de los "+raza+"s en Stonehenge");
  SetIntLong(
   "Te hallas en el corredor interior entre los dos anillos de piedra de "
     "Stonehenge junto al muro "+muro+" frente a un arco de piedra o portal. "
     "En la losa de piedra que hay en el suelo junto al portal, se halla "
     "tallada la figura de un "+raza+" y la siguiente inscripcion en "
     "lengua comun: 'Portal para los "+capitalize(raza)+"s'.\n");

 AddDetail(({"isla","isla Limbo","Limbo","limbo"}),
  "La isla Limbo es el lugar magico de Simauria donde habitan los dioses. "
    "Gracias a ellos, es en este lugar donde las almas de los seres se "
    "encarnan y dan sus primeros pasos para vivir en este mundo.\n");

 AddDetail(({"Stonehenge","stonehenge","monumento"}),
   "Stonehenge es un monumento de piedra que se encuentra sobre una loma "
     "al oeste de la isla Limbo. El poder de los dioses hace que este lugar "
     "este conectado, de forma inexplicable, a otros muchos lugares a lo "
     "largo y ancho de Simauria.\n");

 AddDetail(({"portal","arco","arco de piedra"}),
   "Frente a ti tienes uno de los portales de Stonehenge. Esta constituido "
     "por tres inmensos bloques de piedra, dos colocados en vertical y el "
     "tercero situado horizontalmente sobre los anteriores. Cuando miras a "
     "traves de el, sucede algo extranyo: el paisaje que ves de la isla "
     "tiembla como cuando se mira una imagen reflejada sobre una superficie "
     "de agua. Tienes la sensacion de que este portal debe ser una especie "
     "de 'puerta' magica a alguna otra parte...\n");

SetIntNoise("Se oye el ruido de las olas en los acantilados del oeste de la isla.\n");
SetIntSmell("El aire es limpio y fresco.\n");
SetLocate("Stonehenge");
SetIndoors(0);
}

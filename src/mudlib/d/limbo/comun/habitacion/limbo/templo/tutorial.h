//macros del tutorial
#define TUTORIAL_DOC(x) "/d/limbo/docs/"+x

#define TUT_STEP_LOOK 0
#define TUT_STEP_INVENTORY 1
#define TUT_STEP_USE_OBJS 2
#define TUT_STEP_MOV 3
#define TUT_STEP_HEALTH 4
#define TUT_STEP_COMBAT 5
#define TUT_STEP_SLEEP 6
#define TUT_STEP_SKILL 7
#define TUT_STEP_COMM 8
#define TUT_STEP_HELP 9

#define TUT_STEP_DONE "Usa 'tutorial' para saber que hacer ahora.\nUsa 'mirar lista' para ver que tareas has hecho y cual te faltan.\n"
#define TUT_STEP_NOT_DONE "Antes de seguir has de demostrarme que has aprendido lo que te he explicado. Usa 'tutorial'.\n"
#define TUT_STEP_FEEDBACK "¡Eso es! Teclea 'tutorial' para saber que es lo siguiente.\n"

//funciones comunes del tutorial
int tutorial_cmd() {
	string tmp, doc;
	int i;
	object ob = present("lista_tutorial",TP);
  if (ob)
  	{
             //write("Tutorial step="+ob->QueryNextStep()+"\n");
             doc=TUTORIAL_DOC("tutorial_"+ob->QueryNextStep()+".txt");
             write( read_file(doc) );
	}else{
	     notify_fail("No estas haciendo el tutorial, no recibes ayuda.\n");
     	     return 0;
	}
  return 1;
}

/*string ok_msg() {
	return "¡Eso es! Teclea 'tutorial' para saber que es lo siguiente.\n";
}*/

	
int do_step(int step, object pl) {
	string a, b, Quests;
	object ob = present("lista_tutorial",pl);
	if (ob) {
		if (ob->QueryStepDone(step)==0) {
			write(TUT_STEP_FEEDBACK);
			//dtell(pl,ok_msg());
			ob->SetStepDone(step);	
			if (ob->QueryStepRemain()==0){
             			write( read_file(TUTORIAL_DOC("tutorial_fin.txt")));
      				Quests=TP->QueryQuests();
              			if (!Quests) Quests="hallo";
              			if (sscanf(Quests,"%sutorial_limb%s",a,b)!=2){
                 			write("\n¡Acabas de resolver el quest del tutorial!\n");
                 			QUESTMASTER->InformSolution(TP->QueryName()+" ha superado el tutorial de la isla Limbo");
                 			QUESTMASTER->SetPlayerQuest("tutorial_limbo",TP);
                 		}
             			ob->remove();
           		}
		}else{	write(TUT_STEP_DONE);}
		}
  return 0;
}

int mirar_cmd() {
    do_step(TUT_STEP_LOOK, TP);
  return 0;
}

int inv_cmd() {
    do_step(TUT_STEP_INVENTORY, TP);
  return 0;
}

int skill_cmd() {
    do_step(TUT_STEP_SKILL, TP);
  return 0;
}

inform_death(){
    object killer=PO->QueryKiller();
    do_step(TUT_STEP_COMBAT, killer);
    return 0;
}
	
int dormir_cmd() {
    do_step(TUT_STEP_SLEEP, TP);
  return 0;
}


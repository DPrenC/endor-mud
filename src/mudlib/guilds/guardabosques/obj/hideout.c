#include <colours.h>
#include <skills.h>
inherit "/obj/hideout";

#define valid_guild_action ({"gestado", "gayuda", "ghab", "ghabilidades"})

int ValidAction(object room, string verb, string args) {
	if (member(valid_guild_action, verb) != -1) {
		return 1;
	}
	return ::ValidAction(room, verb, args);
}

int CheckSkill(object room, int first_time) {
	if (TP->QueryTiredMagic()) {
		write("Estás mentalmente exhausto, no puedes esconderte.\n");
		return 0;
	}
	
	if (first_time || member(room->QueryExits(), query_verb())) {
		if (TP->UseSkill(HAB_ESCONDERSE) < 0) {
			TP->SetTiredMagic(5);
  			if (first_time) {
	  			write(TC_BOLD + "No eres lo suficientemente hábil como para esconderte.\n" + TC_NORMAL);
  			}
  			else {
	  			write(TC_BOLD + "Eres tan torpe que sales de tu escondite.\n" + TC_NORMAL);
  			}
  			return 0;
  		}
  	}
  	if (first_time) {
  		write(TC_BOLD + "Consigues esconderte.\n" + TC_NORMAL);
  	}
  	return 1;
}


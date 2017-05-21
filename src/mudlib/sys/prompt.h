#ifndef __PROMPT_H
#define __PROMPT_H

#define PR_NO_PROMPT 	0
#define PR_STD_PROMPT 	1
#define PR_FANCY_PROMPT 2
#define PR_WIZ_PROMPT	3

#define STR_NO_PROMPT 	    "ninguno"
#define STR_STD_PROMPT	    "estándar"
#define STR_STD_PROMPT2	    "estandar"
#define STR_FANCY_PROMPT    "detalle"
#define STR_WIZ_PROMPT	    "path"

#define REP ([ \
	STR_NO_PROMPT:      PR_NO_PROMPT,   \
	STR_STD_PROMPT:     PR_STD_PROMPT,  \
	STR_STD_PROMPT2:    PR_STD_PROMPT,  \
	STR_FANCY_PROMPT:   PR_FANCY_PROMPT,\
	STR_WIZ_PROMPT:     PR_WIZ_PROMPT   \
	])

#define PR_PROMPTS  ({ PR_NO_PROMPT, PR_STD_PROMPT, PR_FANCY_PROMPT, PR_WIZ_PROMPT })

#define IS_VALID_PROMPT(x) (member(PR_PROMPTS, x) > -1)

#endif /* __PROMPT_H */

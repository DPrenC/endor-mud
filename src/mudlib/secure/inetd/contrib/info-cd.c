#define BANNER "-----------------------------------\n"
	case "info":
	{
    		string info = "\n" + BANNER;
    		info += sprintf(" %-20s : %s\n", "MUD NAME", LOCAL_NAME);
#ifdef HOSTIP
    		info += sprintf(" %-20s : %s\n", "IPNUMBER", HOSTIP);
#endif
#ifdef HOSTNAME
    		info += sprintf(" %-20s : %s\n", "IPNAME", HOSTNAME);
#endif
    		info += sprintf(" %-20s : %d\n", "MUD PORT", 
		    SECURITY->do_debug("mud_port"));
    		info += sprintf(" %-20s : %d\n", "UDP PORT", LOCAL_UDP_PORT);
    		info += sprintf(" %-20s : %s\n", "DRIVER", 
		    SECURITY->do_debug("version"));
		info += sprintf(" %-20s : %s\n",  "MUDLIB", MUDLIB_VERSION);
    		info += sprintf(" %-20s : %s\n", "INETD", INETD_VERSION);
    		info += sprintf(" %-20s : %s\n", "EMAIL", EMAIL);
    		info += BANNER;
		ret = ([ DATA: info ]);
		break;
	}


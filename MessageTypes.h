#ifndef MESSAGE_TYPES
#define MESSAGE_TYPES

#include <string>

enum message_type
{
	Msg_HiHoneyImHome,
	Msg_StewReady,
	Msg_Moron,
	Msg_BobHere
};


inline std::string MsgToStr(int msg)
{
	switch (msg)
	{
	case 0:

		return "HiHoneyImHome";

	case 1:

		return "StewReady";

	case 2:
		return "Moron";

	case 3:
		return "BobHere";

	default:

		return "Not recognized!";
	}
}

#endif
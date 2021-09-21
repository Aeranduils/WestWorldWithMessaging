#include "FlyBarOwnedStates.h"
#include "fsm/State.h"
#include "FlyBar.h"
#include "Locations.h"
#include "messaging/Telegram.h"
#include "MessageDispatcher.h"
#include "MessageTypes.h"
#include "Time/CrudeTimer.h"
#include "EntityNames.h"

#include <iostream>
using std::cout;


#ifdef TEXTOUTPUT
#include <fstream>
extern std::ofstream os;
#define cout os
#endif


//------------------------------------------------------------------------methods for GoToBathroom
GoToBathroom* GoToBathroom::Instance()
{
	static GoToBathroom instance;

	return &instance;
}


void GoToBathroom::Enter(FlyBar* pFlyBar)
{
	//if the FlyBar is not already located at the bathroom, he must
	//change location to the bathroom
	if (pFlyBar->Location() != bathroom)
	{
		cout << "\n" << GetNameOfEntity(pFlyBar->ID()) << ": " << "Walkin' to the bathroom";

		pFlyBar->ChangeLocation(bathroom);
	}
}


void GoToBathroom::Execute(FlyBar* pFlyBar)
{


	cout << "\n" << GetNameOfEntity(pFlyBar->ID()) << ": " << "Peeing. Shhhhhh !";
	pFlyBar->GetFSM()->ChangeState(DrinkAtTheBar::Instance());

}


void GoToBathroom::Exit(FlyBar* pFlyBar)
{
	cout << "\n" << GetNameOfEntity(pFlyBar->ID()) << ": "
		<< "Shit, I'm thirsty, I need a fucking drink !";
}


bool GoToBathroom::OnMessage(FlyBar* pFlyBar, const Telegram& msg)
{
	//send msg to global message handler
	return false;
}

//------------------------------------------------------------------------methods for Insult

Insult* Insult::Instance()
{
	static Insult instance;

	return &instance;
}

void Insult::Enter(FlyBar* pFlyBar)
{

}


void Insult::Execute(FlyBar* pFlyBar)
{

	cout << "\n" << GetNameOfEntity(pFlyBar->ID()) << ": "
		<< "Why is everyone looking at me !? You want to fight ?";
	//let Bob know what i think of him
	Dispatch->DispatchMessage(SEND_MSG_IMMEDIATELY, //time delay
		pFlyBar->ID(),        //ID of sender
		ent_Miner_Bob,            //ID of recipient
		Msg_Moron,   //the message
		NO_ADDITIONAL_INFO);

	pFlyBar->GetFSM()->ChangeState(SleepTilRested::Instance());



}


void Insult::Exit(FlyBar* pFlyBar)
{
	cout << "\n" << GetNameOfEntity(pFlyBar->ID()) << ": " << "Falling asleep";
}


bool Insult::OnMessage(FlyBar* pFlyBar, const Telegram& msg)
{
	SetTextColor(BACKGROUND_RED | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

	switch (msg.Msg)
	{
	case Msg_BobHere:

		cout << "\nMessage handled by " << GetNameOfEntity(pFlyBar->ID())
			<< " at time: " << Clock->GetCurrentTime();

		SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);

		cout << "\n" << GetNameOfEntity(pFlyBar->ID())
			<< ": Bob is here ? Oh i've waited for so long to take him down'!";

		pFlyBar->GetFSM()->ChangeState(GetKnockDown::Instance());

		return true;

	}//end switch

	return false; //send message to global message handler
}
//------------------------------------------------------------------------methods for SleepTilRested

SleepTilRested* SleepTilRested::Instance()
{
	static SleepTilRested instance;

	return &instance;
}

void SleepTilRested::Enter(FlyBar* pFlyBar)
{
	if (pFlyBar->Location() != saloon)
	{
		cout << "\n" << GetNameOfEntity(pFlyBar->ID()) << ": " << "KO";

		pFlyBar->ChangeLocation(saloon);

	}
}

void SleepTilRested::Execute(FlyBar* pFlyBar)
{
	//if FlyBar is not fatigued, insult again.
	if (!pFlyBar->Fatigued())
	{
		cout << "\n" << GetNameOfEntity(pFlyBar->ID()) << ": "
			<< "All mah fatigue has drained away. Bit i need to pee!";

		pFlyBar->GetFSM()->ChangeState(Insult::Instance());
	}

	else
	{
		//sleep
		pFlyBar->DecreaseFatigue();

		cout << "\n" << GetNameOfEntity(pFlyBar->ID()) << ": " << "ZZZZ... ";
	}
}

void SleepTilRested::Exit(FlyBar* pFlyBar)
{
}

bool SleepTilRested::OnMessage(FlyBar* pFlyBar, const Telegram& msg)
{
	//send msg to global message handler
	return false;
}




//------------------------------------------------------------------------DrinkAtTheBar

DrinkAtTheBar* DrinkAtTheBar::Instance()
{
	static DrinkAtTheBar instance;

	return &instance;
}

void DrinkAtTheBar::Enter(FlyBar* pFlyBar)
{
	if (pFlyBar->Location() != bar)
	{
		pFlyBar->ChangeLocation(bar);

		cout << "\n" << GetNameOfEntity(pFlyBar->ID()) << ": " << "Oh boy, im in !";
	}
}

void DrinkAtTheBar::Execute(FlyBar* pFlyBar)
{
	//Boit 
	pFlyBar->Drink();

	cout << "\n" << GetNameOfEntity(pFlyBar->ID()) << ": " << "Hum, that whisky is really good ! Another !";

	//Si il est bourr� alors il se met � insulter les gens dans le bar
	if (pFlyBar->Drunk()) {

		pFlyBar->GetFSM()->ChangeState(Insult::Instance());
	}
}


void DrinkAtTheBar::Exit(FlyBar* pFlyBar)
{
}


bool DrinkAtTheBar::OnMessage(FlyBar* pFlyBar, const Telegram& msg)
{
	//send msg to global message handler
	return false;
}


//------------------------------------------------------------------------GetKnockDown

GetKnockDown* GetKnockDown::Instance()
{
	static GetKnockDown instance;

	return &instance;
}


void GetKnockDown::Enter(FlyBar* pFlyBar)
{
	cout << "\n" << GetNameOfEntity(pFlyBar->ID()) << ": " << "Comon bob!";
}

void GetKnockDown::Execute(FlyBar* pFlyBar)
{
	cout << "\n" << GetNameOfEntity(pFlyBar->ID()) << ": " << "Oww, I ... You... Strong boy ...!";

	pFlyBar->GetFSM()->ChangeState(SleepTilRested::Instance());
}

void GetKnockDown::Exit(FlyBar* pFlyBar)
{
	cout << "\n" << GetNameOfEntity(pFlyBar->ID()) << ": " << "I'm gonna need so sleep ....'";
}


bool GetKnockDown::OnMessage(FlyBar* pFlyBar, const Telegram& msg)
{
	//send msg to global message handler
	return false;
}



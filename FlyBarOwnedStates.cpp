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
	//if the FlyBar is not already located at the goldmine, he must
	//change location to the gold mine
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

//------------------------------------------------------------------------methods for InsultBob

InsultBob* InsultBob::Instance()
{
	static InsultBob instance;

	return &instance;
}

void InsultBob::Enter(FlyBar* pFlyBar)
{
	//on entry the FlyBar makes sure he is located at the bank
	if (pFlyBar->Location() != withBob)
	{
		cout << "\n" << GetNameOfEntity(pFlyBar->ID()) << ": " << "What a batard, this B O B, BOB !";

		pFlyBar->ChangeLocation(withBob);
	}
}


void InsultBob::Execute(FlyBar* pFlyBar)
{

	cout << "\n" << GetNameOfEntity(pFlyBar->ID()) << ": "
		<< "WooHoo! Ok Strong boy, i think you got me ...";

	pFlyBar->GetFSM()->ChangeState(SleepTilRested::Instance());



}


void InsultBob::Exit(FlyBar* pFlyBar)
{
	cout << "\n" << GetNameOfEntity(pFlyBar->ID()) << ": " << "Falling asleep";
}


bool InsultBob::OnMessage(FlyBar* pFlyBar, const Telegram& msg)
{
	//send msg to global message handler
	return false;
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
	//if FlyBar is not fatigued start to dig for nuggets again.
	if (!pFlyBar->Fatigued())
	{
		cout << "\n" << GetNameOfEntity(pFlyBar->ID()) << ": "
			<< "All mah fatigue has drained away. Bit i need to pee!";

		pFlyBar->GetFSM()->ChangeState(GoToBathroom::Instance());
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
	pFlyBar->Drink();

	cout << "\n" << GetNameOfEntity(pFlyBar->ID()) << ": " << "Hum, that whisky is really good ! Another !";

	pFlyBar->GetFSM()->ChangeState(InsultBob::Instance());
}


void DrinkAtTheBar::Exit(FlyBar* pFlyBar)
{
	cout << "\n" << GetNameOfEntity(pFlyBar->ID()) << ": " << "Leaving the bar, feeling drunk. zzz";
}


bool DrinkAtTheBar::OnMessage(FlyBar* pFlyBar, const Telegram& msg)
{
	//send msg to global message handler
	return false;
}
/*
//------------------------------------------------------------------------EatStew

EatStew* EatStew::Instance()
{
	static EatStew instance;

	return &instance;
}


void EatStew::Enter(FlyBar* pFlyBar)
{
	cout << "\n" << GetNameOfEntity(pFlyBar->ID()) << ": " << "Smells Reaaal goood Elsa!";
}

void EatStew::Execute(FlyBar* pFlyBar)
{
	cout << "\n" << GetNameOfEntity(pFlyBar->ID()) << ": " << "Tastes real good too!";

	pFlyBar->GetFSM()->RevertToPreviousState();
}

void EatStew::Exit(FlyBar* pFlyBar)
{
	cout << "\n" << GetNameOfEntity(pFlyBar->ID()) << ": " << "Thankya li'lle lady. Ah better get back to whatever ah wuz doin'";
}


bool EatStew::OnMessage(FlyBar* pFlyBar, const Telegram& msg)
{
	//send msg to global message handler
	return false;
}
*/


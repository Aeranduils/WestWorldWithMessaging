#include "DrunkardOwnedStates.h"
#include "fsm/State.h"
#include "Drunkard.h"
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


void GoToBathroom::Enter(Drunkard* pDrunkard)
{
    //if the Drunkard is not already located at the goldmine, he must
    //change location to the gold mine
    if (pDrunkard->Location() != bathroom)
    {
        cout << "\n" << GetNameOfEntity(pDrunkard->ID()) << ": " << "Walkin' to the bathroom";

        pDrunkard->ChangeLocation(bathroom);
    }
}


void GoToBathroom::Execute(Drunkard* pDrunkard)
{
   

    cout << "\n" << GetNameOfEntity(pDrunkard->ID()) << ": " << "Peeing. Shhhhhh !";
    pDrunkard->GetFSM()->ChangeState(DrinkAtTheBar::Instance());
    
}


void GoToBathroom::Exit(Drunkard* pDrunkard)
{
    cout << "\n" << GetNameOfEntity(pDrunkard->ID()) << ": "
        << "Shit, I'm thirsty, I need a fucking drink !";
}


bool GoToBathroom::OnMessage(Drunkard* pDrunkard, const Telegram& msg)
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

void InsultBob::Enter(Drunkard* pDrunkard)
{
    //on entry the Drunkard makes sure he is located at the bank
    if (pDrunkard->Location() != withBob)
    {
        cout << "\n" << GetNameOfEntity(pDrunkard->ID()) << ": " << "What a batard, this B O B, BOB !";

        pDrunkard->ChangeLocation(withBob);
    }
}


void InsultBob::Execute(Drunkard* pDrunkard)
{

        cout << "\n" << GetNameOfEntity(pDrunkard->ID()) << ": "
            << "WooHoo! Ok Strong boy, i think you got me ...";

        pDrunkard->GetFSM()->ChangeState(SleepTilRested::Instance());
    

    
}


void InsultBob::Exit(Drunkard* pDrunkard)
{
    cout << "\n" << GetNameOfEntity(pDrunkard->ID()) << ": " << "Falling asleep";
}


bool InsultBob::OnMessage(Drunkard* pDrunkard, const Telegram& msg)
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

void SleepTilRested::Enter(Drunkard* pDrunkard)
{
    if (pDrunkard->Location() != saloon)
    {
        cout << "\n" << GetNameOfEntity(pDrunkard->ID()) << ": " << "KO";

        pDrunkard->ChangeLocation(saloon);

    }
}

void SleepTilRested::Execute(Drunkard* pDrunkard)
{
    //if Drunkard is not fatigued start to dig for nuggets again.
    if (!pDrunkard->Fatigued())
    {
        cout << "\n" << GetNameOfEntity(pDrunkard->ID()) << ": "
            << "All mah fatigue has drained away. Bit i need to pee!";

        pDrunkard->GetFSM()->ChangeState(GoToBathroom::Instance());
    }

    else
    {
        //sleep
        pDrunkard->DecreaseFatigue();

        cout << "\n" << GetNameOfEntity(pDrunkard->ID()) << ": " << "ZZZZ... ";
    }
}

void SleepTilRested::Exit(Drunkard* pDrunkard)
{
}

bool SleepTilRested::OnMessage(Drunkard* pDrunkard, const Telegram& msg)
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

void DrinkAtTheBar::Enter(Drunkard* pDrunkard)
{
    if (pDrunkard->Location() != bar)
    {
        pDrunkard->ChangeLocation(bar);

        cout << "\n" << GetNameOfEntity(pDrunkard->ID()) << ": " << "Oh boy, im in !";
    }
}

void DrinkAtTheBar::Execute(Drunkard* pDrunkard)
{
    pDrunkard->Drink();

    cout << "\n" << GetNameOfEntity(pDrunkard->ID()) << ": " << "Hum, that whisky is really good ! Another !";

    pDrunkard->GetFSM()->ChangeState(InsultBob::Instance());
}


void DrinkAtTheBar::Exit(Drunkard* pDrunkard)
{
    cout << "\n" << GetNameOfEntity(pDrunkard->ID()) << ": " << "Leaving the bar, feeling drunk. zzz";
}


bool DrinkAtTheBar::OnMessage(Drunkard* pDrunkard, const Telegram& msg)
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


void EatStew::Enter(Drunkard* pDrunkard)
{
    cout << "\n" << GetNameOfEntity(pDrunkard->ID()) << ": " << "Smells Reaaal goood Elsa!";
}

void EatStew::Execute(Drunkard* pDrunkard)
{
    cout << "\n" << GetNameOfEntity(pDrunkard->ID()) << ": " << "Tastes real good too!";

    pDrunkard->GetFSM()->RevertToPreviousState();
}

void EatStew::Exit(Drunkard* pDrunkard)
{
    cout << "\n" << GetNameOfEntity(pDrunkard->ID()) << ": " << "Thankya li'lle lady. Ah better get back to whatever ah wuz doin'";
}


bool EatStew::OnMessage(Drunkard* pDrunkard, const Telegram& msg)
{
    //send msg to global message handler
    return false;
}
*/


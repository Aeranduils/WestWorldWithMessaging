#ifndef DRUNKARD_OWNED_STATES_H
#define DRUNKARD_OWNED_STATES_H
//------------------------------------------------------------------------
//
//  Name:   DrunkardOwnedStates.h
//
//  Desc:   All the states that can be assigned to the Drunkard class.
//          Note that a global state has not been implemented.
//
//  Author: Mat Buckland 2002 (fup@ai-junkie.com)
//
//------------------------------------------------------------------------
#include "fsm/State.h"


class Drunkard;
struct Telegram;




//------------------------------------------------------------------------
//
//  In this state the Drunkard will walk to a goldmine and pick up a nugget
//  of gold. If the Drunkard already has a nugget of gold he'll change state
//  to DrinkAtTheBar. If he gets thirsty he'll change state
//  to InsultBob
//------------------------------------------------------------------------
class GoToBathroom : public State<Drunkard>
{
private:

	GoToBathroom() {}

	//copy ctor and assignment should be private
	GoToBathroom(const GoToBathroom&);
	GoToBathroom& operator=(const GoToBathroom &);

public:

	//this is a singleton
	static GoToBathroom * Instance();

	virtual void Enter(Drunkard* Drunkard);

	virtual void Execute(Drunkard* Drunkard);

	virtual void Exit(Drunkard* Drunkard);

	virtual bool OnMessage(Drunkard* agent, const Telegram& msg);

};

//------------------------------------------------------------------------
//
//  Entity will go to a bank and deposit any nuggets he is carrying. If the 
//  Drunkard is subsequently wealthy enough he'll walk home, otherwise he'll
//  keep going to get more gold
//------------------------------------------------------------------------
class DrinkAtTheBar : public State<Drunkard>
{
private:

	DrinkAtTheBar() {}

	//copy ctor and assignment should be private
	DrinkAtTheBar(const DrinkAtTheBar&);
	DrinkAtTheBar& operator=(const DrinkAtTheBar&);

public:

	//this is a singleton
	static DrinkAtTheBar* Instance();

	virtual void Enter(Drunkard* Drunkard);

	virtual void Execute(Drunkard* Drunkard);

	virtual void Exit(Drunkard* Drunkard);

	virtual bool OnMessage(Drunkard* agent, const Telegram& msg);
};


//------------------------------------------------------------------------
//
//  Drunkard will go home and sleep until his fatigue is decreased
//  sufficiently
//------------------------------------------------------------------------
class SleepTilRested : public State<Drunkard>
{
private:

	SleepTilRested() {}

	//copy ctor and assignment should be private
	SleepTilRested(const SleepTilRested&);
	SleepTilRested& operator=(const SleepTilRested&);

public:

	//this is a singleton
	static SleepTilRested* Instance();

	virtual void Enter(Drunkard* Drunkard);

	virtual void Execute(Drunkard* Drunkard);

	virtual void Exit(Drunkard* Drunkard);

	virtual bool OnMessage(Drunkard* agent, const Telegram& msg);
};


//------------------------------------------------------------------------
//
//  Drunkard changes location to the saloon and keeps buying Whiskey until
//  his thirst is quenched. When satisfied he returns to the goldmine
//  and resumes his quest for nuggets.
//------------------------------------------------------------------------
class InsultBob : public State<Drunkard>
{
private:

	InsultBob() {}

	//copy ctor and assignment should be private
	InsultBob(const InsultBob&);
	InsultBob& operator=(const InsultBob&);

public:

	//this is a singleton
	static InsultBob* Instance();

	virtual void Enter(Drunkard* Drunkard);

	virtual void Execute(Drunkard* Drunkard);

	virtual void Exit(Drunkard* Drunkard);

	virtual bool OnMessage(Drunkard* agent, const Telegram& msg);
};

/*
//------------------------------------------------------------------------
//
//  this is implemented as a state blip. The Drunkard eats the stew, gives
//  Elsa some compliments and then returns to his previous state
//------------------------------------------------------------------------
class EatStew : public State<Drunkard>
{
private:

	EatStew() {}

	//copy ctor and assignment should be private
	EatStew(const EatStew&);
	EatStew& operator=(const EatStew&);

public:

	//this is a singleton
	static EatStew* Instance();

	virtual void Enter(Drunkard* Drunkard);

	virtual void Execute(Drunkard* Drunkard);

	virtual void Exit(Drunkard* Drunkard);

	virtual bool OnMessage(Drunkard* agent, const Telegram& msg);
}
*/
;




#endif
#ifndef FlyBar_OWNED_STATES_H
#define FlyBar_OWNED_STATES_H
//------------------------------------------------------------------------
//
//  Name:   FlyBarOwnedStates.h
//
//  Desc:   All the states that can be assigned to the FlyBar class.
//          Note that a global state has not been implemented.
//
//  Author: Mat Buckland 2002 (fup@ai-junkie.com)
//
//------------------------------------------------------------------------
#include "fsm/State.h"


class FlyBar;
struct Telegram;




//------------------------------------------------------------------------
//
//  In this state the FlyBar will walk to a goldmine and pick up a nugget
//  of gold. If the FlyBar already has a nugget of gold he'll change state
//  to DrinkAtTheBar. If he gets thirsty he'll change state
//  to InsultBob
//------------------------------------------------------------------------
class GoToBathroom : public State<FlyBar>
{
private:

	GoToBathroom() {}

	//copy ctor and assignment should be private
	GoToBathroom(const GoToBathroom&);
	GoToBathroom& operator=(const GoToBathroom&);

public:

	//this is a singleton
	static GoToBathroom* Instance();

	virtual void Enter(FlyBar* FlyBar);

	virtual void Execute(FlyBar* FlyBar);

	virtual void Exit(FlyBar* FlyBar);

	virtual bool OnMessage(FlyBar* agent, const Telegram& msg);

};

//------------------------------------------------------------------------
//
//  Entity will go to a bank and deposit any nuggets he is carrying. If the 
//  FlyBar is subsequently wealthy enough he'll walk home, otherwise he'll
//  keep going to get more gold
//------------------------------------------------------------------------
class DrinkAtTheBar : public State<FlyBar>
{
private:

	DrinkAtTheBar() {}

	//copy ctor and assignment should be private
	DrinkAtTheBar(const DrinkAtTheBar&);
	DrinkAtTheBar& operator=(const DrinkAtTheBar&);

public:

	//this is a singleton
	static DrinkAtTheBar* Instance();

	virtual void Enter(FlyBar* FlyBar);

	virtual void Execute(FlyBar* FlyBar);

	virtual void Exit(FlyBar* FlyBar);

	virtual bool OnMessage(FlyBar* agent, const Telegram& msg);
};


//------------------------------------------------------------------------
//
//  FlyBar will go home and sleep until his fatigue is decreased
//  sufficiently
//------------------------------------------------------------------------
class SleepTilRested : public State<FlyBar>
{
private:

	SleepTilRested() {}

	//copy ctor and assignment should be private
	SleepTilRested(const SleepTilRested&);
	SleepTilRested& operator=(const SleepTilRested&);

public:

	//this is a singleton
	static SleepTilRested* Instance();

	virtual void Enter(FlyBar* FlyBar);

	virtual void Execute(FlyBar* FlyBar);

	virtual void Exit(FlyBar* FlyBar);

	virtual bool OnMessage(FlyBar* agent, const Telegram& msg);
};


//------------------------------------------------------------------------
//
//  FlyBar changes location to the saloon and keeps buying Whiskey until
//  his thirst is quenched. When satisfied he returns to the goldmine
//  and resumes his quest for nuggets.
//------------------------------------------------------------------------
class InsultBob : public State<FlyBar>
{
private:

	InsultBob() {}

	//copy ctor and assignment should be private
	InsultBob(const InsultBob&);
	InsultBob& operator=(const InsultBob&);

public:

	//this is a singleton
	static InsultBob* Instance();

	virtual void Enter(FlyBar* FlyBar);

	virtual void Execute(FlyBar* FlyBar);

	virtual void Exit(FlyBar* FlyBar);

	virtual bool OnMessage(FlyBar* agent, const Telegram& msg);
};

/*
//------------------------------------------------------------------------
//
//  this is implemented as a state blip. The FlyBar eats the stew, gives
//  Elsa some compliments and then returns to his previous state
//------------------------------------------------------------------------
class EatStew : public State<FlyBar>
{
private:

	EatStew() {}

	//copy ctor and assignment should be private
	EatStew(const EatStew&);
	EatStew& operator=(const EatStew&);

public:

	//this is a singleton
	static EatStew* Instance();

	virtual void Enter(FlyBar* FlyBar);

	virtual void Execute(FlyBar* FlyBar);

	virtual void Exit(FlyBar* FlyBar);

	virtual bool OnMessage(FlyBar* agent, const Telegram& msg);
}
*/
;




#endif
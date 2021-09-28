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
//  In this state the FlyBar is going to the bathroom because he need to.
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
//  Drink at the bar until he's drunk.
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
//  FlyBar will sleep until he's rested enough
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
//  FlyBar will drop in insult to everyone in the saloon.
//------------------------------------------------------------------------
class Insult : public State<FlyBar>
{
private:

	Insult() {}

	//copy ctor and assignment should be private
	Insult(const Insult&);
	Insult& operator=(const Insult&);

public:

	//this is a singleton
	static Insult* Instance();

	virtual void Enter(FlyBar* FlyBar);

	virtual void Execute(FlyBar* FlyBar);

	virtual void Exit(FlyBar* FlyBar);

	virtual bool OnMessage(FlyBar* agent, const Telegram& msg);
};


//------------------------------------------------------------------------
//
//  this is implemented as a state blip. The FlyBar eats the stew, gives
//  Elsa some compliments and then returns to his previous state
//------------------------------------------------------------------------
class GetKnockDown : public State<FlyBar>
{
private:

	GetKnockDown() {}

	//copy ctor and assignment should be private
	GetKnockDown(const GetKnockDown&);
	GetKnockDown& operator=(const GetKnockDown&);

public:

	//this is a singleton
	static GetKnockDown* Instance();

	virtual void Enter(FlyBar* FlyBar);

	virtual void Execute(FlyBar* FlyBar);

	virtual void Exit(FlyBar* FlyBar);

	virtual bool OnMessage(FlyBar* agent, const Telegram& msg);
};

class FightFlyBar : public State<FlyBar>
{
private:

	FightFlyBar() {}

	//copy ctor and assignment should be private
	FightFlyBar(const FightFlyBar&);
	FightFlyBar& operator=(const FightFlyBar&);

public:

	//this is a singleton
	static FightFlyBar* Instance();

	virtual void Enter(FlyBar* flybar);

	virtual void Execute(FlyBar* flybar);

	virtual void Exit(FlyBar* flybar);

	virtual bool OnMessage(FlyBar* agent, const Telegram& msg);
};


#endif
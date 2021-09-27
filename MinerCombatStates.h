#ifndef MINERCOMBAT_STATES_H
#define MINERCOMBAT_STATES_H
//------------------------------------------------------------------------
//
//  Name:   MinerCombat.h
//
//  Desc:   All the states that can be assigned to the MinerCombat class
//
//  Author: Mat Buckland 2002 (fup@ai-junkie.com)
//
//------------------------------------------------------------------------
#include "fsm/State.h"

class MinerCombat;



//------------------------------------------------------------------------
//

//------------------------------------------------------------------------
class MinerCombatGlobalState : public State<MinerCombat>
{
private:

	MinerCombatGlobalState() {}

	//copy ctor and assignment should be private
	MinerCombatGlobalState(const MinerCombatGlobalState&);
	MinerCombatGlobalState& operator=(const MinerCombatGlobalState&);

public:

	//this is a singleton
	static MinerCombatGlobalState* Instance();

	virtual void Enter(MinerCombat* minercombat) {}

	virtual void Execute(MinerCombat* minercombat);

	virtual void Exit(MinerCombat* minercombat) {}

	virtual bool OnMessage(MinerCombat* minercombat, const Telegram& msg);
};


//------------------------------------------------------------------------
//

//------------------------------------------------------------------------
class Attack : public State<MinerCombat>
{
private:

	Attack() {}

	//copy ctor and assignment should be private
	Attack(const Attack&);
	Attack& operator=(const Attack&);

public:

	//this is a singleton
	static Attack* Instance();

	virtual void Enter(MinerCombat* minercombat);

	virtual void Execute(MinerCombat* minercombat);

	virtual void Exit(MinerCombat* minercombat);

	virtual bool OnMessage(MinerCombat* minercombat, const Telegram& msg);

};



//------------------------------------------------------------------------
//

//------------------------------------------------------------------------
class Defense : public State<MinerCombat>
{
private:

	Defense() {}

	//copy ctor and assignment should be private
	Defense(const Defense&);
	Defense& operator=(const Defense&);

public:

	//this is a singleton
	static Defense* Instance();

	virtual void Enter(MinerCombat* minercombat);

	virtual void Execute(MinerCombat* minercombat);

	virtual void Exit(MinerCombat* minercombat);

	virtual bool OnMessage(MinerCombat* minercombat, const Telegram& msg);

};


//------------------------------------------------------------------------
//

//------------------------------------------------------------------------
class Dodge : public State<MinerCombat>
{
private:

	Dodge() {}

	//copy ctor and assignment should be private
	Dodge(const Dodge&);
	Dodge& operator=(const Dodge&);

public:

	//this is a singleton
	static Dodge* Instance();

	virtual void Enter(MinerCombat* minercombat);

	virtual void Execute(MinerCombat* minercombat);

	virtual void Exit(MinerCombat* minercombat);

	virtual bool OnMessage(MinerCombat* minercombat, const Telegram& msg);
};


#endif
#ifndef MINERCOMBAT_H
#define MINERCOMBAT_H
//------------------------------------------------------------------------
//
//  Name: MinersWife.h
//
//  Desc: class to implement Miner Bob's wife.
//
//  Author: Mat Buckland 2003 (fup@ai-junkie.com)
//
//------------------------------------------------------------------------

#include <string>

#include "fsm/State.h"
#include "BaseGameEntity.h"
#include "Locations.h"
#include "MinerCombatStates.h"
#include "misc/ConsoleUtils.h"
#include "Miner.h"
#include "fsm/StateMachine.h"
#include "misc/Utils.h"



class MinerCombat : public BaseGameEntity
{
private:

	//an instance of the state machine class
	StateMachine<MinerCombat>* m_pStateMachine;

public:

	MinerCombat(int id) :
		BaseGameEntity(id)

	{
		//set up the state machine
		m_pStateMachine = new StateMachine<MinerCombat>(this);

		m_pStateMachine->SetCurrentState(Attack::Instance());

		m_pStateMachine->SetGlobalState(Defense::Instance());
	}

	~MinerCombat() { delete m_pStateMachine; }


	//this must be implemented
	void          Update();

	//so must this
	virtual bool  HandleMessage(const Telegram& msg);

	StateMachine<MinerCombat>* GetFSM()const { return m_pStateMachine; }

	//----------------------------------------------------accessors


};

#endif

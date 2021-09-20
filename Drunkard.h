#ifndef DRUNKARD_H
#define DRUNKARD_H
//------------------------------------------------------------------------
//
//  Name:   Drunkard.h
//
//  Desc:   A class defining a drunkard.
//
//  Author: Florian Fritz
//
//------------------------------------------------------------------------
#include <string>
#include <cassert>
#include <iostream>

#include "BaseGameEntity.h"
#include "Locations.h"
#include "misc/ConsoleUtils.h"
#include "fsm/StateMachine.h"
#include "DrunkardOwnedStates.h"

template <class entity_type> class State;
struct Telegram;


//above this value a miner is Soify
const int Soif = 5;
//above this value a miner is sleepy
const int Fatigue = 5;



class Drunkard : public BaseGameEntity
{
private:

    //an instance of the state machine class
    StateMachine<Drunkard>* m_pStateMachine;

    location_type         m_Location;

    //the higher the value, the Soifier the miner
    int                   m_iSoif;

    //the higher the value, the more tired the miner
    int                   m_iFatigue;

public:

    Drunkard(int id) :m_Location(shack),
        m_iSoif(0),
        m_iFatigue(0),
        BaseGameEntity(id)

    {
        //set up state machine
        m_pStateMachine = new StateMachine<Drunkard>(this);

        m_pStateMachine->SetCurrentState(SleepTilRested::Instance());

        /* NOTE, A GLOBAL STATE HAS NOT BEEN IMPLEMENTED FOR THE MINER */
    }

    ~Drunkard() { delete m_pStateMachine; }

    //this must be implemented
    void Update();

    //so must this
    virtual bool  HandleMessage(const Telegram& msg);


    StateMachine<Drunkard>* GetFSM()const { return m_pStateMachine; }



    //-------------------------------------------------------------accessors
    location_type Location()const { return m_Location; }
    void          ChangeLocation(location_type loc) { m_Location = loc; }


    bool          Fatigued()const;
    void          DecreaseFatigue() { m_iFatigue -= 1; }
    void          IncreaseFatigue() { m_iFatigue += 1; }

    bool          Soify()const;
    void          Drink() { m_iSoif = 0; }

};



#endif

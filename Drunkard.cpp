#include "Drunkard.h"

bool Drunkard::HandleMessage(const Telegram& msg)
{
    return m_pStateMachine->HandleMessage(msg);
}


void Drunkard::Update()
{
    SetTextColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);

    m_iSoif += 1;

    m_pStateMachine->Update();
}


bool Drunkard::Soify()const
{
    if (m_iSoif >= Soif) { return true; }

    return false;
}

bool Drunkard::Fatigued()const
{
    if (m_iFatigue > Fatigue)
    {
        return true;
    }

    return false;
}

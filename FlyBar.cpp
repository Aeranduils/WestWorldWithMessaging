#include "FlyBar.h"

bool FlyBar::HandleMessage(const Telegram& msg)
{
	return m_pStateMachine->HandleMessage(msg);
}


void FlyBar::Update()
{
	SetTextColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);

	m_iFatigue += 1;

	m_pStateMachine->Update();
}


bool FlyBar::Drunk()const
{
	if (m_iDrunk >= DrunkLevel)
	{
		return true;
	}

	return false;
}

bool FlyBar::Fatigued()const
{
	if (m_iFatigue > Fatigue)
	{
		return true;
	}

	return false;
}

#include <fstream>
#include <time.h>

#include "Locations.h"
#include "Miner.h"
#include "FlyBar.h"
#include "MinersWife.h"
#include "EntityManager.h"
#include "MessageDispatcher.h"
#include "misc/ConsoleUtils.h"
#include "EntityNames.h"
#include "Time/CrudeTimer.h"
#include <thread>


std::ofstream os;

int main()
{
	//define this to send output to a text file (see locations.h)
#ifdef TEXTOUTPUT
	os.open("output.txt");
#endif

	//seed random number generator
	srand((unsigned)time(NULL));


	//create a miner
	Miner* Bob = new Miner(ent_Miner_Bob);

	//create his wife
	MinersWife* Elsa = new MinersWife(ent_Elsa);

	//create the FlyBar
	FlyBar* Mitch = new FlyBar(ent_Mitch);

	//register them with the entity manager
	EntityMgr->RegisterEntity(Bob);
	EntityMgr->RegisterEntity(Elsa);
	EntityMgr->RegisterEntity(Mitch);


	//run Bob, Elsa and Mitch through a few Update calls
	for (int i = 0; i < 100; ++i)
	{
		//Open a thread
		std::thread t1(&Miner::Update, Bob);
		//Wait that it finished before starting the next one
		t1.join();

		std::thread t2(&MinersWife::Update, Elsa);
		t2.join();

		std::thread t3(&FlyBar::Update, Mitch);
		t3.join();

		//dispatch any delayed messages
		Dispatch->DispatchDelayedMessages();

		//Sleep(100);
		SetTextColor(BACKGROUND_RED | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		std::cout << "\n\n-----------------------------------------------------" << std::endl;
	}

	//tidy up
	delete Bob;
	delete Elsa;
	delete Mitch;

	//wait for a keypress before exiting
	PressAnyKeyToContinue();


	return 0;
}







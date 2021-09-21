#include <fstream>
#include <time.h>

#include "Locations.h"
#include "Miner.h"
#include "Drunkard.h"
#include "MinersWife.h"
#include "EntityManager.h"
#include "MessageDispatcher.h"
#include "misc/ConsoleUtils.h"
#include "EntityNames.h"
#include <thread>


std::ofstream os;

int main()
{
//define this to send output to a text file (see locations.h)
#ifdef TEXTOUTPUT
  os.open("output.txt");
#endif

  //seed random number generator
  srand((unsigned) time(NULL));


  //create a miner
  Miner* Bob = new Miner(ent_Miner_Bob);

  //create his wife
  MinersWife* Elsa = new MinersWife(ent_Elsa);

  //create the drunkard
  Drunkard* Mitch = new Drunkard(ent_Mitch);

  //register them with the entity manager
  EntityMgr->RegisterEntity(Bob);
  EntityMgr->RegisterEntity(Elsa);
  EntityMgr->RegisterEntity(Mitch);

  
  //run Bob, Elsa and Mitch through a few Update calls
  for (int i=0; i<30; ++i)
  { 
      
      std::thread t1(&Miner::Update, Bob);
      std::thread t2(&MinersWife::Update, Elsa);
      std::thread t3(&Drunkard::Update, Mitch);

      t1.join();
      t2.join();
      t3.join();

    //dispatch any delayed messages
    Dispatch->DispatchDelayedMessages();

    Sleep(800);
  }

  //tidy up
  delete Bob;
  delete Elsa;
  delete Mitch;

  //wait for a keypress before exiting
  PressAnyKeyToContinue();


  return 0;
}







#include"EventManager.h"
#include<iostream>
#include<future>

using namespace std;

struct EVENT_ID
{
	static const int EVENT_ID1 = 1;
	static const int EVENT_ID2 = 2;
};
//CUSTOM LISTENER CLASS 
class Notification : public IListener
{

public:
	Notification()
	{

	}

	~Notification()
	{

	}

	void onNotify();
};


void Notification::onNotify()
{
	cout << "Notification : Finished Computation"  << endl;
}


//SUBJECT CLASS WHICH USES A CUSTOM LISTENER AND REGISTER IT WIT REGISTER_MANAGER
class Work
{
	Event work_event;
	Event work_event_2;
	
public:
	Work()
	{
		work_event.EVENT_NAME = "WORK";
		work_event.EVENT_ID = EVENT_ID::EVENT_ID1;
		EventManager::getInstance()->SubscribeListener(work_event, new Notification());
		work_event_2.EVENT_NAME = "WORK2";
		work_event_2.EVENT_ID = EVENT_ID::EVENT_ID2;
		EventManager::getInstance()->SubscribeListener(work_event_2, new Notification());
	}


	void process();

	~Work()
	{ 
		EventManager::getInstance()->UnSubscribeListener(work_event);
	}

private:
	bool is_prime(int x);
};


bool Work::is_prime(int x) {
	std::cout << "Calculating. Please, wait...\n";
	for (int i = 2; i<x; ++i) if (x%i == 0) return false;
	return true;
}

void Work::process()
{
	future<bool>fut = async(launch::deferred, &Work::is_prime,this, 313222313);
	bool result = fut.get();
	if (result)
	{
		EventManager::getInstance()->notifyListener(work_event);
	}
}

int main()
{
	Work* work = new Work();
	work->process();
	return 0;
}
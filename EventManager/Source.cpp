#include"EventManager.h"
#include<iostream>
#include<future>

using namespace std;


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
	
public:
	Work()
	{
		work_event.EVENT_NAME = "WORK";
		EventManager::getInstance()->SubscribeListener(work_event, new Notification());
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
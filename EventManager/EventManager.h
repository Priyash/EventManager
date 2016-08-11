#ifndef EVENT_MANAGER_H
#define EVENT_MANAGER_H
#include"Event.h"

class EventManager
{

	Object* object;
	static EventManager* manager;
	EventManager()
	{
		object = new Object();
	}
public:

	static EventManager* getInstance()
	{
		if (!manager)
		{
			manager = new EventManager();
		}
		return manager;
	}
	~EventManager()
	{
		delete object;
	}

	void SubscribeListener(Event event ,IListener*);
	void UnSubscribeListener(Event event);
	void notifyListener(Event event);
	void notifyAll();
};















#endif
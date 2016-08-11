#include"EventManager.h"
#include<memory>

//IF THE CLASS IS DESIGNED TO ACT AS AN SINGLETON CLASS THEN THIS DECLARATION MUST BE NEEDED 
EventManager* EventManager::manager = NULL;

void EventManager::SubscribeListener(Event event, IListener* listener)
{
	object->registerListener(event, listener);
}

void EventManager::UnSubscribeListener(Event event)
{
	object->unregisterListener(event);
}

void EventManager::notifyListener(Event event)
{
	object->notifyListener(event);
}


void EventManager::notifyAll()
{
	object->notifyAll();
}

#include"Event.h"


void Object::registerListener(Event event,IListener* listener)
{
	object_holder.insert(pair<Event, IListener*>(event, listener));
}


void Object::unregisterListener(Event event)
{
	for (auto i : object_holder)
	{
		if (i.first.EVENT_NAME == event.EVENT_NAME)
		{
			object_holder.erase(i.first);
			return;
		}
	}
}


void Object::notifyListener(Event event)
{
	for (auto i : object_holder)
	{
		if (i.first.EVENT_NAME == event.EVENT_NAME)
		{
			IListener* listener = i.second;
			listener->onNotify();
			return;
		}
	}
}


void Object::notifyAll()
{
	for (auto i : object_holder)
	{
		IListener* listener = i.second;
		listener->onNotify();
	}
}


#ifndef EVENT_H
#define EVENT_H
#include<map>
#include<algorithm>
#include<string>
#include<utility>

using namespace std;


struct Event
{
	int EVENT_ID = 0 ;
	string EVENT_NAME;
};


class IListener
{

public:
	IListener()
	{

	}

	~IListener()
	{

	}

	virtual void onNotify() = 0;
};

//VERY VERY IMPORTANT WHEN INSERTING TWO DATATYPE AS A DATA STRUCTURE IN A MAP FOR THAT YOU HAVE TO SPECIFY THE COMPARATOR FUNCTION
struct comparator
{
	bool operator()(Event e1, Event e2)
	{
		return e1.EVENT_ID < e2.EVENT_ID;
	}
};


class Object
{
	map < Event, IListener*, comparator>object_holder;
public:
	Object()
	{

	}

	~Object()
	{
		object_holder.clear();
	}

	void registerListener(Event event,IListener*);
	void unregisterListener(Event event);
	void notifyListener(Event event);
	void notifyAll();

};
















#endif
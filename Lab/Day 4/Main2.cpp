/******************************************************************************
priority queue.

*******************************************************************************/
#include <iostream>

using namespace std;
class queueElement
{
public:
  int queueElementPriority;
  string queueElementStringValue;
    queueElement ()
  {
    //default constructor
  }
  queueElement (string queueElementStringValue, int queueElementPriority)
  {
    this->queueElementStringValue = queueElementStringValue;

    this->queueElementPriority = queueElementPriority;
  }
};

class queue
{
public:

  queueElement * queueArray;
  int top;
  int bottom;
  int size;
public:
    queue ()
  {
    //default constructor
  }
  queue (int size)
  {
    queueArray = new queueElement[size];
    this->size = size;
    top = 0;
    bottom = 0;
  }
  void add (string queueElementStringValue, int queueElementPriority)
  {
    if ((top) >= size)
      {
	cout << "Overflow" << "\n";

      }
    else
      {

	queueElement *elementToBeAdded = new queueElement (queueElementStringValue, queueElementPriority);

	queueArray[top] = *elementToBeAdded;
	top++;
	sort ();
      }
  }

  void sort ()
  {
    if (top > 1)
      {
	for (int i = top - 1; i > 0; i--)
	  {
	    if (queueArray[i].queueElementPriority < queueArray[i - 1].queueElementPriority)
	      {
		//swap;
		queueElement temp = queueArray[i];
		queueArray[i] = queueArray[i - 1];
		queueArray[i - 1] = temp;
	      }
	  }
      }
  }
  queueElement pop ()
  {
    if (bottom == top)
      {
	cout << "underflow" << "\n";
	top = 0;
	bottom = 0;

      }
    else
      {

	bottom++;
	return queueArray[bottom - 1];	//alternative to temp method of removal
      }
  }
  void display ()
  {
    for (int i = bottom; i < top; i++)
      {
	cout << queueArray[i].queueElementStringValue << " , ";
      }
    cout << "\n";
  }
};

int
main ()
{
  queue *myBookQueue = new queue (4);
  myBookQueue->add ("enid blyton", 4);
  myBookQueue->add ("Harry potter", 2);
  myBookQueue->add ("sherlock homes", 1);
  myBookQueue->add ("pokemon", 3);


  myBookQueue->display ();

  return 0;
}

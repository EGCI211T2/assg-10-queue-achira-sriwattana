#ifndef queue_h
#define queue_h
#include "Node.h"
class Queue {
  private:
    NodePtr headPtr,tailPtr;
    int size;
  public:
      void print_queue();
      void enqueue(int);
      int dequeue();
      Queue();
      ~Queue();
};

void Queue::print_queue(){
  NodePtr t = headPtr;
  for(int i=0; i<size; i++){
    int val = t -> get_value();
    cout << val << " ";
    t = t -> get_next();
  }
}

void Queue::enqueue(int x){
  NodePtr new_node = new NODE(x);
  if(new_node){ 
    /*
    Add head and tail for me please
    1. connect & Change tail
    2. (may be) change head  when the queue is empty
    3. increase size
    */
    // cout << "Entering " << x << endl;
    if(headPtr == NULL){ // if queue is empty
      headPtr = new_node;
      tailPtr = new_node;
    }
    else{ // if queue isn't empty
      int test = headPtr -> get_value();
      // cout << "headPtr points to " << test << endl;
      
      tailPtr -> set_next(new_node);
      tailPtr = new_node;
    }

    size++;
  }
  else{
    cout << "Couldn't add node, out of memory!\n";
  }
}

int Queue::dequeue(){
  if(headPtr!=NULL){
    NodePtr t = headPtr;
    int value = t -> get_value();
    int test_val;

    if(size != 1){ // check if headPtr is already at the last node
      headPtr = headPtr -> get_next();
    }
    // test_val = headPtr -> get_value();
    // cout << "headPtr now points to " << test_val << "before deleting " << value << endl;
    
    cout << "Dequeing/Deleting " << value << endl; // this line is here for easier output readability
    delete t;
    size--;
    return value;
  }
  cout << "Empty queue";
  return -1;
}


Queue::Queue(){
    headPtr = NULL;
    tailPtr = NULL;
    size = 0;
}
Queue::~Queue(){
  cout << "\nIn destructor with queue size " << size << ":\n";
  int iterate_amount = size; // we use iterate_amount because dequeue() reduces size when it is called
  for(int i=0; i<iterate_amount; i++){
    // cout << "On element " << i << endl;
    dequeue();
  }
}


#endif

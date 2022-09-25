class MyCircularQueue {
public:
    MyCircularQueue(int k) {
        
        q.resize(k);  // we want the capacity of the vector to be k
        front=rear=size=0; // constructor initializes these values 
        capacity=k;
    }
    
    bool enQueue(int value) {
        // we need to check if the queue is already full or not
        if(size==capacity)
            return false;
        else
        {
            // REASON FOR A SEPARATE CONDITION OF EMPTY QUEUE:
               // If we consider it a normal entry as in rear=(rear+1)%capacity then for the case when
               // our queue is empty, front=0 but rear will be (0+1)%capacity, leaving an empty slot at index 0.
               // The benefit of circular queue is to use the front space well, but this way it would be wasted.
               //   Hence, we make an explicit check if the queue is empty or not and we dont increment
               //  rear in that. 
               // Also, we need to intitialize front=0,rear=0 again because consider a case:
               // empty queue-> enqueue(20)->dequeue()->enqueue(30)->dequeue()
               //     In this case, after the first dequeue has happened, front is one ahead of rear and  
               //     isEmpty()is true.                       
               //       After 30 is enqueued, rear remains at 0 index and front is at index 1.
               //        When we do dequeue, front goes to index 2, that has no element. making the front() give wrong output. Hence, it is important to reset front=0, rear=0 whenever the queue is empty.
            
            
        if(size==0) // the queue is empty, means front=rear=0
        {
            front=0,rear=0;
            q[rear]=value;
            size++;
            return true;
        }
            rear=(rear+1)%capacity; 
            q[rear]=value;
            size++;
            return true;
        }
    }
    
    bool deQueue() {
        // we need to check if the queue is empty or not
        if(size==0)
            return false;
        else
        {
            front=(front+1)%capacity;  // we just ignore(delete) the value that front was pointing to earlier. Actual deletion is not happening, its just that we are manipulating 'size' and the current value will be 'overwritten' in case of an enqueue (if required)
            size--;
            return true;
          
        }
    }
    
    int Front() {
        // one line statement using ternary operators
            return isEmpty()? -1: q[front];
       
    }
    
    int Rear() {  
        
        return isEmpty()? -1 : q[rear];
    }
    
    bool isEmpty() {
        return size==0;
    }
    
    bool isFull() {
        return size==capacity;
    }
    
    private:  // declare the vector and the navigating variables: rear( used for addition) and front (used for deletion)
    vector<int> q;
    int rear=0,front=0,size=0;
    int capacity=0;
    // size is the current size and capacity is the overall size of our queue
    
};
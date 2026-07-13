class MyCircularQueue {
    int* arr;
    int currsize,cap;
    int f,r;
        
public:
    MyCircularQueue(int k) {
        cap=k;
        arr=new int[cap];
        r=-1;
        f=0;
        currsize=0;
    }

    
    bool enQueue(int value) {      
        if (currsize == cap) return false;
        r = (r + 1) % cap;
        arr[r] = value;
        currsize++;
        return true;
    }

    bool deQueue() {              
        if (isEmpty()) return false;
        f = (f + 1) % cap;
        currsize--;
        return true;
    }
    
    int Front() {
        if(isEmpty())
        return -1;
        return arr[f];
    }
    
    int Rear() {
        if(isEmpty())
        return -1;
        return arr[r]; 
    }
    
    bool isEmpty() {
        return(currsize==0);
    }
    
    bool isFull() {
       return(currsize==cap); 
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
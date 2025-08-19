class Stack
{
    // Instance variables : Each stack you make will have unique copies of these variables
    int [] stack;
    int capacity;
    int top;

// Whenever you make a new stack, you will pass its maximum capacity as a parameter.
    Stack(int capacity)
{
    this.capacity = capacity; 
    this.stack = new int[capacity];
    this.top = -1; // Stack will be empty when created.
}

//Checks if stack is full
    boolean isFull()
    {
        if(top>=capacity-1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

//Checks if stack is empty
     boolean isEmpty()
    {
        if(top==-1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void push(int value)
    {
        if(isFull())
        {
            System.out.println("Stack is at max capacity, cannot push value.");
        }
        else
        {
        stack[++top]= value;
        System.out.println("Pushed "+value);
        }
    }

    void pop()
    {
        if(isEmpty())
        {
            System.out.println("Stack is empty, no value to pop.");
        }
        else
        {
            System.out.println("Popped "+stack[top--]);
        }
    }

       void peep()
    {
        if(isEmpty())
        {
            System.out.println("Stack is empty, cannot peep.");
        }
        else
        {
            System.out.println("Topmost value is : "+stack[top]);
        }
    }
  

    public static void main(String[] args) 
    {
      Stack mystack = new Stack(5);

      // pushing values : 
      mystack.push(1);
      mystack.push(2);
      mystack.push(3);
      mystack.push(4);
      mystack.push(5);
      mystack.push(6);

      // popping : 
      mystack.pop();
      mystack.pop();

      // peeping : 
      mystack.peep();

    }
}
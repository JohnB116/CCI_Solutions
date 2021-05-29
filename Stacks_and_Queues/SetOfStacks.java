/* #3, implement a data structure consisting of multiple stacks which
    cascade onto the next if the stack size limit is reached.

*/

import java.util.ArrayList;
import java.util.EmptyStackException;

public class SetOfStacks<T>{

    private ArrayList<MyStack<T>> the_list;
    private final int limit = 5;
    private int index;
    private int tracker;

    public SetOfStacks(){
        the_list = new ArrayList<>();
        MyStack<T> init = new MyStack<>();
        this.the_list.add(init);
        this.index = 0;   //ArrayList index
        this.tracker = 0; //Stack len
    }

    public void push(T val){
        if(++tracker < limit){
            this.the_list.get(this.index).push(val);
        }
        else{
            MyStack<T> next = new MyStack<>();
            this.the_list.add(next);
            this.index++;
            this.tracker = 0;
            this.the_list.get(this.index).push(val);
        }
    }

    public T pop(){
        if(this.the_list.get(this.index).peek() != null){
            T val = this.the_list.get(this.index).pop();
            //Check if index stack is empty
            if(this.the_list.get(this.index).peek() == null){
                this.the_list.remove(index--);
            }
            return val;
        }
        else{
            throw new EmptyStackException();
        }

    }

    public T peek(){
        if(this.the_list.get(this.index).isEmpty() && this.index > 0){
            this.index--;
            T val = this.the_list.get(this.index).peek();
            this.index++;
            return val;
        }    
        else if(this.the_list.get(this.index).peek() != null){
            return this.the_list.get(this.index).peek();
        }
        else{
            throw new EmptyStackException();
        }
    }

}
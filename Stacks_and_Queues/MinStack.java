// #2: Design a stack where push, pop, and
// the minimum can all be found in O(1) time.
//
// This simply uses a standard stack to track minimums
// when the MinStack has a push or pop operation
import java.util.EmptyStackException;

public class MinStack<T>{
    private static class MinStackNode<T>{
        private T data;
        private MinStackNode<T> next;

        public MinStackNode(T data){
            this.data = data;
        }   
    }

    private MinStackNode<T> top;
    private T min;
    private MyStack<T> minimums;


    public T pop(){
        if(top == null){
            throw new EmptyStackException();
        }
        T item = top.data;
        top = top.next;

        //Minimum tracking
        if(min == item){
            minimums.pop(); 
            if(minimums.isEmpty()){
                throw new EmptyStackException();
            }
            min = minimums.peek();
        }
        return item;
    }

    public void push(T item){
        MinStackNode<T> t = new MinStackNode<T>(item);
        t.next = top;
        top = t;

        //Minimum tracking
        if(min == null){
            min = item;
        }
        else if((int)item <= (int)min){
            min = item;
            minimums.push(item);
        }
    }

    //Access minumum
    public T getMin(){
        return min;
    }

    public T peek(){
        if(top == null){
            throw new EmptyStackException();
        }
        return top.data;
    }

    public boolean isEmpty(){
        return top == null;
    }
}

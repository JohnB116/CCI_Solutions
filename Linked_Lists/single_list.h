template <typename T>
struct single_list_node{
    T value;
    single_list_node<T> * next;
};

template <typename T>
class single_list{

    public:
        single_list(){
            size = 0;
            head = nullptr;
        }
        void push_back(T val){
            single_list_node<T> * s = new single_list_node<T>;
            s->next = nullptr;
            s->value = val;
           
            if(size == 0){
                head = s;
                tail = s;
            }
            else{
                tail->next = s;
                tail = s;
            }

            size++;
        }
        int get_size(){
            return size;
        }
        single_list_node<T> * start(){
            return head;
        }

    private:
        int size;
        single_list_node<T> * head;
        single_list_node<T> * tail;
        
};
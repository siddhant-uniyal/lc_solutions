typedef struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
    Node() : data(0) , prev(nullptr) , next(nullptr) {}
    Node(int data) : data(data) , prev(nullptr) , next(nullptr) {}
}Node;

class MyLinkedList {
public:
    Node *head;

    MyLinkedList() {
        head = nullptr;
    }
    
    int get(int index) {
        Node *ptr = head;
        for(int i = 0 ; i < index && ptr ; ++i){
            ptr = ptr->next;
        }
        return ptr ? ptr->data : -1;
    }
    
    void addAtHead(int val) {
        Node *toAdd = new Node(val);
        if(head == nullptr){
            head = toAdd;
        }
        else{
            toAdd->next = head;
            head->prev = toAdd;
            head = toAdd;
        }
    }
    
    void addAtTail(int val) {
        Node *toAdd = new Node(val);
        if(head == nullptr){
            head = toAdd;
        }
        else{
            Node *ptr = head;
            while(ptr->next) ptr = ptr->next;
            ptr->next = toAdd;
            toAdd->prev = ptr;
        }
    }
    
    void addAtIndex(int index, int val) {
        if(index == 0){
            addAtHead(val);
        }
        else{
            Node *ptr = head;
            for(int i = 0 ; i < index - 1 && ptr ; ++i) ptr = ptr->next;
            if(ptr == nullptr) return;
            if(ptr->next == nullptr) addAtTail(val);
            else{
                Node *toAdd = new Node(val);
                toAdd->next = ptr->next;
                toAdd->prev = ptr;
                ptr->next = toAdd;
                toAdd->next->prev = toAdd;
            }
        }
    }
    
    void deleteAtIndex(int index) {
        Node *ptr = head;
        for(int i = 0 ; i < index && ptr ; ++i) ptr = ptr->next;
        if(ptr == nullptr) return;
        if(ptr->next != nullptr){
            ptr->next->prev = ptr->prev;
        }
        if(ptr->prev != nullptr){
            ptr->prev->next = ptr->next;
        }
        delete(ptr);
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
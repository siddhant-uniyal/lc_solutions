typedef struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
    Node() : data(0) , prev(nullptr) , next(nullptr) {}
    Node(int data) : data(data) , prev(nullptr) , next(nullptr) {}
}Node;

class LRUCache {
public:
    int capacity;
    Node *head;
    Node *tail;
    unordered_map<int,Node*>k2n;
    unordered_map<int,int>k2v;

    Node* createNode(int key){
        return new Node(key);
    }

    void deleteNode(Node *ptr){
        if(ptr == nullptr) return;
        if(ptr->next != nullptr){
            ptr->next->prev = ptr->prev;
        }
        if(ptr->prev != nullptr){
            ptr->prev->next = ptr->next;
        }
        if(ptr == head){
            head = head->next;
        }
        delete(ptr);
    }

    Node* addNode(int key , int value){
        Node *toAdd = createNode(value);
        if(head == nullptr){
            head = toAdd;
        }
        else{
            tail->next = toAdd;
            toAdd->prev = tail;
        }
        tail = toAdd;
        return toAdd;
    }

    LRUCache(int capacity) {
        this->capacity = capacity;
        head = nullptr;
        tail = nullptr;
    }
    
    int get(int key) {
        return k2v.count(key) ? -1 : k2v[key];
    }
    
    void put(int key, int value) {
        if(k2v.count(key)){
            deleteNode(k2n[key]);
            Node *newNode = addNode(key , value);
            k2n[key] = newNode;
        }
        else{
            Node *newNode = addNode(key , value);
            k2n[key] = newNode;
            --capacity;
            if(capacity < 0){
                int headKey = head->data;
                k2n.erase(headKey);
                k2v.erase(headKey);
                deleteNode(head);
                capacity = 0;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
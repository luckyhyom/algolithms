class LinkedList {
   public:
    LinkedList();
    void append(int n);
    void remove(int n);
    void retrieve();
    void removeDups();
    void printKthFromEnd(int n);
    void deleteNode(int index);
    void reset();
    void resetToHead();
    static Node* partition(Node* node, int x);
    int getData();
};

### Linked List는 어떤 인터페이스를 제공해야할까?

기본적으로 Node는 캡슐화 해야겠지?

```cpp
int main() {
    LinkedList linkedList; 
    linkedList.add(1);
    linkedList.add(2);
    linkedList.add(3);

    std::cout << linkedList.getValue() << std::endl; // 1

    linkedList.next();
    std::cout << linkedList.getValue() << std::endl; // 2

    linkedList.next();
    std::cout << linkedList.getValue() << std::endl; // 3

    linkedList.next();
    std::cout << linkedList.getValue() << std::endl; // 0

    int data = linkedList.next()->next()->next()->getValue();
    std::cout << data << std::endl; // 3
    return 0;
}
```
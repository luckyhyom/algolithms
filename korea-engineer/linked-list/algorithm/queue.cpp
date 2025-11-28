/**
 * 여가와 안락이란 무엇일까, 언제쯤 불안을 느끼지 않고 살아갈 수 있을까
 * 어느 순간에는 이러한 코드를 짜는 것이 여가처럼 느껴지고 어느 순간에는 그렇지 않다.
 * 매일 아침 무거운 몸을 일으켜 세워 회사로 가 사람들과 마주하는 것, 그런 어떠한 매일의 작은 이겨냄들이 있어야 안락함과 여유도 느낄 수 있는 것인가.
 *
 * ...
 * 특별한 목적 없이 하는 코딩은 만약 내게 시간이 썩어 넘치도록 허락되어있다면 심심풀이로서 나쁘지 않은 일이다.
 * 코드를 쓰고 정리하며 몰입이 되기도 하지만 이성적으로 생각해보면 비생산적인 일이다.
 *
 * 재미로만 치면 사실 게임이 훨씬 재미있을 것이다. 게임 안의 세계관이나 전략들
 * 근데 사실 누워서 숏츠나 릴스를 보는 것 보다는 건강한 활동인 것 같다. 웃기다.
 *
 * ... 역시 시간의 여유가 있을때나 할만한 일인 것 같다. 일을 하면 개인 시간이 적어지고
 * 그 시간안에 하고싶거나 해야하는 활동 중에서 코딩은 우선 순위가 낮을 것이다. 더 중요한 공부나, 여가활동이 있을 것이다.
 *
 * 생각이 너무 길어지면 몰입을 깨버린다. 좋은 느낌은 순간을 그대로 만끽하고 생각은 나중에 하자.
 *
 * ...
 *
 * 가끔 생기는 학구열은 그저 여유롭게 코딩이나 하고싶다는 아주 약간의 호기심이 섞인 게으름인가?
 * 만약 어린 시절로 돌아가 공짜나 다름없는 시간을 얻게 된다면, 코딩을 하게 될까?
 *
 * ...
 *
 * 게으름에 대한 찬양에서 말하는 것 처럼 사람에게는 충분한 여가시간이 필요하다.
 * 개인의 여가 시간에 이런 저런 비생산적인 활동을 하며 그것이 무언가를 창조하고 생산하게 된다.
 * 노동 시간이 하루에 5~6시간정도면 참 좋을텐데!
 */

#include <iostream>

#include "../linked-list.cpp"

/**
 * 문제:
 * 링크드리스트를 이용하여 큐를 구현하시오.
 */
class Animal {
   public:
    std::string name;
    int order;
    Animal(std::string name) : name(name) {};
    virtual void speak() = 0;
    int getOrder() { return this->order; }
    void setOrder(int number) { this->order = number; }
    void info() {
        std::cout << "name: " << this->name << std::endl;
        std::cout << "order: " << this->order << std::endl;
    }
};

std::ostream& operator<<(std::ostream& os, Animal& c) {
    os << "( name: " << c.name << ", order: " << c.order << " ) ";
    return os;
}

class Cat : public Animal {
   public:
    Cat(std::string name) : Animal(name) {}
    void speak() { std::cout << "meow~" << std::endl; }
};

class Dog : public Animal {
   public:
    Dog(std::string name) : Animal(name) {}
    void speak() { std::cout << "bow!" << std::endl; }
};

class AnimalShelther {
    LinkedList<Cat*> cats;
    LinkedList<Dog*> dogs;
    int order = 0;

   public:
    AnimalShelther() {}

    void put(Cat* cat) {
        cat->setOrder(++order);
        cats.append(cat);
    }

    void put(Dog* dog) {
        dog->setOrder(++order);
        dogs.append(dog);
    }

    /**
     * 링크드 리스트의 노드에서 데이터를 추출할때 어떻게 데이터를 보존 혹은 복사하지?
     * 애초에 노드의 data는 노드가 delete하지 않는다. data의 자료형은 포인터일수도, 아닐수도 있으며 포인터일 경우 해당 구조체가 소멸자를 통해 스스로 delete한다.
     *
     * 즉.. data 상관하지 않고 그냥 노드만 삭제하면 된다.
     */
    Cat* getCat() {
        // Cat* cat = cats.get(1); // 이렇게 쓰고싶은데.. 짜증나네
        LinkedList<Cat*>::Node* n = cats.get(1);
        Cat* cat = n->data;
        cats.remove(cat);
        cat->speak();
        cat->info();
        return cat;
    }

    Dog* getDog() {
        LinkedList<Dog*>::Node* n = dogs.get(1);
        Dog* dog = n->data;
        dogs.remove(dog);
        dog->speak();
        dog->info();
        return dog;
    }

    void get() {
        if (dogs.get(1) == nullptr && cats.get(1) == nullptr) {
            return;
        }

        if (cats.get(1) == nullptr) {
            getDog();
            return;
        } else if (dogs.get(1) == nullptr) {
            getCat();
            return;
        }

        Dog* d = dogs.get(1)->data;
        Cat* c = cats.get(1)->data;
        if (d->getOrder() < c->getOrder()) {
            getDog();
        } else {
            getCat();
        }
    }
};

int main() {
    AnimalShelther s;
    s.put(new Dog(std::string("Puppy")));
    s.put(new Cat(std::string("Jessi")));
    s.put(new Dog(std::string("Cookie")));
    s.put(new Cat(std::string("Chewrr")));
    s.put(new Dog(std::string("Jelly")));
    s.put(new Cat(std::string("MeowMeow")));
    s.getDog();
    s.getCat();
    s.get();
    s.get();
    s.get();
    s.get();
    return 0;
}
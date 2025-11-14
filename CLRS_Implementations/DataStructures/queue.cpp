// queue.cpp
#include <iostream>
#include <stdexcept>

template<typename T>
class Queue {
private:
    T* data;
    int capacity;
    int front;
    int rear;
    int size;

public:
    Queue(int capacity) : capacity(capacity), front(0), rear(0), size(0) {
        data = new T[capacity];
    }

    ~Queue() {
        delete[] data;
    }

    void enqueue(const T& value) {
        // TODO: 实现入队逻辑
        if (isFull()) throw std::range_error("chaole");
        data[rear] = value; size++; rear=(rear+1)%capacity;
    }

    void dequeue() {
            // TODO: 实现出队逻辑
        if (isEmpty()) { front=(front+1)%capacity; size--; };
        else throw std::out_of_range("error");
    }

    T& peek() {
        // TODO: 返回队首元素
        if (isEmpty()) {
            throw std::out_of_range("error");
        }
        return data[front];
    }

    bool isEmpty() const {
        return size==0;
    }

    bool isFull() const {
        // TODO: 判断队列是否已满
        return size == capacity;
    }

    int getSize() const {
        return size;
    }
};

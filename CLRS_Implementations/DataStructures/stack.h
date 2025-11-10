#pragma once
#include <memory>     // 用于 std::unique_ptr
#include <stdexcept>  // 用于异常

template<typename T>
class LinkedListStack {
private:
    // 私有成员：
    // 1. 内部节点结构
    struct node {
        T data;
        std::unique_ptr next;
        node(T ata) :data(ata), next(nullptr) {};
    };
    // 2. 指向栈顶的指针
    std::unique_ptr _top;

    // 3. 栈的大小
    int _size{0};
public:
    // 构造函数
    LinkedListStack() :_size(0), _top(nullptr) {};
    LinkedListStack(T data) :_size(1), _top(std::make_unique<node>(data)) {};
    // 析构函数（由于使用 unique_ptr，可自动管理内存）
    ~LinkedListStack() {};

    /**
     * @brief 将一个元素压入栈顶
     * @param value 要入栈的元素
     */
    void push(const T& value) {
        auto new_node=std::make_unique<node>(value);
        new_node_next=std::move(_top);
        _size++;
        _top = std::move(new_node);
    };

    void pop() {
        if (!isEmpty()) {
            _top = std::move(_top->next);
            size--;
        }
        else throw std::out_of_range("error");
    }
    ;
    T& top() {
        if (!isEmpty()) {
            return _top;
        }
        else std::cout << "error";
        return -1;
    };

    bool isEmpty() const {
        return _top == nullptr;
    };

    int size() const {
        return _size;
    };
};

// --- 实现提示 ---
// push -> 创建一个新 Node，将其 next 指向旧的 _top，然后将 _top 指向新 Node
// pop  -> 将 _top 指向 _top->next（unique_ptr 会自动释放旧的 top）
// top  -> 返回 _top->data
// isEmpty -> 检查 _top == nullptr
// size -> 返回 _size（并在 push/pop 时更新它）
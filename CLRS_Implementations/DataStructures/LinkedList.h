#ifndef LINKED_LIST
#define LINKED_LIST
#include <iostream>
#include <memory>
#include <stdexcept>
namespace clrs {
	namespace data {
	template<typename T>
	class list {
	private:
		struct node {
			T data;
			std::shared_ptr<node> next;
			std::weak_ptr<node> front;
			node(T aim) :data(aim), front(nullptr),next() {};
			};
		std::shared_ptr<node> _head{ nullptr };
		std::weak_ptr<node> _tail{ nullptr };
		int _size{ 0 };
	public:
		list() : _head(nullptr), _tail(), _size(0) {};
		list(T data) : _head(std::make_shared<node>(data)),
			_tail(_head), _size(1) {};
		~list() {};
		void push_front(T aim) {
			auto new_node=std::make_shared<node>(aim);
			if (!isEmpty()) {
				new_node->next = _head;
				_head->front = new_node;
			}
			else {
				_tail = new_node;
			}
			_head = new_node;
			_size++;
		};/*这个is 加入head front*/
		void push_back(T aim) {
			auto new_node=std::make_shared<node>(aim);
			if (!isEmpty()) {
				_tail.lock()->next = new_node;
				new_node->front = _tail.lock();
			}
			else {
				_head = new_node;
			}
			_tail = new_node;
			_size++;
		};
		void pop_front() {
			if (isEmpty()) {
				throw std::out_of_range("isempty of the list");
			}
			_size--;
			if (_head->next == nullptr) {
				_head = nullptr;
				_tail.reset();
			}
			else {
				_head = _head->next;
				_head->front = nullptr;
			}
		};
		void pop_back() {
			if (isEmpty()) {
				throw std::out_of_range("is empty of the list");
			}
			_size--;
			if (_head->next == nullptr) {
				_head = nullptr;
				_tail.reset();
			}
			else {
				_tail = _tail.lock()->front.lock();
				_tail.lock()->next = nullptr;
			}
		};
		bool isEmpty() const {
			return _head == nullptr;
		};
		int getSize() const {
			return _size;
		};
		T front() const {
			if (!isEmpty())
				return _head->data;
			else
				throw std::out_of_range("is empty");
		};
		T back() const {
			if (!isEmpty())
				return _tail.lock()->data;
			else
				throw std::out_of_range("is empty");
		};
		};
	};

}
#endif 

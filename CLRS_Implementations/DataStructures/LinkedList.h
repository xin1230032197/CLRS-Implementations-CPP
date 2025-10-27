#ifndef LINKED_LIST
#define LINKED_LIST
#include <iostream>
#include <memory>
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
		void push_back(T aim);
		void pop_front();
		void pop_back();
		bool isEmpty() const;
		int getSize() const;
		T front() const;
		T back() const;
		};
	};

}
#endif 

#include <iostream>
#include <vector>
#include <list>

template<typename K, typename V>
class HashTable {
private:
    struct Node {
        K key; V value;
        Node(K k, V v) :key(k), value(v) {};
    };
    std::vector<std::list<node>> table;
    int rongliang, size;

    int hashFunction(const K& key) const {
        if constexpr (std::is_same<K, int>::value) {
            return key % rongliang;
        }
        else if constexpr (std::is_same<K, std::string>::value) {
            int hash = 0;
            for (char ch : key) {
                hash = (hash * 31 + ch) % rongliang;
            }
            return hash;
        }
        else {
            throw std::invalid_argument("Unsupported key type for hash function");
        }
    }
public:
    HashTable(int rongliang) : rongliang(rongliang), size(0) {
        table.resize(rongliang);
    }

    ~HashTable() {
        // TODO: 如果需要，清理资源
    }

    void insert(const K& key, const V& value) {
        int hashma = hashFunction(key);
        for (auto& node : table[hashma]) {
            if (node.key == key) {
                node.value = value;
                return;
            }
        }
        table[hashma].emplace_back(key, value);
        ++size;
    }

    void remove(const K& key) {
        int hashma = hashFunction(key);
        for (auto it = table[hashma].begin(); it != table[hashma].end(); ++it) {
            if (it->key == key) {
                table[hashma].erase(it); // 使用迭代器删除
                --size;
                return;
            }
        }
        }

        V* search(const K & key) const {
            int hashma = hashFunction(key);
            for (auto& node : table[hashma]) {
                if (key == node.key)
                    return &node.value
            }
            return nullptr;
        }

        bool contains(const K & key) const {
            return search(key) == nullptr;
        }

        int getSize() const {
            return size;
        }

        bool isEmpty() const {
            return size == 0;
        }
    };
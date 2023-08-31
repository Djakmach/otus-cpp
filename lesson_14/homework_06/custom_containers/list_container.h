template<typename T>
struct Node {
    Node* next;
    Node* prev;
    T value;
};



template<typename T>
class ListContainer {
public:
    ListContainer() : _size{0}, _last{nullptr} {
    }

    void push_back(T value) {
        Node<T>* new_node = new Node<T>{};
        new_node->prev = _last;
        new_node->next = nullptr;
        new_node->value = value;
        if (_last) {
            _last->next = new_node;
        }
        _last = new_node;
        ++_size;
        if (_size == 1) _first = new_node;

    }

    T get_value(size_t index) {
        Node<T>* current_node = _last;
        for (size_t i=_size-1; i != index; --i) {
            current_node = current_node->prev;
        }
        return current_node->value;
    }

    void print() {
        Node<T>* current_node = _first;
        std::cout << "[";
        for (size_t i=0; i < _size; ++i) {
            std::cout << current_node->value;
            if (i < _size - 1) std::cout << ", "; 
            current_node = current_node->next;
        }
        std::cout << "]";

    }

private:
    size_t  _size;
    Node<T>* _last;
    Node<T>* _first;
};
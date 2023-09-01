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

    T get_value(size_t index) const {
        Node<T>* current_node = _last;
        for (size_t i=_size-1; i > index; --i) {
            current_node = current_node->prev;
        }
        return current_node->value;
    }

    void print() const{
        Node<T>* current_node = _first;
        std::cout << "[";
        for (size_t i=0; i < _size; ++i) {
            std::cout << current_node->value;
            if (i < _size - 1) std::cout << ", "; 
            current_node = current_node->next;
        }
        std::cout << "]\n";
    }

    size_t get_size() const {
        return _size;
    }

    void insert(size_t index, T value) {
        Node<T>* current_node = _first;
        Node<T>* new_node = new Node<T>;
        new_node->value = value;
        if (index == 0) {
            new_node->next = current_node;
            _first = new_node;
            current_node->prev = new_node;
            ++_size;
        }

        else if (index == _size) {
            this->push_back(value);
        }

        else {
            for (size_t i=0; i <= index+1; ++i) {
                if (i == index-1) {
                    new_node->next = current_node->next;
                    current_node->next = new_node;
                    new_node->prev = current_node;
                }
                if (i < _size) {
                    if (i == index+1) {
                        current_node->prev = new_node;
                    break;
                    }
                }
                current_node = current_node->next;
            }
            ++_size;
        }
        
    }


private:
    size_t  _size;
    Node<T>* _last;
    Node<T>* _first;
};
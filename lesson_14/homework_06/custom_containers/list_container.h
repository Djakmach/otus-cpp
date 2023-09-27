template<typename T>
struct Node {
    Node* next;
    Node* prev;
    T value;
};


template<typename T>
class ListContainer {
public:
    ListContainer() : _size{0}, _first{nullptr}, _last{nullptr} {
    }


    // TODO возможно ли реализовать конструктор 
    // ListContainer(args) {
    //     for arg in *args:
    //         this.push_back(arg)
    // }


    void push_back(const T& value) {
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
        if (index < 0 || index >= _size) {
            return -1;
        }
        Node<T>* current_node = _first;
        for (size_t i=0; i < index; ++i) {
            current_node = current_node->next;
        }
        return current_node->value;
    }

    void print() const{
        Node<T>* current_node = _first;

        std::cout << "[";
        for (size_t i=0; i < _size; ++i) {
            std::cout << current_node->value;
            // std::cout << current_node->value << ": " << current_node << "\tprev: " << current_node->prev << "\tnext: " << current_node->next << '\n';
            if (i < _size - 1) std::cout << ", "; 
            current_node = current_node->next;
        }
        std::cout << "]\n";
    }

    size_t get_size() const {
        return _size;
    }

    Node<T>* search_node_by_index(const size_t index) {
        Node<T>* current_node = _first;
        for (size_t i = 0; i < index; ++i) current_node = current_node->next;
        return current_node;
    }


    void insert(size_t index, T value) {
        Node<T>* current_node = _first;
        Node<T>* new_node = new Node<T>;
        new_node->value = value;

        if (_size == 0) {
            _first = new_node;
            _last = new_node;
            new_node->prev = nullptr;
            new_node->next = nullptr;
            ++_size;
        }
        else if (index == 0) {
            new_node->prev = nullptr;
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

    void erase(size_t index) {
        if (index < 0 || index >= _size) {
            return;
        }

        if (index == 0) {
            Node<T>* second_node = _first->next;
            delete _first;
            _first = second_node;
            _first->prev = nullptr;
        }
        else if (index == _size - 1) {
            Node<T>* penultimate_node = _last->prev;
            delete _last;
            _last = penultimate_node;
            _last->next = nullptr;
        } else {
            Node<T>* current_node = search_node_by_index(index);
            if (current_node->next) current_node->prev->next = current_node->next;
            if (current_node->prev) current_node->next->prev = current_node->prev;
            delete current_node;
        }
        --_size;
    }

    T operator[](const size_t index) {
        return this->get_value(index);
    }

    const T& operator[](const size_t index) const {
        return this->get_value(index);
    }

    ~ListContainer() {
        while (_first) {
            auto next = _first->next;
            // std::cout << _first << '\n';
            delete _first;
            _first = next;
        }
    }

private:
    size_t  _size;
    Node<T>* _last;
    Node<T>* _first;
};

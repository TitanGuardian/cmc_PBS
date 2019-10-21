#include <memory>
#include <iostream>
class A {
  public:
    // ...
    
    static void * operator new(size_t size) {
        std::cout << "operator new!" << std::endl;
        return ::operator new(size);
    }
    static void operator delete(void *p, size_t size) {
        std::cout << "operator delete!" << std::endl;
        return ::operator delete(p);
    }
};

template <typename T>
struct Allocator {
    typedef T value_type;

    Allocator() noexcept {}
    template <class U> Allocator (const Allocator<U>&) noexcept {}
    
    T* allocate (std::size_t n) {
        return static_cast<T*>( A::operator new(n*sizeof(T)));
    }
    void deallocate (T* p, std::size_t n) {
        A::operator delete(p, n);
    }
};
template <class T, class U>
bool operator==(const Allocator<T>&, const Allocator<U>&) { return true; }
template <class T, class U>
bool operator!=(const Allocator<T>&, const Allocator<U>&) { return false; }


int main() {
    auto sp = std::allocate_shared<A>(Allocator<A>());
}
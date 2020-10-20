
#include <string>
#include <cstddef>
#include <limits>

#include <iostream>


namespace cv
{
    template <class T>
    class SpecialAlloc  
    {
        public:
        //type definitions
        typedef size_t size_type;
        typedef ptrdiff_t difference_type;
        typedef T* pointer;
        typedef const T* const_pointer;
        typedef T& reference;
        typedef const T& const_reference;
        typedef T value_type;

        //rebind allocator to type U
        template <class U>
        struct rebind {
            typedef SpecialAlloc<U> other;
        };

        //return address of values
        pointer address(reference value) const { return &value; }
        const_pointer address(const_reference value) const { return &value; }
        //constructors and destructor
        SpecialAlloc() throw() {}
        SpecialAlloc(const SpecialAlloc&) throw() {}
        template <class U> SpecialAlloc(const SpecialAlloc<U>&) throw() {}
        ~SpecialAlloc() throw() {}
        //return maximum number of elements that can be allocated
        size_type max_size() const throw()
        {
            return std::numeric_limits<size_t>::max()/ sizeof(T);
        }
    
        // allocate but don't initialize num elements of type T
        pointer allocate(size_type num, SpecialAlloc::const_pointer hint = 0)
        {
            return (pointer) ::operator new(num*sizeof(T));
        }
        // initialize elements of allocated storage p with value value
        void construct(pointer p, const T& value)
        {
            new((void*)p) T (value);
        }
        // delete elements of initialized storage p
        void destroy(pointer p)
        {
            p->~T();
        }
        // deallocate storage p of deleted elements
        void deallocate(pointer p, size_type num)
        {
            ::operator delete((void*)p);
        }


    };
        template <class T1, class T2>
        bool operator == (const SpecialAlloc<T1>&, const SpecialAlloc<T2>&) throw() 
        {
            return true;
        }
        template <class T1, class T2>
        bool operator != (const SpecialAlloc<T1>&, const SpecialAlloc<T2>&) throw() 
        {
            return false;
        }

}

typedef std::basic_string<char, std::char_traits<char>, cv::SpecialAlloc<char> > mstring;

mstring s;

int main()
{
    mstring a = "abcd";
    
    std::cout << a << std::endl;
}

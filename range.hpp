#pragma once

namespace itertools
{//Represents a range of objects.
    template <typename T>
    class range
    {
        private:
        T _start;
        T _end;

        public:
       ~range(){}
        range(T _sta, T _finish) : _start(_sta), _end(_finish) 
	{//It can be assumed that
	}


        class iterator
        {
            private:
            T data;

            public:
            iterator(T ptr) : data(ptr) {

            }

            T operator*() const {
			    return data;
            }

            iterator& operator++() {
                ++data;
			    return *this;
            }

		    bool operator==(const iterator& rhs) const {
			    return (data == rhs.data);
		    }

		    bool operator!=(const iterator& rhs) const {
			    return (data != rhs.data);
            }
        };

        public:

        iterator begin() {
		    return iterator(_start);
	    }
	
	    iterator end() {
		    return iterator(_end);
        }

    };
}

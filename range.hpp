#pragma once

namespace itertools
{//Represents a range of objects.
    template <typename T>
    class range
    {
        private:
        T bigenN;
        T endD;

        public:
       ~range(){}
        range(T _bigen, T _end) : bigenN(_bigen), endD(_end) 
	{//It can be assumed that
	}


        class iterator
        {
            private:
            T index;

            public:
            iterator(T temp) : index(temp)
	    {
            }

            T operator*() const
	    {
	      return index;
            }

            iterator& operator++()
	    {
              ++index;
	      return *this;
            }

            bool operator!=(const iterator& our) const
	    {
	       return (index != our.index);
            }
		
	    bool operator==(const iterator& our) const
	    {
	       return (index == our.index);
	    }
        };

        public:

        iterator begin() 
	{
	   return iterator(bigenN);
        }
	
	iterator end()
	{
	   return iterator(endD);
        }
    };
}

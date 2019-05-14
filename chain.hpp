#pragma once

#import "range.hpp"

namespace itertools
{
	
	  template<typename T1, typename T2>
   	class chain
    {//Represents a concatenation of two iterable.
        private:
	    	T1 a;
	    	T2 b;
      	public:
	     	chain<T1,T2>( T1 x,  T2 y) //x:first iterable , y:secound iterable
		   	: a(x),
			  b(y) {}
        
   

	 	class iterator
    {

			public: 
				 iterator(typename T1::iterator xStart, typename T1::iterator xStop, typename T2::iterator yStart,typename T2::iterator yStop):
				 x1Start(xStart), x1Stop(xStop),
         y2Start(yStart), y2Stop(yStop) {}
 				 auto operator*() const
         {
					if (x1Start!=x1Stop)
						return *x1Start;
					else return *y2Start;
  			 }

				 iterator& operator++()
         {
					if(x1Start!=x1Stop)
						++x1Start;
					else
						++y2Start;
					return *this;	
				}

				const iterator operator++(int)
        {
					iterator _cd(*this);
					operator++();
					return _cd;
				}

				bool operator==(const iterator& other) const
        {
					if(x1Start==other.x1Start) 
						if(y2Start==other.y2Start)
							return true;
					return false;
				}

				bool operator!=(const iterator& other) const
        {
					if(*this==other)
						return false;
					return true;
				}

        private:
				typename T1::iterator x1Start;
				typename T1::iterator x1Stop;
				typename T2::iterator y2Start;
        typename T2::iterator y2Stop;
		};




         typename chain<T1,T2>::  iterator begin()
         {
		   	 return chain<T1,T2>::iterator(a.begin(), a.end(), b.begin());
	       }
			
    		typename chain<T1,T2>::  iterator end()
        {
			  return chain<T1,T2>::iterator(a.end(), a.end(), b.end());
	      }

	};


}

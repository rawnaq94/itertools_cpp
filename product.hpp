#pragma once

namespace itertools
{

	template<typename T1, typename T2> class product
  {//Represents a cartesian product of two iterable

		public:
			product<T1,T2>(const T1 x, const T2 y) : a(x) , b(y){}
		private:
			T1 a;
			T2 b;
		
    
    class iterator {

			public:
				iterator(typename T1::iterator tIt, typename T1::iterator tIy2Stop, typename T2::iterator sIt, typename T2::iterator sIy2Stop):
					x1Start(tIt), y2Stop(tIy2Stop),
					sStart(sIt), y2Start(sIt), sStop(sIy2Stop)
				 {}

				auto operator*() const
        {
					ostringstream stream;
					stream<<*x1Start<<","<<*y2Start;
					return stream.str();
				}

				iterator& operator++()
        {
					++y2Start;
					if (y2Start == sStop)
          {
						++x1Start;
						if (x1Start != y2Stop)
							y2Start = sStart;
					}	
					return *this;
				 }

				const iterator operator++(int)
        {
					iterator Cd(*this);
					operator++();
					return Cd;
				}

      	bool operator!=(const iterator& other) const
        {
					if(*this==other)
						return false;
					return true;
				}
        
				bool operator==(const iterator& other) const
        {
					if (x1Start == other.x1Start)
						if(y2Start == other.y2Start)
							return true;
					return false;
				}

			
      private:
				typename T1::iterator x1Start;
        typename T2::iterator y2Start;
				typename T1::iterator y2Stop;
				typename T2::iterator sStart;
				typename T2::iterator sStop;
		};
		
		typename product<T1,T2>::iterator begin()
    {
			return product<T1,T2>::iterator(a.begin(), a.end(),b.begin(),b.end());
		}
			
		typename product<T1,T2>::iterator end() 
    {
			return product<T1,T2>::iterator(a.end(), a.end(),b.end(),b.end());
		}

	}; 

}

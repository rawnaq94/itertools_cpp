#include <iostream>
#include "range.hpp"
#include "chain.hpp"
#include "zip.hpp"
#include "product.hpp"
#include "powerset.hpp"
#include "badkan.hpp"
using namespace std;
using namespace itertools;

int main() {

        template<typename Iterable>
        string iterable_to_string(const Iterable& iterable)
        {
         ostringstream ostream ;
         badkan::TestCase testcase;
       	 int grade=0;
	       int signal = setjmp(badkan::longjmp_buffer);
	       if (signal == 0) {
         ostringstream ostream ;
		     testcase.setname("range-test");
		     for(int i : range(5,9))
         {
             if(i<8)
		           ostream << i<<',' ; 
             else
               ostream << i ; 
         }
		
    
         testcase.CHECK_OUTPUT(ostream.str(),"5,6,7,8") ; 
		     ostream.str("") ;
         for(double i : range(6.6,7.6))
                   ostream << i;

        testcase.CHECK_OUTPUT(ostream.str(),"6.6");
	
  
  
  
  
  
  
  
	     	grade = testcase.grade();
      	} else {
	    	testcase.print_signal(signal);
	    	grade = 0;
        }
	     if(grade>95)
      cout<< "Your grade is: "<<grade<<" great! :-)"<<endl;
   	  else
	    cout << "Your grade is: "  << grade << endl;
	    return 0;
}

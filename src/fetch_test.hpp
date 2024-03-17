#pragma once 

namespace fetch_test
{
	void fetch_fun();
	
#ifdef BUILD_A
	void fun_a();	
#endif

#ifdef BUILD_B
	void fun_b();
#endif 
}

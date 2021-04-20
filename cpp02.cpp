#include <iostream>

#include "DataStructures.h"
#ifndef  IOSTREAM
#include <iostream>
#endif
#include <stdlib.h>
#include <time.h>

void Test()
{
	srand(time(0));
    Stack st(15);
    for(int i=0;i<25;i++)
    {
        st.Push(rand()%100);
    }
    st.Print();
}

int main(void)
{
	Test();
	return 0;
}
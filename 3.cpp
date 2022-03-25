#include <ctime>
#include <iostream>
using namespace std;

int  main()
{
    srand(time(0));
    long long size1;
    cout << "Enter size value: ";
    cin >> size1;

    long long *array1 = new long long[size1]; 
    cout<<"array1: ";
    for (int i = 0; i < size1; i++) 
    {
          array1[i] = rand() % 10;
	cout<<array1[i]<<" ";
    }

    long long size2;
    cout << "\n\nEnter size2 value: ";
    cin >> size2; 

    long long *array2 = new long long[size2]; 
	cout<<"array2: ";
    for (int  i = 0; i < size2; i++)
    {
        array2[i] = rand() % 10;
	cout<<array2[i]<<" ";
    }


    long long size3 = size1 + size2;
    long long *array3 = new long long[size3]; 


    long long* ptr_array1 = &array1[0]; 
    long long* end_array1 = &array1[size1]; 
    long long* ptr_array2 = &array2[0];
    long long* ptr_array3 = &array3[0];
    long long* end_array3 = &array3[size3-1]; 
	asm( 
        "mov %[ptr_array1], %%rax\n\t"  
        "mov %[ptr_array2], %%rbx\n\t"  
        "mov %[ptr_array3], %%rcx\n\t"  
        "mov (%%rax), %%rdx\n\t"        


 
	"start1:\n\t" // функция 
	"push (%%rax)\n\t"          
        "pop (%%rcx)\n\t"           
        "cmp %%rax, %[end_array1]\n\t" 
        "je start2\n\t"                
        "jmp next_element1\n\t"            





        "next_element1:\n\t" 
        "add $8, %%rax\n\t"        
        "add $8, %%rcx\n\t"         
        "mov (%%rax), %%rdx\n\t"    
	"jmp start1\n\t"


	"start2:\n\t"
        "push (%%rbx)\n\t"          
        "pop (%%rcx)\n\t"           
        "cmp %%rbx, %[end_array3]\n\t" 
        "je end\n\t"                
        "jmp next_element2\n\t"            


        "next_element2:\n\t"
        "add $8, %%rbx\n\t"         
        "add $8, %%rcx\n\t"         
        "mov (%%rax), %%rdx\n\t"    
        "jmp start2\n\t"
        "end:\n\t"
        :
    : [ptr_array1] "m"(ptr_array1), [ptr_array2]"m"(ptr_array2), [ptr_array3]"m"(ptr_array3), [end_array1]"m"(end_array1), [end_array3]"m"(end_array3) 

        : "%rax", "%rbx", "%rcx", "%rdx"
        );

    cout<<"\n\narr3: ";
    for (int  i = 0; i < size3; i++) {
        cout<<array3[i]<<" ";
    }
    cout<<"\n";

    delete [] array1; 
    delete [] array2; 
    delete [] array3; 
    return 0;
}

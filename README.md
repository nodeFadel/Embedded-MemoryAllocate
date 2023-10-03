# Embedded-MemoryAllocate
How to allocate memory statically and dynamically to reserve memory.

## Allocating memory for calloc and then adjuct the allocation with more memory using the realloc allocation.
    - In calloc good to understand what are the parameters used to reach the right allocation. 
        Ex: calloc(3,sizeof(int))
        where the calloc should receive the number of units to be allocated.
        And the size that can be intialize dynamically by mentioning the typre of the variable used throughout the allocation.

    - In realloc the allocation fiffere where the parameters Ex: realloc(pointer,5*sizeof(int));
    are the pointer for the allocated memory and the type of variables that should use in those allocated memory.


## Allocating memory for malloc and realloc as well.
    - In malloc the allocation differ Ex:  malloc(numberOfunits*sizeof(customer));
    Where the number of units that are going to be allocate in the memory multiplied by the types of used variables in allocation,
    the it will reserve the right dynamicall memory to that number of units mentioned.

    - The realloc is the same used here again but with the malloc instead of alloc.
        Then the allocation memory have been adjust to meet the relevant number of memory allocation.

## The linkedlist is very crucial upon many other aspects.
    ### LinkedList:
        - Create node Linked list.
        - Add node to the head.
        - Find node containing.
        - Delete node from position.
        - Delete the head.
        - Delete node with Data.
        - Reverse all the linked list.
    
    While running the exe file which is under the linked list folder, when it displayed on the screen 
    it is clear how the linked list running in two different order so the reverse actually applied as expected.
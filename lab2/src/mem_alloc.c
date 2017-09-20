#include "mem_alloc.h"
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

#include "mem_alloc_types.h"

/* memory */
char memory[MEMORY_SIZE];

/* Pointer to the first free block in the memory */
mem_bfree_t *first_free; 


#define ULONG(x)((long unsigned int)(x))
#define max(x,y) (x>y?x:y)

#if defined(FIRST_FIT)

/* code specific to first fit strategy can be inserted here */

#elif defined(BEST_FIT)

/* code specific to best fit strategy can be inserted here */

#elif defined(WORST_FIT)

/* code specific to worst fit strategy can be inserted here */

#endif

void run_at_exit(void)
{
    /* function called when the programs exits */
    /* To be used to display memory leaks informations */
    
    /* ... */
}



void memory_init(void){

    /* register the function that will be called when the programs exits*/
    atexit(run_at_exit);

    /* Initialize the list of free blocks with a single free block corresponding to the full array */
    mem_bfree_t first_header;
    first_header.prev = NULL;
    first_header.next = NULL; 
    first_header.block_size = MEMORY_SIZE;
    *(mem_bfree_t*) memory = first_header;
    first_free = (mem_bfree_t*) memory;
}

char *memory_alloc(int size){
    
    /* Warning: do not forget to call print_alloc_info() or
       print_alloc_error() */
    //int size_total = size + sizeof(mem_bfree_t);
    //while(first_free){

    //}

    
    /* .... */

    return NULL; /* to be modified */
}

void memory_free(char *p){

    /* Warning: do not forget to call print_free_info() */
    
    /* ... */
    
}

void memory_display_state(void){

    /* ... */

    printf("yyy");
    
}


void print_alloc_info(char *addr, int size){
    fprintf(stderr, "ALLOC at : %lu (%d byte(s))\n", 
            ULONG(addr - memory), size);
}


void print_free_info(char *addr){
    fprintf(stderr, "FREE  at : %lu \n", ULONG(addr - memory));
}

void print_alloc_error(int size) 
{
    fprintf(stderr, "ALLOC error : can't allocate %d bytes\n", size);
}

void print_info(void) {
  fprintf(stderr, "Memory : [%lu %lu] (%lu bytes)\n", (long unsigned int) memory, (long unsigned int) (memory+MEMORY_SIZE), (long unsigned int) (MEMORY_SIZE));
}



#ifdef MAIN
int main(int argc, char **argv){

  /* The main can be changed, it is *not* involved in tests */
  memory_init();
  print_info();
  int i ; 
  for( i = 0; i < 10; i++){
    char *b = memory_alloc(rand()%8);
    memory_free(b);
  }

  char * a = memory_alloc(15); 
  memory_free(a);


  a = memory_alloc(10);
  memory_free(a);

  fprintf(stderr,"%lu\n",(long unsigned int) (memory_alloc(9)));
  return EXIT_SUCCESS;
}
#endif 

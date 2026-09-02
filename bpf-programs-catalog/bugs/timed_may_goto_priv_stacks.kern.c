#include "bpf_experimental.h"

#define SIZE_OF_STACK 208
#define MAX_ENTRIES	10000

SEC("fentry/__sys_socket")
int trigger_syscall_prog(void *ctx) {
		
	 unsigned char stack_space[SIZE_OF_STACK] = {0};
    
	/* 8 byte */
    unsigned long int i = 0;
    bpf_printk("value of i: %d, address of stack_space[i]: %llu\n", i,(unsigned long long) &stack_space[i]);

    for(i = 0; i < SIZE_OF_STACK; i++) {
        stack_space[i] = i % 255;
    }   

    bpf_printk("value of i: %d, address of stack_space[i]: %llu\n", i,(unsigned long long) &stack_space[i]);

	int j = 0;
	for (;can_loop;) {
		j++;                 
	}
	bpf_printk("%d\n", j);
	
    return 0;

}

char LISENSE[] SEC("license") = "Dual BSD/GPL";


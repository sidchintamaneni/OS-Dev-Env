#include "bpf_experimental.h"

SEC("fentry/__sys_socket")
int trigger_syscall_prog(void *ctx) {
		
	int j = 0;
	for (;can_loop;) {
		j++;                 
	}
	bpf_printk("%d\n", j);
	
    return 0;

}

char LISENSE[] SEC("license") = "Dual BSD/GPL";


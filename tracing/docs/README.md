# is there a requirement for new tracing tool?

This project started with a simple thoughts whether if I can trace a program or
process from userspace till the kernel.

trace I mean
- The ability to get all the functions that were being called
- The ability to stop the programs execution in the middle of the function and
  read the systems state

I kind of know that we can acheive this functionality to with multiple tools
like ftrace, bpftrace, gdb (maybe with some hacks), uprobes and things like
that but I guess there is no unified tool to do that.

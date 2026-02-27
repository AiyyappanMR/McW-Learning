    # Day 2 - 19/02/26

    ## Linux Commands

    Started my Ubuntu VM setup in VirtualBox and practiced essential Linux commands: `ls`, `cd`, `pwd`, `cp`, `rm`, `mkdir`, `rmdir`, `touch`, `nano`, `cat`, `echo`, `less`, and `more`.

    **Key command syntax:**
    - `cd ..` - navigate to parent directory
    - `cd /` - navigate to root directory
    - `cp hello hellocopy` - copy and rename file in same directory
    - `cp hello /home/ubuntu/Desktop` - copy file to another directory
    - `rm -r test` - remove directory with contents
    - `cat file.txt` - view file contents
    - `cat > file.txt` - write to file
    - `echo 'hi' >> file.txt` - append content to file
    - `echo 'hi' > file.txt` - overwrite file content

    ## Makefile

    Learned about Makefiles and when to use them. Built a mini project using OOP (Student Course Mark Enrollment) with separate `.h` header files and `.cpp` implementation files. Compared manual compilation with Makefile-based compilation.

    ## Memory Leak & Valgrind

    Explored memory leaks and used Valgrind to identify and resolve memory management issues in code. Learned that memory leaks occur when dynamically allocated memory isn't properly freed, causing memory waste.

    **Key concepts and syntax:**
    - `new` - allocate memory on heap
    - `delete` - free single allocated object
    - `delete[]` - free dynamically allocated array
    - `valgrind --leak-check=full ./program` - run Valgrind to detect memory leaks
    - Valgrind output shows "definitely lost", "indirectly lost", and "possibly lost" memory
    - Always pair `new` with `delete` to prevent leaks

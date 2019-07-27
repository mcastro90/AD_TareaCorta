HowTo:;

Generate executable and shared library:
- cd /homework1/PartII
- bash setup.sh (or ./setup.sh)

This will execute autotools and generate everything required. The binary and
shared library will be placed in ./build/[bin, lib]

To execute the binary, you should execute from project root directory

- cd homework1/PartII
- ./setup.sh
- ./build/bin/memcheck

And it will display the usage, like the following one:

Usage: memcheck [OPTIONS]
  or:  memcheck [OPTIONS] PROGRAM

Mandatory arguments to long options are mandatory for short options too.
  -a, --author                Displays author information
  -h, --help                  Displays this message
  -p, --program               Run memcheck for given binary

To execute using an external binary:

- ./build/bin/memcheck ../PartI/case4/case4

And the output should be like the following one:

$ ./build/bin/memcheck -p ../PartI/case4/case4
96 36
All done! :)
Analysis finished!
Memory allocations: 101 
Memory free: 40 
Total memory leaks found: 61 

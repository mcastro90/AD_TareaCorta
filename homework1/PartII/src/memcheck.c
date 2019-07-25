#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

void print_usage();
void print_authors();

int main(int argc, char *argv[])
{
    int opt= 0;
    int area = -1, perimeter = -1, breadth = -1, length =-1;
    char *program;

    static struct option long_options[] = {
        {"author",    no_argument,       0,  'a' },
        {"help",      no_argument,       0,  'h' },
        {"program",   required_argument, 0,  'p' },
        {0,           0,                 0,   0  }
    };

    if (argc < 2) {
        print_usage();
        return -1;
    }

    int long_index =0;
    while ((opt = getopt_long(argc, argv,"ahp:", long_options, &long_index))
            != -1) {
        switch (opt) {
             case 'a' :
                 print_authors();
                 break;
             case 'h' :
                 print_usage();
                 break;
             case 'p' :
                 program = optarg;
                 break;
             default: print_usage();
                 exit(EXIT_FAILURE);
        }
    }

    if (program) {
        printf("Program stored: %s\n", program);
    }
    return 0;
}

void print_usage() {
    printf(
"Usage: memcheck [OPTIONS]\n"
"  or:  memcheck [OPTIONS] PROGRAM\n\n"
"Mandatory arguments to long options are mandatory for short options too.\n"
"  -a, --author                Displays author information\n"
"  -h, --help                  Displays this message\n"
"  -p, --program               Run memcheck for given binary\n");
}

void print_authors() {
    printf(
"ITCR - Maestría en Electrónica, II Cuatrimestre 2019\n"
"High Performance Embedded Systems\n"
"Mario Castro\nÓscar Dengo\nAlejandro Rodríguez\n");
}

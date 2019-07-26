#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <errno.h>
#include <sys/wait.h>

void print_usage();
void print_authors();
int process_program(char *program, char *argv[]);

char *environ = "LD_PRELOAD=./build/lib/libmemcheck.so\0";

int main(int argc, char *argv[])
{
    int opt= 0;
    int long_index =0;
    char *program;

    static struct option long_options[] = {
        {"author",    no_argument,       0,  'a' },
        {"help",      no_argument,       0,  'h' },
        {"program",   required_argument, 0,  'p' },
        {0,           0,                 0,   0  }
    };

    opt = getopt_long(argc, argv,"ahp:", long_options, &long_index);

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
        case '?':
        default: print_usage();
             exit(EXIT_FAILURE);
    }

    if (program) {
        return process_program(program, argv);
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

int process_program(char *program, char *argv[])
{
    pid_t process;

    process = fork();

    if (process < 0) {
        perror("fork");
        return 2;
    }

    if (process == 0) {
        argv[0] = program;
        execve(argv[0], argv, &environ);
        return 2;
    }

    int status;
    pid_t wait_result;

    while ((wait_result = wait(&status)) != -1);

    return 0;
}

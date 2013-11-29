/* Copyright 2013 goodyoga all rights reserved. */

#include <stdio.h>    /* printf */
#include <stdlib.h>   /* atoi,exit   */
#include <unistd.h>   /* getopt */

int check_and_add(int n, int sum);
void usage(void);
char *prog;

//
// @startuml
// participant defaults
// participant n
// participant sum
// 
// note over defaults,sum:  [Problem 2] Even Fibonacci numbers
// 
// break h option
// defaults->defaults: PRINT(usage)
// defaults->defaults: exit(EXIT_SUCCESS)
// end
// defaults->defaults: not_exceed = 4000000
// opt n option
// defaults->defaults: not_exceed = value by cmdline
// end
// 
// n->n: n2 = 1 : prev.prev
// n->n: n1 = 2 : prev
// alt even number
// n->sum: sum = sum + n2
// else odd number
// note over n,sum: skip
// end 
// alt even number
// n->sum: sum = sum + n1
// else odd number
// note over n,sum: skip
// end 
// 
// 
// loop
// n -> n: n = n1 + n2
// break n > not_exceed
// note over n,sum: end
// end
// 
// alt even number
// n->sum: sum = sum + n
// else odd number
// note over n,sum: skip
// end 
// n->n: n_2 = n_1;
// n->n: n_1 = n;
// end loop
// @enduml
//

int main(int argc __attribute__((unused)), char **argv)
{
    int not_exceed = 4000000;
    int n,n_1 = 2, n_2 = 1;
    int sum = 0;
    int opt;

    prog = argv[0];

    while ( -1 != (opt = getopt(argc, argv, "hn:")) )
    {
        if('h' == opt)
        {
            usage();
            exit(EXIT_SUCCESS);
        }
        else if ('n' == opt)
        {
            not_exceed = atoi(optarg);
        }
    }

    sum = check_and_add(n_2, sum);
    sum = check_and_add(n_1, sum);

    while ( 1 )
    {
        n = n_2 + n_1;
        if ( n > not_exceed )  break;

        sum = check_and_add(n, sum);
        n_2 = n_1;
        n_1 = n;
    }
    return EXIT_SUCCESS;
}

int check_and_add(int n, int sum)
{
    int s = sum;
    if ( !(n % 2) )
    {
        s += n;
        printf("%s: add:%d, sum:%d\n", prog, n, s);
    }
    else
    {
        printf("%s: n:%d, sum:%d\n", prog, n, s);
    }
    return s;
}


void usage(void)
{
    printf("    http://projecteuler.net/problem=2\n");
    printf("    [Problem 2] Even Fibonacci numbers\n");
    printf("    Each new term in the Fibonacci sequence is generated\n"
           "    by adding the previous two terms. By starting \n"
           "    with 1 and 2, the first 10 terms will be:\n\n"
           "        1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...\n\n"
           "    By considering the terms in the Fibonacci sequence whose values \n"
           "    do not exceed four million, find the sum of the even-valued terms.\n");
    printf("    -h: show this help\n"
           "    -n <number>: solve this between 1 and not exceeding <number>\n");
    return;
}

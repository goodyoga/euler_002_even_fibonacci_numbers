/* Copyright 2013 goodyoga all rights reserved. */

#include <stdio.h>    /* printf */
#include <stdlib.h>   /* atoi,exit   */
#include <unistd.h>   /* getopt */

int check_and_add(int n, int sum);
void usage(void);
char *prog;

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

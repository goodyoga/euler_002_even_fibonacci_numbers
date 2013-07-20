/* Copyright 2013 goodyoga all rights reserved. */

#include <stdio.h>    /* printf */
#include <stdlib.h>   /* atoi,exit   */
#include <unistd.h>   /* getopt */

void usage(void);

int main(int argc __attribute__((unused)), char **argv)
{
    int i;
    int sum;
    int opt, not_exceed = 4000000;
    while ( -1 != (opt = getopt(argc, argv, "hn:")) )
    {
        if('h' == opt)
	{
	  usage();
	  exit(EXIT_SUCCESS);
	}
        else if ('b' == opt)
	{
	  below = atoi(optarg);
	}
    }
    for ( i = 1,sum = 0 ; i <= not_exceed ; i++)
    {
        if ( !( i % 3 ) || !( i % 5 ) )
        {
            sum += i;
            printf("%s: add:%d, sum:%d\n", argv[0], i, sum);
        }
    }
    return EXIT_SUCCESS;
}


void usage(void)
{
    printf("    http://projecteuler.net/problem=2\n");
    printf("    [Problem 1] Even Fibonacci numbers\n");
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

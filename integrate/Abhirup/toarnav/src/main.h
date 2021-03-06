#include<stdio.h>
#include "huff.h"
#include<string.h>
#define MAX 60

long int filesize(FILE *fp)
{
	fseek(fp, 0L, SEEK_END); 

    // calculating the size of the file 
    long int res = ftell(fp);
	return res;
}

long int dohuffman(char option)
{	
    FILE *in, *out;
	
	
	if(option == 'c')
	{
		char *infilename = "/home/dev/Documents/toarnav/src/tex.txt";	
		char *outfilename = "/home/dev/Documents/toarnav/src/com.txt";
		if(!(in = fopen(infilename, "rb"))) 
	{
		perror("ERRROR opening input file");
		return -1;
	}

	if(!(out = fopen(outfilename, "wb")))
	{
		perror("ERROR opening output file");
		return -1;
	}
	}

	if(option == 'd')
	{
		char *infilename = "/home/dev/Documents/toarnav/src/com.txt";	
		char *outfilename = "/home/dev/Documents/toarnav/src/decom.txt";
		if(!(in = fopen(infilename, "rb"))) 
	{
		perror("ERRROR opening input file");
		return -1;
	}
	if(!(out = fopen(outfilename, "wb")))
	{
		perror("ERROR opening output file");
		return -1;
	}
	}


	if(option == 'c')
		huff_cod(in, out);
	else if(option == 'd')
		huff_dec(in, out);
	else
		printf("Provide option to either compress or decompress! \n");
	
	long int insize = filesize(in);
	long int outsize = filesize(out);
	// if(option == 'c')
	// 	printf("\nFile size of orginal file and compressed file in bytes is:  %li %li", insize, outsize);
	// else if(option == 'd')
	// 	printf("\nFile size of compressed file and decompressed file in bytes is:  %li %li", insize, outsize);
	


	fclose(in);
	fclose(out);
	return insize;
}

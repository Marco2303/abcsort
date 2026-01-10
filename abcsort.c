/*
 * Project: abcsort
 * Author: Marco Tosti
 * Copyright (c) 2026 Marco Tosti
 *
 * BSD 3-Clause License
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 1. Redistributions of source code must retain this notice.
 * 2. Redistributions in binary form must reproduce this notice.
 * 3. Neither the name of the author nor the project name may be used to
 *    endorse or promote products derived from this software without
 *    specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS", WITHOUT ANY WARRANTY OF ANY KIND.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DAMAGES ARISING FROM
 * THE USE OF THIS SOFTWARE.
 */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "define.h"

int __flags = 0;


/* ========================= Init struct ======================== */

	
init_parameters init_par = {	
	.filenamein = NULL,
    	.filenameout = NULL,
    	.total_number_row = 0
};


/* ===================== Object definition ====================== */

//memory allocation definition
void *xmalloc(size_t len){
    void *prt = malloc(len);
    if (prt == NULL){
        fprintf(stderr, "malloc error\n");
        exit (1);
    }
    return prt;
}

void *xrealloc(readfile *read, size_t len){
    readfile *__temp = realloc(read, len);
    if (__temp == NULL){
        fprintf(stderr, "Realloc memory error\n");
    }
    return __temp;
}


/* ====================== Input parser ========================== */


/* for verify that essential parameters is ok */ 
void flags_control(void){
   /* test name of the ouput file and assign default
   *  name if not found pram -o*/
   if (!(__flags & USE_PARAM_O)){
        printf("Out filename out.txt\n");
        init_par.filenameout = "out.txt";
    }
    if (__flags & USE_PARAM_B){
        printf("Bouble sort ascending MIN to MAX\n");
    }
    else if (__flags & USE_PARAM_C){
        printf("Bouble sort descending MAX to MIN\n");
    }
}
//
//routin for set input parameters
//
void parser_param(char **input_param, int len){
	int __count = 0; 
	while (__count < len){
		char *param = input_param[__count];
		if (param[0] == '-'){
			switch(param[1]){
				case INPUT_PARAM_I:
					if (__count+1 <= len){ 
						init_par.filenamein = input_param[__count+1];
                        __flags |= USE_PARAM_I;
						if (init_par.filenamein[0] == '-'){
							printf("File %s not found \n",init_par.filenamein);
							exit(1);
						}else{
							printf("Found input file %s\n",init_par.filenamein);
						}
					}else{printf("Insufficient parameters\n");}
					break;
				case INPUT_PARAM_O:
					if (__count+1 <= len){ 
						init_par.filenameout = input_param[__count+1];
                         __flags |= USE_PARAM_O;
						if (init_par.filenameout[0] == '-'){
							printf("File out error\n");
							exit(1);
						}else{
							printf("Create file %s\n",init_par.filenameout);
						}
					}else{printf("Insufficient parameters\n");}
					break;
				case INPUT_PARAM_B:
                    {
                        __flags |= USE_PARAM_B;
                        flags_control();
					    readfile *records = read_file();
					    bubble_sort(records, __flags);
                        save_file(records);
					    break;
                    }
				case INPUT_PARAM_C:
                    {
                        __flags |= USE_PARAM_C;
                        flags_control();
					    readfile *records = read_file();
					    bubble_sort(records, __flags);
                        save_file(records);
					    break;
                    }
			}
		}
		__count++;
	}
}

/* ============================ main =========================== */


int main(int argc, char **argv){
 
	if ( argc > 1 ){
		parser_param(argv, argc);
	}else{
        help();
	}
	return 0;
}

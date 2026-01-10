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


//extern init_parameters init_par;

/* ==================== Imput/output file  ======================= */

readfile *read_file(void){
	
    char __buffer[1024];
	size_t __capacity = 2;
	
    FILE *__fp = fopen(init_par.filenamein, "r");
	if (__fp == NULL){
		printf("File input %s not fount\n", init_par.filenamein);
		exit(1);
	}
	
	readfile *__read = xmalloc(sizeof(readfile)*__capacity);

	while (fgets(__buffer,sizeof(__buffer),__fp) != NULL){
		//printf("buffer %s",buffer);
		if (init_par.total_number_row == __capacity){	// increments 
			__capacity *= 2;
			readfile *__tmp = xrealloc(__read, sizeof(readfile)*__capacity);
			__read = __tmp;
		}

		strcpy(__read[init_par.total_number_row].line, __buffer);

		init_par.total_number_row++;
	}
       	fclose(__fp);

    return __read;	
}

void save_file(readfile *records){
    
    FILE *fp = fopen(init_par.filenameout, "w"); 

    if (fp == NULL){
        fprintf(stderr, "Save file error\n");
        exit(1);
    }
    
    for (size_t i=0; i<init_par.total_number_row; i++){
        fputs( records[i].line, fp );
    }

    fclose(fp);
}


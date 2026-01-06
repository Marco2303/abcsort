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

extern init_parameters init_par;

/* ==================== Bouble sort ======================= */

/* compare record str1 to str2 and change if str1 > str2 */
void compare_records(readfile *records, size_t i, size_t x, int __flags){
    
    int __scmp = strcmp(records[i].line, records[(x)].line); // 4 3 
    if (__flags & USE_PARAM_B){
       if (__scmp > 0){ // ascending
            strcpy(records[i].tmp, records[i].line);
            strcpy(records[i].line, records[x].line);
            strcpy(records[x].line, records[i].tmp);
        }
    }
    else if (__flags & USE_PARAM_C){
         if (__scmp < 0){ //descending   
            strcpy(records[i].tmp, records[i].line);
            strcpy(records[i].line, records[x].line);
            strcpy(records[x].line, records[i].tmp);
        }
    }
}

void bubble_sort(readfile *records, int __flags){
	
    for (size_t i=0; i < init_par.total_number_row; i++){
        for (size_t x = i+1; x < init_par.total_number_row; x++){
            if (i < (init_par.total_number_row-1) ){
                compare_records(records, i, x, __flags);
            }
        }
    }   

    printf("total row number %zu\n",init_par.total_number_row);
}


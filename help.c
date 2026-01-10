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
#include "define.h"

void help(void){
    
    printf("\nabcsort version "VERSION"\n");
    printf("====================\n\n");
    printf("-i name = input file txt name\n");
    printf("-o name = output file name (if absent parm name out.txt)\n");
    printf("-b = bouble sort (ascendent)\n");
    printf("-c = bouble sort (discendent)\n");
}

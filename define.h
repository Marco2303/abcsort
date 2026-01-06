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

#define APP_NAME "abcsort"
#define VERSION "0.0.1"

#define INPUT_PARAM_I 'i'
#define INPUT_PARAM_O 'o'
#define INPUT_PARAM_B 'b'
#define INPUT_PARAM_C 'c'

#define USE_PARAM_I (1 << 1)
#define USE_PARAM_O (1 << 2)
#define USE_PARAM_B (1 << 3)
#define USE_PARAM_C (1 << 4)


typedef struct {
    char *filenamein;
    char *filenameout;
    size_t total_number_row;
} init_parameters;


typedef struct {
    char tmp[1024];
    char line[1024];
} readfile;


/* ===== Bouble definition ===== */
void compare_recordas(readfile *records, size_t i, size_t x, int __flags);
void bubble_sort(readfile *records, int __falgs);

/* ===== Help definition ===== */
void help(void);

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

#ifndef DEFINE_H
#define DEFINE_H

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

extern init_parameters init_par;

typedef struct {
    char tmp[1024];
    char line[1024];
} readfile;

/* ===== abcsort definition ===== */
void *xmalloc(size_t len);
void *xrealloc(readfile *read, size_t len);
void flags_control(void);
void parser_param(char **input_param, int len);

/* ===== Bouble definition ===== */
void compare_recordas(readfile *records, size_t i, size_t x, int __flags);
void bubble_sort(readfile *records, int __falgs);

/* ===== Help definition ===== */
void help(void);

/* ==== Sortio definition ==== */
readfile *read_file(void);
void save_file(readfile *records);

#endif


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define APP_NAME "abcsort"
#define VERSION "0.0.1"

#define INPUT_PARAM_I 'i'
#define INPUT_PARAM_O 'o'
#define INPUT_PARAM_B 'b'

#define USE_PARAM_I (0 << 1)
#define USE_PARAM_O (0 << 2)
#define USE_PARAM_B (0 << 3)

/* ==================== Data struct ======================= */

typedef struct {
    char *filenamein;
    char *filenameout;
    size_t total_number_row;
} init_parameters;

init_parameters init_par;

typedef struct { 	
    char tmp[1024];
    char line[1024];
} readfile;

/* ===================== Object definition ====================== */

//memori allocation definition
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

/* ==================== Imput/potput file  ======================= */

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

/* ==================== Bouble sort ======================= */

/* compare record str1 to str2 and return true if str1 > str2 */
void compare_records(readfile *records, size_t i, size_t x){

    int __scmp = strcmp(records[i].line, records[(x)].line); // 4 3 
    //printf("==================i=====================\n"); 
    //printf("__scmp = %d\n",__scmp);
    if (__scmp > 0){
        strcpy(records[i].tmp, records[i].line);
        strcpy(records[i].line, records[x].line);
        //printf("-str1 = %s - prt1 = %p\n",records[i].line, records[i].line);
        strcpy(records[x].line, records[i].tmp);
        //printf("--str2 = %s - prt2 = %p\n",records[x].line, records[x].line);
    }

     //printf("==================f=====================\n"); 
  
}

void bouble_sort(readfile *records){
	
    for (size_t i=0; i < init_par.total_number_row; i++){
        for (size_t x = i+1; x < init_par.total_number_row; x++){
            if (i < (init_par.total_number_row-1) ){
                compare_records(records, i, x);
            }
        }
    }   

    printf("total row number %zu\n",init_par.total_number_row);
	for (size_t i=0; i<init_par.total_number_row; i++){
		//printf("Output row: %s",records[i].line);
	}
	printf("\n");
}


/* ====================== Input parser ========================== */


/* for verify that all parameters of input is ok */ 
void flags_control(void){
    
    int __flags = 0;

    if (__flags & USE_PARAM_I){
        printf("Not use PARAM_I\n");
    }
    if (!(__flags & USE_PARAM_O)){
        printf("Out filename out.txt\n");
        init_par.filenameout = "out.txt";
    }

   if (__flags & USE_PARAM_B){
        printf("Not use PARAM_b\n");
    }


}

//
//routin for set input param
//
void parser_param(char **input_param, int len){
	int __count = 0;
    int __flags = 0;
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
                    __flags |= USE_PARAM_B;
                    flags_control();
					readfile *records = read_file();
					bouble_sort(records);
                    save_file(records);
					break;
			}
		}
		//printf("%c\n",par[0]);
		__count++;
	}
}

/* ============================ main =========================== */


int main(int argc, char **argv){
 	
	if ( argc > 1 ){
		parser_param(argv, argc);
	}else{
		printf("\tSort - insert param\n");
		printf("\t====================\n");
		printf("\t-i name = input file name\n");
		printf("\t-o name = output file name\n");
		printf("\t-b = bouble sort\n");
	}

	return 0;
}

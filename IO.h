#ifndef __IO_H__
#define __IO_H__

int Atoi(const char *pStr);
void Itoa(int num,char *pStr);
void print(const char *pFormat,...);
//one level pointer to rewrite printf
void print_rewrite(const char *pFormat, ...);
void scan(const char *pFormat,...);
void scan_rewrite(const char *pFormat, ...);
void Input_char(char *pStr);


#endif
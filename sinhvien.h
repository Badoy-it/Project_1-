#ifndef SINHVIEN_H   // chống include 2 lần
#define SINHVIEN_H




#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <direct.h> 
#include <malloc.h>
#include <errno.h>


typedef struct {
	int d, m, y;
} date;

typedef struct {
	char id[16];
	char name[50];
	char sex[8];
	date ngaysinh;
	int tuoi;
	float diem1,diem2,diem3;
	float diemTB;
	char xeploai[10];
	char hocluc[16];
	char malop[16]; 

} Sinhvien;

void nhapsinhvien(Sinhvien *sv);

void insinhvien(const Sinhvien *sv);

void capnhatsinhvien(Sinhvien *sv);

void themsinhvien(Sinhvien **sv , int *n, int *capacity);

void xoadem(char name[]);

void swap(Sinhvien *a, Sinhvien *b);

void tinhtuoi(Sinhvien *sv);

void tinhdiemTB(Sinhvien *sv);

void xeploai(Sinhvien *sv);

void hocluc(Sinhvien *sv);

#endif // SINHVIEN_H
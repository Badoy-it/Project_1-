#ifndef DANHSACH_H   // chống include 2 lần
#define DANHSACH_H

#include "sinhvien.h"

void nhapDSSV(Sinhvien *sv, int n);

void inDSSV(Sinhvien *sv, int n);

float max_diemTB(Sinhvien sv[], int n, char id_max[]);

int min_tuoi(Sinhvien sv[], int n, char id_min[]);

void xuatdssvloaigioi(Sinhvien sv[], int n);

char* tim_svtheoten(Sinhvien sv[], int n, char name[]);

char* tim_svtheoid(Sinhvien sv[], int n, char id[]);

void xoasinhvientheoid(Sinhvien sv[], int *n, char id[]);

void xuatdssvtheolop(Sinhvien sv[], int n, char malop[]);

void sapxepdssvtheodiemTB(Sinhvien *sv, int n);

void sapxepdssvtheoten(Sinhvien *sv, int n);


#endif // DANHSACH_H
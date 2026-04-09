#include "danhsach.h"


void nhapDSSV(Sinhvien *sv ,  int n) {
	for (int i = 0; i < n; i++) {
		printf("Nhap thong tin sinh vien thu %d:\n", i + 1);
		capnhatsinhvien(&sv[i]);
	} 
}

void inDSSV(Sinhvien *sv, int n) {
	for (int i = 0; i < n; i++) {
		insinhvien(&sv[i]);
	} 
}

float max_diemTB(Sinhvien sv[], int n, char id_max[]) {
	float max = sv[0].diemTB;
	for (int i = 1; i < n; i++) {
		if (sv[i].diemTB > max) {
			max = sv[i].diemTB;
			strcpy(id_max, sv[i].id);
		}
	}
	return max;
}

int min_tuoi(Sinhvien sv[], int n, char id_min[]) {
	int min = sv[0].tuoi;
	for (int i = 1; i < n; i++) {
		if (sv[i].tuoi < min) {
			min = sv[i].tuoi;
			strcpy(id_min, sv[i].id);
		}
	}
	return min;
}

void xuatdssvloaigioi(Sinhvien sv[], int n) {
	printf("Danh sach sinh vien xep loai gioi:\n");
	for (int i = 0; i < n; i++) {
		if (strcmp(sv[i].hocluc, "Gioi") == 0) {
			insinhvien(&sv[i]);
		}
	}
}

char* tim_svtheoten(Sinhvien sv[], int n, char name[]) {
	for (int i = 0; i < n; i++) {
		if (strcmp(sv[i].name, name) == 0) {
			printf("Ten sinh vien: %s\n", name);
			return sv[i].id;
		}
	}
	return (char*)"Not found";
}

char* tim_svtheoid(Sinhvien sv[], int n, char id[]) {
	for (int i = 0; i < n; i++) {
		if (strcmp(sv[i].id, id) == 0) {
			printf("Ma sinh vien: %s\n", id);
			return sv[i].name;
		}
	}
	return (char*)"Not found";
}


void xoasinhvientheoid(Sinhvien sv[], int *n, char id[]) {
	int index = -1;
	for (int i = 0; i < *n ; i++) {
		if (strcmp(sv[i].id, id) == 0) {
			index = i;
			break;
		}
	}
	if (index == -1) {
		printf("Khong tim thay sinh vien!\n");
		return;
	}
	memmove(&sv[index], &sv[index + 1], (*n - index - 1) * sizeof(Sinhvien));
	(*n)--;
}



void xuatdssvtheolop(Sinhvien sv[], int n, char malop[]) {
	printf("Danh sach sinh vien lop %s:\n", malop);
	for (int i = 0; i < n; i++) {
		if (strcmp(sv[i].malop, malop) == 0) {
			insinhvien(&sv[i]);
		}
	}
}


void sapxepdssvtheodiemTB(Sinhvien *sv, int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (sv[j].diemTB < sv[j + 1].diemTB) {
				swap(&sv[j], &sv[j + 1]);
			}
		}
	}
}

void sapxepdssvtheoten(Sinhvien *sv, int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (strcmp(sv[j].name, sv[j + 1].name) > 0) {
				swap(&sv[j], &sv[j + 1]);
			}
		}
	}
}
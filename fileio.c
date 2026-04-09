#include "fileio.h"

void xuatvaofile (Sinhvien sv[], int n) {
	char filename[30];
	printf("Nhap ten file de xuat: ");
	fgets(filename, 29, stdin);
	xoadem(filename);
	FILE *f = fopen(filename, "wb");
	if (f == NULL) {
		printf("Khong the mo file!\n");
		return;
	}
	fwrite(&n, sizeof(int), 1, f);
	for (int i = 0; i < n; i++) {
		fwrite(&sv[i], sizeof(Sinhvien), 1, f);
	}
	fclose(f);
}



void nhaptufile (Sinhvien sv[], int *n) {
	char filename[30];
	printf("Nhap ten file de nhap: ");
	fgets(filename, 29, stdin);
	xoadem(filename);
	FILE *f = fopen(filename, "rb");
	if (f == NULL) {
		printf("Khong the mo file!\n");
		return;
	}
	fread(n, sizeof(int), 1, f);
	for (int i = 0; i < *n; i++) {
		fread(&sv[i], sizeof(Sinhvien), 1, f);
	}
	fclose(f);
}
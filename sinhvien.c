#include "sinhvien.h"

const int present_year= 2026;

void nhapsinhvien(Sinhvien *sv) {
	printf("Nhap ma sinh vien: ");
	fgets(sv->id, 15, stdin);
	xoadem(sv->id);
	printf("Nhap ten sinh vien: ");
	fgets(sv->name, 49, stdin);
	xoadem(sv->name);
	printf("Nhap gioi tinh: ");
	fgets(sv->sex, 49, stdin);
	xoadem(sv->sex);
	printf("Nhap ngay sinh (d m y): ");
	scanf("%d %d %d", &(sv->ngaysinh.d), &(sv->ngaysinh.m), &(sv->ngaysinh.y));
	getchar(); // Đọc ký tự newline sau khi nhập ngày sinh
	printf("Nhap lan luot diem mon 1, 2, 3: ");
	scanf("%f %f %f", &(sv->diem1), &(sv->diem2), &(sv->diem3));
	getchar(); // Đọc ký tự newline sau khi nhập điểm
	printf("Nhap ma lop: ");
	fgets(sv->malop, 15, stdin);
	xoadem(sv->malop);
}

void insinhvien(const Sinhvien *sv) {
	printf("Ma sinh vien: %s\n", sv->id);
	printf("Ten sinh vien: %s\n", sv->name);
	printf("Gioi tinh: %s\n", sv->sex);
	printf("Ngay sinh: %d/%d/%d\n", sv->ngaysinh.d, sv->ngaysinh.m, sv->ngaysinh.y);
	printf("Tuoi: %d\n", sv->tuoi);
	printf("Diem mon 1: %.2f\n", sv->diem1);
	printf("Diem mon 2: %.2f\n", sv->diem2);
	printf("Diem mon 3: %.2f\n", sv->diem3);
	printf("Diem trung binh: %.2f\n", sv->diemTB);
	printf("Xep loai: %s\n", sv->xeploai);
	printf("Hoc luc: %s\n", sv->hocluc);
	printf("Ma lop: %s\n", sv->malop);
	printf("\n");
}

void capnhatsinhvien(Sinhvien *sv) {
	nhapsinhvien(sv);
	tinhtuoi(sv);
	tinhdiemTB(sv);
	xeploai(sv);
	hocluc(sv);
}

void themsinhvien(Sinhvien **sv , int *n, int *capacity) {

	if (*n >= *capacity) {
		*capacity *= 2;
		*sv = (Sinhvien*)realloc(*sv, (*capacity) * sizeof(Sinhvien));
	}
	capnhatsinhvien(&((*sv)[*n]));
	(*n)++;

}

void xoadem(char name[]) {
	if (name[strlen(name) - 1] == '\n') {
		name[strlen(name) - 1] = '\0';
	}
}

void swap(Sinhvien *a, Sinhvien *b) {
	Sinhvien temp = *a;
	*a = *b;
	*b = temp;
}





void tinhtuoi(Sinhvien *sv) {
	sv->tuoi = present_year - sv->ngaysinh.y;
}

void tinhdiemTB(Sinhvien *sv) {
	sv->diemTB = (sv->diem1 + sv->diem2 + sv->diem3) / 3;
}

void xeploai(Sinhvien *sv) {
	char A[][10]={"A","B+","B","C+","C","D+","D","F"};
	float diem[] = {9, 8, 7, 6, 5, 4.5, 4};
	int i = 0;
	while (i<7) {
		if (sv->diemTB >= diem[i]) {
			strcpy(sv->xeploai, A[i]);
			break;
		}
		i++;
	}
	if (i == 7) {
		strcpy(sv->xeploai, A[7]);
	}
}

void hocluc(Sinhvien *sv) {
	if (strcmp(sv->xeploai, "A") == 0) {
		strcpy(sv->hocluc, "Xuat sac");
	} else if (strcmp(sv->xeploai, "B+") == 0 || strcmp(sv->xeploai, "B") == 0) {
		strcpy(sv->hocluc, "Gioi");
	} else if (strcmp(sv->xeploai, "C+") == 0 || strcmp(sv->xeploai, "C") == 0) {
		strcpy(sv->hocluc, "Kha");
	} else if (strcmp(sv->xeploai, "D+") == 0 || strcmp(sv->xeploai, "D") == 0) {
		strcpy(sv->hocluc, "Trung binh");
	} else {
		strcpy(sv->hocluc, "Yeu");
	}
}


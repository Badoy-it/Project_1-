#include "sinhvien.h"
#include "danhsach.h"
#include "fileio.h"
#include <stdio.h>





int main() {
char cwd[256];
_getcwd(cwd, sizeof(cwd));
printf("Thu muc hien tai: %s\n", cwd);
Sinhvien *sv = NULL;
int n=0;
int capacity = 10;
sv=(Sinhvien*)malloc(capacity * sizeof(Sinhvien));
char id_max[16];
char id_min[16];

do
{
	printf("1. Nhap danh sach sinh vien\n");
	printf("2. In danh sach sinh vien\n");
	printf("3. Tim sinh vien theo ten\n");
	printf("4. Xoa sinh vien theo ma\n");
	printf("5. Xuat danh sach sinh vien theo lop\n");
	printf("6. Sap xep danh sach sinh vien theo diem trung binh\n");
	printf("7. Sap xep danh sach sinh vien theo ten\n");
	printf("8. Xuat danh sach sinh vien xep loai gioi\n");
	printf("9. Xuat sinh vien co diem trung binh cao nhat\n");
	printf("10. Xuat sinh vien co tuoi nho nhat\n");
	printf("11.Nhap vao file danh sach sinh vien\n");
	printf("12.Xuat ra file danh sach sinh vien\n");
	printf("13. Them sinh vien\n");
	printf("14. Tim sinh vien theo ID\n");
	printf("15. Thoat\n");
	int choice;
	printf("Nhap lua chon: ");
	scanf("%d", &choice);
	getchar(); // Đọc ký tự newline sau khi nhập lựa chọn

	switch (choice)
	{
	case 1:
	{
		printf("Nhap so luong sinh vien: ");
		scanf("%d", &n);
		getchar(); // Đọc ký tự newline sau khi nhập số lượng sinh viên
		if (n > capacity)
		{
			capacity = n;
			sv = (Sinhvien *)realloc(sv, capacity * sizeof(Sinhvien));
		}
		nhapDSSV(sv, n);
		// Nhập danh sách sinh viên
		break;
	}
	case 2:
	{
		inDSSV(sv, n);
		// In danh sách sinh viên
		break;
	}
	case 3:
	{
		char name[50];
		printf("Nhap ten sinh vien can tim: ");
		fgets(name, 49, stdin);
		xoadem(name);
		char *id = tim_svtheoten(sv, n, name);
		if (strcmp(id, "Not found") == 0)
		{
			printf("Khong tim thay sinh vien!\n");
		}
		else
		{
			printf("Ma sinh vien: %s\n", id);
		}
		// Tìm sinh viên theo tên
		break;
	}
	case 4:
	{
		char id_to_delete[16];
		printf("Nhap ma sinh vien can xoa: ");
		fgets(id_to_delete, 15, stdin);
		xoadem(id_to_delete);
		xoasinhvientheoid(sv, &n, id_to_delete);
		// Xóa sinh viên theo mã
		break;
	}
	case 5:
	{
		char malop[16];
		printf("Nhap ma lop can xuat: ");
		fgets(malop, 15, stdin);
		xoadem(malop);
		xuatdssvtheolop(sv, n, malop);
		// Xuất danh sách sinh viên theo lớp
		break;
	}

	case 6:
	{
		sapxepdssvtheodiemTB(sv, n);
		// Sắp xếp danh sách sinh viên theo điểm trung bình
		break;
	}
	case 7:
	{
		sapxepdssvtheoten(sv, n);
		// Sắp xếp danh sách sinh viên theo tên
		break;
	}

	case 8:
	{
		xuatdssvloaigioi(sv, n);
		// Xuất danh sách sinh viên xếp loại giỏi
		break;
	}

	case 9:
	{
		float max = max_diemTB(sv, n , id_max);
		printf("Diem trung binh cao nhat: %.2f\n ID : %s\n", max, id_max);
		// Xuất sinh viên có điểm trung bình cao nhất
		break;
	}

	case 10:
	{
		int min = min_tuoi(sv, n, id_min );
		printf("Tuoi nho nhat: %d\n ID : %s\n", min, id_min);
		// Xuất sinh viên có tuổi nhỏ nhất
		break;
	}

	case 11:
	{

		xuatvaofile(sv, n);
		// Nhập vào file danh sách sinh viên
		break;
	}

	case 12:
	{

		nhaptufile(sv, &n);
		// Xuất ra file danh sách sinh viên
		break;
	}

	case 13:
	{
		themsinhvien(&sv, &n, &capacity);
		// Thêm sinh viên vào danh sách
		break;
	}

	case 14 : 
	{
		printf("Nhap ma sinh vien can tim: ");
		char id_to_find[16];
		fgets(id_to_find, 15, stdin);
		xoadem(id_to_find);
		char *name = tim_svtheoid(sv, n, id_to_find);
		if (strcmp(name, "Not found") == 0)
		{
			printf("Khong tim thay sinh vien!\n");
		}
		else
		{
			printf("Ten sinh vien: %s\n", name);
		}
		break;
	} 

	case 15:
	{
		printf("Thoat chuong trinh.\n");
		free(sv);
		return 0;
	}
	default:
	{
		printf("Lua chon khong hop le. Vui long chon lai.\n");
	}
	} }  while (1);

	

	return 0;
}
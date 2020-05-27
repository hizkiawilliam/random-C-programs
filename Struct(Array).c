#include <stdio.h>
#include <string.h>

struct DaftarNilai {
   	int NPM;
   	char  nama[50];
   	float nilai;
   	char  nilaiHuruf[5];
   	//struct *ptr;
};

/* function declaration */
void printDaftarNilai(struct DaftarNilai mhs);
char *huruf(float nilai);
void add_data();
int data = 0,i;
char nama[5][50] = {"Hizkia","Ican"};
struct DaftarNilai mhs[100];
//struct DaftarNilai nama[0];
int main( ) {
	
   /* DaftarNilai 1 specification */
//   scanf("%d",&var);
//   mhs[0].NPM = var;
//   strcpy( mhs[0].nama, "Hizkia William Eben");
//   mhs[0].nilai = 82.6; 
//   strcpy( mhs[0].nilaiHuruf, huruf(mhs[0].nilai));
//   
//   mhs[1].NPM = 1706042812;
//   strcpy( mhs[1].nama, "Darrell Yonathan");
//   mhs[1].nilai = 78.6; 
//   strcpy( mhs[1].nilaiHuruf, huruf(mhs[1].nilai));
//   
//   mhs[2].NPM = 1706042417;
//   strcpy( mhs[2].nama, "Galih Damar Jati");
//   mhs[2].nilai = 80.2; 
//   strcpy( mhs[2].nilaiHuruf, huruf(mhs[2].nilai));
//   
//   mhs[3].NPM = 1706042853;
//   strcpy( mhs[3].nama, "Ikhsan Firdauz	");
//   mhs[3].nilai = 95.5; 
//   strcpy( mhs[3].nilaiHuruf, huruf(mhs[3].nilai));
   menu();
   /* print mhs[0] info */

   return 0;
}

int menu() {
	printf("Select menu : ");
   	switch(getch())
	    {
	    	case '1':
			    add_data();
			case '2':
				printf( "\nNPM        \tNama Mahasiswa    \tNilai\tNilai Huruf\n\n");
   				for(i=0;i<data;i++)
   				{
   					printDaftarNilai(mhs[i]);
   				}
   				system("pause");
   				menu();
			default:
				printf("\n\t\t\t\tWrong input!");
				printf("\n\t\t\t\t");
    			system("pause");
				menu();	
		}
   return 0;
}

void printDaftarNilai(struct DaftarNilai mhs) {

	printf( "%d\t%s\t%.2f\t%s\n", mhs.NPM, mhs.nama, mhs.nilai, mhs.nilaiHuruf);
}

void add_data()
{
	printf("\nNPM : ");
	scanf("%d",&mhs[data].NPM);
	printf("Nama : ");
    scanf("%s",mhs[data].nama);
    printf("Nilai: ");
    scanf("%f",&mhs[data].nilai);
   	strcpy( mhs[data].nilaiHuruf, huruf(mhs[data].nilai));
   	data += 1;
   	main();
}

char *huruf(float nilai)
{
	if (nilai >= 85)
	{
		return "A";
	}
	else if (nilai >= 80)
	{
		return "A-";
	}
	else if (nilai >= 75)
	{
		return "B+";
	}
	else if (nilai >= 70)
	{
		return "B";
	}
	else if (nilai >= 65)
	{
		return "B-";
	}
	else if (nilai >= 60)
	{
		return "C+";
	}
	else if (nilai >= 55)
	{
		return "C";
	}
	else if (nilai < 55)
	{
		return "D";
	}
	else
	{
		return "None";
	}
}

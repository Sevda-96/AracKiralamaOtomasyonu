#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<stdbool.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct arac_info{
	int plaka;
	char renk[10];
	char model[50];
	int ucret;
    bool  musait;
   
	
};
struct musteri_info{
	int musteri_no;
	char isim[50];
	char soy_isim[50];
	char memleket[50];
	
};
struct kiralama_info{
	int plaka;
	int musteri_no;
	char kiralama_tarih[10];
	char iade_tarihi[10];
	
};
void arac_ekle(){
	struct arac_info arac;
	int b;
	FILE *file=fopen("arac.txt","a");
	printf("Arac plakasini giriniz:");
	scanf("%d",&arac.plaka);
	printf("Arac rengini giriniz:");
	scanf("%s",&arac.renk);
	printf("Arac model giriniz:");
	scanf("%s",&arac.model);
	printf("Arac gunluk ucreti giriniz:");
	scanf("%d",&arac.ucret);
	printf("Arac musaitmi? Musait ise 1 deðil ise 0 giriniz:");
	scanf("%d",&arac.musait);
    fprintf(file,"%d %s %s %d %d \n",arac.plaka,arac.renk,arac.model,arac.ucret,arac.musait);
 printf("Arac basariyla eklendi. \n");
 fclose(file);
 printf("---------------------------\n");

}
void arac_listele(){
	struct arac_info list;
	FILE *file=fopen("arac.txt","r");
	 while (!feof(file))
          {
	 	
	    fscanf(file,"%d %s %s %d %d ",&list.plaka,&list.renk,&list.model,&list.ucret,&list.musait);//veriler dosyadan okunuyor
	    printf("Arac Plaka : %d\n",list.plaka);
        printf("Aracin rengi: %s\n",list.renk);
        printf("Aracin modeli: %s\n",list.model);
        printf("Aracin ucreti: %d\n",list.ucret);
        printf("Aracin musaitligi: %d\n ",list.musait);
        printf("---------------------------\n");
    
 	      }
  
    fclose(file);
    printf("---------------------------\n");
}
void arac_ara(){
	int plaka;
	struct arac_info search;
	printf("Aramak istediginiz aracin plakasini giriniz:");
	scanf("%d",&plaka);
	FILE *file=fopen("arac.txt","r");
	
	 while(!feof(file))
     {
        
               fscanf(file,"%d %s %s %d %d ",&search.plaka,&search.renk,&search.model,&search.ucret,&search.musait);
                if(plaka==search.plaka)
                {
                  printf("Arac Bulundu.\n");
                  printf("Arac Plaka : %d\n",search.plaka);
                  printf("Aracin rengi: %s\n",search.renk);
                  printf("Aracin modeli: %s\n",search.model);
                  printf("Aracin ucreti: %d\n",search.ucret);
                  printf("Aracin musaitligi: %d\n ",search.musait);
                  printf("---------------------------\n");
                  break;
                }
                else{
                	printf("Arac Bulunamadi\n");
				}
           
     }
     
    fclose(file);
	printf("---------------------------\n");
}
void arac_sil(){
	
	int plaka;
	struct arac_info delete;
	printf("Aramak istediginiz aracin plakasini giriniz:");
	scanf("%d",&plaka);
	FILE *file=fopen("arac.txt","r");
	FILE *tmp=fopen("tmp.txt","w");
	
	while(!feof(file)){
		fscanf(file,"%d %s %s %d %d ",&delete.plaka,&delete.renk,&delete.model,&delete.ucret,&delete.musait);
		if(plaka!=delete.plaka){
			 fprintf(tmp,"%d %s %s %d %d \n",delete.plaka,delete.renk,delete.model,delete.ucret,delete.musait);    
		}
		else 
         {
              break;
         }
                
                
	}
	printf("Kayit silindi.\n");
	fclose(file);
	fclose(tmp);
	remove("arac.txt");
    rename("tmp.txt","arac.txt");
	printf("---------------------------\n");	
	
}
void musteri_ekle(){
	struct musteri_info ekle;
	FILE *file=fopen("musteri.txt","a");
	printf("Musteri numarasini giriniz:");
	scanf("%d",&ekle.musteri_no);
	printf("Musteri ismi giriniz:");
	scanf("%s",&ekle.isim);
	printf("Musteri soyisim giriniz:");
	scanf("%s",&ekle.soy_isim);
	printf("Memleket giriniz:");
	scanf("%s",&ekle.memleket);
    fprintf(file,"%d %s %s %s \n",ekle.musteri_no,ekle.isim,ekle.soy_isim,ekle.memleket);
    printf("Musteri basariyla eklendi.\n");
 
 fclose(file);
 printf("---------------------------\n");
}
void musteri_listele(){
	struct musteri_info list;
	FILE *file=fopen("musteri.txt","r");
	 while (!feof(file))
          {
	 	
	    fscanf(file,"%d %s %s %s ",&list.musteri_no,&list.isim,&list.soy_isim,&list.memleket);
	    printf("Musteri Numarasi : %d\n",list.musteri_no);
        printf("Musteri Ismi: %s\n",list.isim);
        printf("Musteri Soyismi %s\n",list.soy_isim);
        printf("Memleket: %s\n",list.memleket);
        printf("---------------------------\n");
    
 	      }
  
    fclose(file);
    printf("---------------------------\n");
	
}
void musteri_ara(){
	struct musteri_info search;
	int number;
	printf("Aramak istediginiz musterinin numarasini giriniz:");
	scanf("%d",&number);
	FILE *file=fopen("musteri.txt","r");
		 while(!feof(file))
     {
               fscanf(file,"%d %s %s %s ",&search.musteri_no,&search.isim,&search.soy_isim,&search.memleket);
                if(number==search.musteri_no)
                {
                 printf("Musteri Bulundu.\n");
                 printf("Musteri Numarasi : %d\n",search.musteri_no);
                 printf("Musteri Ismi: %s\n",search.isim);
                 printf("Musteri Soyismi %s\n",search.soy_isim);
                 printf("Memleket: %s\n",search.memleket);
                 printf("---------------------------\n");
                 break;
                }
                else{
                	printf("Bulanamadi.\n");
				}
                
           
     }
    fclose(file);
    printf("---------------------------\n");
	
}
void musteri_sil(){
	struct musteri_info delete;
	int number;
	printf("Silmek istediginiz musterinin numarasini giriniz:");
	scanf("%d",&number);
	FILE *file=fopen("musteri.txt","r");
	FILE *tmp2=fopen("tmp2.txt","w");
	while(!feof(file)){
		fscanf(file,"%d %s %s %s ",&delete.musteri_no,&delete.isim,&delete.soy_isim,&delete.memleket);
		if(number!=delete.musteri_no){
			fprintf(tmp2,"%d %s %s %s \n",delete.musteri_no,delete.isim,delete.soy_isim,delete.memleket);    
		}
		else 
         {
            break;
         }
                
                
	}
	printf("Kayit silindi.");
	fclose(file);
	fclose(tmp2);
	remove("musteri.txt");
    rename("tmp2.txt","musteri.txt");	
	printf("---------------------------\n");
	
	
}


void kiralama(){
	int plaka;
	struct arac_info arac;
	struct kiralama_info kira;
	FILE *file=fopen("kirala.txt","a");
	FILE *file2=fopen("arac.txt","r+");
	FILE *temp=fopen("temp.txt","a");
	printf("Kiralamak istediginiz aracin plakasini giriniz:");
	scanf("%d",&plaka);
	while(!feof(file2)){
		fscanf(file2,"%d %s %s %d %d ",&arac.plaka,&arac.renk,&arac.model,&arac.ucret,&arac.musait);
		if(plaka==arac.plaka){
			if(arac.musait==1){
			printf("Kiralamak istediginiz aracin plakasini tekrar giriniz:");
	        scanf("%d",&kira.plaka);
			printf("Musteri numarasi giriniz:");
			scanf("%d",&kira.musteri_no);
			printf("Kiramalama tarihi giriniz(GG.AA.YY):");
			scanf("%s",&kira.kiralama_tarih);
			fprintf(file,"%d %d %s \n",kira.plaka,kira.musteri_no,kira.kiralama_tarih);
			arac.musait=0;
			printf("Arac kiralandi.\n");
			fprintf(temp,"%d %s %s %d %d \n",arac.plaka,arac.renk,arac.model,arac.ucret,arac.musait);	
			} 
		    else{
			printf("Hata\n");
	    	}
	
		}
        else{	
	        fprintf(temp,"%d %s %s %d %d \n",arac.plaka,arac.renk,arac.model,arac.ucret,arac.musait);
		}
		
	}	
	fclose(file);
	fclose(file2);
	fclose(temp);
	remove("arac.txt");
    rename("temp.txt","arac.txt");
    printf("---------------------------\n");
}



void iade(){
	int plaka;
    int musaid;
	struct arac_info arac;
	struct kiralama_info iade;
	FILE *file=fopen("kirala.txt","r+");
	FILE *file2=fopen("arac.txt","r+");
	FILE *temp=fopen("temp.txt","a");
	FILE *temp2=fopen("temp2.txt","a");
	printf("Iade etmek istediginiz aracin plakasini giriniz:");
	scanf("%d",&plaka);

	while(!feof(file2)){
		fscanf(file2,"%d %s %s %d %d",&arac.plaka,&arac.renk,&arac.model,&arac.ucret,&arac.musait);
    	while(!feof(file)){
		fscanf(file,"%d %d %s",&iade.plaka,&iade.musteri_no,&iade.kiralama_tarih);
		if(plaka==arac.plaka && plaka==iade.plaka){
			if(arac.musait==0){
			printf("Iade ettiginiz tarihi giriniz(GG.AA.YY):");
			scanf("%s",&iade.iade_tarihi);
			fprintf(temp2,"%d %d %s %s\n",iade.plaka,iade.musteri_no,iade.kiralama_tarih,iade.iade_tarihi);
			arac.musait=1;
			printf("Arac Iade edildi.\n");
			fprintf(temp,"%d %s %s %d %d \n",arac.plaka,arac.renk,arac.model,arac.ucret,arac.musait);
			}
	        else{
	    	break;
		    }
			
	    }
		
		else{
		fprintf(temp,"%d %s %s %d %d \n",arac.plaka,arac.renk,arac.model,arac.ucret,arac.musait);
		fprintf(temp2,"%d %d %s %s \n",iade.plaka,iade.musteri_no,iade.kiralama_tarih,iade.iade_tarihi);
		break;
		}
		
		}
    }
	fclose(file);
	fclose(file2);
	fclose(temp);
	fclose(temp2);
	remove("arac.txt");
    rename("temp.txt","arac.txt");
	remove("kirala.txt");
	rename("temp2.txt","kirala.txt");	
	printf("---------------------------\n");
	
	
	
}



int choose1=0;
int choose2;
void cikis(){
	choose2=0;
}

int main(int argc, char *argv[]) {
	
	do{
		printf("1.Arac Islemleri\n");
		printf("2.Musteri Islemleri\n");
		printf("3.Kiralama Islemleri\n");
		printf("Tamamen cikmak icin lutfen 0 basiniz.\n");
		printf("Yapmak istediginiz islemi seciniz:");
		scanf("%d",&choose1);
		switch(choose1){
			case 1:
			printf("1.Arac Ekle\n");
			printf("2.Arac Listele\n");
			printf("3.Arac Ara\n");
			printf("4.Arac Sil\n");
			printf("5.Cikis\n");
			scanf("%d",&choose2);
			if(choose2==1){
				arac_ekle();
			}
		    	else if(choose2==2){
				arac_listele();
			}
				else if(choose2==3){
				arac_ara();
			}
				else if(choose2==4){
				arac_sil();
			}
			    else if(choose2==5){
				cikis();
			}
			choose2=0;
			break;
			case 2:
			printf("1.Musteri Ekle\n");
			printf("2.Musteri Listele\n");
			printf("3.Musteri Ara\n");
			printf("4.Musteri Sil\n");
			printf("5.Cikis\n");
			scanf("%d",&choose2);
			if(choose2==1){
				musteri_ekle();
			}
			   else if(choose2==2){
				musteri_listele();
			}
				else if(choose2==3){
				musteri_ara();
			}
				else if(choose2==4){
				musteri_sil();
			}
			    else if(choose2==5){
				cikis();
			}
			
			choose2=0;
			
			break;
			case 3:
			printf("1.Arac Kirala\n");
			printf("2.Arac Iade \n");
			printf("3.Cikis\n");
			scanf("%d",&choose2);
			if(choose2==1){
				kiralama();
			}
			else if(choose2==2){
				iade();
			}
			else if(choose2==3){
				cikis();
			}
			
			choose2=0;
			break;
			
			default:
			break;	
				
		}
			
		}while(choose1!=0);
	
	choose1=0;

	return 0;
}

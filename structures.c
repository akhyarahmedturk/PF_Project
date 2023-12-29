#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
    struct products{
       int cat;//catigories
       int stock;
       char name[30];
       int price;
       float discount;
       float f_price;// after discount
       int s_no;
    };
    void create_products_list(int category ,int size){
        FILE *ptr;
        int i,S_No=0;
        ptr=fopen("products.txt","r");
        struct products p;
        while( fread(&p,sizeof(struct products),1,ptr)){
              S_No=p.s_no;
        }
        fclose(ptr);
        ptr=fopen("products.txt","a");
        struct products ap[size];
        for(i=0;i<size;i++){
            if(S_No==0){
              S_No=1;
              ap[i].s_no=1;
            }
            else
              ap[i].s_no=++S_No;
            ap[i].cat=category;
            printf("Enter name of product %d : ",i+1);
            scanf("%s",ap[i].name);
            printf("Enter original price of %s : ",ap[i].name);
            scanf("%d",&ap[i].price);
            printf("Enter discount on %s : ",ap[i].name);
            scanf("%f",&ap[i].discount);
            printf("How much stock avalible of %s : ",ap[i].name);
            scanf("%d",&ap[i].stock);
            ap[i].f_price=ap[i].price -(ap[i].price*ap[i].discount/100.0);
        }
        fwrite(&ap,sizeof(struct products), size, ptr);
        fclose(ptr);
    }
    void search_data(int category, char Name[15]){
          FILE *ptr;
          int a,b=0;
          ptr=fopen("products.txt","r");
           struct products ap;
          while( fread(&ap,sizeof(struct products),1,ptr)){
            a=strcmp(Name,ap.name);
           if( category==ap.cat && a==0 ){
               b=1;
               printf("Name = %s\n",ap.name);
               printf("Price = %d\n",ap.price);
               printf("Discount = %.2f %%\n",ap.discount);
               printf("Final Price = %.2f\n",ap.f_price);
               printf("Stock availible = %d\n",ap.stock);
           }
          }
          fclose(ptr);
          if(b!=1){
            printf("product not found!\n");
          }
    }
    void display_data(int category){
         FILE *ptr;
         int a=0;
          ptr=fopen("products.txt","r");
           struct products ap;
           printf("  S.No\t    Name\t Price\tDiscount  Final price\tstock\n");
          while( fread(&ap,sizeof(struct products),1,ptr)){
           if( category==ap.cat){
               a=1;
               printf("%4d %14s %7d %7.1f %% %12.2f %7d \n",ap.s_no,ap.name,ap.price,ap.discount,ap.f_price,ap.stock);
           }
        }
        fclose(ptr);
        if(a!=1){
            printf("Data not found!\n");
        }
    }
    void update_data(int category, char Name[15]){
          FILE *ptr,*ptr1;
          int a,b=0;
          ptr=fopen("products.txt","r");
          ptr1=fopen("temp.txt","w");
          struct products ap;
          while( fread(&ap,sizeof(struct products),1,ptr)){
            a=strcmp(Name,ap.name);
            if( category==ap.cat && a==0 ){
               b=1;
               printf("Enter new name of product : ");
               scanf("%s",ap.name);
               printf("Enter new original price of %s : ",ap.name);
               scanf("%d",&ap.price);
               printf("Enter new discount on %s : ",ap.name);
               scanf("%f",&ap.discount);
               printf("How much stock avalible of %s : ",ap.name);
               scanf("%d",&ap.stock);
               ap.f_price=ap.price -(ap.price*ap.discount/100.0);
           }
           fwrite(&ap,sizeof(struct products),1,ptr1);
          }
          fclose(ptr);
          fclose(ptr1);
          if(b==1){
        ptr1=fopen("temp.txt","r");
        ptr=fopen("products.txt","w");
        while( fread(&ap,sizeof(struct products),1,ptr1)){
             fwrite(&ap,sizeof(struct products),1,ptr);
        }
        fclose(ptr);
        fclose(ptr1);
        printf("Data Updated Sucessfully!\n");
    }
          if(b!=1){
            printf("product not found!\n");
          }
    }
    void delete_data(int category, char Name[15]){
          FILE *ptr,*ptr1;
          int a,b=0;
          ptr=fopen("products.txt","r");
          ptr1=fopen("temp.txt","w");
          struct products ap;
          while( fread(&ap,sizeof(struct products),1,ptr)){
            a=strcmp(Name,ap.name);
            if( category==ap.cat && a==0 ){
               b=1;
           }
           else
           fwrite(&ap,sizeof(struct products),1,ptr1);
          }
          fclose(ptr);
          fclose(ptr1);
          if(b==1){
        ptr1=fopen("temp.txt","r");
        ptr=fopen("products.txt","w");
        while( fread(&ap,sizeof(struct products),1,ptr1)){
             fwrite(&ap,sizeof(struct products),1,ptr);
        }
        fclose(ptr);
        fclose(ptr1);
        printf("Data Deleted Sucessfully!\n");
    }
          if(b!=1){
            printf("product not found!\n");
          }
    }
    void admin(){
       int ch,category;
       char name[15];
       do{
         printf("Chose from below\n");
         printf("1 ->Add data in products list\n");
         printf("2 ->To Search a pirticular data\n");
         printf("3 ->Update data\n");
         printf("4 ->Delete data\n");
         printf("5 ->To Display data of a particular caegory\n");
         printf("0 ->To exit\n");
         printf("Your Choice : ");
         scanf("%d",&ch);
         if(ch<=6 && ch>=1){
            printf("Enter the name of category from below\n");
            printf("1 ->Dairy\n");
            printf("2 ->Grains_and_cooking_products\n");
            printf("3 ->Snacks\n");
            printf("4 ->Driks\n");
            printf("0 ->To get back to main menu\n");
            printf("Your Choice : ");
            while (scanf("%d", &category) != 1) {
            printf("Invalid input!\nPlease enter a number: ");
            clearInputBuffer();
            }
            if(category<=4 && category>=1){
                switch(ch){
                    int num;
                    case 1:
                      printf("How many products you want to add? : ");
                      scanf("%d",&num);
                      create_products_list(category,num);
                      break;
                    case 2:
                      printf("Enter name of product : ");
						scanf("%s",name);
                      search_data(category,name);
                      break;
                    case 3:
                      printf("Enter name of product : ");
                      scanf("%s",name);
                      update_data(category,name);
                      break;
                    case 4:
                      printf("Enter name of product : ");
                      scanf("%s",name);
                      delete_data(category,name);
                      break;
                    case 5:
                     display_data(category);
                     break;
                  }
              }
              else
              	printf("Catagory not found!\n");
            }
            else if(ch!=0)
            printf("Chose right option!\n");
       }while(ch!=0);     
    }
int main(){
    admin();
     return 0;
}

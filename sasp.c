#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N_Pr 200 //reservation


typedef struct {//structure contient les infos d'un produit
    char productName[30];
    char productCode[30];
    int productQuantity;
    float productPrice;
    float ttcPrice;
                        }Product;



Product product[N_Pr];//reservation d'une array de type Product
int tSize=0,i; // utilisé comme indice des produit existés



int CalculateTtcPrice(){//fonction permet de calculer le prix TTC
    product[tSize].ttcPrice+= product[tSize].productPrice * 0.15;
    return product[tSize].ttcPrice;
}



void Menu(){//fonction permet d'afficher les choix des operations
     printf("\t\t\t\t_______________________________________ \n");
     printf("\t\t\t\t1. Ajouter un produit\n");
     printf("\t\t\t\t2. Ajouter plusieurs nouveaux produits\n");
     printf("\t\t\t\t3. Lister tous les produits \n");
     printf("\t\t\t\t4. Acheter un produit \n");
     printf("\t\t\t\t5. Rechercher des produits\n");
     printf("\t\t\t\t6. Voir l'etat du stock\n");
     printf("\t\t\t\t7. Alimenter le stock\n");
     printf("\t\t\t\t8. Supprimer des produits\n");
     printf("\t\t\t\t9. Statistique de vente \n");
     printf("\t\t\t\t10. Quittez l'application \n");
     printf("\t\t\t\t_______________________________________ \n\n\n");
}



int Choice(){ // pour obtenir le choix d'utilisateur
    int choice;
    printf("\t\t\t\tEntrer votre choix :");
    scanf("%d",&choice);
    system("cls");
    return choice;
}


void AddNewProduct(){//fonction permet d'entrer les donnees

    printf("\t\t\t\tEntrer le nom du produit : ");
    scanf(" %s",product[tSize]. productName);
    printf("\n");
    printf("\t\t\t\tEntrer le code du produit : ");
    scanf(" %s",product[tSize].productCode);
    printf("\n");
    printf("\t\t\t\tLa quantite que vous voulez ajouter: ");
    scanf(" %d",&product[tSize].productQuantity);
    printf("\n");
    printf("\t\t\t\tLe prix du produit est: ");
    scanf(" %f",&product[tSize].productPrice);
    printf("\n");
    tSize++;
    system("cls");

}




void AddMoreThanOneProduct(){ //fonction permet l'utilisateur d'entrer plusieurs produits
    int nProducts; //nombre des produits qui l'utilisateur va ajouter
    printf("\n\t\t\t\tEntre le nombre des produits que vous voulez ajouter : ");
    scanf("%d",& nProducts);
    system("cls");

    for (i=0;i<nProducts;i++){
        printf("\t\t\t\tEntrer les données du produit %d\n",i+1);
        AddNewProduct();
    }
}


//void Display1(){
//        int c
//            do {
//        printf("\t\t\t\tLister les produit selon ordre :\n\t\t\t\t");
//        printf("1. alphabetique croissant du nom\t\t\t\t\n2. decroissant du prix\t\t\t\t\n");
//        scanf("%d",&c);
//        if (c<1 || c>2)
//            WrongChoice();
//        }while(c<1 || c>2);
//
//
//}


void Display2(tSize){

		printf("\t\t\t\tnom: %s\n",product[tSize].productName);
		printf("\t\t\t\tcode : %s\n",product[tSize].productCode);
		printf("\t\t\t\tquantité: %d\n",product[tSize].productQuantity);
		printf("\t\t\t\tprix: %2.f MAD\n",product[tSize].productPrice);
        printf("\t\t\t\tTTC prix: %2.f MAD\n",CalculateTtcPrice());
		printf("\t\t\t\t__________________________________\n \n \n");
}




//void BuyProduct(){
//
//}


void SearchProduct(){
    int c,q;
    char code[30];

    do {
        printf("\t\t\t\tVous voulez chercher par :\n\t\t\t\t 1. Code\n\t\t\t\t 2. Quantite\t\t\t\t\n");
        scanf("%d",&c);
        if (c<1 || c>2)
            WrongChoice();
        }while(c<1 || c>2);
    if(c==1){
        printf("\t\t\t\tEntrer le Code du produit :\n\t\t\t\t");
        scanf("%s",code);
        for(i=0;i<tSize;i++){
            if (strcmp(code,product[i].productCode)==0){
                Display2(i);
            }
        }
    }
    else if(c==2){
        printf("\t\t\t\tEntrer la quantite du produit :\n\t\t\t\t");
        scanf("%d",&c);
        for(i=0;i<tSize;i++){
            if (c==product[i].productQuantity){
                Display2(i);
            }
        }
    }
}

//
//void StockStatus(){
//
//}
//
//void FeedStock(){
//}
//
//void Delete(){
//}
//
//
//void SaleStatistics(){
//}
//
//
void WrongChoice(){
    printf("\t\t\t\tVotre choix est incorrect :\n");
}



void Thanks(){
    printf("\t\t\t\tMERCI POUR VOTRE VISITE");
}


//void AfterProcess(){
//    int c;
//
//    do {
//        printf("\t\t\t\t1. Menu principal\n\t\t\t\t 2. Quittez l'application \t\t\t\t\n");
//        scanf("%d",&c);
//        if (c<1 || c>2)
//            WrongChoice();
//        }while(c<1 || c>2);
//
//}


int main(){
        int choice,c;

debut :
    do{
        Menu();
        int choice=Choice();


        switch(choice){
            case 1:
                AddNewProduct();
            break;


            case 2:
                AddMoreThanOneProduct();
            break;


//            case 3:
//                Display();
//            break;
//
//
//            case 4:
//                BuyProduct();
//            break;
//
//
            case 5:
                SearchProduct();
            break;
//
//
//            case 6:
//                StockStatus();
//            break;
//
//
//            case 7:
//                FeedStock();
//            break;
//
//
//            case 8:
//                Delete();
//            break;
//
//
//            case 9:
//                SaleStatistics();
//            break;

            default:
                if(choice==10)
                {Thanks();}
                else{WrongChoice();}
            break;
          }

       }while(choice==10);





    return 0;
}

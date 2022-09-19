#include <stdio.h>
#include <stdlib.h>
#define N_Pr 200 //reservation

typedef struct {//structure contient les infos d'un produit
    char productName[30];
    char productCode[30];
    int productQuantity;
    float productPrice;
    float ttcPrice;
                        }Product;


Product product[N_Pr];//reservation d'une array de type Product
int tSize=0; // utilisé comme indice des produit existés





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
    return choice;
}


void AddNewProduct(){//fonction permet d'entrer les donnees

    printf("Entrer le nom du produit : ");
    scanf("%s",product[tSize]. productName);
    printf("\n");
    printf("Entrer le code du produit : ");
    scanf("%s",product[tSize].productCode);
    printf("\n");
    printf("La quantitÃ© que vous voulez ajouter: ");
    scanf("%d",product[tSize].productQuantity);
    printf("\n \n");
    printf("Le prix du produit est: ");
    scanf("%f",product[tSize].productPrice);
    printf("\n");
    tSize++;

}

//
//
//void AddMoreThanOneProduct(){
//
//}
//
//
//
//void Display(){
//
//
//}
//
//
//void BuyProduct(){
//
//}
//
//void SearchProduct(){
//
//}
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
//void WrongChoice(){
//
//}
//void Thanks(){
//
//}
//




int main(){

 //   do{
        Menu();
        int choice=Choice();


//        switch(choice){
//            case 1:
//                AddNewProduct();
//            break;
//
//
//            case 2:
//                AddMoreThanProduct();
//            break;
//
//
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
//            case 5:
//                SearchProduct();
//            break;
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
//
//
//            default:
//                WrongChoice();
//            break;
//
//
//          }
//
//       }while(choice!=10);
//
//
//        Thanks();


    return 0;
}

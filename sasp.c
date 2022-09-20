#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define debut
#define N_Pr 200 //reservation

//reservation d'une array de type Product
int tSize=0; // utilisé comme indice des produit existés
int nSales=0;


typedef struct {//structure contient les infos d'un produit
    char productName[30];
    char productCode[30];
    int productQuantity;
    float productPrice;
    float ttcPrice;//=productPrice*0.15;
                        }Product;
Product product[N_Pr];

//typedef struct {
//
//    float ttlPrice;
//    float ttlPricePr[tSize];
//    float minPrice;
//    float maxPrice;
//    float meanPrice;
//
//}Sales;
//
//Sales saleStat[];






float CalculateTtcPrice(int i){//fonction permet de calculer le prix TTC
    product[i].ttcPrice= product[i].productPrice+product[i].productPrice * 0.15;
    return product[i].ttcPrice;
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

    for (int i=0;i<nProducts;i++){
        printf("\t\t\t\tEntrer les données du produit %d\n",i+1);
        AddNewProduct();
    }
}


void Ordre (int i,int j){
    char helper [30];
    int q,p;
                    strcpy(helper,product[j].productCode);
                    strcpy(product[j].productCode,product[i].productCode);
                    strcpy(product[i].productCode,helper);

                    strcpy(helper,product[j].productName);
                    strcpy(product[j].productName,product[i].productName);
                    strcpy(product[i].productName,helper);

                    q=product[j].productQuantity;
                    product[j].productQuantity=product[i].productQuantity;
                    product[i].productQuantity=q;

                    p=product[j].productPrice;
                    product[j].productPrice=product[i].productPrice;
                    product[i].productPrice=p;
}


void Display(){

        int c,i,j;
        if (tSize<=0){
            printf("pas de produit pour le moment ");
        } else {
            do {
        printf("\t\t\t\tLister les produit selon ordre :\n\t\t\t\t");
        printf("1. alphabetique croissant du nom\t\t\t\t\n2. decroissant du prix\t\t\t\t\n");
        scanf("%d",&c);
        if (c<1 || c>2){
            WrongChoice();}
        }while(c<1 || c>2);

        if(c==1){
            for(i=0;i<tSize;i++){
                for(j=i+1;j<tSize;j++){
                    if( strcmp(product[i].productName, product[j].productName)>0){
                    Ordre (i,j);

                    }
                }
            }
        }else if(c==2){
            for (i=0;i<tSize;i++){
                    for(j=i+1;j<tSize;j++){
               if( product[i].productPrice < product[j].productPrice){
                    Ordre (i,j);
                    }
                }
            }
        }
        for (i=0;i<tSize;i++){
            Display1(i);
        }}
}


void Display1(tSize){// fonction permet l'affichage des donnees d'un produit pricise

		printf("\t\t\t\tnom: %s\n",product[tSize].productName);
		printf("\t\t\t\tcode : %s\n",product[tSize].productCode);
		printf("\t\t\t\tquantite: %d\n",product[tSize].productQuantity);
		printf("\t\t\t\tprix: %2.f MAD\n",product[tSize].productPrice);
        printf("\t\t\t\tTTC prix: %2.f MAD\n",CalculateTtcPrice(tSize));
		printf("\t\t\t\t__________________________________\n \n \n");
}


void BuyProduct(){
    int q;
    char pCode[30];
    printf("entrer le code du produit que vous voulez acheter : ");
    scanf("%s",pCode);
    printf("entre la quantite :");
    scanf("%d",&q);
    for( int i=0;i<tSize;i++){
        if (strcmp(pCode,product[i].productCode)==0){
            if(q>product[i].productQuantity){
                printf("|!| le stock est insuffisant |!|");
            }else if (q<=product[i].productQuantity){
                product[i].productQuantity-=q;
                if(product[i].productQuantity==0){
                  Delete();}
}}}}



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
        for(int i=0;i<tSize;i++){
            if (strcmp(code,product[i].productCode)==0){
                Display1(i);
            }
        }
    }
    else if(c==2){
        printf("\t\t\t\tEntrer la quantite du produit :\n\t\t\t\t");
        scanf("%d",&c);
        for(int i=0;i<tSize;i++){
            if (c==product[i].productQuantity){
                Display1(i);
            }
        }
    }
}


void StockStatus(){
    if(tSize==0){
        printf("\t\t\t\tpas de produits actuellement !!!\n");
    }else{
    printf("\t\t\t\tles produits dont la quantite est inferieure a 3 sont :\n");
    for(int i=0;i<tSize;i++){
        if(product[i].productQuantity<3){

            Display1(i);
            }
        }
    }
}


void FeedStock(){
    char fCode[30];
    int qAdd;
    printf("\t\t\t\tentrer le code du produit que vous voulez ajouter :\n\t\t\t\t");
    scanf("%s",fCode);
    printf("\t\t\t\tentrer la quantite que vous voulez ajouter :\n\t\t\t\t");
    scanf("%d",&qAdd);
    for (int i=0;i<tSize;i++){
        if(strcmp(fCode,product[i].productCode)==0){
            product[i].productQuantity+=qAdd;
        }else{
        printf("\t\t\t\tPas de produit a le code que vous avez entre");}
    }
}


void Delete(){
    char pCode[30];
    printf("entrer le code du produit que vous voulez supprimer :");
    scanf("%s",pCode);
    for (int i=0;i<tSize;i++){
        if(strcmp(pCode,product[i].productCode)!=0){
            printf("pas de produits a ce code");
        }
        else if(strcmp(pCode,product[i].productCode)==0){
                product[i]=product[i+1];
        tSize--;
        }
    }
}


void EverySell(){

}

void SaleStatistics(){
}


void WrongChoice(){
    printf("\t\t\t\tVotre choix est incorrect :\n");
}




void AfterProcess(){
    int c;

    do {
        printf("\t\t\t\t1. Menu principal\n\t\t\t\t2. Quittez l'application\n\n\n\t\t\t\tVOTRE CHOIX : ");
        scanf("%d",&c);
        if (c<1 || c>2)
            WrongChoice();
        }while(c<1 || c>2);
        if(c==1){
        system("cls");
         main();}

        else if(c==2){
           Exxit(); }

}

void Exxit(){

        printf("\t\t\t\tMERCI POUR VOTRE VISITE\n\n\n");
        exit(0);
}


int main(){
        int choice,c;

    do{
        Menu();
        int choice=Choice();


        switch(choice){
            case 1:
                AddNewProduct();
                AfterProcess();
            break;


            case 2:
                AddMoreThanOneProduct();
                AfterProcess();

            break;


            case 3:
                Display();
                AfterProcess();

            break;


            case 4:
                BuyProduct();
                AfterProcess();

            break;


            case 5:
                SearchProduct();
                AfterProcess();

            break;


            case 6:
                StockStatus();
                AfterProcess();

            break;


            case 7:
                FeedStock();
                AfterProcess();

            break;


            case 8:
                Delete();
                AfterProcess();

            break;


////            case 9:
////                SaleStatistics();
//                AfterProcess();

////            break;
            case 10:
                Exxit();
                break;

            default:
               WrongChoice();
            break;
          }

       }while(choice<1 || choice>10);

    return 0;
}

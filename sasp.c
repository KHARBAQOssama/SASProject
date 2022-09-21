#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>
#include <time.h>
#define N_Pr 200 //reservation


int tSize=0; // utilisé comme indice des produit existés



int v=0;// un variable qui count le nombre des ventes

char pSales[N_Pr][30]; //reservation d'une array pour copie les noms des produits qui sont achetée

float ttcPrV[N_Pr];//pour enregistrer le prix ttc de la quantite vendus pour chaque produit

float ttlPrice=0;// prix accumulé de tous les produits vendus

float ttlPricePr[N_Pr];//le prix totale de la vente de chaque produit

float pricePr[N_Pr];//le prix d'une unité de chaque produit vendu

int qua[N_Pr];// array qui stock la quantité vendue de chaque produit

int qu=0;// count la quantité totale des ventes

int vTime[N_Pr][5];// array pour stacker le temps

bool status=false,buy=false,searchByC=false,searchByQ=false,feed=false,checkDelete=false;//Cela nous aide à savoir si l'opération a réussi ou non



float minPrice,maxPrice,meanPrice;//pour calculer les statistique








typedef struct {//structure contient les infos d'un produit
    char productName[30];
    char productCode[30];
    int productQuantity;
    float productPrice;
    float ttcPrice;//=productPrice*0.15;
                        }Product;

Product helper[1];
Product product[N_Pr];//reservation d'une array de type Product





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


void Ordre (int i,int j){//Une fonction qui nous aide à classer les produits

    helper[0]=product[j];
    product[j]=product[i];
    product[i]=helper[0];

}


void Display(){// fonction permet d'afficher les produits par un ordre pricis a l'aide de la fonction  Ordre

        int c,i,j;
        if (tSize<=0){
            printf("\t\t\t\t pas de produit pour le moment \n");
        } else {
            do {
        printf("\t\t\t\tLister les produit selon ordre :\n\n\t\t\t\t");
        printf("1. alphabetique croissant du nom\t\t\t\t\n\t\t\t\t2. decroissant du prix\t\t\t\t\n");
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


void Display1(int a){// fonction permet l'affichage des donnees d'un produit pricise

		printf("\t\t\t\tnom: %s\n",product[a].productName);
//		printf("\t\t\t\tcode : %s\n",product[a].productCode);
//		printf("\t\t\t\tquantite: %d\n",product[a].productQuantity);
		printf("\t\t\t\tprix: %2.f MAD\n",product[a].productPrice);
        printf("\t\t\t\tTTC prix: %2.f MAD\n",CalculateTtcPrice(a));
		printf("\t\t\t\t__________________________________\n \n \n");
}


void BuyProduct(){
    int q;
    char pCode[30];
    printf("\n\t\t\t\entrer le code du produit que vous voulez acheter : ");
    scanf("%s",pCode);
    printf("\n\t\t\t\entre la quantite :");
    scanf("%d",&q);
    for( int i=0;i<tSize;i++){
        if (strcmp(pCode,product[i].productCode)==0){
            if(q>product[i].productQuantity){
                printf("\n\t\t\t\t|!| le stock est insuffisant |!|");
            }else if (q<=product[i].productQuantity){
                product[i].productQuantity-=q;

                        pricePr[v]=product[i].productPrice;
                        ttlPrice+=q*product[i].productPrice;
                        qu+=q;
                        ttcPrV[v]=q*CalculateTtcPrice(i);
                        time_t vDate=time(NULL);
                        struct tm *v_date=localtime(&vDate);

                        ttlPricePr[v]+=q*product[i].productPrice;
                        strcpy(pSales[v],product[i].productName);
                        qua[v]=q;
                        vTime[v][0]=(v_date->tm_mday);
                        vTime[v][1]=(v_date->tm_mon)+1;
                        vTime[v][2]=(v_date->tm_year)+1900;
                        vTime[v][3]=(v_date->tm_min);
                        vTime[v][4]=(v_date->tm_hour);

                        v++;
                        buy=true;

                if(product[i].productQuantity==0){//si la quanité est 0 alors il faux supprimer le produit
                  product[i]=product[i+1];
                  tSize--;}
            }}} if(buy=true){
            printf("\n\t\t\t\tl'operation a bien ete effectue");
             }
    }

float CalculateMin(minPrice){// fonction pour calculer le prix minimal dans les produit vendus
    for (int i=0;i<v;i++){
            for(int j=0;j<v;j++){
        if(ttlPricePr[i]<ttlPricePr[j]){
//            minPrice=ttlPricePr[i];
            minPrice=pricePr[i];
        }
    }} return minPrice;
}

float CalculateMax(maxPrice){// fonction pour calculer le prix maximal dans les produit vendus
    for (int i=0;i<v;i++){
            for(int j=0;j<v;j++){
        if(ttlPricePr[i]>ttlPricePr[j]){
//            maxPrice=ttlPricePr[i];
            maxPrice=pricePr[i];

        }
    }} return maxPrice;}

float CalculateMean(meanPrice){//fonction pour calculer le moyenne
    meanPrice=ttlPrice/qu;
//    meanPrice=ttlPrice/v;

    return meanPrice;
}

void SearchProduct(){//fonction permet de trouver un produit à travers se code ou sa quantité
    int c;
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
                searchByC=true;
            }
        }
        if(searchByC=false){
            printf("\n\t\t\t\t Pas de produit a ce code");
        }
    }
    else if(c==2){
        printf("\t\t\t\tEntrer la quantite du produit :\n\t\t\t\t");
        scanf("%d",&c);
        for(int i=0;i<tSize;i++){
            if (c==product[i].productQuantity){
                Display1(i);
                searchByQ=true;
            }
        }
        if(searchByQ=false){
            printf("\n\t\t\t\t Pas de produit a cette quantite");
        }
    }
}


void StockStatus(){//permet d’afficher les produits dont la quantité est inférieure à 3.
    if(tSize==0){
        printf("\t\t\t\tpas de produits actuellement !!!\n");
    }else{
    for(int i=0;i<tSize;i++){
        if(product[i].productQuantity<3){
            status=true;}
    }
    if(status=true){
    printf("\t\t\t\tles produits dont la quantite est inferieure a 3 sont :\n");
    for(int i=0;i<tSize;i++){
        if(product[i].productQuantity<3){

            Display1(i);
            }}
        }else{
        printf("\t\t\t\t pas des produit ont une quantite inferieure a 3\n");
        }
    }
}


void FeedStock(){//permet de mettre à jour la quantité après avoir introduit le code produit et la quantité à ajouter.
    char fCode[30];
    int qAdd;
    printf("\t\t\t\t entrer le code du produit que vous voulez ajouter :\n\t\t\t\t");
    scanf("%s",fCode);
    printf("\t\t\t\t entrer la quantite que vous voulez ajouter :\n\t\t\t\t");
    scanf("%d",&qAdd);
    for (int i=0;i<tSize;i++){
        if(strcmp(fCode,product[i].productCode)==0){
            product[i].productQuantity+=qAdd;
            feed=true;}
            }
        if(feed=false){
        printf("\t\t\t\tPas de produit a le code que vous avez entre");}
        if(feed=true){
        printf("\t\t\t\t l'opperation a bien ete effectue");}
    }



void Delete(){//fonction permet de supprimer un produit a partir de se code
    char pCode[30];
    printf("\n\t\t\t\entrer le code du produit que vous voulez supprimer :");
    scanf("%s",pCode);
    for (int i=0;i<tSize;i++){
            if(strcmp(pCode,product[i].productCode)==0){
                product[i]=product[i+1];
        tSize--;
        checkDelete=true;
        }
    }
    if(checkDelete=false){
        printf("\t\t\t\tPas de produit a le code que vous avez entre");}
    else{
        printf("\t\t\t\t l'opperation a bien ete effectue");}
    }




void SaleStatistics(){
    if(v==0){
        printf("\n\t\t\t\t pas de vente pour le moment\n");

    }else {
    printf("\t\t\t\t les ventes sont :\n\n");
    for (int i=0;i<v;i++){
        printf("\t\t\t\t Produit : %s\n",pSales[i]);
        printf("\t\t\t\t Quantite vendue : %d\n",qua[i]);
        printf("\t\t\t\t Prix total : %.2f               temps: %d:%d\n",ttlPricePr[i],vTime[i][4],vTime[i][3]);
        printf("\t\t\t\t Prix TTC : %.2f                 date: %d-%d-%d\n\n",ttcPrV[i],vTime[i][0],vTime[i][1],vTime[i][2]);
        printf("\t\t\t\t___________________________________________________\n\n");
        }
    printf("\t\t\t\t les statistiques  :\n");
    printf("\t\t\t\t MIN: %.2f     MAX:%.2f     MOYENNE: %.2f\n",CalculateMin(minPrice),CalculateMax(maxPrice),CalculateMean(meanPrice));
        }
}

void WrongChoice(){
    printf("\n\n\t\t\t\t Votre choix est incorrect :\n");
}




void AfterProcess(){
    int c;

    do {
        printf("\n\t\t\t\t1. Menu principal\n\t\t\t\t2. Quittez l'application\n\n\n\t\t\t\tVOTRE CHOIX : ");
        scanf("%d",&c);
        if (c<1 || c>2)
            WrongChoice();
        }while(c<1 || c>2);
        if(c==1){
        system("cls");
         main();
        }

        else if(c==2){
           Exxit(); }

}

void Exxit(){

        printf("\t\t\t\t MERCI POUR VOTRE VISITE\n\n\n");
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


            case 9:
                SaleStatistics();
                AfterProcess();

            break;
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

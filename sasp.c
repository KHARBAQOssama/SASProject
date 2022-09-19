#include <stdio.h>
#include <stdlib.h>


typedef struct {
    char productName[30];
    char productCode[30];
    int productQuantity;
    float productPrice;
    float ttcPrice;
                        }Product;



int Choice(){
}


void AddNewProduct(){

}


void AddMoreThanOneProduct(){

}



void Display(){


}


void BuyProduct(){

}

void SearchProduct(){

}

void StockStatus(){

}

void FeedStock(){
}

void Delete(){
}


void SaleStatistics(){
}


void WrongChoice(){

}
void Thanks(){

}





int main(){
    do{
        Menu();
        Choice();


        switch(choice){
            case 1:
                AddNewProduct();
            break;


            case 2:
                AddMoreThanProduct();
            break;


            case 3:
                Display();
            break;


            case 4:
                BuyProduct();
            break;


            case 5:
                SearchProduct();
            break;


            case 6:
                StockStatus();
            break;


            case 7:
                FeedStock();
            break;


            case 8:
                Delete();
            break;


            case 9:
                SaleStatistics();
            break;


            default:
                WrongChoice();
            break;


          }

       }while(choice!=10);


        Thanks();


    return 0;
}

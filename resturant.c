#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct items
{
    char  item[20];
    float price;
    int qty;
};

struct orders
{
    char customer[50];
    char date[50];
    int numOfItems; 
    struct items itm[50];
};

//function to genrate the bill
void generatebill(char name[50],char date[30]){
    printf("\n\n");
    printf("\t   Domino's Pizza");
    printf("\n---------------------------------");
    printf("\nDate:%s",date);
    printf("\nInvoice To:%s",name);
    printf("\n");
    printf("---------------------------------\n");
    printf("Item\t\t");
    printf("Qty\t\t");
    printf("Total\n");
    printf("-----------------------------------");
    printf("\n\n");
}

//function to generate billbody
void generateBillBody(char item[30],int qty,float price) {
   // printf("%s\t\t%d\t\t%.2f\n",item, qty, qty*price);
    printf("%s\t\t",item);
     printf("%d\t\t",qty);
     printf("%.2f\t\t",qty*price);
     printf("\n");
}

void generateBillFooter(float total) {
    printf("\n");
    float dis= 0.1*total;
    float netTotal=total-dis;
    float cgst=0.09*netTotal,grandTotal=netTotal +2*cgst;
    printf("-------------------------------------\n");
    printf("Sub Total\t\t\t%.2f",total);
    printf("\nDiscount @10%s\t\t\t%.2f","%",dis);
    printf("\n\t\t\t\t--------");
    printf("\nNet Total\t\t\t%.2f",netTotal);
    printf("\nCGST @9%s\t\t\t%.2f","%",cgst);
    printf("\nSGST @9%s\t\t\t%.2f","%",cgst);
    printf("\n------------------------------------");
    printf("\nGrand Total\t\t\t%.2f",grandTotal);
    printf("\n------------------------------------\n");

}

int main() {
    float total;
    int i,opt,n,j;
    struct orders ord;
    struct orders order;
    char saveBill='y';
    FILE *fp;

    printf("============Domino's Pizza============\n\n");

    printf("Please select your prefered option:\n");
    printf("1.Genrate Invoice\n");
 //  printf("2.Show all Invoice\n");
 //  printf("3.Search Invoice\n");
 //  printf("4.Exit\n\n");


    printf("Your Choice:");
    scanf("\t%d",&opt);
    fgetc(stdin);

    switch (opt)
    {
        case 1:
            printf("\nplease enter the name of the customer:\t");
            fgets(ord.customer,50,stdin);
            ord.customer[strlen(ord.customer)-1]=0;     
            strcpy(ord.date,__DATE__);
            printf("\nPlease enter the number of items:\t");
            scanf("%d",&n);
            ord.numOfItems=n;
            for(i=1;i<=n;i++){
                fgetc(stdin);
                printf("\n\n");
                printf("Please enter the item %d:\t",i);
                fgets(ord.itm[i].item,20,stdin);
                ord.itm[i].item[strlen(ord.itm[i].item)-1]=0; //problem was here '=0' not presemt
                printf("Please enter the quantity:\t");
                scanf("%d",&ord.itm[i].qty);
                printf("Please enter the unit price:\t");
                scanf("%f",&ord.itm[i].price);
                total += ord.itm[i].qty * ord.itm[i].price;
            }

            generatebill(ord.customer,ord.date);
            for (int j = 1; j <= ord.numOfItems; j++)
            {
                generateBillBody(ord.itm[j].item,ord.itm[j].qty,ord.itm[j].price);
            }
            generateBillFooter(total);
            printf("\nDo you want to save the Invoice[y/n]:\t");
            scanf("%s",&saveBill);

            if (saveBill=='y')
            {
               fp=fopen("resturant.txt","a+");
               fwrite(&ord,sizeof(struct orders),1,fp);
               if (fwrite!=0)
               {
                printf("\nSuccessfully saved");}
                else{
                printf("\nError Saving");
                fclose(fp);
               }
                
            }
            break;

       /* case 2:
            fp=fopen("resturant.txt","r");
            printf("\n   *****Yours Previous Invoices*****\n");
            while (fread(&order,sizeof(struct orders),1,fp))
            {
                float tot=0;
                generatebill(order.customer,order.date);
                for (int i = 0; i <= order.numOfItems; i++)
                {
                    generateBillBody(order.itm[i].item,order.itm[i].qty,order.itm[i].price);
                    tot+=order.itm[i].qty * order.itm[i].price;
                }
                generateBillFooter(tot);       
            }
            fclose(fp);*/
           // break;
            

        default:
            printf("Thank YOU!!");
            break;
        }

}




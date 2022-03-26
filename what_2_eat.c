#include <stdio.h>
#include <string.h>
#include <stdlib.h>



void firstRound(int peopleCount){
    int threshold=10;
    printf("%s","Food options are:Pasta,Susi,Burger,Salad,Soup");
    printf("%s","Please vote food options according to your preferences:");
    int foodOption[]={0,0,0,0,0,};
    //"Pasta", "Susi","Burger","Salad","Soup"
    for(int i=0;i<peopleCount;i++){
        int preference=1;
        for(int j=5;j>0;j--){
            printf("\nEnter your ");
            printf("%d",preference);
            printf("preference");
            int selection;

            scanf("%d",&selection);
            if(selection==1){
                foodOption[0]=foodOption[0]+j;
            }
            else if(selection==2){
                foodOption[1]=foodOption[1]+j;
            }
            else if(selection==3){
                foodOption[2]=foodOption[2]+j;
            }
            else if(selection==4){
                foodOption[3]=foodOption[3]+j;
            }
            else{
                foodOption[4]=foodOption[4]+j;
            }
            preference=preference+1;
        }

    }
    for(int i=0;i<5;i++){
        printf("%d",foodOption[i]);
        printf("\n");
    }
    if(foodOption[0]<=threshold&& foodOption[1]<=threshold&& foodOption[2]<=threshold&&foodOption[3]<=threshold&&foodOption[4]<=threshold){
        printf("\n You are eating at home today");
        exit(0);
    }

    //Second Round/////////////
    int secondList[]={-100,-100,-100,-100,-100};

    if(foodOption[0]>threshold){
        secondList[0]=0;
        printf("\npasta pass threshold %d",foodOption[0]);
    }
    if(foodOption[1]>threshold){
        secondList[1]=0;
        printf("\nsusi passed thereshold%d",foodOption[1]);
    }
    if(foodOption[2]>threshold){
        secondList[2]=0;
        printf("\nburger passed threshold%d",foodOption[2]);
    }
    if(foodOption[3]>threshold){
        secondList[3]=0;
        printf("\nsalad passed threshold%d",foodOption[3]);
    }
    if(foodOption[4]>threshold) {
        secondList[4]=0;
        printf("\nsoup passed threshold%d", foodOption[4]);
    }

    for(int i=0;i<peopleCount;i++){
        if(foodOption[0]>threshold||foodOption[1]>threshold||foodOption[2]>threshold||foodOption[3]>threshold||foodOption[4]>threshold){
            printf("\nChoose for second round among the passed food.\n");
            printf("\n1.Pasta,2.Susi,3.Burger,4.Salad,5.Soup");
        }
        else{
            printf("\nNo food passed");
            break;
        }
        printf("\nPlayer ");
        printf("%d",i+1);
        printf(" choose \n");
        int secondSelection;
        scanf(" %d",&secondSelection );
        while(1){
            if(secondList[secondSelection-1]>-50){
                secondList[secondSelection-1]=secondList[secondSelection-1]+20;
                break;

            }else{
                printf("\nChoose again");
                scanf(" %d",&secondSelection );


            }
        }
    }
    for(int i=0;i<5;i++){
        if(secondList[i]>-50){
            printf("%d",i+1);
            printf("%d",secondList[i]);
            printf("\n");

        }

    }
    if(secondList[0]>secondList[1]&&secondList[0]>secondList[2]&&secondList[0]>secondList[3]&&secondList[0]>secondList[4])
        printf("\nYou are ordering Pasta");
    if(secondList[1]>secondList[0]&&secondList[1]>secondList[2]&&secondList[1]>secondList[3]&&secondList[1]>secondList[4])
        printf("\nYou are ordering Susi");
    if(secondList[2]>secondList[0]&&secondList[2]>secondList[1]&&secondList[2]>secondList[3]&&secondList[2]>secondList[4])
        printf("\nYou are ordering Burger");
    if(secondList[3]>secondList[0]&&secondList[3]>secondList[2]&&secondList[3]>secondList[4]&&secondList[3]>secondList[4])
        printf("\nYou are ordering Salad");
    if(secondList[4]>secondList[0]&&secondList[4]>secondList[2]&&secondList[4]>secondList[3]&&secondList[4]>secondList[1])
        printf("\nYou are ordering Soup");



}


int main() {
    int peopleCount;
    printf("How many people will make food choice?");
    scanf("%d",&peopleCount);
    firstRound(peopleCount);


    return 0;
}



#include<stdio.h>
#include<string.h>
#include<ctype.h>
 
#define MAXN  100

void initTestObject(char bookName[][40], char bookType[][40], char bookCode[][40], double bookPrice[], int *currentSize, int bookAmount[]);

void addNewBook(char bookName[][40], char bookType[][40], char bookCode[][40], double bookPrice[], int bookAmount[], int *currentSize);
int addSingleBook(char bookName[][40], char bookType[][40], char bookCode[][40], double bookPrice[], int bookAmount[], int size);
void viewListBook(char bookName[][40], char bookType[][40], char bookCode[][40], double bookPrice[], int size, int bookAmount[]);
void viewSingleBook(char bookName[][40], char bookType[][40], char bookCode[][40], double bookPrice[], int size, int bookAmount[]);
void deleteBook(char bookName[][40], char bookType[][40], char bookCode[][40], double bookPrice[], int *currentSize, int bookAmount[]);
void deleteAllBook(char bookName[][40], char bookType[][40], char bookCode[][40], double bookPrice[], int *currentSize, int bookAmount[]);
void arrangingBook(char bookName[][40], char bookType[][40], char bookCode[][40], double bookPrice[], int size, int bookAmount[]);
void copyBook(char bookName[][40], char bookType[][40], char bookCode[][40], double bookPrice[], int size, int bookAmount[]);
int exist(char *fileName);
int writeFile(char *fileName, char bookName[][40], char bookType[][40], char bookCode[][40], double bookPrice[], int size, int bookAmount[]);

int main(){

    int choice, currentSize = 0, index;
    int bookAmount[MAXN];
    char bookName[MAXN][40], bookType[MAXN][40], bookCode[MAXN][40];
    double bookPrice[MAXN];

    initTestObject(bookName, bookType, bookCode, bookPrice, &currentSize, bookAmount);

    do{
        printf("\n--MANAGING BOOK--");
        printf("\n1- Add new book");
        printf("\n2- View a book");
        printf("\n3- View list of all books");
        printf("\n4- Delete a book");
        printf("\n5- Delete all books");
        printf("\n6- Arranging list of books");
        printf("\n7- Copy to a file");
        printf("\n8- Exit\n");
        printf("\nPlease select an option<1-7>: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                addNewBook(bookName, bookType, bookCode, bookPrice, bookAmount, &currentSize);
                break;
            
            case 2:
                if(currentSize == 0){
                    printf("\nHave no book to show\n");
                }
                viewSingleBook(bookName, bookType, bookCode, bookPrice, currentSize, bookAmount);
                break;

            case 3:
                if(currentSize == 0){
                    printf("\nHave no book to show\n");
                }
                viewListBook(bookName, bookType, bookCode, bookPrice, currentSize, bookAmount);
                break;
            case 4:
                if(currentSize == 0){
                    printf("\nHave no book to delete\n");
                }
                deleteBook(bookName, bookType, bookCode, bookPrice, &currentSize, bookAmount);
                break;
            case 5:
                if(currentSize == 0){
                    printf("\nHave no book to delete\n");
                }
                deleteAllBook(bookName, bookType, bookCode, bookPrice, &currentSize, bookAmount);
                break;
            case 6:
                if(currentSize == 0){
                    printf("\nHave no book to delete\n");
                }
                arrangingBook(bookName, bookType, bookCode, bookPrice, currentSize, bookAmount);
                break;
            case 7:
                if(currentSize == 0){
                    printf("\nHave no book to delete\n");
                }
                copyBook(bookName, bookType, bookCode, bookPrice, currentSize, bookAmount);
                break;
        }
    } while(choice >= 1 && choice <= 7);

    return 0;
}


void initTestObject(char bookName[][40], char bookType[][40], char bookCode[][40], double bookPrice[], int *currentSize, int bookAmount[]){
    strcpy(bookName[0], "In Search of Lost Time");
    strcpy(bookName[1], "Ulyssese");
    strcpy(bookName[2], "Don Quixote");
    strcpy(bookName[3], "One Hundred Years of Solitude");
    strcpy(bookName[4], "The Great Gatsby");

    strcpy(bookType[0], "novel");
    strcpy(bookType[1], "novel");
    strcpy(bookType[2], "novel");
    strcpy(bookType[3], "novel");
    strcpy(bookType[4], "novel");

    strcpy(bookCode[0], "aBxgh1");
    strcpy(bookCode[1], "aBxgh2");
    strcpy(bookCode[2], "aBxgh3");
    strcpy(bookCode[3], "aBxgh4");
    strcpy(bookCode[4], "aBxgh5");

    bookPrice[0] = 12345;
    bookPrice[1] = 54321;
    bookPrice[2] = 11122;
    bookPrice[3] = 13579;
    bookPrice[4] = 66699;

    bookAmount[0] = 1;
    bookAmount[1] = 1;
    bookAmount[2] = 1;
    bookAmount[3] = 1;
    bookAmount[4] = 1;

    *currentSize = 5;
}


void addNewBook(char bookName[][40], char bookType[][40], char bookCode[][40], double bookPrice[], int bookAmount[], int *currentSize){

    int choice, number, index;

    do{
        printf("\n\t1- Add single book");
        printf("\n\t2- Add list of books");
        printf("\n\tSelect a valid option<1-2>: ");
        scanf("%d", &choice);
    } while(choice < 1 && choice > 2);

    switch(choice){
        case 1:
            *currentSize += addSingleBook(bookName, bookType, bookCode, bookPrice, bookAmount, *currentSize);;
            break;
        case 2:
            printf("\n\tNumber of book to add: ");
            scanf("%d", &number);
            for(index = 0; index < number; index++){
                *currentSize += addSingleBook(bookName, bookType, bookCode, bookPrice, bookAmount, *currentSize);
            }

            break;
    }

}   

int addSingleBook(char bookName[][40], char bookType[][40], char bookCode[][40], double bookPrice[], int bookAmount[], int size){
    int tempBookAmount, index, count = 0;
    char tempBookName[40], tempBookType[40], tempBookCode[40];
    double tempBookPrice;


    printf("\t-----------");
    printf("\n\tBook name: ");
    getchar();
    scanf("%[^\n]", tempBookName);
    printf("\tBook type: ");
    getchar();
    scanf("%[^\n]", tempBookType);
    printf("\tBook code: ");
    getchar();
    scanf("%[^\n]", tempBookCode);
    printf("\tBook price: ");
    scanf("%lf", &tempBookPrice);

    for(index = 0; index < size; index ++){
        if(strcmp(tempBookName, bookName[index]) == 0){

            strcpy(bookType[index], tempBookType);
            strcpy(bookCode[index], tempBookCode);
            bookPrice[index] = tempBookPrice;
            bookAmount[index] += 1;

            count ++;
            break;
        }
    }

    if(count == 0){
        strcpy(bookName[size], tempBookName);
        strcpy(bookType[size], tempBookType);
        strcpy(bookCode[size], tempBookCode);
        bookPrice[size] = tempBookPrice;
        bookAmount[size] = 1;
    }

    if(count == 0){
        return 1;
    }
    else{
        return 0;
    }
}

void viewListBook(char bookName[][40], char bookType[][40], char bookCode[][40], double bookPrice[], int size, int bookAmount[]){
    int index;

    printf("\n\tList data:");
    for(index = 0; index < size; index++){
        printf("\n\t%d - name: %s| type: %s| code: %s | price: %.2lf vnd| amount: %d", index + 1, bookName[index], bookType[index], bookCode[index], bookPrice[index], bookAmount[index]);
    }
}

void viewSingleBook(char bookName[][40], char bookType[][40], char bookCode[][40], double bookPrice[], int size, int bookAmount[]){

    int index, count = 0;
    char tempBookName[40];

    printf("Enter name of book to find: ");
    getchar();
    scanf("%[^\n]", tempBookName);

    printf("Result search:\n");
    for(index = 0; index < size; index++){
        if(strcmp(tempBookName, bookName[index]) == 0){
            printf("\n\t%d - name: %s| type: %s| code: %s | price: %.2lf vnd| amount: %d", index + 1, bookName[index], bookType[index], bookCode[index], bookPrice[index], bookAmount[index]);
            count ++;
        }
    }

    if(count == 0){
        printf("Not found!\n");
    }

}

void deleteBook(char bookName[][40], char bookType[][40], char bookCode[][40], double bookPrice[], int *currentSize, int bookAmount[]){
    int index, count = 0;
    char tempName[40];

    printf("\n\tEnter name of book to delete: ");
    getchar();
    scanf("%[^\n]", tempName);

    for(index = 0; index < *currentSize; index++){
        if(strcmp(bookName[index], tempName) == 0){
            strcpy(bookName[index], "");
            strcpy(bookType[index], "");
            strcpy(bookCode[index], "");
            bookAmount[index] = 0;
            bookPrice[index] = 0;

            count ++;
        }
    }

    for(index = 0; index < *currentSize - 1; index++){
        if(strcmp(bookName[index], "") == 0){
            strcpy(bookName[index], bookName[index + 1]);
            strcpy(bookType[index], bookType[index + 1]);
            strcpy(bookCode[index], bookCode[index + 1]);
            bookAmount[index] = bookAmount[index + 1];
            bookAmount[index + 1] = 0;
            bookPrice[index] = bookPrice[index + 1];
            bookPrice[index + 1] = 0;
        }
    }

    if(count == 0){
        printf("\nDon't have any book named: %s\n", tempName);
    }
    else{
        *currentSize -= 1;
        printf("\n\tDeleted! Result:\n");
        viewListBook(bookName, bookType, bookCode, bookPrice, *currentSize, bookAmount);
    }
}

void deleteAllBook(char bookName[][40], char bookType[][40], char bookCode[][40], double bookPrice[], int *currentSize, int bookAmount[]){
    int index;

    for(index = 0; index < *currentSize; index++){
        strcpy(bookName[index], "");
        strcpy(bookType[index], "");
        strcpy(bookCode[index], "");
        bookPrice[index] = 0;
        bookAmount[index] = 0;
    }

    *currentSize = 0;
    printf("\nDeleted all!\n");
}

void arrangingBook(char bookName[][40], char bookType[][40], char bookCode[][40], double bookPrice[], int size, int bookAmount[]){
    int index1, index2, tempInt;
    int tempBookAmount[MAXN];
    char tempBookName[MAXN][40], tempBookType[MAXN][40], tempBookCode[MAXN][40], tempString[40];
    double tempBookPrice[MAXN], tempDouble;

    for(index1 = 0; index1 < size; index1++){
        strcpy(tempBookName[index1], bookName[index1]);
        strcpy(tempBookType[index1], bookType[index1]);
        strcpy(tempBookCode[index1], bookCode[index1]);
        tempBookPrice[index1] = bookPrice[index1];
        tempBookAmount[index1] = bookAmount[index1];
    }

    for(index1 = 0; index1 < size-1; index1++){
        for(index2 = index1+1; index2 < size; index2++){
            if(strcmp(tempBookName[index1], tempBookName[index2]) == 1){
                tempInt = tempBookAmount[index1];
                tempBookAmount[index1] = tempBookAmount[index2];
                tempBookAmount[index2] = tempInt;

                strcpy(tempString, tempBookName[index1]);
                strcpy(tempBookName[index1], tempBookName[index2]);
                strcpy(tempBookName[index2], tempString);

                strcpy(tempString, tempBookType[index1]);
                strcpy(tempBookType[index1], tempBookType[index2]);
                strcpy(tempBookType[index2], tempString);

                strcpy(tempString, tempBookCode[index1]);
                strcpy(tempBookCode[index1], tempBookCode[index2]);
                strcpy(tempBookCode[index2], tempString);

                tempDouble = tempBookPrice[index1];
                tempBookPrice[index1] = tempBookPrice[index2];
                tempBookPrice[index2] = tempDouble;
            }
        }
    }

    printf("\nResult after sort:\n");
    for(index1 = 0; index1 < size; index1++){
        printf("\n\t%d - name: %s| amount: %d| price: %.2lf", index1 + 1, tempBookName[index1], tempBookAmount[index1], tempBookPrice[index1]);
    }
}

void copyBook(char bookName[][40], char bookType[][40], char bookCode[][40], double bookPrice[], int size, int bookAmount[]){
    char fileName[40];
    int continueWrite = 1, index;

    printf("\nEnter file name: ");
    getchar();
    scanf("%[^\n]", fileName);

	if(writeFile(fileName, bookName, bookType, bookCode, bookPrice, size, bookAmount) == 1){
		printf("\nCopy successful!\n");
	}
	else{
		printf("Writing the file fail!\n");
	}
}

int exist(char *fileName){
	int existed = 0;
	
	FILE* f = fopen(fileName, "r");

	if(f != NULL){
		existed = 1;
		fclose(f);
	}
	
	return existed;
}

int writeFile(char *fileName, char bookName[][40], char bookType[][40], char bookCode[][40], double bookPrice[], int size, int bookAmount[]){ 
    int index;
    char choice;
	
	if(exist(fileName) == 1){
		printf("The file %s existed. Override it Y/N? :", fileName);
        getchar();
		scanf("%c", &choice);
        if(toupper(choice) == 'N'){
            return 0;
        }
	}
	
	FILE* f = fopen(fileName, "w");
	fflush(stdin);
	
	for(index = 0; index < size; index++){
        fprintf(f,"%d - name: %s| type: %s| code: %s | price: %.2lf vnd| amount: %d\n", index + 1, bookName[index], bookType[index], bookCode[index], bookPrice[index], bookAmount[index]);
    }
	
	fclose(f);
	return 1;
}

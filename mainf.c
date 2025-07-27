#include<stdio.h>
#include<math.h>
int det2x2();
int det3x3();
void matrixAddition();
void matrixSubtraction();
void matrixMultiplication();
void transpose();
void power();

int main(){
    int ch,det;

    printf("-----------\"Welcome to matrix Calculator\"-----------\n");

    menu:
    printf("\nSelect choice to calculate:\n\n");
    printf("1) Determinant of 2x2 matrix\n");
    printf("2) Determinant of 3x3 matrix\n");
    printf("3) Matrix Addition (2x2 or 3x3)\n");
    printf("4) Matrix Subtraction (2x2 or 3x3)\n");
    printf("5) Matrix Multiplication\n");
    printf("6) Transpose of a matrix (2x2 or 3x3)\n");
    printf("7) Power of a matrix (2x2 or 3x3)\n");
    printf("0) Exit\n\n");

    do{
        scanf("%d", &ch);

        switch(ch){
            case 1:
            det=det2x2();
            printf("-------------------------------------------\n");
            printf("The determinant of the matrix is: %d\n",det);
            if(det==0){
                printf("The matrix is linearly dependent.\n");
            }
            else{
                printf("The matrix is linearly independent.\n");
            }
            printf("-------------------------------------------\n");
            break;

            case 2:
            det=det3x3();
            printf("-------------------------------------------\n");
            printf("The determinant of the 3x3 matrix is: %d\n", det);

            if (det==0) {
                printf("The matrix is linearly dependent.\n");
            }
            else{
                printf("The matrix is linearly independent.\n");
            }
            printf("-------------------------------------------\n");
            break;

            case 3:
            matrixAddition();
            break;

            case 4:
            matrixSubtraction();
            break;

            case 5:
            matrixMultiplication();
            break;

            case 6:
            transpose();
            break;

            case 7:
            power();
            break;
            
            case 0:
            printf("Exited calculator\n");
            return 0;

            default:
            printf("Entered Invalid Choice!\n");
            break;
        }
    }
    while(ch!=0);
    return 0;
}

int det2x2(){
    int det,arr[2][2];

    for (int i=0;i<2;i++){
        for (int j=0;j<2;j++){
            printf("Enter the value for arr[%d][%d]: ",i,j);
            scanf("%d",&arr[i][j]);
        }
    }
    printf("\n");

    det=(arr[0][0] * arr[1][1]) - 
        (arr[0][1] * arr[1][0]);

    return det;
}


int det3x3(){
    int det,arr[3][3];

    for (int i=0;i<3;i++){
        for (int j=0;j<3;j++) {
            printf("Enter the value for arr[%d][%d]: ",i,j);
            scanf("%d",&arr[i][j]);
        }
    }
    printf("\n");

    det = arr[0][0] * (arr[1][1] * arr[2][2] - arr[1][2] * arr[2][1]) -
          arr[0][1] * (arr[1][0] * arr[2][2] - arr[1][2] * arr[2][0]) +
          arr[0][2] * (arr[1][0] * arr[2][1] - arr[1][1] * arr[2][0]);

    return det;
}


void matrixAddition(){
    int n;
    printf("Enter the size of the matrix (2 for 2x2, 3 for 3x3): ");
    scanf("%d", &n);

    if (n != 2 && n != 3) {
        printf("Invalid size! Only 2x2 and 3x3 matrices are supported.\n");
        return;
    }

    int arr1[n][n], arr2[n][n], result[n][n];

    printf("Enter values for first matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Enter the value for arr[%d][%d]: ",i,j);
            scanf("%d", &arr1[i][j]);
        }
    }

    printf("Enter values for second matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Enter the value for arr[%d][%d]: ",i,j);
            scanf("%d", &arr2[i][j]);
        }
    }

    printf("The result of matrix addition is:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = arr1[i][j] + arr2[i][j];
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}


void matrixSubtraction() {
    int n;
    printf("Enter the size of the matrix (2 for 2x2, 3 for 3x3): ");
    scanf("%d", &n);

    if (n != 2 && n != 3) {
        printf("Invalid size! Only 2x2 and 3x3 matrices are supported.\n");
        return;
    }

    int arr1[n][n], arr2[n][n], result[n][n];

    printf("Enter values for first matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Enter the value for arr[%d][%d]: ",i,j);
            scanf("%d", &arr1[i][j]);
        }
    }

    printf("Enter values for second matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Enter the value for arr[%d][%d]: ",i,j);
            scanf("%d", &arr2[i][j]);
        }
    }

    printf("The result of matrix subtraction is:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = arr1[i][j] - arr2[i][j];
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}


void matrixMultiplication() {
    int m,n,r,c;
    printf("Enter the row size and column size of the matrix 1 : ");
    scanf("%d %d",&m,&n);
    printf("Enter the row size and column size of the matrix 2 : ");
    scanf("%d %d",&r,&c);

    if (n!=r) {
        printf("Invalid size! matrices are not supported.\n");
        return;
    }

    int arr1[m][n], arr2[r][c], result[m][c];

    printf("Enter values for first matrix:\n");
    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            printf("Enter the value for arr[%d][%d]: ",i,j);
            scanf("%d",&arr1[i][j]);
        }
    }

    printf("Enter values for second matrix:\n");
    for(int i=0;i<r;i++) {
        for(int j=0;j<c;j++) {
            printf("Enter the value for arr[%d][%d]: ",i,j);
            scanf("%d",&arr2[i][j]);
        }
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<c;j++){
            result[i][j]=0;
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < c; j++) {
            for (int k = 0; k < n; k++) {
                result[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }

    printf("The result of matrix multiplication is:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}


void transpose(){
    int n;
    printf("Enter the size of the matrix (2 for 2x2, 3 for 3x3): ");
    scanf("%d", &n);
    
    if (n != 2 && n != 3) {
        printf("Invalid size! Only 2x2 and 3x3 matrices are supported.\n");
        return;
    }

    int arr[n][n];
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            printf("Enter the value for arr[%d][%d]: ",i,j);
            scanf("%d",&arr[i][j]);
        }
    }
    printf("\n");
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int temp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp;
        }
    }

    printf("The result of transpose of matrix is:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}


void power(){
    int m,n,p;

    printf("Enter the row size and column size of the matrix : ");
    scanf("%d %d",&m,&n);

    if (m!=n) {
        printf("Invalid size! matrices are not supported.\n");
        return;
    }

    int arr[m][n],result[m][n],temp[m][n];

    printf("Enter values for the matrix:\n");
    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            printf("Enter the value for arr[%d][%d]: ",i,j);
            scanf("%d",&arr[i][j]);
            temp[i][j]=arr[i][j];
            result[i][j]=arr[i][j];
        }
    }

    printf("Enter power for calculation: ");
    scanf("%d",&p);
    int t=p;
    
    for (int power = 1; power < p; power++) {
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                temp[i][j]=0;
                for(int k=0;k<m;k++){
                    temp[i][j] += result[i][k] * arr[k][j];
                }
            }
        }
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++) {
                result[i][j] = temp[i][j];
            }
        }
    }

    printf("The result of matrix raised to power %d is:\n",t);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}
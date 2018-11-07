#include <iostream>

using namespace std;


int arr[]= {0};
int sum=0;


class matrix
{
    int** data;       // Pointer to 2-D array that will simulate matrix
    int row, col;

public:
    matrix() {}
    matrix(int r, int c, int num[])
    {
        row=r;
        col=c;

        data = new int* [row];

        for (int i = 0; i < row; i++)
            data[i] = new int [col];


        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                data[i][j] = num[i * col + j];
    }

    int operator =(matrix c)  // operator =
    {
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                data[i][j] = c.data[i][j];
    }






    friend matrix operator+  (matrix mat1, matrix mat2); // Add if same dimensions
    friend  matrix operator-  (matrix mat1, matrix mat2); // Sub if same dimensions
    friend  matrix operator*  (matrix mat1, matrix mat2); // Multi if col1 == row2
    friend  matrix operator+  (matrix mat1, int scalar);  // Add a scalar
    friend  matrix operator-  (matrix mat1, int scalar);  // Subtract a scalar
    friend  matrix operator*  (matrix mat1, int scalar);  // Multiple by scalar




    friend  matrix operator+= (matrix& mat1, matrix mat2); // mat1 changes & return

    friend  matrix operator-= (matrix& mat1, matrix mat2); // mat1 changes + return new

    friend  matrix operator+= (matrix& mat, int scalar);   // change mat & return new matrix
    friend  matrix operator-= (matrix& mat, int scalar);   // change mat & return new matrix
    friend  void   operator++ (matrix& mat);   	// Add 1 to each element ++mat
    friend  void   operator-- (matrix& mat);    	// Sub 1 from each element --mat
    friend  istream& operator>> (istream& in, matrix& mat);




    friend  ostream& operator<< (ostream& out, matrix mat);
    friend  bool   operator== (matrix mat1, matrix mat2);	// True if identical
    friend  bool   operator!= (matrix mat1, matrix mat2); 	// True if not same
    friend  bool   isSquare   (matrix mat);  // True if square matrix
    friend  bool   isSymetric (matrix mat1,matrix mat2); // True if square and symmetric
    friend  bool   isIdentity (matrix mat);  // True if square and identity
    friend  matrix transpose(matrix mat);    // Return new matrix with the transpose

};


matrix operator+  (matrix mat1, matrix mat2) // sum two object (we can use / or * or - instead of +)
{
    if(mat1.col==mat2.col && mat1.row==mat1.row)
    {

        matrix result(mat1.row,mat1.col,arr);

        for(int i=0; i<mat1.row; i++)
        {
            for(int j=0; j<mat1.col; j++)
            {
                result.data[i][j]=mat1.data[i][j]+mat2.data[i][j];
            }
        }
        return result;
    }
}

//_______________________________________________________________________________________________



matrix operator-  (matrix mat1, matrix mat2) // sum two object (we can use / or * or - instead of +)
{
    if(mat1.col==mat2.col && mat1.row==mat1.row)
    {
        matrix result(mat1.row,mat1.col,arr);


        for(int i=0; i<mat1.row; i++)
        {
            for(int j=0; j<mat1.col; j++)
            {
                result.data[i][j]=mat1.data[i][j]-mat2.data[i][j];
            }
        }
        return result;
    }
}
//_______________________________________________________________________________________________


matrix operator*  (matrix mat1, matrix mat2) // sum two object (we can use / or * or - instead of +)
{
    if(mat1.col==mat2.col && mat1.row==mat2.row)
    {
        matrix result(mat1.row,mat1.col,arr);


        for(int i=0; i<mat1.row; i++)
        {
            for(int j=0; j<mat1.col; j++)
            {
                result.data[i][j]=mat1.data[i][j]*mat2.data[i][j];
            }
        }
        return result;
    }
}

//_______________________________________________________________________________________________


matrix operator+  (matrix mat1, int scalar) // sum object to integer (we can use / or * or - instead of +)
{
    for(int i=0; i<mat1.row; i++)
    {
        for(int j=0 ; j<mat1.col ; j++)
        {
            mat1.data[i][j]=mat1.data[i][j]+scalar;
        }
    }
    return mat1;
}

//_______________________________________________________________________________________________

matrix operator-  (matrix mat1, int scalar) // sum object to integer (we can use / or * or - instead of +)
{
    for(int i=0; i<mat1.row; i++)
    {
        for(int j=0 ; j<mat1.col ; j++)
        {
            mat1.data[i][j]=mat1.data[i][j]-scalar;
        }
    }
    return mat1;
}

//_______________________________________________________________________________________________

matrix operator*  (matrix mat1, int scalar) // sum object to integer (we can use / or * or - instead of +)
{
    for(int i=0; i<mat1.row; i++)
    {
        for(int j=0 ; j<mat1.col ; j++)
        {
            mat1.data[i][j]=mat1.data[i][j]*scalar;
        }
    }
    return mat1;
}

//_______________________________________________________________________________________________



matrix operator+= (matrix& mat1, matrix mat2) // sum two object (we can use /= or *= or -= instead of +=)
{
    if(mat1.col==mat2.col && mat1.row==mat2.row)
    {
        for(int i=0; i<mat1.row; i++)
        {
            for( int j=0 ; j<mat1.col; j++ )
            {
                mat1.data[i][j]+=mat2.data[i][j];
            }
        }

    }

}

//_______________________________________________________________________________________________


matrix operator-= (matrix& mat1, matrix mat2) // sum two object (we can use /= or *= or -= instead of +=)
{
    if(mat1.col==mat2.col && mat1.row==mat2.row)
    {
        for(int i=0; i<mat1.row; i++)
        {
            for( int j=0 ; j<mat1.col; j++ )
            {
                mat1.data[i][j]-=mat2.data[i][j];
            }
        }

    }

}

//_______________________________________________________________________________________________


matrix operator+= (matrix& mat1, int scalar) // sum  object to integer (we can use /= or *= or -= instead of +=)
{
    for(int i=0; i<mat1.row; i++)
    {
        for(int j=0; j<mat1.col; j++)
        {
            mat1.data[i][j]+=scalar;
        }
    }
}

//_______________________________________________________________________________________________

matrix operator-= (matrix& mat1, int scalar) // sum  object to integer (we can use /= or *= or -= instead of +=)
{
    for(int i=0; i<mat1.row; i++)
    {
        for(int j=0; j<mat1.col; j++)
        {
            mat1.data[i][j]-=scalar;
        }
    }
}


//_______________________________________________________________________________________________

void   operator++ (matrix& mat1) // increase each element of the array by 1 (we can use -- instead of ++)
{
    for(int i=0; i<mat1.row; i++)
    {
        for(int j=0 ; j<mat1.col ; j++)
        {
            mat1.data[i][j]++;
        }
    }

}

//_______________________________________________________________________________________________


void   operator-- (matrix& mat1) // increase each element of the array by 1 (we can use -- instead of ++)
{
    for(int i=0; i<mat1.row; i++)
    {
        for(int j=0 ; j<mat1.col ; j++)
        {
            mat1.data[i][j]--;
        }
    }

}

//_______________________________________________________________________________________________



istream& operator>> (istream& in, matrix& mat) // make cin for the object
{
    for(int i=0; i<mat.row; i++)
    {
        for(int j=0 ; j<mat.col ; j++)
        {
            in>>mat.data[i][j];
        }
    }
    return in;

}

//_______________________________________________________________________________________________

ostream& operator<< (ostream& out, matrix mat) //make cout for the object
{
    for(int i=0; i<mat.row; i++)
    {
        for(int j=0 ; j<mat.col ; j++)
        {
            out<<mat.data[i][j]<<" ";
        }
        cout<<endl;
    }
    return out;

}


//_______________________________________________________________________________________________


bool   operator== (matrix mat1, matrix mat2) // check if matrix 1 equal matrix 2 or not (we can use int instead of bool)
{
    for(int i=0; i<mat1.row; i++)
    {
        for(int j=0; j<mat1.col; j++)
        {
            if(mat1.data[i]==mat2.data[i])
                sum++;
        }

    }
    if(sum==mat1.col*mat1.row)
        return true;
    else
        return false;
}


//_______________________________________________________________________________________________



bool   operator!= (matrix mat1, matrix mat2) // check if matrix 1 equal matrix 2 or not (we can use int instead of bool)
{
    int sum0=0;
    for(int i=0; i<mat1.row; i++)
    {
        for(int j=0; j<mat1.col; j++)
        {
            if(mat1.data[i]==mat2.data[i])
                sum0++;
        }

    }
    if(sum0!=mat1.col*mat1.row)
        return true;
    else
        return false;
}

//_______________________________________________________________________________________________




bool   isSquare   (matrix mat) // check if the matrix is square or not  (we can use int instead of bool)
{
    return (mat.row==mat.col? true : false);
}

//_______________________________________________________________________________________________


bool   isSymetric (matrix mat1,matrix mat)  // check if the matrix is symetric or not  (we can use int instead of bool)
{
    int sum2=0;
    if(mat1.row==mat1.col)
    {

        for(int i=0; i<mat1.row; i++)
        {
            for(int j=0; j<mat1.col; j++)
            {
                mat1.data[j][i]=mat.data[i][j];
            }
        }
        for(int i=0; i<mat1.row; i++)
        {
            for(int j=0; j<mat1.col; j++)
            {
                if(mat1.data[i][j]==mat.data[i][j])
                    sum2++;
            }
        }
        if(sum2==mat1.row*mat1.col)
            return true;
        else
            return false;
    }
    else
        return false;


}

//_______________________________________________________________________________________________


bool   isIdentity (matrix mat) // check if the matrix is identity or not  (we can use int instead of bool)
{
    int k=0;
    int sum1=0;
    if(mat.row==mat.col)
    {
        for(int i=0; i<mat.row; i++)
        {
            for(int j=0; j<mat.col; j++)
            {
                if(mat.data[i][j]==0)
                    sum1++;
                if(k==j && mat.data[i][j]==1)
                    sum1++;
            }
            k++;
        }


        if(sum1==mat.col*mat.row)
            return true;
        else
            return false;
    }
    else
        return false;

}


//_______________________________________________________________________________________________




matrix transpose(matrix mat) // make transpose for the matrix
{
    cout<<"The transpose of the matrix : \n";
    for(int i=0; i<mat.col; i++)
    {
        for(int j=0; j<mat.row; j++)
        {
            cout<<mat.data[j][i]<<" ";
        }
        cout<<endl;
    }
}






int main()
{
    int data1 [] = {1,2,3,4,5,6,7,8};
    int data2 [] = {13,233,3,4,5,6};
    int data3 [] = {10,100,10,100,10,100,10,100};


    matrix  mat1(4,2,data1), mat2(2,3,data2), mat3(4,2,data3),mat;

    matrix mat6(mat1);  // shallow copy
    cout<<mat1<<endl;
    cout<<endl<<endl;

    matrix mat7=mat1;  // operator =
    cout<<mat1<<endl;
    cout<<endl<<endl;


    cout<<"matrix no.1 : \n"<<mat1<<endl;
    cout<<endl<<endl;
    cout<<"matrix no.2 : \n"<<mat2<<endl;
    cout<<endl<<endl;
    cout<<"matrix no.3 : \n"<<mat3<<endl;
    cout<<endl<<endl;



//_________________________________________




    cout<<"mat1 + mat3 = \n";
    cout<<mat1+mat3;
    cout<<endl<<endl;


    cout<<"mat1 - mat3 = \n";
    cout<<mat1-mat3;
    cout<<endl<<endl;


    cout<<"mat1 * mat3 = \n";
    cout<<mat1*mat3;
    cout<<endl<<endl;








//_________________________________________



    cout<<"mat1 + 5 =  \n"<<mat1+5<<endl;
    cout<<endl<<endl;
    cout<<"mat1 - 5 =  \n"<<mat1-5<<endl;
    cout<<endl<<endl;
    cout<<"mat1 * 5 =  \n"<<mat1*5<<endl;
    cout<<endl<<endl;

//_________________________________________


    mat1+=mat3;
    cout<<"mat1+=mat3 : \n"<<mat1<<endl;
    cout<<endl<<endl;
    mat1-=mat3;
    cout<<"mat1-=mat3 : \n"<<mat1<<endl;
    cout<<endl<<endl;


    mat1+= mat3 += mat3;
    cout <<"mat1 after this operation (mat1+= mat3 += mat3) is equal : \n"<< mat1 << endl;
    cout<<endl<<endl;
    cout <<"mat3 after this operation (mat1+= mat3 += mat3) is equal : \n"<< mat3 << endl;
    cout<<endl<<endl;


//_________________________________________


    mat1+=15;
    cout<<"mat1+=15 : \n"<<mat1<<endl;
    cout<<endl<<endl;
    mat1-=15;
    cout<<"mat1-=15 : \n"<<mat1<<endl;
    cout<<endl<<endl;


//_________________________________________

    ++mat1;
    cout<<"mat1++ : \n"<<mat1<<endl;
    cout<<endl<<endl;

    ++mat2;
    cout<<"mat2++ : \n"<<mat2<<endl;
    cout<<endl<<endl;
    ++mat3;
    cout<<"mat3++ : \n"<<mat3<<endl;
    cout<<endl<<endl;

//_________________________________________

    --mat1;
    cout<<"mat2-- : \n"<<mat1<<endl;
    cout<<endl<<endl;
    --mat2;
    cout<<"mat2-- : \n"<<mat2<<endl;
    cout<<endl<<endl;
    --mat3;
    cout<<"mat2-- : \n"<<mat3<<endl;
    cout<<endl<<endl;


//_________________________________________


    cout<<"enter the matrix : "<<endl;
    cin>>mat1; // ifstream and ofstream
    cout<<"The matrix which you entered is : \n" <<mat1<<endl;
    cout<<endl<<endl;


//_________________________________________

    if(mat1==mat3) // True if identical (== operator)
        cout<<"they are identical"<<endl;
    else
        cout<<"they are not identical"<<endl;

    cout<<endl<<endl;

//_________________________________________

    if(mat1!=mat3)  // True if not same (!= operator)
        cout<<"they are identical"<<endl;
    else
        cout<<"they are not identical"<<endl;

    cout<<endl<<endl;
//_________________________________________



    // function will be square when the number of rows equal number of columns.

    cout<<isSquare(mat1)<<endl;  // square or not
    cout<<isSquare(mat2)<<endl;
    cout<<isSquare(mat3)<<endl;

    cout<<endl<<endl;


//_________________________________________

    // function will be Symmetric when the matrix equal its transpose
    // and number of rows equal number of columns.

    cout<<isSymetric(mat1,mat1)<<endl; // Symmetric or not
    cout<<isSymetric(mat2,mat2)<<endl;
    cout<<isSymetric(mat3,mat3)<<endl;

    cout<<endl<<endl;


//_________________________________________



    // function will be Identity when all number in it equal 0 except the number of the main diameter equal 1
    // and the matrix should be symmetric too.

    cout<<isIdentity(mat1)<<endl; // Identity or not
    cout<<isIdentity(mat2)<<endl;
    cout<<isIdentity(mat3)<<endl;

    cout<<endl<<endl;
//_________________________________________



    transpose(mat1); // transpose of the matrix 1
    transpose(mat2); // transpose of the matrix 2
    transpose(mat3); // transpose of the matrix 3

    cout<<endl<<endl;


//_________________________________________________________________________


}

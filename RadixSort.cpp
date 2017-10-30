

void counting_sort(int* arr, int n);
void radix_sort(int *arr, int n, int base);
void sort_at_digit(int *arr, int n, int base, int digit_index);
int get_digit(int number, int base, int digit_index);
int max_element(int* arr, int n);
int min_element(int* arr, int n);
int count_digits(int number);
void copy_array(int *from, int *to, int size);


void counting_sort(int* arr, int n)
{
    int min=min_element(arr,n);
    int max=max_element(arr,n);
    int* indexes=new int[max-min+1];// Create array of indices

    for (int j=0;j<max-min+1;j++)
    {
      indexes[j]=0;//Make all elements of indices array 0
    }

    for (int k=0;k<n;k++)
    {
      indexes[arr[k]-min]++; // Substract minimum from each element and make indices array
    }                        //through counting the number of times the same elements met

    for (int m=0;m<max-min+1;m++)//Run through all values of indices array
    {
        for (int h=0;h<indexes[m];h++)
        {
            *arr++ =m+min; // Add to current position  array value of the current index  of the indices array
        }                  //and so many times , the number of times corresponding index/element met in source array
    }                      //and plus min value of source array

    delete[]indexes;

}
void radix_sort(int* arr,int N,int base) // use sort at digit as many times as digits in maximum element
{

    int max=max_element(arr,N);
    int count=count_digits(max);\
    for (int i=0;i<count;i++)
    {
       sort_at_digit(arr,N,base,i);
    }
}

void copy_array(int* source,int* copy,int s) // make copy of array
{
    for (int i = 0; i < s; ++i)
        copy[i] = source[i];
}
int max_element(int* arrm, int N) // find maximum element in array
{
    int max=arrm[0];
    for (int i=0;i<N;i++)
    {
        if (arrm[i]>max)
        {
            max=arrm[i];

        }
    }
    return max;
}
int min_element(int* arrm,int N) // find minimum element in array
{
    int min=arrm[0];
    for (int i=0;i<N;i++)
    {
         if (arrm[i]<min)
         {
         min=arrm[i];
}
}
    return min;
}
int get_digit(int num,int base,int dig_ind) // get needed digit
{
   for (int i=0;i<dig_ind;i++)
   {
        num=num/base;
   }
   return num % base;
}
void sort_at_digit(int* arrd,int N,int base,int dig_ind)
{
    int* arrindex=new int[base]; // Create array of indices
    int* resularr=new int[N];
   for (int i=0;i<base;i++)
   {
       arrindex[i]=0; // Make all elements of indices array 0
   }
      for (int i=0;i<N;i++ )
      {
           arrindex[get_digit(arrd[i],base,dig_ind)]++; //Count the number of times corresponding to the digit met
        }

 for (int k=1;k<base;k++)
 {
     arrindex[k]+=arrindex[k-1];// define the index following the last number of this digit
 }
 for (int j=N-1;j>=0;j--)
 {
     resularr[arrindex[get_digit(arrd[j],base,dig_ind)]-1]=arrd[j];//iterate through the source array elements, starting with the older towards younger
     arrindex[get_digit(arrd[j],base,dig_ind)]--;                  //and put them into a new array of the corresponding index preliminary reducing on 1
 }
for (int i=0;i<N;i++)
{
    arrd[i]=resularr[i];
}
    delete[] arrindex;
    delete[] resularr;
}
int count_digits(int number)  //сount the number of digits
{
        int count = (number == 0) ? 1 : 0;
        while (number != 0)
        {
            count++;
            number /= 10;
        }
        return count;
    }








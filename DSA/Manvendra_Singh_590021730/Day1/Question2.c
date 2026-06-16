// A simple function in which sum starts with 0 then arr[1] adds to sum and sum updates ,the loop continues till 1 - arraysize.

int SumArray(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    return sum;
}
int countSubarrays(int arr[], int n, int limit)
{
    int count = 0;
    int length = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= limit)
        {
            length++;
        }
        else
        {
            length = 0;
        }

        count += length;
    }

    return count;
}

int countSubarraysWithBoundedMax(int arr[], int n, int left, int right)
{
    return countSubarrays(arr, n, right) -
           countSubarrays(arr, n, left - 1);
}
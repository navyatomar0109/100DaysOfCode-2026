long long countSubarrays(int arr[], int n, int limit)
{
    long long count = 0;
    int len = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= limit)
        {
            len++;
        }
        else
        {
            len = 0;
        }
        count += len;
    }
    return count;
}
long long countValidSubarrays(int arr[], int n, int l, int r)
{
    return countSubarrays(arr, n, r) - countSubarrays(arr, n, l - 1);
}
#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

void swap(int *a, int *b)
{
   int t = *a;
   *a = *b;
   *b = t;
}

int array_length(int a[])
{
   int i = 0;
   while (a[i])
   {
      i++;
   }
   return i;
}

void selection_sort_for_radix(int a[], int length, int exp)
{
   int temp;

   for (int i = 0; i < length - 1; i++)
   {
      for (int j = i + 1; j < length; j++)
      {
         if ((a[i] / exp) % 10 > (a[j] / exp) % 10)
         {
            swap(a[i], a[j]);
         }
      }
   }
}

void counting_sort_for_radix(int a[], int length, int exponential)
{
   int temp[length];
   int frequency[10] = {0}; // as total 9 digits are possible

   for (int i = 0; i < length; i++)
   {
      frequency[(a[i] / exponential) % 10]++;
   }

   for (int i = 1; i < 10; i++)
   {
      frequency[i] += frequency[i - 1];
   }

   for (int i = length - 1; i >= 0; i--)
   {
      temp[frequency[(a[i] / exponential) % 10] - 1] = a[i];
      frequency[(a[i] / exponential) % 10]--;
   }

   for (int i = 0; i < length; i++)
   {
      a[i] = temp[i];
   }
}

void merge(int a[], int start, int end, int mid, int exp)
{

   // cout << "X\n";

   int left_array_size = mid - start + 1;
   int right_array_size = end - mid;

   // cout << exp << endl;

   int left_array[left_array_size], right_array[right_array_size];

   for (int k = 0; k < left_array_size; k++)
   {
      left_array[k] = a[start + k];
      // cout << left_array[k] << " ";
   }

   for (int k = 0; k < right_array_size; k++)
   {
      right_array[k] = a[mid + 1 + k];
   }

   int i = 0, j = 0, count = start;

   while (i < left_array_size && j < right_array_size)
   {
      if ((left_array[i] / exp) % 10 <= (right_array[j] / exp) % 10)
      {
         a[count] = left_array[i];
         i++;
         count++;
      }
      else
      {
         a[count] = right_array[j];
         j++;
         count++;
      }
   }

   while (i < left_array_size)
   {
      a[count] = left_array[i];
      i++;
      count++;
   }

   while (j < right_array_size)
   {
      a[count] = right_array[j];
      j++;
      count++;
   }
}

void merge_sort_for_radix(int a[], int start, int end, int exp)
{

   if (start < end)
   {
      int mid = start + (end - start) / 2;

      merge_sort_for_radix(a, start, mid, exp);
      merge_sort_for_radix(a, mid + 1, end, exp);
      merge(a, start, end, mid, exp);
   }
}

int partition(int a[], int low, int high, int exp)
{
   // printf("x\n");
   int pivot = (a[high]);

   int i = low - 1;

   for (int j = low; j <= high - 1; j++)
   {
      if ((a[j])< (pivot))
      {
         i++;
         swap(&a[i], &a[j]);
      }
   }

   swap(&a[i + 1], &a[high]);
   return i + 1;
}

void quick_sort_for_radix(int a[], int low, int high, int exp)
{
   if (low < high)
   {
      int partition_index = partition(a, low, high, exp);

      quick_sort_for_radix(a, low, partition_index - 1, exp);
      quick_sort_for_radix(a, partition_index + 1, high, exp);
   }
}

void radix_sort_selection(int a[], int length)
{
   int max = a[0];

   for (int i = 0; i < length; i++)
   {
      if (a[i] > max)
      {
         max = a[i];
      }
   }
   // cout << max << endl;

   for (int i = 1; max / i > 0; i *= 10)
   {
      selection_sort_for_radix(a, length, i);
   }
}

void radix_sort_counting(int a[], int length)
{
   int max = a[0];

   for (int i = 0; i < length; i++)
   {
      if (a[i] > max)
      {
         max = a[i];
      }
   }
   // cout << max << endl;

   for (int i = 1; max / i > 0; i *= 10)
   {
      counting_sort_for_radix(a, length, i);
   }
}

void radix_sort_merge(int a[], int length)
{
   int max = a[0];

   for (int i = 0; i < length; i++)
   {
      if (a[i] > max)
      {
         max = a[i];
      }
   }
   // cout << max << endl;

   for (int i = 1; max / i > 0; i *= 10)
   {
      merge_sort_for_radix(a, 0, length - 1, i);
   }
}

void radix_sort_quick(int a[], int length)
{
   int max = a[0];

   for (int i = 0; i < length; i++)
   {
      if (a[i] > max)
      {
         max = a[i];
      }
   }
   // cout << max << endl;

   for (int i = 1; max / i > 0; i *= 10)
   {
      quick_sort_for_radix(a, 0, length - 1, i);
   }
}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   freopen("input.txt", "w", stdout);
   // freopen("output.txt", "w", stdout);

   int length = 5000;

   int a[length];

   for (int i = 0; i < length; i++)
   {
      a[i] = rand() % 100000;

      if (a[i] < 10000)
         a[i] += 10000;

      // cin >> a[i];
   }

   // time count for selection

   auto start1 = high_resolution_clock::now();

   radix_sort_selection(a, length);

   for (int i = 0; i < length; i++)
   {
      cout << a[i] << " ";
   }

   cout << endl;

   auto stop1 = high_resolution_clock::now();

   auto duration1 = duration_cast<microseconds>(stop1 - start1);

   cout << "selection " << duration1.count() << " microsecond" << endl;

   // time count for counting

   auto start2 = high_resolution_clock::now();

   radix_sort_counting(a, length);

   for (int i = 0; i < length; i++)
   {
      cout << a[i] << " ";
   }

   cout << endl;

   auto stop2 = high_resolution_clock::now();

   auto duration2 = duration_cast<microseconds>(stop2 - start2);

   cout << "Counting " << duration2.count() << " microsecond" << endl;

   // time count for merge

   auto start3 = high_resolution_clock::now();

   radix_sort_merge(a, length);

   for (int i = 0; i < length; i++)
   {
      cout << a[i] << " ";
   }

   cout << endl;

   auto stop3 = high_resolution_clock::now();

   auto duration3 = duration_cast<microseconds>(stop3 - start3);

   cout << "Merge " << duration3.count() << " microsecond" << endl;

   // time count for quick

   auto start4 = high_resolution_clock::now();

   radix_sort_quick(a, length);

   for (int i = 0; i < length; i++)
   {
      cout << a[i] << " ";
   }

   cout << endl;

   auto stop4 = high_resolution_clock::now();

   auto duration4 = duration_cast<microseconds>(stop4 - start4);

   cout << "Quick " << duration4.count() << " microsecond" << endl;

   return 0;
}
#include <iostream>
#include <iomanip>
using namespace std;

struct Item
{
  int value, weight;
};

bool compare(Item a, Item b)
{
  double r1 = (double)a.value / a.weight;
  double r2 = (double)b.value / b.weight;
  return r1 > r2;
}

double fractionalKnapsack(int W, Item arr[], int n)
{

  sort(arr, arr + n, compare);

  double finalValue = 0.0;
  for (int i = 0; i < n; i++)
  {
    if (arr[i].weight <= W)
    {
      W -= arr[i].weight;
      finalValue += arr[i].value;
    }
    else
    {

      double fraction = (double)W / arr[i].weight;
      finalValue += arr[i].value * fraction;
      break;
    }
  }

  return finalValue;
}

int main()
{
  int n = 3;
  int W = 50;

  Item arr[] = {{60, 10}, {100, 20}, {120, 30}};

  double maxValue = fractionalKnapsack(W, arr, n);

  cout << fixed << setprecision(2);
  cout << "Maximum value in Knapsack = " << maxValue << endl;

  return 0;
}

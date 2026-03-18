// 0/1 Knapsack Greedy Approach WITHOUT using inbuilt functions
// Uses arrays and manual sorting (Bubble Sort)

#include <iostream>
using namespace std;

// Step 1: Structure for Item
struct Item
{
    int index;
    int weight;
    int value;
    float ratio;
};

// Step 2: Manual Bubble Sort (Descending order of ratio)
void sortItems(Item items[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (items[j].ratio < items[j + 1].ratio)
            {
                // Swap items
                Item temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }
}

// Step 3: Greedy Knapsack Function
int knapsackGreedy(int weights[], int values[], int n, int capacity, int selected[])
{
    Item items[100];

    // Step 3.1: Create items with ratio
    for (int i = 0; i < n; i++)
    {
        items[i].index = i;
        items[i].weight = weights[i];
        items[i].value = values[i];
        items[i].ratio = (float)values[i] / weights[i];
    }

    // Step 3.2: Sort items manually
    sortItems(items, n);

    int totalWeight = 0;
    int totalValue = 0;
    int count = 0;

    // Step 3.3: Select items greedily
    for (int i = 0; i < n; i++)
    {
        if (totalWeight + items[i].weight <= capacity)
        {
            selected[count] = items[i].index;
            count++;

            totalWeight += items[i].weight;
            totalValue += items[i].value;
        }
    }

    return totalValue;
}

// Step 4: Main Function
int main()
{
    int n, capacity;

    cout << "0/1 Knapsack Greedy Approach\n";

    cout << "Enter number of items: ";
    cin >> n;

    int weights[100], values[100], selected[100];

    for (int i = 0; i < n; i++)
    {
        cout << "Item " << i + 1 << " Weight: ";
        cin >> weights[i];

        cout << "Item " << i + 1 << " Value: ";
        cin >> values[i];
    }

    cout << "Enter capacity: ";
    cin >> capacity;

    int maxValue = knapsackGreedy(weights, values, n, capacity, selected);

    cout << "\nMaximum value = " << maxValue << endl;

    cout << "Selected items (0-indexed): ";
    for (int i = 0; i < n; i++)
    {
        if (selected[i] >= 0 && selected[i] < n)
            cout << selected[i] << " ";
    }

    return 0;
}
/*
0/1 Knapsack Greedy Approach
Enter number of items: 4
Item 1 Weight: 10
Item 1 Value: 60
Item 2 Weight: 20
Item 2 Value: 100
Item 3 Weight: 30
Item 3 Value: 120
Item 4 Weight: 5
Item 4 Value: 50
Enter capacity: 35

Maximum value = 210
Selected items (0-indexed): 3 0 1

*/
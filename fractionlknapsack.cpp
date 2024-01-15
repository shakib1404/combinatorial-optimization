#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
    int weight;
    int benefit;
    double value; // benefit-to-weight ratio

    Item(int w, int b) : weight(w), benefit(b) {
        value = static_cast<double>(benefit) / weight;
    }
};

bool compareItems(const Item& item1, const Item& item2) {
    return item1.value > item2.value;
}

void fractionalKnapsack(vector<Item>& items, int W) {
    sort(items.begin(), items.end(), compareItems);

    double totalValue = 0.0;
    int totalWeight = 0;

    for (const Item& item : items) {
        if (totalWeight + item.weight <= W) {
            totalValue += item.benefit;
            totalWeight += item.weight;
            cout << "Take the whole item with weight " << item.weight << " and benefit " << item.benefit << endl;
        } else {
            int remainingWeight = W - totalWeight;
            totalValue += item.value * remainingWeight;
            cout << "Take " << remainingWeight << " units of item with weight " << item.weight << " and benefit " << item.benefit << endl;
            break;
        }
    }

    cout << "Total value: " << totalValue << endl;
}

int main() {
    vector<Item> items = { {2, 7}, {3, 6}, {4, 9} ,{2,6},{5,12},{4,10},{1,3}};
    int maxWeight = 15;

    fractionalKnapsack(items, maxWeight);

    return 0;
}

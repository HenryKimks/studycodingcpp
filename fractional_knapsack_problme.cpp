#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    int weight;
    int value;  // 무게당 가격 (그냥 가격인 경우와 다름)
};

bool compare(Item item1, Item item2) {
    double unitValue1 = static_cast<double>(item1.value);
    double unitValue2 = static_cast<double>(item2.value);
    return unitValue1 > unitValue2;
}

int fractionalKnapsack(int W, vector<Item>& items) {
    sort(items.begin(), items.end(), compare);
    
    int totalValue = 0;
    
    for (int i = 0; i < items.size(); i++) {
        //cout << "i: " << i << ", weight: " << items[i].weight << ", value: " << items[i].value;
        if (W > items[i].weight) {
            totalValue += items[i].value * items[i].weight;
            W -= items[i].weight;            
            //cout << ", totalValue: " << totalValue << ", remained W: " << W << endl;
        } else {
            totalValue += items[i].value * W;
            W = 0;
            //cout << ", totalValue: " << totalValue << ", remained W: " << W << endl;
            break;
        }
    }
    
    return totalValue;
}

int main() {
    int W, N;
    cin >> W >> N;
    
    vector<Item> items(N);
    
    for (int i = 0; i < N; i++) {
        cin >> items[i].weight >> items[i].value;
    }
    
    int result = fractionalKnapsack(W, items);
    cout << result << endl;
    
    return 0;
}

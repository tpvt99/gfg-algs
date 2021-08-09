#include <iostream>
#include <vector>
#include <algorithm>

class Element {
private:
    int m_weight{};
    int m_value{};
public:
    Element(int weight, int value) {
        m_weight = weight;
        m_value = value;
    }
    int getWeight() {
        return m_weight;
    }
    int getValue() {
        return m_value;
    }
};



void initialize1(std::vector<Element> &elements);
void initialize2(std::vector<Element> &elements);
bool sortElement(Element e1, Element e2) ;
int fractionalKnapsack(std::vector<Element> elements, int maxWeight);

int main() {
    std::vector<Element> elements;
    initialize2(elements);
    std::cout << fractionalKnapsack(elements, 15) << std::endl;
    return 0;
}

void initialize1(std::vector<Element> &elements) {
    elements.push_back({50, 600});
    elements.push_back({20, 500});
    elements.push_back({30, 400});
}

void initialize2(std::vector<Element> &elements) {
    elements.push_back({10, 200});
    elements.push_back({5, 50});
    elements.push_back({20, 100});
}

bool sortElement(Element e1, Element e2) {
    return e1.getValue()/e1.getWeight() > e2.getValue()/e2.getWeight();
}

int fractionalKnapsack(std::vector<Element> elements, int maxWeight) {
    std::sort(elements.begin(), elements.end(), sortElement);
    int currentValue = 0;
    int currentWeight = 0;
    for (Element e : elements) {
        if (currentWeight < maxWeight) {
            if (e.getWeight() < (maxWeight - currentWeight)) {
                currentValue += e.getValue();
                currentWeight += e.getWeight();
            } else {
                double fractional = (maxWeight - currentWeight) / (float) e.getWeight();
                currentValue += (int) e.getValue() * fractional;
                currentWeight += (int) e.getWeight() * fractional;
            }
        }
        if (currentWeight == maxWeight)
            break;
    }
    return currentValue;
}
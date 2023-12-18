#include <iostream>
#include <memory>
#include <vector>

class ShopItem {
private:
    int id;
    std::string name;
    double price;

public:
    ShopItem(int itemId, const std::string& itemName, double itemPrice)
        : id(itemId), name(itemName), price(itemPrice) {}

    // ������ �������
    int getId() const {
        return id;
    }

    std::string getName() const {
        return name;
    }

    double getPrice() const {
        return price;
    }

    void setId(int itemId) {
        id = itemId;
    }

    void setName(const std::string& itemName) {
        name = itemName;
    }

    void setPrice(double itemPrice) {
        price = itemPrice;
    }
};

class ShopOrder {
private:
    std::vector<std::shared_ptr<ShopItem>> orderItems;

public:
    // ������ ����� � ����������
    void addItem(const std::shared_ptr<ShopItem>& item, int quantity) {
        orderItems.push_back(item);
        // ��������� ������� ���������� ������
        item->setPrice(item->getPrice() * quantity);
    }

    // �������� �������� ������� ����������
    double getTotalCost() const {
        double totalCost = 0.0;
        for (const auto& item : orderItems) {
            totalCost += item->getPrice();
        }
        return totalCost;
    }

    // ������� ���������� �� �����
    void printOrder() const {
        std::cout << "����������:\n";
        for (const auto& item : orderItems) {
            std::cout << "����� ������: " << item->getName() << "\n"
                << "ֳ�� �� �������: " << item->getPrice() << "\n"
                << "-----------------------------\n";
        }
        std::cout << "�������� ������� ����������: " << getTotalCost() << "\n";
    }
};

int main() {
    
    // ��������� ��'���� ShopItem �� ������������� �������� ���������
    std::setlocale(LC_ALL, "uk_UA.utf8");
    auto item1 = std::make_shared<ShopItem>(1, "����� 1", 10.5);
    auto item2 = std::make_shared<ShopItem>(2, "����� 2", 20.0);
    auto item3 = std::make_shared<ShopItem>(3, "����� 3", 15.75);

    // ��������� ��'��� ShopOrder
    ShopOrder order;

    // ������ ������ �� ����������
    order.addItem(item1, 2); // ����������, �� �������� 2 ������� ������ 1
    order.addItem(item2, 1); // ����������, �� �������� 1 ������� ������ 2
    order.addItem(item3, 3); // ����������, �� �������� 3 ������� ������ 3

    // �������� ���������� �� �����
    order.printOrder();

    return 0;
}

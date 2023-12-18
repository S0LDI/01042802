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

    // Методи доступу
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
    // Додати товар у замовлення
    void addItem(const std::shared_ptr<ShopItem>& item, int quantity) {
        orderItems.push_back(item);
        // Враховуємо кількість замовлених товарів
        item->setPrice(item->getPrice() * quantity);
    }

    // Отримати загальну вартість замовлення
    double getTotalCost() const {
        double totalCost = 0.0;
        for (const auto& item : orderItems) {
            totalCost += item->getPrice();
        }
        return totalCost;
    }

    // Вивести замовлення на екран
    void printOrder() const {
        std::cout << "Замовлення:\n";
        for (const auto& item : orderItems) {
            std::cout << "Назва товару: " << item->getName() << "\n"
                << "Ціна за одиницю: " << item->getPrice() << "\n"
                << "-----------------------------\n";
        }
        std::cout << "Загальна вартість замовлення: " << getTotalCost() << "\n";
    }
};

int main() {
    
    // Створюємо об'єкти ShopItem із використанням розумних вказівників
    std::setlocale(LC_ALL, "uk_UA.utf8");
    auto item1 = std::make_shared<ShopItem>(1, "Товар 1", 10.5);
    auto item2 = std::make_shared<ShopItem>(2, "Товар 2", 20.0);
    auto item3 = std::make_shared<ShopItem>(3, "Товар 3", 15.75);

    // Створюємо об'єкт ShopOrder
    ShopOrder order;

    // Додаємо товари до замовлення
    order.addItem(item1, 2); // Припустимо, що замовили 2 одиниці товару 1
    order.addItem(item2, 1); // Припустимо, що замовили 1 одиницю товару 2
    order.addItem(item3, 3); // Припустимо, що замовили 3 одиниці товару 3

    // Виводимо замовлення на екран
    order.printOrder();

    return 0;
}

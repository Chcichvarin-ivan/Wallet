/*
 * @Author: Ivan Chichvarin ichichvarin@humanplus.ru
 * @Date: 2024-05-09 18:38:44
 * @LastEditors: Ivan Chichvarin ichichvarin@humanplus.ru
 * @LastEditTime: 2024-05-09 18:39:00
 * @FilePath: /Wallet/wallet.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <vector>

using namespace std;

class MoneyBox {
public:
    explicit MoneyBox(vector<int64_t> nominals)
        : nominals_(move(nominals))
        , counts_(nominals_.size()) {
    }

    const vector<int>& GetCounts() const {
        return counts_;
    }

    void PushCoin(int64_t value) {
        // реализуйте метод добавления купюры или монеты
    }

    void PrintCoins(ostream& out) const {
        // реализуйте метод печати доступных средств
    }

private:
    const vector<int64_t> nominals_;
    vector<int> counts_;
};

ostream& operator<<(ostream& out, const MoneyBox& cash) {
    cash.PrintCoins(out);
    return out;
}

int main() {
    MoneyBox cash({10, 50, 100, 200, 500, 1000, 2000, 5000});

    int times;
    cout << "Enter number of coins you have:"s << endl;
    cin >> times;

    cout << "Enter all nominals:"s << endl;
    for (int i = 0; i < times; ++i) {
        int64_t value;
        cin >> value;
        cash.PushCoin(value);
    }

    cout << cash << endl;
}
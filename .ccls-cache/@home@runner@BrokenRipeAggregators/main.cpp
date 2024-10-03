#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    int N, A, B;

    // Введення розміру масиву
    cout << "Введіть розмір масиву N: ";
    cin >> N;

    // Введення меж для випадкових чисел
    cout << "Введіть межі A і B для випадкових чисел (A < B): ";
    cin >> A >> B;

    // Створення масиву та заповнення випадковими числами
    vector<int> arr(N);
    srand(time(0)); // Ініціалізація генератора випадкових чисел
    for (int i = 0; i < N; ++i) {
        arr[i] = rand() % (B - A + 1) + A; // Випадкові числа в діапазоні [A, B]
    }

    // Виведення елементів масиву
    cout << "Елементи масиву: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    // Знаходження максимального і мінімального елемента
    int maxElem = *max_element(arr.begin(), arr.end());
    int minElem = *min_element(arr.begin(), arr.end());
    cout << "Максимальний елемент: " << maxElem << endl;
    cout << "Мінімальний елемент: " << minElem << endl;

    // Обчислення суми всіх елементів
    int sum = 0;
    for (int num : arr) {
        sum += num;
    }
    cout << "Сума всіх елементів: " << sum << endl;

    // Сортування масиву
    sort(arr.begin(), arr.end());
    cout << "Відсортований масив: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    // Пошук індексу заданого елемента
    int searchElement;
    cout << "Введіть елемент для пошуку: ";
    cin >> searchElement;

    auto it = find(arr.begin(), arr.end(), searchElement);
    if (it != arr.end()) {
        cout << "Індекс елемента " << searchElement << ": " << distance(arr.begin(), it) << endl;
    } else {
        cout << "Елемент " << searchElement << " не знайдено в масиві." << endl;
    }

    // Перевірка, чи масив відсортований
    if (is_sorted(arr.begin(), arr.end())) {
        cout << "Масив відсортований." << endl;
    } else {
        cout << "Масив не відсортований." << endl;
    }

    return 0;
}

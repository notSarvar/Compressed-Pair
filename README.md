# Compressed Pair
Аналог класса std::pair обладающий следующим полезным свойством: если один из хранимых типов является пустым, то он не занимает памяти в структуре. Сам прием называется [empty base optimization](https://en.cppreference.com/w/cpp/language/ebo).
### Класс умеет :
Получать хранимые поля по константной/неконстантной ссылке через методы GetFirst/GetSecond;

Умеет конструироваться из lvalue- и rvalue-ссылок;

Когда это возможно, пустые типы не занимают места.

### Примечание
Для более глубокого понимания метода оптимизации не использовался аттрибут [[[no_unique_address]]](https://en.cppreference.com/w/cpp/language/attributes/no_unique_address), добавленный в C++20.

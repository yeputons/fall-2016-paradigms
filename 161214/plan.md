# Юнит-тесты
## Практика
* `pip install pytest`
* Качаем скрипты первого задания (без wordcount) с https://www.dropbox.com/sh/l7zh2fquflldw9y/AAArxvYNcScTLqPJ5IL355EZa?dl=0
* Пишем юнит-тесты вместе, не оглядываясь на реализацию (типа TDD).
## Как принято писать
* Хороший: зависит только от интерфейса (а не по коду), нет зависимостей и вспомогательных функций
* Хотя знание кода может подсказать, какие дополнительные тесты интерфейса надо написать.
* Тестируем не циклы и if'ы реализации, а "сценарии поведения": как этот объект/функцию будут использовать клиенты в реальном мире.
* Написан в стиле "настроили-действие-проверили"
## Что unit-тестировать
* "Очевидные" случаи
* Все крайние случаи (пустые строки/списки, None-ы, NULL-ы, nullptr-ы, деление на ноль и прочая) - потом вы их уже тестировать не будете
## Продолжение практики
* Пишем реализацию, настраиваем хоткей в редакторе, тестируем, итерируемся.
* Если совсем надо протестировать именно реализацию - может, распилить функцию на несколько? Ну или можно написать честный white-box тест, но его лучше от остальных отделить. Например, тестирование подсчёта ссылок в умном указателе.
* Нашли баг - сразу написали тест, *проверили падение*, поправили, *проверили работу*

## Что ещё unit-тестировать
* Полное покрытие строк кода (можно мерять автоматически: https://docs.python.org/devguide/coverage.html). Это заменит статическую типизацию для Python и заодно половит кучу крайних случаев. В идеале - все пути исполнения, но фиг такое получится в реальном коде.
* Всякие некорректные аргументы.
* Заодно документируем "как использовать библиотеку", это документация никогда не устареет
* Полезно писать такие тесты к старому коду, у которого тестов не было: тогда мы фиксируем старое поведение и его точно не поломаем, и не поломаем зависимый код (привет из гугла)

## Требования к unit-тестами
* Все тесты всегда проходят в корректном коде. Нестабильные тесты лесом - делаем детерминированными (потому что фиг поймаешь ошибку). Особенно весело в многопоточных программах
* Все внешние зависимости очень изолированны внутри кода теста (максимум - временный файл создать при помощи фреймворка, чтобы он потом удалился), никаких "поднимите SQL-сервер там-то". Если хочется - см. mock'и чуть позже
* Никаких зависимостей от других unit'ов - тестируем отдельно. Если надо - см. mock
* Отрабатывает за миллисекунды, чтобы можно было запустить сотни тестов за секунду
* Никакого вывода, на который надо глазами смотреть (это общее требование к автотестам). Сообщения об ошибках в логе - либо ожидаемые, либо сигналят об ошибке. Иначе кто-нибудь либо забудет прочитать логи, либо забьёт, потому что там куча сообщений не по делу.
* Запускаются одной кнопкой (при правильном фреймворке), чтобы всегда можно было пустить
* Важно проверять, что тесты работают: написали, сломали, проверили, починили, проверили. TDD идёт примерно отсюда.

## Проблемы с unit-тестами
* Не проверят то, про что вы не подумали (крайний случай или не так поняли задание, плохо спроектировали интерфейс и потом его где-то не так используете)
* Не проверят, что функции друг про друга предполагают одно и то же (для этого есть интеграционные)
* Не проверят, что программа в целом адекватна (для этого есть функциональные)
* Поэтому даже если все юнит-тесты проходят - ещё не факт, что всё корректно. Но очень хорошее приближение, из которого намного проще что-то исправлять

## Что делать с зависимостями 
* Если компонент зависит от реализации остальных, в юнит-тестах (пример: тестирование без Scope).
* Библиотека для Mock'ов вроде https://docs.python.org/3/library/unittest.mock.html - создаёт "фиктивные объекты", у которых тест задаёт поведение. Сначала рассказываем mock'у, каких вызовов ждать и как реагировать, потом используем.
* Надо осторожно с mock'ами, потому что мы влезаем в детали реализации ("сколько раз вызывается такой-то метод" или "с какими аргументами")
* Можно делать mock на внешние зависимости: базу данных, файлы, сеть. В динамических языках просто monkey patching (есть в библиотеках), а в статических надо аккуратно выносить интерфейсы и не делать глобальных или статических переменных (потому что их не запатчишь). Доведение до абсолюта - dependency injection на всё на свете, но не в этом курсе.
* Пример с monkey patch стандартного ввода руками для функции print.
* Пример с monkey patch для pytest.

# Практика
* Решаем задание: "написать калькулятор для выражений вида <<сложение>>, <<деление>> и <<синус от этих двух>>". Надо разделить на функции, написать юнит тесты, и - самое главное - функциональный тест с monkey patch и StringIO (mock)

Файл laba_2_sem_2 - своя реализация двусвязного циклического списка
Заданние:
Дана последовательность неповторяющихся целых чисел ,n1,n2…nz. Получить последовательность длиной, содержащую разность между первым и последним 
элементом, вторым и предпоследним и т.д. Если n - нечетное, центральный элемент копируется без изменений

Файл laba_3_algos - своя реализация, динамического стек и статической очереди, процессора и генератора задач
Задание:
Система состоит из процессора P, трѐх очередей F0, F1, F2 и стека S. 
В систему поступают запросы на выполнение задач.Поступающие запросы ставятся в соответствующие приоритетам 
очереди. Сначала обрабатываются задачи из очереди F0. Если она пуста, 
можно обрабатывать задачи из очереди F1. Если и она пуста, то можно 
обрабатывать задачи из очереди F2. Если все очереди пусты, то система 
находится в ожидании поступающих задач (процессор свободен), либо в 
режиме обработки предыдущей задачи (процессор занят). Если поступает 
задача с более высоким приоритетом, чем обрабатываемая в данный момент,
то обрабатываемая помещается в стек и может обрабатываться тогда и 
только тогда, когда все задачи с более высоким приоритетом уже 
обработаны.

Файл laba_4_alogos - своя реализация хэш-таблицы с форматом ключа "ццББцц", где «ц» – это цифра 0…9; «Б» – это большая буква латиницы A…Z.
Метод хэширования: Открытое хэширование

Описание хэш функции:
Функция начинает с инициализации переменной hash нулем. Затем каждый символ строки key обрабатывается в цикле. Для каждого символа выполняется следующее действие: текущее значение hash умножается на 7 и прибавляется к квадрату кода символа c (это обеспечивает различность значений для разных символов). Затем результат берется по модулю от максимального размера хэш-таблицы (maxsize), чтобы получить число в пределах допустимого диапазона индексов.

Результаты анализа хеш-функции

![image](https://github.com/cherrypasska/Algos/assets/144723038/a004e841-c0c7-44a5-806b-8979e9b3b093)

Что может программа:
создавать хеш-таблицу;
добавлять элементы в хеш-таблицу; 
просматривать хеш-таблицу; 
искать элементы в хеш-таблице по номеру сегмента/по ключу; 
выгружать содержимое хеш-таблицы в файл для построения гистограммы в MS Excel, или в аналогичном подходящем ПО; 
удалять элементы из хеш-таблицы;
проверка формата вводимого ключа;
при удалении элементов из хэш-таблицы, реализован алгоритм, позволяющий искать элементы, вызвавшие коллизию с удаленным;
в программе реализован алгоритм, обрабатывающий ситуации с переполнением хэш-таблицы. 

Файл laba_5_algos_2 - реализация сортировки массива методом подсчёта
В программе реализованы функции нахождения количества повторяющихся чисел среди элементов, а так же их добавления, удаления и нахождения.

Файл laba_6_algos - реализация АВЛ-дерева поиска
В программе реализованы функции, позволяющие:
Добавлять элементы в сбалансированное дерево поиска;
Удалять элементы из сбалансированного дерева поиска;
Искать элементы в дереве поиска с выводом количества шагов, за которое осуществляется поиск; 
Выводить дерево на экран в горизонтальном виде;
Выводить список, соответствующий обходу вершин, обратным обходом; 
Циклично удалять каждый нечётный узел дерева и перестраивать дерево, беря элементы по порядку обхода (на каждой итерации выводится дерево).

Файл laba_7_algos - реализация графа как матрицы смежности
В программе реализована функци позволяющая решить задачу:
В помещении присутствует некоторое число человек. Некоторые из них знакомы между собой. Проверить можно ли перезнакомить людей между собой?
(Незнакомы люди могут познакомиться через общего знакомого

#include <iostream>
using namespace std;

struct Elem
{
   int data; // данные
   Elem * next, * prev;
};

class List
{
   // Голова, хвост
   Elem * Head, * Tail;
   // Количество элементов
   int Count;

public:

   // Конструктор
   List();
   // Деструктор
   ~List();
    // Получить количество
   int GetCount();
   // Получить элемент списка
   Elem* GetElem(int);
	   // Удалить весь список
    void Insert(int pos = 0);
	   // Добавление в конец списка
   void AddTail(int n);
	   // Добавление в начало списка
   void AddHead(int n);
   void Swap();

	
};

List::List()
{
   // Изначально список пуст
   Head = Tail = NULL;
   Count = 0;
}
List::~List()
{
   // Удаляем все элементы
   DelAll();
}
void List::AddHead(int n)
{
   // новый элемент
   Elem * temp = new Elem;

   // Предыдущего нет
   temp->prev = 0;
   // Заполняем данные
   temp->data = n;
   // Следующий - бывшая голова
   temp->next = Head;

   // Если элементы есть?
   if(Head != 0)
      Head->prev = temp;

   // Если элемент первый, то он одновременно и голова и хвост
   if(Count == 0)
      Head = Tail = temp;
   else
      // иначе новый элемент - головной
      Head = temp;

   Count++;
}

void List::AddTail(int n)
{
   // Создаем новый элемент
   Elem * temp = new Elem;
   // Следующего нет
   temp->next = 0;
   // Заполняем данные
   temp->data = n;
   // Предыдущий - бывший хвост
   temp->prev = Tail;
	
   // Если элементы есть?
   if(Tail != 0)
      Tail->next = temp;
	
   // Если элемент первый, то он одновременно и голова и хвост
   if(Count == 0)
      Head = Tail = temp;
   else
      // иначе новый элемент - хвостовой
   Tail = temp;			

   Count++;
}

void List::Insert(int pos)
{
   // если параметр отсутствует или равен 0, то запрашиваем его
   if(pos == 0)
   {
      cout << "Input position: ";
      cin >> pos;
   }

  // Позиция от 1 до Count?
   if(pos < 1 || pos > Count + 1)
   {
      // Неверная позиция
      cout << "Incorrect position !!!\n";
      return;
   }

   // Если вставка в конец списка
   if(pos == Count + 1)
   {
      // Вставляемые данные
      int data;
      cout << "Input new number: ";
      cin >> data;
      // Добавление в конец списка
      AddTail(data);
      return;
   }
   else if(pos == 1)
   {
      // Вставляемые данные
      int data;
      cout << "Input new number: ";
      cin >> data;
      // Добавление в начало списка
      AddHead(data);
      return;
   }

   // Счетчик
   int i = 1;

   // Отсчитываем от головы n - 1 элементов
   Elem * Ins = Head;

   while(i < pos)
   {
      // Доходим до элемента, 
      // перед которым вставляемся
      Ins = Ins->next;
      i++;
   }

   // Доходим до элемента, 
   // который предшествует
   Elem * PrevIns = Ins->prev;
	
   // Создаем новый элемент
   Elem * temp = new Elem;

   // Вводим данные
   cout << "Input new number: ";
   cin >> temp->data;

   // настройка связей
   if(PrevIns != 0 && Count != 1)
      PrevIns->next = temp;
	
   temp->next = Ins;
   temp->prev = PrevIns;
   Ins->prev = temp;
	
   Count++;
}

int List::GetCount()
{
    return Count;
}

Elem * List::GetElem(int pos)
{
   Elem *temp = Head;

   // Позиция от 1 до Count?
   if(pos < 1 || pos > Count)
   {
      // Неверная позиция
      cout << "Incorrect position !!!\n";
      return 0;
   }

   int i = 1;
   // Ищем нужный нам элемент
   while(i < pos && temp != 0)
   {
      temp = temp->next;
      i++;
   }

   if(temp == 0)
      return 0;
   else
      return temp;
}

List::Swap();
{
   int i = 1;
   Elem *temp = Head;
   while (i + 2 < count)
   {
      if (temp->data > 0 && temp->next->data < 0)
         swap(temp->data, temp->next->data);
      temp = temp->next->next;
   }
     
}


using System;
using System.IO;

namespace LinkedList
{
    public class Item
    {
        public int number { get; set; }
        public string name { get; set; }
        public Item next;
    }
    public class LinkedList
    {
        private Item head;
        private int count;
        public LinkedList()
        {
            head = null;
            count = 0;
        }
        public LinkedList(int kolvo)
        {
            head = new Item();
            Item tmp = head;
            Console.WriteLine("Введите данные (номер, имя):");
            tmp.number = Int32.Parse(Console.ReadLine());
            tmp.name = Console.ReadLine();
            for (int i = 0; i < kolvo - 1; ++i)
            {
                tmp.next = new Item();
                tmp = tmp.next;
                Console.WriteLine("Введите данные (номер, имя):");
                tmp.number = Int32.Parse(Console.ReadLine());
                tmp.name = Console.ReadLine();
            }
            tmp.next = null;
            count = kolvo;
        }
        ~LinkedList()
        {
            head = null;
        }
        public void print()
        {
            Item tmp = head;
            for (int i = 0; i < count; ++i)
            {
                Console.WriteLine(tmp.number + tmp.name);
                tmp = tmp.next;
            }
        }
        public void addToEnd(int number, string name)
        {
            if (count == 0)
            {
                head = new Item();
                head.number = number;
                head.name = name;
                head.next = null;
                count += 1;
            }
            else
            {
                Item tmp = head;
                for (int i = 0; i < count - 1; i++)
                {
                    tmp = tmp.next;
                }
                tmp.next = new Item();
                tmp = tmp.next;
                tmp.number = number;
                tmp.name = name;
                tmp.next = null;
                count += 1;
            }
        }
        public void addByInd(int index, int number, string name)
        {
            if (index == count - 1)
            {
                addToEnd(number, name);
            }
            else if (index < count)
            {
                Item tmp = head;
                for (int i = 0; i < index - 1; ++i)
                {
                    tmp = tmp.next;
                }
                Item rez = tmp.next;        // сохраняю адрес впереди стоящего
                tmp.next = new Item();      // создаю новый элемент, ссылка на который находится у предыдущего
                tmp = tmp.next;             // перехожу в новый
                tmp.number = number;
                tmp.name = name;
                tmp.next = rez;             // новый указывает на следующий
                count += 1;
            }
            else
            {
                Console.WriteLine("Выход за границы списка");
            }
        }
        public void delEl(int index)
        {
            if (index < count)
            {
                Item tmp = head;
                for (int i = 0; i < index; ++i)
                {
                    tmp = tmp.next;
                }
                Item rez = tmp.next;            // сохранил адрес на следующий после удаляемого
                tmp = head;
                for (int i = 0; i < index - 1; ++i)
                {
                    tmp = tmp.next;
                }
                tmp.next = rez;                 // теперь предыдущий указывает на следующий после удаленного
                count -= 1;
            }
            else
            {
                Console.WriteLine("Выход за границы списка");
            }
        }
        public string searchByNum(int number)
        {
            Item tmp = head;
            if (tmp.number == number)
            {
                return tmp.name;
            }
            for (int i = 0; i < count - 1; ++i)
            {
                tmp = tmp.next;
                if (tmp.number == number)
                {
                    return tmp.name;
                }
            }
            return "Совпадений не найдено";
        }
        public void look(int index)
        {
            Item tmp = head;
            for (int i = 0; i < index; ++i)
            {
                tmp = tmp.next;
            }
            Console.WriteLine(tmp.number + tmp.name);
        }
        public void redact(int index, int number, string name)
        {
            Item tmp = head;
            for (int i = 0; i < index; ++i)
            {
                tmp = tmp.next;
            }
            tmp.number = number;
            tmp.name = name;
        }
        public void recordToFile(string nameOfFile)
        {
            using (var sw = new StreamWriter(nameOfFile))
            {
                Item tmp = head;
                sw.WriteLine(tmp.number + tmp.name);
                for (int i = 0; i < count - 1; ++i)
                {
                    tmp = tmp.next;
                    sw.WriteLine(tmp.number + tmp.name);
                }
            }
        }
        public void readFromFile(string nameOfFile)
        {
            using (var sr = new StreamReader(nameOfFile))
            {
                var text = sr.ReadToEnd();
                Console.Write(text);
            }
        }
    }
    class Program
    {
        static void Main()
        {
            var list = new LinkedList(4);
            list.addByInd(2, 99, "PPP");
            list.delEl(2);
            Console.WriteLine(list.searchByNum(1234));
            Console.WriteLine(list.searchByNum(4));
            list.look(1);
            list.print();
            Console.WriteLine("__________________");
            list.recordToFile("test.txt");
            list.readFromFile("test.txt");
        }
    }
}

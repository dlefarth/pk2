namespace _12
{
    class Node<T>
    {
        public Node(T value)
        {
            this.Value = value;
            this.Next = null;
        }

        public T Value { get; set; }
        public Node<T> Next { get; set; }
    }

    public class LinkedList<T>
    {
        class ListIterator<IT> : Iterator<IT>
        {
            public ListIterator(LinkedList<IT> list) => node = list.head;

            Node<IT> node;
            public bool HasNext()
            {
                return !(node is null);
            }

            public IT Next()
            {
                IT value = node.Value;
                node = node.Next;
                return value;
            }
        }

        Node<T> head;

        public void Add(T element)
        {
            if (head is null)
            {
                head = new Node<T>(element);
                return;
            }

            Node<T> current = head;
            while (!(current.Next is null))
            {
                current = current.Next;
            }
            current.Next = new Node<T>(element);
        }

        public void Remove(int i)
        {
            Node<T> previous = null;
            Node<T> current = head;
            int counter = 0;

            if (current is null)
            {
                return;
            }

            while (!(current.Next is null) && counter < i)
            {
                previous = current;
                current = current.Next;
            }

            if (previous != null)
            {
                previous.Next = current.Next;
            }
            else
            {
                head = null;
            }
        }

        public Iterator<T> Iterator()
        {
            return new ListIterator<T>(this);
        }
    }
}
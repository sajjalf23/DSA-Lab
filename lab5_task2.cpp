#include<iostream>
using namespace std;

template<class T>
class queue {
    private:
        T* data;
        int front;
        int rear;
        const int max_size;

    public:
        queue(const int n) : max_size(n) {
            data = new T[max_size];
            front = -1;
            rear = -1;
        }

        queue() : max_size(5) {
            data = new T[max_size];
            front = -1;
            rear = -1;
        }

        ~queue() {
            delete[] data;
        }

        bool isfull() {
            return (front == (rear + 1) % max_size);
        }

        bool isempty() {
            return (front == -1);
        }

        void enqueue(const T newitem) {
            if (isfull()) {
                cout << "Queue overflow" << endl;
            } else {
                rear = (rear + 1) % max_size;
                data[rear] = newitem;
                if (front == -1) {
                    front = 0;
                }
            }
        }

        void dequeue() {
            if (isempty()) {
                cout << "Queue is empty" << endl;
            } else if (front == rear) {
                // Only one element was in the queue, after dequeue it's empty
                front = rear = -1;
            } else {
                front = (front + 1) % max_size;
            }
        }

        void clear() {
            front = -1;
            rear = -1;
        }

        T getfront() {
            if (isempty()) {
                cout << "Queue is empty" << endl;
                return T();  // Return default-constructed object
            }
            return data[front];
        }

        T getrear() {
            if (isempty()) {
                cout << "Queue is empty" << endl;
                return T();  // Return default-constructed object
            }
            return data[rear];
        }

        void showstructure() {
            if (isempty()) {
                cout << "Queue is empty" << endl;
                return;
            }
            cout << "Queue elements: ";
            if (front <= rear) {
                for (int i = front; i <= rear; i++) {
                    cout << data[i] << " ";
                }
            } else {
                for (int i = front; i < max_size; i++) {
                    cout << data[i] << " ";
                }
                for (int i = 0; i <= rear; i++) {
                    cout << data[i] << " ";
                }
            }
            cout << endl;
        }
};

int main() {
    queue<string> q1;

    q1.enqueue("sajjal");
    q1.enqueue("papa");
    q1.enqueue("bahi");
    q1.enqueue("mama");
    q1.enqueue("class");

    q1.showstructure();  // Shows all elements
    cout << "Front element: " << q1.getfront() << endl;
    cout << "Rear element: " << q1.getrear() << endl;

    q1.dequeue();
    q1.showstructure();  // Shows updated structure after dequeuing

    q1.clear();
    q1.showstructure();  // Shows that queue is empty
}

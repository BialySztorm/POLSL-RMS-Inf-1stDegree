# skipcq: PYL-W0622
def max(tab):
    max = tab[0]
    for i in range(1, len(tab)):
        if tab[i] > max:
            max = tab[i]
    return max


# skipcq: PYL-W0622
def min_and_max(tab):
    min = tab[0]
    max = tab[0]
    for i in range(1, len(tab)):
        if tab[i] > max:
            max = tab[i]
        if tab[i] < min:
            min = tab[i]
    return (min, max)


class Queue:
    def __init__(self, size):
        self.size = size
        self.queueTab = [None] * size
        self.head = 0
        self.tail = 0
        self.count = 0

    def is_empty(self):
        return self.count == 0

    def is_full(self):
        return self.count == self.size

    def enqueue(self, item):
        if not self.is_full():
            self.queueTab[self.tail] = item
            self.tail = (self.tail + 1) % self.size
            self.count += 1
        else:
            print("Queue is full. Cannot enqueue.")

    def dequeue(self):
        if not self.is_empty():
            item = self.queueTab[self.head]
            self.queueTab[self.head] = None
            self.head = (self.head + 1) % self.size
            self.count -= 1
            return item
        print("Queue is empty. Cannot dequeue.")
        return None

    def display(self):
        if not self.is_empty():
            current = self.head
            items = []
            for _ in range(self.count):
                items.append(self.queueTab[current])
                current = (current + 1) % self.size
            print("Queue:", items)
        else:
            print("Queue is empty.")


tab = [5, 3, 2, 1, 4, 6, 7, 6, 3]
print("Tab we working on: ", tab)
print("max:", max(tab))
mini, maxi = min_and_max(tab)
print("min:", mini, ", max:", maxi)
size = 20
print("creating queue with size ", size)
q = Queue(size)
for i in tab:
    q.enqueue(i)
q.display()
# while not q.isEmpty():
# print(q.dequeue())

print(q.dequeue())
print(q.dequeue())
print(q.dequeue())

for i in tab:
    q.enqueue(i)
q.display()

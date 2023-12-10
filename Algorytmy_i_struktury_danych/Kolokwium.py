# %%
import random
import time
import heapq
from collections import defaultdict

# %%
# *  Zadanie 1


def quicksort(arr):
    if len(arr) <= 1:
        return arr
    else:
        pivot_index = get_median_of_three(arr)
        pivot = arr.pop(pivot_index)
        less = [x for x in arr if x <= pivot]
        greater = [x for x in arr if x > pivot]
        return quicksort(less) + [pivot] + quicksort(greater)


def get_median_of_three(arr):
    if len(arr) < 3:
        return len(arr) // 2
    else:
        indices = random.sample(range(len(arr)), 3)
        values = [arr[i] for i in indices]
        median_value = sorted(values)[1]
        return arr.index(median_value)

# %%
# tab = list({2,6,9,5,34,87,65,5,4})
# tab =  list({2,1})
# print(quicksort(tab))


for i in range(10):
    tab = [random.randint(0, 1000000) for _ in range(1000000)]
    start_time = time.time()
    # print(quicksort(tab))
    quicksort(tab)
    quicksort_time = time.time() - start_time
    print("quicksort time: ", quicksort_time)

# Quicksort z medianą 3 el jako pivot:
# quicksort time:  3.7627944946289062
# quicksort time:  3.7460193634033203
# quicksort time:  3.7387912273406982
# quicksort time:  3.7462315559387207
# quicksort time:  3.7346951961517334
# quicksort time:  3.968057870864868
# quicksort time:  3.9064981937408447
# quicksort time:  3.779522657394409
# quicksort time:  3.737534284591675
# quicksort time:  3.7574946880340576

# Quicksort z pivotem jako posortowany element:
# quicksort time:  2.7400870323181152
# quicksort time:  2.9044342041015625
# quicksort time:  2.706010103225708
# quicksort time:  2.778737783432007
# quicksort time:  2.7594971656799316
# quicksort time:  2.8044345378875732
# quicksort time:  2.658747434616089
# quicksort time:  2.525383949279785
# quicksort time:  2.8117263317108154
# quicksort time:  2.7053821086883545

# Funkcja quicksort z zadania II
# def partition(tab, left, right):
#     pivot = tab[left]
#     low = left + 1
#     high = right

#     done = False
#     while not done:
#         while low <= high and tab[low] <= pivot:
#             low = low + 1
#         while tab[high] >= pivot and high >= low:
#             high = high - 1
#         if high < low:
#             done = True
#         else:
#             tab[low], tab[high] = tab[high], tab[low]
#     tab[left], tab[high] = tab[high], tab[left]

#     return high


# def quicksort(tab, left, right):
#     if left < right:
#         pivot = partition(tab, left, right)
#         quicksort(tab, left, pivot - 1)
#         quicksort(tab, pivot + 1, right)
#     return tab

# *  Zadanie 2


def calculate_frequencies(text):
    frequencies = defaultdict(int)
    for symbol in text:
        frequencies[symbol] += 1
    return frequencies


def build_huffman_tree(frequencies):
    heap = [[weight, [symbol, ""]] for symbol, weight in frequencies.items()]
    heapq.heapify(heap)
    while len(heap) > 1:
        lo = heapq.heappop(heap)
        hi = heapq.heappop(heap)
        for pair in lo[1:]:
            pair[1] = '0' + pair[1]
        for pair in hi[1:]:
            pair[1] = '1' + pair[1]
        heapq.heappush(heap, [lo[0] + hi[0]] + lo[1:] + hi[1:])
    return sorted(heapq.heappop(heap)[1:], key=lambda p: (len(p[-1]), p))


def huffman_encode(text):
    frequencies = calculate_frequencies(text)
    huffman_tree = build_huffman_tree(frequencies)
    with open("huffman_tree.txt", "w") as f:
        f.write(str(huffman_tree))
    huffman_code = {symbol: code for symbol, code in huffman_tree}
    return "".join(huffman_code[symbol] for symbol in text)


# %%
with (open("tekst.txt", "r")) as f:
    text = f.read()
encoded = huffman_encode(text)
with (open("encoded.txt", "w")) as f:
    f.write(encoded)
print(encoded)

# Zakodowany tekst:
# 010111010110101010011111011100001111011111010001011011000101110011100110100111111001000111001011011111111101100011010011111100101101111001101011111110101001011001011110100111110001110011101000111111000110001001011010000101010111011010000011000001011110101110101111010111101010101001111111010111000011111100111000100111011111000011100100011011010110001111000111100110111001011000010000001100010101110110001111101001001111101010101000111100011001000011110101010100101110010101101010100111111010001001101110000111111001111110010111010011111101110010001111001110011101011100011000100111110110001011011110010101010111011010011101101000101110101001011101011010000000111101101001010111010111101001111100011101111110001101111110110001111110100011010010111110001011101111001010000010101101111000100001011100001101010101011011111100011101101011111111011100011100001011110011011010010001011110110010011001111111110111000110001011011100000010111100110101101100110111011010011110111011011001110100110101011000110100111001000001101110001100010000001100010000001111111011001110110001010100111101111101110010110110110111001111101000111101110100011111011100011011011100111100000010011010010110110000001110001110010110011010110101000111000011001101000110000000001110100011010111001110010101011101111110101000010100100101000001000011111001110111001011010100100010010011111110011011011100111111010001111101110001100010111101010000111011001101101100111001000000001110011010000010000011011100101100010100000100000100001001011000101001010010000101101001001000110000010101111100101001000000110001101101110000000100000110111001010000011011100111101110000111011000110101001111000110011011100110011111110111000111101110011111110011011011001110110111110101100011011110100011100011000100100011001000011100100110110100010101001101111111001010011100110100001000011010100000110111001100000011001111010101001

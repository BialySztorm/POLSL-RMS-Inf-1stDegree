from random import randint
import time


def build_bad_char_table(pattern):
    bad_char = {}
    pattern_len = len(pattern)
    for i in range(pattern_len - 1):
        bad_char[pattern[i]] = pattern_len - i - 1
    return bad_char


def boyer_moore(text, pattern):
    text_length = len(text)
    pattern_length = len(pattern)
    alphabet_size = 256  # Assuming an extended ASCII character set
    tab = []

    def bad_character_shift(pattern):
        bad_char_shift = [pattern_length] * alphabet_size
        for i in range(pattern_length - 1):
            bad_char_shift[ord(pattern[i])] = pattern_length - 1 - i
        return bad_char_shift

    def good_suffix_shift(pattern):
        good_suffix_shift = [0] * pattern_length
        last_prefix_position = pattern_length

        for i in range(pattern_length - 1, -1, -1):
            if is_prefix(pattern, i + 1):
                last_prefix_position = i + 1
            good_suffix_shift[i] = last_prefix_position + pattern_length - 1 - i

        for i in range(pattern_length - 1):
            j = pattern_length - 1 - i
            if border_at_suffix(pattern, j):
                good_suffix_shift[j] = pattern_length - 1 - i

        return good_suffix_shift

    def is_prefix(pattern, p):
        pattern_length = len(pattern)
        j = 0
        for i in range(p, pattern_length):
            if pattern[i] != pattern[j]:
                return False
            j += 1
        return True

    def border_at_suffix(pattern, p):
        pattern_length = len(pattern)
        border_length = 0
        j = pattern_length - 1
        for i in range(p, -1, -1):
            if pattern[i] == pattern[j]:
                border_length += 1
                j -= 1
            else:
                return False
        return border_length == p + 1

    bad_char_shift = bad_character_shift(pattern)
    good_suffix_shift = good_suffix_shift(pattern)

    shift = 0
    while shift <= text_length - pattern_length:
        j = pattern_length - 1

        while j >= 0 and pattern[j] == text[shift + j]:
            j -= 1

        if j < 0:
            print(f"Pattern found at position: {shift}")
            tab.append(shift)
            shift += good_suffix_shift[0]
        else:
            bad_char_shift_value = bad_char_shift[ord(text[shift + j])] - (pattern_length - 1 - j)
            good_suffix_shift_value = good_suffix_shift[j]
            shift += max(bad_char_shift_value, good_suffix_shift_value)
    return tab


def rabin_karp(text, pattern):
    result = []
    text_len = len(text)
    pattern_len = len(pattern)
    if pattern_len == 0:
        return result

    # Wybierz wartość modulo dużą liczbę pierwszą
    prime = 101

    # Oblicz hasz wzorca i hasz pierwszego okna tekstu
    pattern_hash = 0
    text_hash = 0
    for i in range(pattern_len):
        pattern_hash = (pattern_hash + ord(pattern[i])) % prime
        text_hash = (text_hash + ord(text[i])) % prime

    for i in range(text_len - pattern_len + 1):
        if pattern_hash == text_hash:
            match = True
            for j in range(pattern_len):
                if pattern[j] != text[i + j]:
                    match = False
                    break
            if match:
                result.append(i)

        if i < text_len - pattern_len:
            # Oblicz hasz dla kolejnego okna tekstu
            text_hash = (text_hash - ord(text[i]) + ord(text[i + pattern_len])) % prime
            if text_hash < 0:
                text_hash += prime

    return result


def bubblesort(tab):
    n = len(tab)
    for i in range(n - 1):
        for j in range(n - 1, i, -1):
            if tab[j] < tab[j - 1]:
                tab[j], tab[j - 1] = tab[j - 1], tab[j]
    return tab


def partition(tab, left, right):
    pivot = tab[left]
    low = left + 1
    high = right

    done = False
    while not done:
        while low <= high and tab[low] <= pivot:
            low = low + 1
        while tab[high] >= pivot and high >= low:
            high = high - 1
        if high < low:
            done = True
        else:
            tab[low], tab[high] = tab[high], tab[low]
    tab[left], tab[high] = tab[high], tab[left]

    return high


def quicksort(tab, left, right):
    if left < right:
        pivot = partition(tab, left, right)
        quicksort(tab, left, pivot - 1)
        quicksort(tab, pivot + 1, right)
    return tab


# tab1 = ""
# size1 = 5
# for i in range(20):
#     tab1 += str(chr(ord('A') + randint(1, size1) - 1))

# print(tab1)
# print(boyer_moore(tab1, "AB"))
# print(rabin_karp(tab1, "AB"))
# tab2 = []
# size2 = 30
# for i in range(20):
#     tab2.append(randint(1, size2))

# print(tab2)
# print(bubblesort(tab2))
# print(quicksort(tab2, 0, len(tab2) - 1))
for i in range(10):
    tab = [randint(0, 1000000) for _ in range(1000000)]
    start_time = time.time()
    # print(quicksort(tab))
    quicksort(tab, 0, len(tab) - 1)
    quicksort_time = time.time() - start_time
    print("quicksort time: ", quicksort_time)


# Pobierz aktualny czas przed wykonaniem funkcji main
# start_time = time.time()

# print(start_time)

# # 10 zbiorów po 1mln elementów dla sortowanie liczb
# for i in range(10):
#     # Pobierz aktualny czas przed wykonaniem funkcji main
#     start_time1 = time.time()
#     print(f"iteration {i}")
#     tab = []
#     size = 10000
#     for j in range(size):
#         tab.append(randint(1, size))
#     quicksort(tab, 0, len(tab)-1)
#     # Pobierz czas po wykonaniu funkcji main
#     end_time1 = time.time()

#     # Oblicz różnicę czasu
#     elapsed_time1 = end_time1 - start_time1
#     print(f"Execution time: {elapsed_time1} seconds")

# # Pobierz czas po wykonaniu funkcji main
# end_time = time.time()

# # Oblicz różnicę czasu
# elapsed_time = end_time - start_time

# print(f"All\nExecution time: {elapsed_time} seconds")

# Bubble sort
# iteration 0
# Execution time: 5.067083358764648 seconds
# iteration 1
# Execution time: 5.11958909034729 seconds
# iteration 2
# Execution time: 5.014516592025757 seconds
# iteration 3
# Execution time: 4.9903037548065186 seconds
# iteration 4
# Execution time: 4.931165933609009 seconds
# iteration 5
# Execution time: 5.07574987411499 seconds
# iteration 6
# Execution time: 5.755630016326904 seconds
# iteration 7
# Execution time: 6.012115240097046 seconds
# iteration 8
# Execution time: 5.8065736293792725 seconds
# iteration 9
# Execution time: 5.894266843795776 seconds
# All
# Execution time: 53.669198989868164 seconds

# standard deviation: 0,415995925

# Quick sort
# iteration 0
# Execution time: 0.022989749908447266 seconds
# iteration 1
# Execution time: 0.026999473571777344 seconds
# iteration 2
# Execution time: 0.021264314651489258 seconds
# iteration 3
# Execution time: 0.023993492126464844 seconds
# iteration 4
# Execution time: 0.026000261306762695 seconds
# iteration 5
# Execution time: 0.02200627326965332 seconds
# iteration 6
# Execution time: 0.02899003028869629 seconds
# iteration 7
# Execution time: 0.02300739288330078 seconds
# iteration 8
# Execution time: 0.021992206573486328 seconds
# iteration 9
# Execution time: 0.02208399772644043 seconds
# All
# Execution time: 0.24431586265563965 seconds

# standard deviation: 0,002429406
